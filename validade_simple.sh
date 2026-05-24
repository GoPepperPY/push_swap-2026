#!/bin/bash

make

cat << 'EOF' > generate_sequence.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double compute_disorder(int *arr, int size) {
    long long mistakes = 0;
    long long total_pairs = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            total_pairs++;
            if (arr[i] > arr[j]) {
                mistakes++;
            }
        }
    }
    if (total_pairs == 0) return 0.0;
    return ((double)mistakes / (double)total_pairs) * 100.0;
}

void swap_elements(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        return 1;
    }
    
    int count = atoi(argv[1]);
    double min_disorder = atof(argv[2]);
    double max_disorder = atof(argv[3]);
    int seed_offset = atoi(argv[4]);

    srand((unsigned int)time(NULL) ^ (clock() + seed_offset));

    int *sorted_arr = malloc(count * sizeof(int));
    int *arr = malloc(count * sizeof(int));
    int *indices = malloc(count * sizeof(int));
    int *values = malloc(count * sizeof(int));

    int current_val = 0;
    for (int i = 0; i < count; i++) {
        current_val += (rand() % 10) + 1;
        sorted_arr[i] = current_val;
    }

    while (1) {
        for (int i = 0; i < count; i++) {
            arr[i] = sorted_arr[i];
        }

        int shuffle_percent = 40 + (rand() % 21);
        int unsorted_count = (count * shuffle_percent) / 100;

        for (int i = 0; i < count; i++) {
            indices[i] = i;
        }
        
        for (int i = 0; i < count; i++) {
            int j = i + rand() % (count - i);
            swap_elements(&indices[i], &indices[j]);
        }

        for (int i = 0; i < unsorted_count; i++) {
            values[i] = arr[indices[i]];
        }

        for (int i = 0; i < unsorted_count; i++) {
            int j = i + rand() % (unsorted_count - i);
            swap_elements(&values[i], &values[j]);
        }

        for (int i = 0; i < unsorted_count; i++) {
            arr[indices[i]] = values[i];
        }

        double disorder = compute_disorder(arr, count);
        
        if (disorder >= min_disorder && disorder <= max_disorder) {
            fprintf(stderr, "%.2f", disorder);
            for (int i = 0; i < count; i++) {
                printf("%d", arr[i]);
                if (i < count - 1) printf(" ");
            }
            printf("\n");
            break;
        }
    }

    free(sorted_arr);
    free(arr);
    free(indices);
    free(values);
    return 0;
}
EOF
rm -f args.txt generate_sequence.bin
echo "Compiling C sequence generator..."
gcc -O3 generate_sequence.c -o generate_sequence.bin
if [ $? -ne 0 ]; then
    echo "[ERROR] Compilation of generate_sequence.c failed."
    rm -f generate_sequence.c
    exit 1
else
    rm -f generate_sequence.c
fi

run_validation_suite() {
    local count=$1
    local limit_pass=$2
    local limit_good=$3
    local limit_excellent=$4
    local runs=1
    local min_disorder=48
    local max_disorder=50
    local max_ops=0

    echo "=================================================="
    echo "Starting test for $count numbers"
    echo "Runs: $runs | Disorder: ${min_disorder}% - ${max_disorder}% | Flag: --simple"
    echo "=================================================="

    for i in $(seq 1 $runs); do
        local disorder_value=$(./generate_sequence.bin $count $min_disorder $max_disorder $i 2>&1 > args.txt)
        local args=$(cat args.txt)
        
        local instructions=$(./push_swap --simple $args 2>/dev/null)
        local ops=$(echo "$instructions" | wc -l)
        local checker_result=$(echo "$instructions" | ./checker_linux $args 2>/dev/null)

        if [ "$checker_result" != "OK" ]; then
            echo "[ERROR] Run $i failed! checker_linux returned: $checker_result"
            echo "[ERROR] Operations count: $ops"
            echo "[ERROR] Disorder level: ${disorder_value}%"
            rm -f args.txt generate_sequence.c generate_sequence.bin
            exit 1
        fi

        if [ $ops -ge $limit_pass ]; then
            echo "[ERROR] Run $i failed! Exceeded operations limit."
            echo "[ERROR] Target: < $limit_pass | Actual: $ops"
            echo "[ERROR] Disorder level: ${disorder_value}%"
            rm -f args.txt generate_sequence.c generate_sequence.bin
            exit 1
        fi

        if [ $ops -gt $max_ops ]; then
            max_ops=$ops
        fi

        if [ $((i % 100)) -eq 0 ]; then
            echo "Progress: $i / $runs completed. Current max ops: $max_ops"
        fi
    done

    echo "--------------------------------------------------"
    echo "SUCCESS: All $runs tests passed for $count numbers!"
    echo "Maximum operations found: $max_ops"
    
    if [ $max_ops -lt $limit_excellent ]; then
        echo "Performance evaluation: EXCELLENT"
    elif [ $max_ops -lt $limit_good ]; then
        echo "Performance evaluation: GOOD"
    else
        echo "Performance evaluation: PASS"
    fi
    echo -e "\n"
}

run_validation_suite 500 12000 8000 5500
run_validation_suite 100 2000 1500 700

rm -f args.txt generate_sequence.c generate_sequence.bin
echo "Validation finished successfully."
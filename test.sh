#!/bin/bash
NUMS=500
DISORDER_MAX=100
FLAGS=''
while getopts "n:d:f:" opcao; do
    case "${opcao}" in
        n)
            NUMS="${OPTARG}"
            ;;
        d)
            DISORDER_MAX="${OPTARG}"
            ;;
        f)
            FLAGS="${OPTARG}"
            ;;
    esac
done
make
echo "[DISORDER_MAX=$DISORDER_MAX NUMS=$NUMS FLAGS=$FLAGS]"
python3 -c "import sys, random; count, range_min, range_max, unsorted_percent = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), float(sys.argv[4]); numbers = sorted(random.sample(range(range_min, range_max + 1), count)); unsorted_count = int(count * (unsorted_percent / 100.0)); indices = random.sample(range(count), unsorted_count) if unsorted_count > 1 else []; values = [numbers[i] for i in indices]; random.shuffle(values); [numbers.__setitem__(i, v) for i, v in zip(indices, values)]; print(*(numbers))" $NUMS 0 9999 $(( $DISORDER_MAX > 100 ? 100 : $DISORDER_MAX )) > args.txt
./push_swap --bench $FLAGS $(cat args.txt) | ./checker_linux $(cat args.txt)
rm args.txt 
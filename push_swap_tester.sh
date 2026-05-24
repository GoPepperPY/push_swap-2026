#!/bin/bash

# ══════════════════════════════════════════════════════════════════════════════
#  PUSH_SWAP ADVANCED TESTER
# ══════════════════════════════════════════════════════════════════════════════

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
BOLD='\033[1m'
DIM='\033[2m'
RESET='\033[0m'

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"
PASS=0
FAIL=0
TOTAL=0
ERRORS=()

# ── helpers ──────────────────────────────────────────────────────────────────

print_header() {
    echo ""
    echo -e "${BOLD}${CYAN}╔══════════════════════════════════════════════════════╗${RESET}"
    echo -e "${BOLD}${CYAN}║         PUSH_SWAP ADVANCED TESTER v2.0               ║${RESET}"
    echo -e "${BOLD}${CYAN}╚══════════════════════════════════════════════════════╝${RESET}"
    echo ""
}

print_section() {
    echo ""
    echo -e "${BOLD}${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
    echo -e "${BOLD}${MAGENTA}  $1${RESET}"
    echo -e "${BOLD}${MAGENTA}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
}

run_test() {
    local desc="$1"
    local args="$2"
    local expect_error="$3"
    local max_ops="$4"

    TOTAL=$((TOTAL + 1))

    if [ "$expect_error" = "error" ]; then
        output=$($PUSH_SWAP $args 2>&1)
        if echo "$output" | grep -q "Error"; then
            echo -e "  ${GREEN}✔${RESET} ${DIM}$desc${RESET}"
            PASS=$((PASS + 1))
        else
            echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}(expected Error, got: $output)${RESET}"
            FAIL=$((FAIL + 1))
            ERRORS+=("$desc")
        fi
        return
    fi

    ops=$($PUSH_SWAP $args 2>/dev/null)
    op_count=$(echo "$ops" | grep -c .)
    
    if [ -z "$ops" ]; then
        op_count=0
    fi

    result=$(echo "$ops" | $CHECKER $args 2>/dev/null)

    if [ "$result" = "OK" ]; then
        if [ -n "$max_ops" ] && [ "$op_count" -gt "$max_ops" ]; then
            echo -e "  ${YELLOW}⚠${RESET} ${BOLD}$desc${RESET} ${YELLOW}OK but $op_count ops (limit: $max_ops)${RESET}"
            FAIL=$((FAIL + 1))
            ERRORS+=("$desc — too many ops: $op_count/$max_ops")
        else
            if [ -n "$max_ops" ]; then
                echo -e "  ${GREEN}✔${RESET} ${DIM}$desc${RESET} ${DIM}[$op_count ops / limit $max_ops]${RESET}"
            else
                echo -e "  ${GREEN}✔${RESET} ${DIM}$desc${RESET} ${DIM}[$op_count ops]${RESET}"
            fi
            PASS=$((PASS + 1))
        fi
    else
        echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}(checker: $result, ops: $op_count)${RESET}"
        FAIL=$((FAIL + 1))
        ERRORS+=("$desc")
    fi
}

run_perf_test() {
    local desc="$1"
    local n="$2"
    local limit_pass="$3"
    local limit_good="$4"
    local limit_excellent="$5"
    local extra_flags="$6"

    TOTAL=$((TOTAL + 1))
    args=$(python3 -c "import random; l=list(range($n)); random.shuffle(l); print(' '.join(map(str,l)))")
    
    ops=$($PUSH_SWAP $extra_flags $args 2>/dev/null)
    op_count=$(echo "$ops" | grep -c .)
    if [ -z "$ops" ]; then op_count=0; fi

    result=$(echo "$ops" | $CHECKER $args 2>/dev/null)

    if [ "$result" != "OK" ]; then
        echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}WRONG SORT ($op_count ops)${RESET}"
        FAIL=$((FAIL + 1))
        ERRORS+=("$desc — wrong sort")
        return
    fi

    if [ "$op_count" -le "$limit_excellent" ]; then
        echo -e "  ${GREEN}✔${RESET} ${BOLD}$desc${RESET} ${GREEN}EXCELLENT${RESET} ${DIM}[$op_count ops / limit $limit_excellent]${RESET}"
        PASS=$((PASS + 1))
    elif [ "$op_count" -le "$limit_good" ]; then
        echo -e "  ${CYAN}✔${RESET} ${BOLD}$desc${RESET} ${CYAN}GOOD${RESET} ${DIM}[$op_count ops / limit $limit_good]${RESET}"
        PASS=$((PASS + 1))
    elif [ "$op_count" -le "$limit_pass" ]; then
        echo -e "  ${YELLOW}⚠${RESET} ${BOLD}$desc${RESET} ${YELLOW}PASS${RESET} ${DIM}[$op_count ops / limit $limit_pass]${RESET}"
        PASS=$((PASS + 1))
    else
        echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}FAIL${RESET} ${DIM}[$op_count ops / limit $limit_pass]${RESET}"
        FAIL=$((FAIL + 1))
        ERRORS+=("$desc — $op_count ops exceeds $limit_pass")
    fi
}

run_avg_perf_test() {
    local desc="$1"
    local n="$2"
    local runs="$3"
    local limit_pass="$4"
    local limit_good="$5"
    local limit_excellent="$6"
    local extra_flags="$7"

    TOTAL=$((TOTAL + 1))
    total_ops=0
    all_ok=true

    echo -ne "  ${DIM}Running $runs tests for $desc...${RESET}\r"

    for i in $(seq 1 $runs); do
        args=$(python3 -c "import random; l=list(range($n)); random.shuffle(l); print(' '.join(map(str,l)))")
        ops=$($PUSH_SWAP $extra_flags $args 2>/dev/null)
        op_count=$(echo "$ops" | grep -c .)
        if [ -z "$ops" ]; then op_count=0; fi
        result=$(echo "$ops" | $CHECKER $args 2>/dev/null)
        if [ "$result" != "OK" ]; then
            all_ok=false
            break
        fi
        total_ops=$((total_ops + op_count))
    done

    if [ "$all_ok" = false ]; then
        echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}WRONG SORT on one of $runs runs${RESET}"
        FAIL=$((FAIL + 1))
        ERRORS+=("$desc — wrong sort")
        return
    fi

    avg=$((total_ops / runs))

    if [ "$avg" -le "$limit_excellent" ]; then
        echo -e "  ${GREEN}✔${RESET} ${BOLD}$desc${RESET} ${GREEN}EXCELLENT${RESET} ${DIM}[avg $avg ops over $runs runs / limit $limit_excellent]${RESET}"
        PASS=$((PASS + 1))
    elif [ "$avg" -le "$limit_good" ]; then
        echo -e "  ${CYAN}✔${RESET} ${BOLD}$desc${RESET} ${CYAN}GOOD${RESET} ${DIM}[avg $avg ops over $runs runs / limit $limit_good]${RESET}"
        PASS=$((PASS + 1))
    elif [ "$avg" -le "$limit_pass" ]; then
        echo -e "  ${YELLOW}⚠${RESET} ${BOLD}$desc${RESET} ${YELLOW}PASS${RESET} ${DIM}[avg $avg ops over $runs runs / limit $limit_pass]${RESET}"
        PASS=$((PASS + 1))
    else
        echo -e "  ${RED}✘${RESET} ${BOLD}$desc${RESET} ${RED}FAIL${RESET} ${DIM}[avg $avg ops over $runs runs / limit $limit_pass]${RESET}"
        FAIL=$((FAIL + 1))
        ERRORS+=("$desc — avg $avg ops exceeds $limit_pass")
    fi
}

# ── checks ───────────────────────────────────────────────────────────────────

print_header

if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}ERROR: $PUSH_SWAP not found!${RESET}"
    exit 1
fi

if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}ERROR: $CHECKER not found!${RESET}"
    exit 1
fi

# ── edge cases ───────────────────────────────────────────────────────────────

print_section "EDGE CASES"

# no args
TOTAL=$((TOTAL + 1))
out=$($PUSH_SWAP 2>/dev/null)
if [ -z "$out" ]; then
    echo -e "  ${GREEN}✔${RESET} ${DIM}No args → no output${RESET}"
    PASS=$((PASS + 1))
else
    echo -e "  ${RED}✘${RESET} ${BOLD}No args → expected no output, got: $out${RESET}"
    FAIL=$((FAIL + 1))
    ERRORS+=("No args")
fi

# already sorted
TOTAL=$((TOTAL + 1))
out=$($PUSH_SWAP 1 2 3 4 5 2>/dev/null)
if [ -z "$out" ]; then
    echo -e "  ${GREEN}✔${RESET} ${DIM}Already sorted → no output${RESET}"
    PASS=$((PASS + 1))
else
    echo -e "  ${YELLOW}⚠${RESET} ${DIM}Already sorted → $out${RESET}"
    PASS=$((PASS + 1))
fi

# single element
run_test "Single element" "42" "" ""

# two elements
run_test "Two elements sorted" "1 2" "" "1"
run_test "Two elements unsorted" "2 1" "" "1"

# three elements
run_test "Three elements (1)" "1 2 3" "" "2"
run_test "Three elements (2)" "3 2 1" "" "3"
run_test "Three elements (3)" "2 3 1" "" "3"
run_test "Three elements (4)" "1 3 2" "" "3"

# five elements
run_test "Five elements" "5 4 3 2 1" "" "12"

# negative numbers
run_test "Negatives" "-5 -3 -1 -4 -2" "" ""
run_test "Mixed neg/pos" "-2 3 -1 4 0" "" ""

# large numbers
run_test "Large numbers" "2147483647 -2147483648 0 1 -1" "" ""

# ── error cases ───────────────────────────────────────────────────────────────

print_section "ERROR HANDLING"

run_test "Duplicate values" "3 2 3" "error"
run_test "Non-integer input" "1 two 3" "error"
run_test "Float input" "1.5 2 3" "error"
run_test "Empty string" '""' "error"
run_test "Overflow positive" "2147483648 1 2" "error"
run_test "Overflow negative" "-2147483649 1 2" "error"
run_test "Duplicate zeros" "0 0 1" "error"
run_test "Mixed valid/invalid" "1 2 abc 4" "error"

# ── strategy flags ────────────────────────────────────────────────────────────

print_section "STRATEGY FLAGS"

run_test "--simple flag" "--simple 5 4 3 2 1" "" ""
run_test "--medium flag" "--medium 5 4 3 2 1" "" ""
run_test "--complex flag" "--complex 5 4 3 2 1" "" ""
run_test "--adaptive flag" "--adaptive 5 4 3 2 1" "" ""

# ── correctness tests ─────────────────────────────────────────────────────────

print_section "CORRECTNESS — 20 RANDOM TESTS (n=100)"

for i in $(seq 1 20); do
    args=$(python3 -c "import random; l=list(range(100)); random.shuffle(l); print(' '.join(map(str,l)))")
    run_test "Random 100 #$i" "$args" "" ""
done

print_section "CORRECTNESS — 10 RANDOM TESTS (n=500)"

for i in $(seq 1 10); do
    args=$(python3 -c "import random; l=list(range(500)); random.shuffle(l); print(' '.join(map(str,l)))")
    run_test "Random 500 #$i" "$args" "" ""
done

# ── performance ───────────────────────────────────────────────────────────────

print_section "PERFORMANCE — n=100 (avg over 10 runs)"

run_avg_perf_test "Default (adaptive) n=100" 100 10 2000 1500 700
run_avg_perf_test "--simple n=100" 100 10 99999 99999 99999 "--simple"
run_avg_perf_test "--medium n=100" 100 10 2000 1500 700 "--medium"
run_avg_perf_test "--complex n=100" 100 10 2000 1500 700 "--complex"

print_section "PERFORMANCE — n=500 (avg over 5 runs)"

run_avg_perf_test "Default (adaptive) n=500" 500 5 12000 8000 5500
run_avg_perf_test "--medium n=500" 500 5 12000 8000 5500 "--medium"
run_avg_perf_test "--complex n=500" 500 5 12000 8000 5500 "--complex"

# ── disorder adaptive ─────────────────────────────────────────────────────────

print_section "ADAPTIVE — DISORDER SCENARIOS"

# low disorder (~10%)
TOTAL=$((TOTAL + 1))
args=$(python3 -c "
import random
l = list(range(100))
swaps = 5
for _ in range(swaps):
    i,j = random.sample(range(100),2)
    l[i],l[j] = l[j],l[i]
print(' '.join(map(str,l)))
")
ops=$($PUSH_SWAP --adaptive $args 2>/dev/null)
op_count=$(echo "$ops" | grep -c .)
if [ -z "$ops" ]; then op_count=0; fi
result=$(echo "$ops" | $CHECKER $args 2>/dev/null)
if [ "$result" = "OK" ]; then
    echo -e "  ${GREEN}✔${RESET} ${DIM}Low disorder (~10%) adaptive${RESET} ${DIM}[$op_count ops]${RESET}"
    PASS=$((PASS + 1))
else
    echo -e "  ${RED}✘${RESET} ${BOLD}Low disorder adaptive WRONG${RESET}"
    FAIL=$((FAIL + 1))
    ERRORS+=("Low disorder adaptive")
fi

# high disorder (~90%)
TOTAL=$((TOTAL + 1))
args=$(python3 -c "
import random
l = list(range(100))
random.shuffle(l)
print(' '.join(map(str,l)))
")
ops=$($PUSH_SWAP --adaptive $args 2>/dev/null)
op_count=$(echo "$ops" | grep -c .)
if [ -z "$ops" ]; then op_count=0; fi
result=$(echo "$ops" | $CHECKER $args 2>/dev/null)
if [ "$result" = "OK" ]; then
    echo -e "  ${GREEN}✔${RESET} ${DIM}High disorder (~90%) adaptive${RESET} ${DIM}[$op_count ops]${RESET}"
    PASS=$((PASS + 1))
else
    echo -e "  ${RED}✘${RESET} ${BOLD}High disorder adaptive WRONG${RESET}"
    FAIL=$((FAIL + 1))
    ERRORS+=("High disorder adaptive")
fi

# ── bench mode ────────────────────────────────────────────────────────────────

print_section "--bench MODE"

TOTAL=$((TOTAL + 1))
bench_out=$($PUSH_SWAP --bench 1 5 3 2 4 2>&1 >/dev/null)
if echo "$bench_out" | grep -q "disorder" && echo "$bench_out" | grep -q "total_ops"; then
    echo -e "  ${GREEN}✔${RESET} ${DIM}--bench outputs disorder and total_ops${RESET}"
    PASS=$((PASS + 1))
else
    echo -e "  ${RED}✘${RESET} ${BOLD}--bench missing disorder or total_ops${RESET}"
    FAIL=$((FAIL + 1))
    ERRORS+=("--bench output format")
fi

# ── summary ───────────────────────────────────────────────────────────────────

echo ""
echo -e "${BOLD}${CYAN}╔══════════════════════════════════════════════════════╗${RESET}"
echo -e "${BOLD}${CYAN}║                    SUMMARY                          ║${RESET}"
echo -e "${BOLD}${CYAN}╠══════════════════════════════════════════════════════╣${RESET}"
echo -e "${BOLD}${CYAN}║${RESET}  Total:  ${BOLD}$TOTAL${RESET}"
echo -e "${BOLD}${CYAN}║${RESET}  ${GREEN}Passed: $PASS${RESET}"
echo -e "${BOLD}${CYAN}║${RESET}  ${RED}Failed: $FAIL${RESET}"
echo -e "${BOLD}${CYAN}╚══════════════════════════════════════════════════════╝${RESET}"

if [ ${#ERRORS[@]} -gt 0 ]; then
    echo ""
    echo -e "${RED}${BOLD}FAILED TESTS:${RESET}"
    for err in "${ERRORS[@]}"; do
        echo -e "  ${RED}✘${RESET} $err"
    done
fi

echo ""
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ALL TESTS PASSED! 🎉${RESET}"
else
    echo -e "${RED}${BOLD}  $FAIL TEST(S) FAILED${RESET}"
fi
echo ""

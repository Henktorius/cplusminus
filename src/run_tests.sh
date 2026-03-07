#!/bin/bash

COMPILER="./target/compiler"
TEST_DIR="./test_files"

# Exit codes
declare -A ERROR_NAMES=(
    [0]="SUCCESS"
    [1]="LEXICAL ERROR"
    [2]="SYNTAX ERROR"
    [3]="AST ERROR"
    [4]="SEMANTIC ERROR"
)

# Counters
total=0
passed=0
failed=0

# Result buckets
declare -A count_by_code
declare -a failed_tests

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

# Check compiler exists
if [ ! -f "$COMPILER" ]; then
    echo -e "${RED}Error: compiler not found at $COMPILER. Run 'make' first.${RESET}"
    exit 1
fi

# Check test directory exists
if [ ! -d "$TEST_DIR" ]; then
    echo -e "${RED}Error: test directory not found at $TEST_DIR${RESET}"
    exit 1
fi

echo -e "${BOLD}==============================${RESET}"
echo -e "${BOLD}       COMPILER TEST SUITE    ${RESET}"
echo -e "${BOLD}==============================${RESET}"
echo ""

# Run all .cpm files found recursively under test_files
while IFS= read -r -d '' test_file; do
    total=$((total + 1))

    # Run compiler, suppress all output (stdout + stderr)
    "$COMPILER" "$test_file" > /dev/null 2>&1
    exit_code=$?

    # Get label, default to UNKNOWN for unexpected codes
    label="${ERROR_NAMES[$exit_code]:-UNKNOWN ($exit_code)}"

    # Track counts per exit code
    count_by_code[$exit_code]=$((${count_by_code[$exit_code]:-0} + 1))

    # A test "passes" if it exits with 0 (success)
    if [ "$exit_code" -eq 0 ]; then
        passed=$((passed + 1))
        echo -e "  ${GREEN}✔${RESET}  $test_file"
    else
        failed=$((failed + 1))
        failed_tests+=("$test_file|$exit_code|$label")
        echo -e "  ${RED}✘${RESET}  $test_file ${YELLOW}[$label]${RESET}"
    fi

done < <(find "$TEST_DIR" -name "*.cpm" -print0 | sort -z)

# Summary
echo ""
echo -e "${BOLD}==============================${RESET}"
echo -e "${BOLD}           SUMMARY            ${RESET}"
echo -e "${BOLD}==============================${RESET}"
echo -e "  Total:   ${BOLD}$total${RESET}"
echo -e "  ${GREEN}Passed:  $passed${RESET}"
echo -e "  ${RED}Failed:  $failed${RESET}"
echo ""

# Breakdown by error type
if [ ${#count_by_code[@]} -gt 0 ]; then
    echo -e "${BOLD}--- Results by exit code ---${RESET}"
    for code in $(echo "${!count_by_code[@]}" | tr ' ' '\n' | sort -n); do
        label="${ERROR_NAMES[$code]:-UNKNOWN}"
        count="${count_by_code[$code]}"
        if [ "$code" -eq 0 ]; then
            echo -e "  ${GREEN}[$code] $label: $count${RESET}"
        else
            echo -e "  ${RED}[$code] $label: $count${RESET}"
        fi
    done
    echo ""
fi

# List failed tests
if [ ${#failed_tests[@]} -gt 0 ]; then
    echo -e "${BOLD}--- Failed tests ---${RESET}"

    # Find the longest filename for alignment
    max_len=0
    for entry in "${failed_tests[@]}"; do
        file="${entry%%|*}"
        len=${#file}
        [ "$len" -gt "$max_len" ] && max_len=$len
    done

    for entry in "${failed_tests[@]}"; do
        IFS='|' read -r file code label <<< "$entry"
        printf "  ${RED}✘${RESET}  %-${max_len}s  ${YELLOW}[%s]${RESET}\n" "$file" "$label"
    done
    echo ""
fi

# Exit with failure if any test failed
if [ "$failed" -gt 0 ]; then
    exit 1
else
    echo -e "${GREEN}${BOLD}All tests passed!${RESET}"
    exit 0
fi

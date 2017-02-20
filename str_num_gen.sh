# this script generates a char string of digits separated by spaces
# ARG=$(sh str_num_gen.sh 50); ./1push_swap $ARG | wc -l
# ARG=1 7 10 3 2 8 9 5 6 4; ./1push_swap $ARG
# ARG=$(sh str_num_gen.sh 50); ./push_swap $ARG | ./checker $ARG

shuf() { awk 'BEGIN {srand(); OFMT="%.17f"} {print rand(), $0}' "$@" |sort -k1,1n | cut -d ' ' -f2-; };
seq 1 $1 | shuf | tr '\n' ' '

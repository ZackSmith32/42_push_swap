# this script generates a char string of digits separated by spaces
# ARG=$(sh str_num_gen.sh 50); ./1push_swap $ARG | wc -l

shuf() { awk 'BEGIN {srand(); OFMT="%.17f"} {print rand(), $0}' "$@" |sort -k1,1n | cut -d ' ' -f2-; };
seq 1 $1 | shuf | tr '\n' ' '

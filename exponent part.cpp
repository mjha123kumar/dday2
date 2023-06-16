#include <stdio.h>
#include <stdint.h>

void print_exponent_parts(double num) {
    uint64_t* binary_ptr = (uint64_t*)&num;
    uint64_t binary = *binary_ptr;
    uint64_t exponent = (binary >> 52) & 0x7FF;
    char exponent_hex[5];
    sprintf(exponent_hex, "0x%llX", exponent);
    char exponent_binary[13];
    sprintf(exponent_binary, "0b%011llb", exponent);
    printf("Exponent (Hexadecimal): %s\n", exponent_hex);
    printf("Exponent (Binary): %s\n", exponent_binary);
}

int main() {
    double x = 0.7;
    print_exponent_parts(x);
    return 0;
}

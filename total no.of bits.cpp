#include <stdio.h>

int countBitsSet(unsigned int num) {
    int count = 0;

    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int countTotalBitsSet(unsigned int arr[], int size) {
    int totalCount = 0;

    for (int i = 0; i < size; i++) {
        totalCount += countBitsSet(arr[i]);
    }

    return totalCount;
}

int main() {
    unsigned int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int totalBitsSet = countTotalBitsSet(arr, size);

    printf("The total number of set bits in the given array is: %d\n", totalBitsSet);

    for (int i = 0; i < size; i++) {
        int bitsSet = countBitsSet(arr[i]);
        printf("%d bit(s) in 0x%08X\n", bitsSet, arr[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void compareAndReplaceBits(unsigned char *sequence) {
    unsigned char msb = (*sequence & 0x80) >> 7; // Extract the most significant bit
    unsigned char lsb = (*sequence & 0x01); // Extract the least significant bit

    if (msb == lsb) {
        *sequence &= 0x7F; // Replace the most significant bit with 0
        *sequence |= 0x01; // Replace the least significant bit with 1
    } else {
        *sequence |= 0x80; // Replace the most significant bit with 1
        *sequence &= 0xFE; // Replace the least significant bit with 0
    }
}

void printBitRepresentation(int length, char c[]) {
    for (int i = 0; i < length - 1; ++i) {
        printf("\nchar %c = ", c[i]);

        for (int j = 7; j >= 0; --j) {
            printf("%d", (c[i] >> j) & 1);
        }
    }
    for (int i = 7; i >= 0; i--) {

    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "utf-8");
    char sequence[16] = "qweqwert"; // Example sequence

    printf("Original абоба sequence: %s\n", sequence);

    printf(": ");
    printBitRepresentation(8, sequence);
    printf("\n Size of char: %llu\n", sizeof(sequence));

    compareAndReplaceBits((unsigned char *) &sequence);

    printf("\nModified sequence: %2s\n", sequence);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int puk(char str[]){
    int isPaly = 1;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != str[strlen(str) - 1 - i]) {
            isPaly = 0;
        }
    }

    printf("%d", isPaly);
    return 0;
}
int main(void)
{
    puk("ABOBA");

    return EXIT_SUCCESS;
}

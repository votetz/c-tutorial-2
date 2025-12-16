#include <stdio.h>
int main() {
    char str[100];
    int sum = 0;
    int checksum;
    int i;

    printf("Enter string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }

    for (i = 0; str[i] != '\0'; i++) {
        sum += (unsigned char)str[i];
    }

    checksum = ~sum;

    printf("Original Sum: %d\n", sum);
    printf("Checksum (Inverted): %d\n", checksum);
    printf("Hex representation: %#X\n", checksum);

    return 0;
}
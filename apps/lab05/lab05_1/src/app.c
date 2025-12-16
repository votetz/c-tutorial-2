#include <stdio.h>
#define N 3
#define LEN 100

int main() {
    char arr[N][LEN];
    int i, j;
    int max_cons = -1;
    int max_idx = 0;
    const char* vowels = "aeiouAEIOU";

    printf("Enter %d strings:\n", N);
    for (i = 0; i < N; i++) {
        if (fgets(arr[i], LEN, stdin) != NULL) {
            arr[i][strcspn(arr[i], "\n")] = '\0';
        }
    }

    for (i = 0; i < N; i++) {
        int current_cons = 0;
        int len = strlen(arr[i]);

        for (j = 0; j < len; j++) {
            if (isalpha(arr[i][j])) {
                if (strchr(vowels, arr[i][j]) == NULL) {
                    current_cons++;
                }
            }
        }

        if (current_cons > max_cons) {
            max_cons = current_cons;
            max_idx = i;
        }
    }

    printf("String with most consonants: %s\n", arr[max_idx]);
    printf("Consonants count: %d\n", max_cons);

    return 0;
}
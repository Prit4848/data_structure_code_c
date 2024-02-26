#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;

    printf("Enter the value for allocated memory: ");
    scanf("%d", &n);
    printf("The value of n = %d\n", n);

    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory is not allocated.\n");
    } else {
        for (i = 0; i < n; i++) {
            ptr[i] = i + 1;
        }

        printf("Memory was allocated.\n");

        for (i = 0; i < n; i++) {
            printf("%d, ", ptr[i]);
        }

        free(ptr);
        printf("\nMemory freed.\n");
    }

    return 0;
}


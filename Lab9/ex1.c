#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n){

    if(n <= 1) return 0;
    if(n == 2 || n == 3 || n == 5) return 1;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return 0;

    int i = 6;
    while (i <= sqrt(n) + 1){
        if(n % (i - 1) == 0 || n % (i + 1) == 0){
            return 0;
        }
        i += 6;
    }

    return 1;
}

int main() {

    char *A = malloc(51 * sizeof(char ));
    char *B = malloc(51 * sizeof(char ));
    for (int i = 0; i < 51; i++) {
        A[i]=0;
        B[i]=0;
    }
    scanf("%s", A);

    int i=0, len=0, min='z', index_min=-1;

    while (A[i] != 0){
        if (A[i]<min){
            min=A[i];
        }
        i++;
        len++;
    }

    i=0;
    while (A[i]) {
        if (A[i] == min) {
            index_min = i;

            int j = 0, x;
            if (B[j]==0) {
                while (A[j]) {
                    x = index_min + (j * 2);
                    x = x % len;
                    B[j] = A[x];
                    j++;
                }
            }
            for (int i = 2; i < len; i ++) {
                if (is_prime(i) == 1) {
                    j = 0;
                    while (A[j]) {
                        x = index_min + (j * i);
                        x = x % len;
                        if (B[j] < A[x])break;
                        if (B[j] == A[x]) {
                            j++;
                            continue;
                        }
                        while (A[j]) {
                            x = index_min + (j * i);
                            x = x % len;
                            B[j] = A[x];
                            j++;
                        }
                    }
                }
            }
        }
        i++;
    }

    printf("%s",B);

    return 0;
}
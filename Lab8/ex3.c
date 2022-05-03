#include <stdio.h>
#include <stdlib.h>

int main() {
    char *A = malloc(50 * sizeof(char));
    char *B = malloc(50 * sizeof(char));

    for (int i = 0; i < 20; i++) {
        A[i]=0;
        B[i]=0;
    }

    scanf("%s",A);

    int i=0, len=0;
    while (A[i]!=0){
        int j=0;
        while (j <= len){
            if(B[j]<A[i]){
                len=j+1;
                B[j]=A[i];
                j++;
                while (B[j]!=0){
                    B[j]=0;
                    j++;
                }
            }
            j++;
        }
        i++;
    }

    printf("%s", B);

    return 0;
}
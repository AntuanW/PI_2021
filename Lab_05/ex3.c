#include <stdio.h>

int arr[100][100];
int coordinates[10000][2];

int main() {

    int counter = 0, n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    if(n == 2) printf("%d", 0);
    else{
        for (int i = 3; i <= n ; i += 2) {
            for (int j = 0; j <= n-i; ++j) {
                for (int l = 0; l <= n-i; ++l) {

                    int sum = 0;
                    for (int a = 0; a < i; ++a) {
                        for (int b = 0; b < i; ++b) {
                            if(a == 0 || a == i-1 || b == 0 || b == i-1) sum += arr[j + a][l + b];
                        }
                    }

                    if(sum == k){
                        coordinates[counter][0] =j + i/2;
                        coordinates[counter][1] =l + i/2;
                        counter += 1;
                    }
                }
            }
        }
    }

    printf("%d\n", counter);
    for (int i = 0; i < counter; ++i) {
        printf("%d %d\n", coordinates[i][0], coordinates[i][1]);
    }

    return 0;
}
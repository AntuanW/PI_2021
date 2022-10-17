#include <stdio.h>

int arr[100][100];
int main() {

    int n;
    scanf("%d", &n);

    int a = 0, b = n-1, num = 1;

    while(a <= b){
        for (int i = a; i < b ; ++i) {
            arr[a][i] = num;
            num += 1;
        }
        for (int i = a; i < b; ++i) {
            arr[i][b] = num;
            num += 1;
        }
        for (int i = b; i > a ; --i) {
            arr[b][i] = num;
            num += 1;
        }
        for (int i = b; i > a ; --i) {
            arr[i][a] = num;
            num += 1;
        }
        a += 1;
        b -= 1;
    }

    if(n % 2 == 1) arr[n/2][n/2] = num;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int arrT[100][100];
int arrP[100][100];
int main() {

    int n, k, l, best = -2147483647, sum = 0;
    scanf("%d %d %d", &n, &k, &l);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arrT[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            scanf("%d", &arrP[i][j]);
        }
    }

    for (int i = (-1)*k + 1; i < n; ++i) {
        for (int j = (-1)*l + 1; j < n; ++j) {
            for (int m = 0; m < k; ++m) {
                for (int p = 0; p < l; ++p) {
                    if(arrP[m][p] == 1 && i + m >= 0 && i + m < n && j + p >= 0 && j + p < n) sum += arrT[i+m][j+p];
                }
            }
            best = max(best, sum);
            sum = 0;
        }
    }

    printf("%d", best);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int distance(int i, int j, int k, int l){

    if(abs(i-k) > abs(j-l)) return abs(i-k);
    else return abs(j-l);

}

int tab[100][100];
int w[100][100];

int main() {

    int n,r;
    scanf("%d %d", &n, &r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &tab[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if(distance(i, j, k, l) <= r) sum += tab[k][l];
                }
            }
            w[i][j] = sum;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", w[i][j]);
            if(j == n-1) printf("\n");
        }
    }

    return 0;
}
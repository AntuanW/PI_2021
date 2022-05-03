#include <stdio.h>

void copy(int org[100][100], int arr[300][300], int n, int a, int b){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[a+i][b+j] = org[i][j];
        }
    }
}

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int org[100][100];
int arr[300][300];

int main() {
    int n, k, best = 0, curr =0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &org[i][j]);
        }
    }

    for (int i = 0; i < 3*n; i += n) {
        for (int j = 0; j < 3*n; j += n) {
            copy(org, arr, n, i, j);
        }
    }

    //pion
    for (int i = n; i < 2*n; ++i) {
        for (int j = n; j < 2*n; ++j) {
            curr = 0;
            for (int l = 0; l < k; ++l) {
                curr += arr[i+l][j];
            }
            best = max(best, curr);
        }
    }

    //poziom
    for (int i = n; i < 2*n; ++i) {
        for (int j = n; j < 2*n; ++j) {
            curr = 0;
            for (int l = 0; l < k; ++l) {
                curr += arr[i][j+l];
            }
            best = max(best, curr);
        }
    }

    //prawoskos
    for (int i = n; i < 2*n; ++i) {
        for (int j = n; j < 2*n; ++j) {
            curr = 0;
            for (int l = 0; l < k; ++l) {
                curr += arr[i+l][j+l];
            }
            best = max(best, curr);
        }
    }

    //lewoskos
    for (int i = n; i < 2*n; ++i) {
        for (int j = n; j <2*n; ++j) {
            curr = 0;
            for (int l = 0; l < k; ++l) {
                curr += arr[i+l][j-l];
            }
            best = max(best, curr);
        }
    }

    printf("%d", best);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void jump_l(int *t, int i, int j) {
    t[i] -= j;
    t[i - 1] += j;
    t[i - 2] += j;
}

void jump_r(int *t, int a, int b) {
    t[a] -= b;
    t[a + 1] -= b;
    t[a + 2] += b;
}

void rxj(int *t, int a) {
    int b = (t[a]) / 3;
    jump_l(t, a, b);
    jump_r(t, a - 1, b);
    jump_r(t, a, b);
}


int exist_s(int *t, int x) {
    for (int a = 0; a < x; a++) {
        if (t[a] >= 3) {
            return a;
        }
    }
    return -1;
}

int left_c(int *t, int k) {
    for (int a = 0; a <= k; a++) {
        if (t[a] != 0) {
            return a;
        }
    }
    return -1;
}

int right_c(int *t, int k) {
    for (int a = k - 1; a >= 0; a--) {
        if (t[a] != 0) {
            return a;
        }
    }
    return -1;
}


void helpp(int *T, int pl, int c) {
    while (1) {
        if (T[pl] > 0 && T[pl + 1] > 0) {
            jump_r(T, pl, 1);
            pl += 2;
        } else if (T[pl] == 2 && T[pl - 1] > 0) {
            pl -= 1;
        } else if (T[pl + 1] == 0 && T[pl] == 2) {
            jump_l(T, pl, 1);
            jump_r(T, pl - 1, 1);
            pl++;
        } else if (T[pl] == 3) {
            rxj(T, pl);
            pl += 2;
        } else if (left_c(T, c) == pl) {
            break;
        } else {
            pl--;
            while (T[pl] == 0) {
                pl--;
            }
        }
    }

    for (int a = 0; a < c; a++) {
        if (T[a] == 1) {
            printf("%d ", a - 99);
        }
    }
    printf("\n");
}

int main() {
    int N, c;
    scanf("%d", &N);
    int **t = (int **) calloc(N, sizeof(int *));
    for (int a = 0; a < N; a++) {
        t[a] = (int *) calloc(2, sizeof(int));
        scanf("%d %d", &t[a][0], &t[a][1]);
    }
    c = t[N - 1][0] - t[0][0] + 200;
    int *T = (int *) calloc(c, sizeof(int));
    for (int a = 0; a < N; a++) {
        T[t[a][0] + 99] = t[a][1];
    }
    int s = exist_s(T, c);
    while (s != -1) {
        rxj(T, s);
        s = exist_s(T, c);
    }
    int first = right_c(T, c);
    first--;
    helpp(T, first, c);
    return 0;
}
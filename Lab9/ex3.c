# include <stdio.h>
# include <stdlib.h>

char *decToBinary(int n) {
    int c, d, t;
    char *binaryNum;

    t = 0;
    binaryNum = (char *) malloc(33);

    if (binaryNum == NULL)
        exit(EXIT_FAILURE);

    for (c = 31; c >= 0; c--) {
        d = n >> c;
        if (d & 1)
            *(binaryNum + t) = 1 + '0';
        else
            *(binaryNum + t) = 0 + '0';
        t++;
    }
    *(binaryNum + t) = '\0';
    return binaryNum;
}

int findMin(int a, int b){
    if(a < b){
        if(a != 0) return a;
        else return b;
    } else{
        if(b != 0) return b;
        else return a;
    }
}

int game(int G, int N, int T[25]) {

    char *binG;
    binG = decToBinary(G);
    int TMP[25][32], tmpSum, minSum = 0;

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 32; j++) {
            TMP[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (T[i] > G) {
            for (int j = 0; j < 32; j++) {
                TMP[i][j] = 0;
            }
        } else {
            char *bin_i = decToBinary(T[i]);
            for (int j = 32; j >= 1; j--) {
                TMP[i][j] = bin_i[j] - 48;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int flag = 0;
        for (int j = 0; j < 32; j++) {
            if (flag == 0) {
                if ((binG[j] == 48) && (TMP[i][j] == 1)) {
                    for (int p = 0; p < 32; p++) {
                        TMP[i][p] = 0;
                        flag = 1;
                    }
                }
            }
        }

    }

    for (int i = 1; i < 32; i++) {
        tmpSum = 0;
        for (int j = 0; j < N; j++) {
            tmpSum += TMP[j][i];

        }
        minSum = findMin(minSum, tmpSum);
    }

    return minSum;
}

int main() {

    int N, G, T[25];
    scanf("%d%d", &N, &G);

    for (int i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }
    printf("%d ", game(G, N, T));

    return 0;
}
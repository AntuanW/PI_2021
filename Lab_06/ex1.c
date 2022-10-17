#include <stdio.h>

void rectangle(int arr[201][201], int a, int b, int c, int d){
    for (int i = b; i < d; ++i) {
        for (int j = a; j < c ; ++j) {
            if(arr[i][j] == 0) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
}

int map[201][201];
int coordinates[100000][4];
int main() {

    int n, counter = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &coordinates[i][0], &coordinates[i][1], &coordinates[i][2], &coordinates[i][3]);
    }

    for (int i = 0; i < n; ++i) {
        coordinates[i][0] += 100;
        coordinates[i][1] += 100;
        coordinates[i][2] += 100;
        coordinates[i][3] += 100;
    }

    for (int i = 0; i < n; ++i) {
        rectangle(map, coordinates[i][0], coordinates[i][1], coordinates[i][2], coordinates[i][3]);
    }

    for (int i = 0; i < 201; ++i) {
        for (int j = 0; j < 201; ++j) {
            if(map[i][j]) ++counter;
        }
    }

    printf("%d", counter);

    return 0;
}
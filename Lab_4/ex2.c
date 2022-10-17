#include <stdio.h>

int find_min(int arr[100][100], int indeksy[100], int n){

    int min_indeks = 0;
    int min_value = arr[0][indeksy[0]];

    for (int i = 1; i < n; ++i) {
        if(arr[i][indeksy[i]] < min_value){
            min_value = arr[i][indeksy[i]];
            min_indeks = i;
        }
    }

    return min_indeks;
}

int t1[100][100];
int indeksy[100];
int wynik[10000];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &t1[i][j]);
        }
    }

    int size = 0;

    for (int k = 0; k < n*n; ++k) {

        int x = find_min(t1, indeksy, n);

        if(k == 0){
            wynik[size] = t1[x][indeksy[x]];
            size++;
            indeksy[x]++;
        } else{
            if(wynik[size-1] != t1[x][indeksy[x]]){
                wynik[size] = t1[x][indeksy[x]];
                size++;
                indeksy[x]++;
            }else{
                indeksy[x]++;
            }
        }

        if(indeksy[x] == n){
            t1[x][indeksy[x]] = 2147483647;
        }
    }

    for (int a = 0; a < size; ++a) {
        printf("%d ", wynik[a]);
    }

    return 0;
}

#include <stdio.h>

int tab[1000000];
int wynik[1000000];

int scan_arr(int A[], int n, int x){
    if(n == 0) return 0;
    else{
        for (int i = 0; i < n; ++i) {
            if (A[i] == x) return 1;
        }
    }
    return 0;
}

int main() {

    int n, k, counter = 0, indeks = 0;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; ++i){
        scanf("%d",&tab[i]);
    }

    for(int j=0; j<n; j++){
        if(scan_arr(wynik, indeks, tab[j]) == 1 ) counter++;
        else{
            for(int l = 0; l < n; ++l){
                if((tab[l] >= tab[j] - k) && (tab[l] <= tab[j] + k) && (tab[l] != tab[j])){
                    counter++;
                    wynik[indeks] = tab[j];
                    indeks++;
                    break;
                }
            }
        }
    }

    printf("%d", counter);

    return 0;
}
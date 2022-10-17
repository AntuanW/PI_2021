#include <stdio.h>

int tab[1000000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; ++i){
        scanf("%d",&tab[i]);
    }

    int counter = 0;
    for(int j = 0; j < n; ++j){
        for(int l = 0; l < n; ++l){
            if((tab[l] >= tab[j] - k) && (tab[l] <= tab[j] + k) && (tab[l] != tab[j])){
                counter++;
                break;
            }
        }
    }

    printf("%d", counter);


    return 0;
}
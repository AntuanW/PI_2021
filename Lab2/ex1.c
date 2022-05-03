#include <stdio.h>

int sprawdz(int arr[], int n){

    int suma_el = 0;
    for(int i = 0; i < n; ++i){
        suma_el = suma_el + arr[i];
    }

    int suma_lewa = 0;

    for(int j = 0; j < n; ++j){
        if(suma_lewa == suma_el - suma_lewa - arr[j]) return j;
        suma_lewa = suma_lewa + arr[j];
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int k = 0; k < n; ++k){
        scanf("%d", &arr[k]);
    }

    printf("%d", sprawdz(arr, n));

    return 0;
}
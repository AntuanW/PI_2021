#include <stdio.h>

int wagi(int arr[], int ilosc_odwaznikow, int masa, int indeks){

    if(masa == 0) return 1;
    if(indeks == ilosc_odwaznikow) return 0;

    return (wagi(arr, ilosc_odwaznikow, masa, indeks + 1) || wagi(arr, ilosc_odwaznikow, masa - arr[indeks], indeks + 1) || wagi(arr, ilosc_odwaznikow, masa + arr[indeks], indeks + 1));

}

int main() {

    int a,b;
    scanf("%d %d", &a, &b);

    int arr[a];
    int suma = 0;
    for(int i = 0; i < a; ++i){
        scanf("%d", &arr[i]);
        suma = suma + arr[i];
    }

    if(suma < b){
        printf("NO");
    } else if(wagi(arr, a, b, 0) == 1){
        printf("YES");
    } else{
        printf("NO");
    }

    return 0;
}
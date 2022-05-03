#include <stdio.h>

void multiply(int arr[], int x){
    for (int i = 0; i < 200; ++i) {
        arr[i] = arr[i] * x;
    }
}

void repair(int arr[]){
    for (int i = 0; i < 198; ++i) {
        arr[i+1] = arr[i+1] + (arr[i]/10);
        arr[i] = arr[i]%10;
    }
}

int factor[200];

int main() {

    factor[0] = 1;
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; ++i) {
        multiply(factor, i);
        repair(factor);
    }


    int j = 199;
    while (factor[j] == 0){
        --j;
    }
    while (j >= 0){
        printf("%d",factor[j]);
        --j;
    }

    return 0;
}

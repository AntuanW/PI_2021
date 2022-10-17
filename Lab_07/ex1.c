#include <stdio.h>

int binary(unsigned long long x){
    int curr = 0, prev = 0;
    while (x > 0){
        prev = curr;
        curr = x%2;
        x /= 2;
        if(prev == 1 && curr == 1) return -1;
    }
    return 0;
}

unsigned long long pow(int a, int b){
    unsigned long long res = 1;
    for ( int i = 0; i < b; ++i) {
        res *= a;
    }
    return res;
}

int main() {

    int n, k, counter = 0;
    scanf("%d %d", &n, &k);

    for (unsigned long long i = 0; i <= pow(2,n); ++i) {
        if(binary(i) != -1) counter++;
        if(counter == k){
            int arr[63];
            unsigned long long a = i;
            for (int j = 62; j >= 0 ; --j) {
                arr[j] = a%2;
                a /= 2;
            }
            for (int j = 63-n; j < 63 ; ++j) {
                printf("%d", arr[j]);
            }
            break;
        }
    }
    if(counter < k) printf("%d", -1);

    return 0;
}
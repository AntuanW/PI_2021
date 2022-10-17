#include <stdio.h>

unsigned long long sum(unsigned long long a){
    unsigned long long suma = 0;
    while(a > 0){
        suma += a;
        a /= 10;
    }
    return suma;
}

int main() {
    unsigned long long S;
    scanf("%llu", &S);

    unsigned long long l = 0, r = S, mid;
    while (l <= r){
        mid = (r+l)/2;
        if(sum(mid) < S) l = mid +1;
        else if(sum(mid) > S) r = mid -1;
        else {
            printf("%llu", mid);
            break;
        }
    }
    if(sum(mid) != S) printf("%d", -1);
    return 0;
}
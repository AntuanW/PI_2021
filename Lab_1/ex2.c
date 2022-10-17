#include <stdio.h>
#include <math.h>

int is_prime(int n){

    if(n <= 1) return 0;
    if(n == 2 || n == 3 || n == 5) return 1;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return 0;

    int i = 6;
    while (i <= sqrt(n) + 1){
        if(n % (i - 1) == 0 || n % (i + 1) == 0){
            return 0;
        }
        i += 6;
    }

    return 1;
}

int czy_rosnaca(int n){

    int x = n;
    int last = x % 10;

    while (x > 0){
        if((x / 10) % 10 > last){
            return 0;
        }
        x /= 10;
        last = x % 10;
    }
    return 1;

}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 2; i < n; ++i){
        if (is_prime(i) == 1){
            if (czy_rosnaca(i) == 1) printf("%d\n", i);
        }
    }

    return 0;
}
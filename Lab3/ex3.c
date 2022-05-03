#include <stdio.h>
#include <math.h>

int power(int a){
    return a*a;
}

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

int czy_jednokwadratowa(int a){

    int x = a;
    int suma = 0;

    while((suma != 4) && (suma != 1)){
        suma = 0;
        while(x > 0){
            suma = suma + power(x % 10);
            x = (x-(x%10))/10;
        }
        x = suma;
    }

    if(suma == 1) return 1;
    else return 0;

}

void zadanie(int l, int u, int k){
    int counter = 0;
    while(counter < k && l <= u){
        if(is_prime(l) == 1){
            if(czy_jednokwadratowa(l) == 1){
                counter = counter + 1;
            }
        }
        l = l + 1;
    }
    if(counter == k) printf("%d", l-1);
    else printf("%d", -1);
}


int main() {
    int l,u,k;
    scanf("%d %d %d", &l, &u, &k);
    zadanie(l, u, k);
    return 0;
}
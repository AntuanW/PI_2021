#include <stdio.h>
#include <math.h>

int czy_doskonala(int n){
    int s = 1;
    int p = sqrt(n);
    for (int i = 2; i <= p; ++i){
        if (n % i == 0){
            s = s + i + n/i;
        }
    }
    if (n == p*p){
        s = s-p;
    }
    if (n == s){
        return 1;
    }
    return 0;
}

int main() {
    int a,b;
    int counter = 0;
    int data[10];
    scanf("%d%*[ ]%d", &a, &b);
    for (int i = a; i <= b; ++i){
        if (czy_doskonala(i) == 1){
            data[counter] = i;
            counter = counter + 1;
        }
    }
    printf("%d\n", counter);
    if (counter != 0){
        for (int j = 0; j <= counter - 1; ++j){
            printf("%d ", data[j]);
        }
    }
    return 0;
}
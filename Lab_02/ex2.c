#include <stdio.h>

int power(int a, int b){
    if(b == 0) return 1;
    else{
        int result = a;
        for(int i = 1; i < b; ++i){
            result = result * a;
        }
        return result;
    }
}

int czy_narcystyczna(int x, int podst, int m){

    char liczba[8];
    int a = x, counter = 0, suma = 0, cyfra;

    while(a != 0){
        cyfra = a % podst;
        suma = suma + power(cyfra, m);

        if(cyfra < 10) liczba[counter] = (char)(cyfra + 48);
        else liczba[counter] = (char)(cyfra + 55);

        a = a/podst;
        counter = counter + 1;
    }

    if(suma == x){
        counter = counter - 1;
        while(counter >= 0){
            printf("%c", liczba[counter]);
            counter = counter - 1;
        }
        printf(" ");
        return 1;
    }
    else{
        return 0;
    }

}


int main() {
    int m, b, flag = 0;
    scanf("%d %d",&m,&b);
    int minimal = power(b, m-1);
    int makxymal = power(b,m);

    for(int i = minimal; i < makxymal; ++i){
        if(czy_narcystyczna(i, b, m) ==1) flag = 1;
    }
    if(flag == 0) printf("NO");

    return 0;
}
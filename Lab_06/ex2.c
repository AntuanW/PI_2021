#include <stdio.h>
#include<string.h>

void zmiana_na_rzymski(int num){
    while(num != 0)
    {

        if (num >= 1000)       // 1000 - m
        {
            printf("M");
            num -= 1000;
        }

        else if (num >= 900)   // 900 -  cm
        {
            printf("CM");
            num -= 900;
        }

        else if (num >= 500)   // 500 - d
        {
            printf("D");
            num -= 500;
        }

        else if (num >= 400)   // 400 -  cd
        {
            printf("CD");
            num -= 400;
        }

        else if (num >= 100)   // 100 - c
        {
            printf("C");
            num -= 100;
        }

        else if (num >= 90)    // 90 - xc
        {
            printf("XC");
            num -= 90;
        }

        else if (num >= 50)    // 50 - l
        {
            printf("L");
            num -= 50;
        }

        else if (num >= 40)    // 40 - xl
        {
            printf("XL");
            num -= 40;
        }

        else if (num >= 10)    // 10 - x
        {
            printf("X");
            num -= 10;
        }

        else if (num >= 9)     // 9 - ix
        {
            printf("IX");
            num -= 9;
        }

        else if (num >= 5)     // 5 - v
        {
            printf("V");
            num -= 5;
        }

        else if (num >= 4)     // 4 - iv
        {
            printf("IV");
            num -= 4;
        }

        else if (num >= 1)     // 1 - i
        {
            printf("I");
            num -= 1;
        }

    }
}

int zamiana_na_dziesietny(char napis[100]){

    int a[100];
    int n = strlen(napis);

    for (int i = 0; i < n; ++i) {

        if(napis[i]=='I') a[i]=1;
        else if(napis[i]=='V') a[i]=5;
        else if(napis[i]=='X') a[i]=10;
        else if(napis[i]=='L') a[i]=50;
        else if(napis[i]=='C') a[i]=100;
        else if(napis[i]=='D') a[i]=500;
        else if(napis[i]=='M') a[i]=1000;

    }

    int num = a[n-1];
    for (int i = n-1; i > 0; --i) {
        if(a[i]>a[i-1]) num -= a[i-1];
        else if(a[i] == a[i-1] || a[i] < a[i-1]) num += a[i-1];
    }

    return num;
}

int main() {

    char rom1[100], rom2[100];

    scanf("%s %s", &rom1, &rom2);

    int a = zamiana_na_dziesietny(rom1);
    int b = zamiana_na_dziesietny(rom2);

    zmiana_na_rzymski(a + b);

    return 0;
}

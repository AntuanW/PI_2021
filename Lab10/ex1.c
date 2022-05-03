#include <stdio.h>
#include <stdlib.h>

long long int bezwgl(long long int x){
    if(x>=0) return x;
    else
        return -x;
}

int main() {
    long long int N, N2;
    int p=0, p2=0;
    long long int tab[10000], tab2[10000];
    scanf("%lld", &N);
    N2=-N;

    for(int i=0; i<=99; ++i){
        tab[i]=bezwgl(N%2);
        N=(N-tab[i])/(-2);
        if(N!=0) ++p;
    }

    if(N!=0){
        printf("%s", "NO");
        exit(0);
    }

    for(int j=0; j<=p; ++j){
        if(tab[j]!=0)
            printf("%d\t", j);
    }

    printf("\n");

    for(int a=0; a<=99; ++a){
        tab2[a]=bezwgl(N2%2);
        N2=(N2-tab2[a])/(-2);
        if(N2!=0) ++p2;
    }

    for(int b=0; b<=p2; ++b){
        if(tab2[b]!=0)
            printf("%d\t", b);
    }

    return 0;
}

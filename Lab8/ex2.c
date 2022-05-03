#include <stdio.h>

long long div(int n) {
    while (!(n & 1)) {
        n >>= 1;
    }
    return n;
}
int main()
{
    long long TT, sum = 0;
    scanf("%lld", &TT);
    long long T[9] = {36, 3344, 333396, 33333566, 3333334736, 333333339224, 33333333370068, 3333333333471362, 333333333334181226};
    int beg = 2;
    if(TT >= 10 && TT < 100) {
        sum += T[0];
        beg = 12;
    } else if(TT >= 100 && TT < 1000) {
        sum += T[1];
        beg = 102;
    }else if(TT >= 1000 && TT < 10000) {
        sum += T[2];
        beg = 1002;
    }else if(TT >= 10000 && TT < 100000) {
        sum += T[3];
        beg = 10002;
    }else if(TT >= 100000 && TT < 1000000) {
        sum += T[4];
        beg = 100002;
    }else if(TT >= 1000000 && TT < 10000000) {
        sum += T[5];
        beg = 1000002;
    }else if(TT >= 10000000 && TT < 100000000) {
        sum += T[6];
        beg = 10000002;
    }else if(TT >= 100000000 && TT < 1000000000) {
        sum += T[7];
        beg = 100000002;
    }else if(TT >= 1000000000) {
        sum += T[8];
        beg = 1000000002;
    }

    for(int i = beg; i <= TT; i += 2) {
        sum += div(i) + (i - 1);
    }
    if(TT % 2 != 0) sum += TT;
    printf("%lld", sum);
    return 0;
}

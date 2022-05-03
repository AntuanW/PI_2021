#include <stdio.h>
#include <math.h>

int main() {

    int bitNum, M;
    scanf("%d %d", &bitNum, &M);

    unsigned long long int cnt = 0, power = pow(2, bitNum);

    if (M == 1){
        printf("%d",0);
        return 0;
    }

    for (unsigned long long int i = 0; i < power; i++) {
        if ( i % M != 0 || i == 0 || i == 1) {
            for (int j = 0; j < bitNum; j++) {
                if (((i ^ (1 << j)) % M == 0) && ((i ^ (1 << j)) != 0)) {
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%llu", cnt);\

    return 0;
}
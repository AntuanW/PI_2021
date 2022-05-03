#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int f1 = 0, f2 = 1;

    while(f1 <= n){
        if (f1 * f2 == n){
            printf("YES");
            return 0;
        }

        f1 = f1 + f2;
        int tmp = f1;
        f1 = f2;
        f2 = tmp;

    }

    printf("NO");

    return 0;
}
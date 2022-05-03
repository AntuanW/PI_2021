#include <stdio.h>

int newton(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    return newton(n - 1, k - 1)
           + newton(n - 1, k);
}

int number_of_red_edges(int i, int m, int arr[500000][2]){

    int sum = 0;
    for (int j = 0; j < m; ++j) {
        if(arr[j][0] == i || arr[j][1] == i) sum += 1;
    }

    return sum;

}

int arr[499500][2];
int main() {

    int n, m, sum = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = 1; i <= n ; ++i) {
        int d = number_of_red_edges(i, m, arr);
        sum += (d*(n-1-d))/2;
    }

    printf("%d", newton(n,3) - sum);

    return 0;
}

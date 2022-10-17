#include <stdio.h>

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int get_max_area(int size, int hist[100][2]){

    int max_area=-1;

    for(int i=0;i<size;i++){
        int low = hist[i][0];
        int temp=0;

        for(int j=i;j<size;j++){
            if(low > hist[j][0]){
                low = hist[j][0];
            }

            temp=(j-i+1)*low;

            if(temp>max_area){
                max_area=temp;
            }
        }
    }

    return max_area;
}


int arr[100][100];
int hist[100][2];
int main() {

    int n, max_area = -1, tmp;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int i = row; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(arr[i][j] == 0 && hist[j][1] != 1) hist[j][0] += 1;
                if(arr[i][j] == 1) hist[j][1] = 1;
            }
        }

        tmp = get_max_area(n, hist);
        max_area = max(tmp, max_area);

        for (int i = 0; i < n; ++i) {
            hist[i][0] = 0;
            hist[i][1] = 0;
        }
    }

    if(max_area == -1) printf("%d", 0);
    else printf("%d", max_area);

    return 0;
}
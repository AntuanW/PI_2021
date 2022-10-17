#include <stdio.h>

int partition(int tablica[], int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
    int x = tablica[p]; // obieramy x
    int i = p, j = r, w; // i, j - indeksy w tabeli
    while (1) // petla nieskonczona - wychodzimy z niej tylko przez return j
    {
        while (tablica[j] > x) // dopoki elementy sa wieksze od x
            j--;
        while (tablica[i] < x) // dopoki elementy sa mniejsze od x
            i++;
        if (i < j) // zamieniamy miejscami gdy i < j
        {
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
        }
        else // gdy i >= j zwracamy j jako punkt podzialu tablicy
            return j;
    }
}

void quicksort(int tablica[], int p, int r) // sortowanie szybkie
{
    int q;
    if (p < r)
    {
        q = partition(tablica,p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
        quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
        quicksort(tablica, q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
    }
}

void move(int tab[], int n){
    int x = tab[n];
    int i = n - 1;
    while(i >= 0 && tab[i] > x){
        tab[i+1] = tab[i];
        --i;
    }
    tab[i+1] = x;
}

int A[1000000];

int main() {

    int n,k,sum = 0;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        sum = sum + A[i];
    }

    quicksort(A,0,n-1);

    for (int j = 0; j < k; ++j) {
        sum = sum - A[n-1] + (A[n-1] - (A[n-1]%2))/2;
        A[n-1] = (A[n-1] - (A[n-1]%2))/2;
        move(A,n-1);
    }

    printf("%d", sum);

    return 0;
}
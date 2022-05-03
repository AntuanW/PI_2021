#include <stdio.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int tab[m];
    int gates[m][2];
    char temp;
    for (int i = 0; i < m; i++) {
        int j = 0;
        do {
            scanf("%d%c", &gates[i][j], &temp);
            j++;
        } while (temp != '\n' && j < 2);
    }

    int bin[100], bin_stop[100];

    for (int p = 0; p < 100; p++) {
        bin[p] = 0;
        bin_stop[p] = 0;
    }

    unsigned char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);

    int h = 0;
    for (int p = n - 1; p > -1; p--) {
        bin[p] = a[h] - 48;
        bin_stop[p] = b[h] - 48;
        h++;
    }

    int f_loop = 1, l_loop = 0, counter = 0;
    while (1) {
        for (int o = 0; o < m; o++) {
            tab[o] = -1;
        }
        int x = 0;
        while (1) {
            if (f_loop) {
                f_loop = 0;
                break;
            } else {
                bin[x] = (bin[x] + 1) % 2;
                if (bin[x]) {
                    break;
                } else {
                    x++;
                }
            }
        }

        int stop = 0;
        for (int p = 0; p < n; p++) {
            if (bin[p] == bin_stop[p]) {
                stop++;
            } else {
                break;
            }
        }

        if (stop == n) {
            l_loop = 1;
        }

        while (1) {
            if (tab[k - 1] == -1) {
                for (int i = 0; i < m; i++) {
                    if (tab[i] == -1) {
                        if (gates[i][0] < 0) {
                            if (gates[i][1] < 0) {
                                int f = bin[n + gates[i][0]];
                                int s = bin[n + gates[i][1]];
                                if (f == s) {
                                    tab[i] = 0;
                                } else {
                                    tab[i] = 1;
                                }
                            } else {
                                if (tab[gates[i][1] - 1] != -1) {
                                    int f = bin[n + gates[i][0]];
                                    int s = tab[gates[i][1] - 1];
                                    if (f == s) {
                                        tab[i] = 0;
                                    } else {
                                        tab[i] = 1;
                                    }
                                } else {
                                    continue;
                                }
                            }
                        } else {
                            if (tab[gates[i][0] - 1] != -1) {
                                if (gates[i][1] < 0) {
                                    int f = tab[gates[i][0] - 1];
                                    int s = bin[n + gates[i][1]];
                                    if (f == s) {
                                        tab[i] = 0;
                                    } else {
                                        tab[i] = 1;
                                    }
                                } else {
                                    if (tab[gates[i][1] - 1] != -1) {
                                        int f = tab[gates[i][0] - 1];
                                        int s = tab[gates[i][1] - 1];
                                        if (f == s) {
                                            tab[i] = 0;
                                        } else {
                                            tab[i] = 1;
                                        }
                                    } else {
                                        continue;
                                    }
                                }
                            } else {
                                continue;
                            }
                        }
                    } else {
                        continue;
                    }
                }

            } else {
                if (tab[k - 1]) {
                    counter++;
                    break;
                } else {
                    break;
                }
            }
        }

        if (l_loop) {
            break;
        }
    }

    printf("%d", counter);

    return 0;
}
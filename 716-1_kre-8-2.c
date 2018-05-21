#include <stdlib.h>
#include <stdio.h>

int pyramidS(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
        return 0;
}

int main(){
        int n, i, count = 0, b = 0;
        scanf ("%i", &n);
        int a[n];
        for (i = 0; i < n; ++i){
                scanf ("%i", &a[i]);
        }
        while (1){
                b = 0;
                for (i = 0; i < n; ++i){
                        if (i*2 + 2 + count < n){
                                if (a[i+count] > a[i*2 + 1 + count] || a[i + count] > a[i*2 + 2 + count]){
                                        if (a[i*2+1+count] < a[i*2+2+count]){
                                                pyramidS(&a[i+count], &a[i*2+1+count]);
                                                b = 1;
                                        }
                                        else if (a[i*2+2+count] < a[i*2+1+count]){
                                                pyramidS(&a[i+count],&a[i*2+2+count]);
                                                b = 1;
                                        }
                                }
                        }
                        else if (i * 2 + 1 + count < n){
                                if (a[i+count] > a[i*2+1+count]){
                                        pyramidS(&a[i+count], &a[i*2+1+count]);
                                        b=1;
                                }
                        }
                }
                if (!b)
                        count++;
                if (count + 2 == n)
 break;
        }

        for (i = 0; i < n; ++i){
                printf ("%d\t", a[i]);
        }
        printf ("\n");
        return 0;
}


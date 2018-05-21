#include <stdlib.h>
#include <stdio.h>

int first, last;

void Hoarsort(int *arr, int first, int last){
        int mid, count, f = first, l = last;
        mid = arr[(f+l) / 2];
        do{
                while (arr[f] < mid)
                        f++;
                while (arr[l] > mid)
                        l--;
                if (f <= l){
                        count = arr[f];
                        arr[f] = arr[l];
                        arr[l] = count;
                        f++;
                        l--;
                }
        } while (f < l);

        if (first < l)
                 Hoarsort(arr, first, l);
        if (f < last)
                 Hoarsort(arr, f, last);
}

int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        int *a = &arr[0];
        for (int i=0; i<n; i++){
                scanf("%d",&arr[i]);
        }
        first = 0;
        last = n-1;
        Hoarsort(a, first, last);
        for (int i=0; i<n; i++){
                printf("%d\t", arr[i]);
        }
        printf("\n");
 	return 0;
}


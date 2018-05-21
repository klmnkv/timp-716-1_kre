#include <stdio.h>
#include <malloc.h>
 
void Combsort11(int a[], int nElements)
{
  int i, j, gap, swapped = 1;
  double temp;
 
  gap = nElements;
  while (gap > 1 || swapped == 1)
  {
    gap = gap * 10 / 13;
    if (gap == 9 || gap == 10) gap = 11;
    if (gap < 1) gap = 1;
    swapped = 0;
    for (i = 0, j = gap; j < nElements; i++, j++)
    {
      if (a[i] > a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        swapped = 1;
      }
    }
  }
}
 
int main()
{
    int nElements;
    scanf("%d", &nElements);
    int* mass;
    mass = (int *)malloc(nElements * sizeof(int));
    for (int i = 0; i < nElements; i++)
        scanf("%d", &mass[i]);

    Combsort11(mass, nElements);
    for (int i = 0; i < nElements; i++)
        printf("%d ", mass[i]);
    printf("\n");
    free(mass);
    return 0;
}

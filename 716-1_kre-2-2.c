#include <stdio.h>

int main()
{
int i,n,a,b;
scanf ("%d",&n);
scanf ("%d",&a);
        if(n>1)
        for(i=1; i<n; i++)
        {
                scanf ("%d",&b);
                        if (a<b) printf ("0");
                        else
                                {
                                printf ("1");
                                }
       	       a=b;
	}

return 0;
}


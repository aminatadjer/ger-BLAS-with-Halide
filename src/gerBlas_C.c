#include <stdio.h>
#include <stdlib.h>

int main()
{   int m=3,n=5;
    int a[3][5]={
    {
        5,6,5,8,5
    },
    {
        1,2,3,4,5
    },
    {
        1,5,9,2,6
    }
    };
    int x[3]={1,4,7};
    int y[5]={1,5,2,3,3};
    int alpha=4;
    int i=0,j=0;
    FILE *fptr;
    fptr = fopen("outC.txt","w");
    for(i=0;i<3;i++){
         for(j=0;j<5;j++){
        a[i][j]=a[i][j]+alpha*x[i]*y[j];
        fprintf(fptr,"a[%d][%d]=%d\n",i,j,a[i][j]);
    }
    }
    fclose(fptr);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    // We will intialize the matrix A, the vectors X and Y and the scalar alpha  from a file
    // This programme will calculate the 1-rank update of the matrix A := alpha*X*Y' + A
    // "in.txt" file is for reading A,X,Y,m,n,alpha
    // "out.txt" file is for writing results
    // m is the number of rows, n is the number of columns, alpha is the scalar
    int m,n,alpha;
    FILE *in;
    FILE *out;
    if ((in = fopen("./files/in.txt","r")) == NULL){
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(2);
      }
    out= fopen("./files/outC.txt","w");

    // The char c is just used to verify the format of the file in (check the file and change the values )
    char c;
    // Read m and n and alpha
    fscanf(in,"%d\n", &m);
    fscanf(in,"%d\n", &n);
    fscanf(in,"%d\n", &alpha);
    // X is a vector (matrix with 1 column and m rows)
    // Y is a vector (matrix with 1 column and n rows)
    // We are declaring y with 1 row and n columns to avoid to calculate the transpose of Y, so y represents Y'
    // This declaration is permitted from C99 onwards ( we can use malloc instead)
    int x[m][1];
    int y[1][n];
    int a[m][n];
    fscanf(in,"%c\n", &c);
    int i=0,j=0;
    if (c=='x'){ // to verify the file format
    // Reading x from the file
        for(i=0;i<m;i++) {
            fscanf(in,"%d\n", &x[i][0]);
         }
        // Initialize y from the file
        fscanf(in,"%c\n", &c);
        if (c=='y'){
             for(i=0;i<n;i++) {
                fscanf(in,"%d\n", &y[0][i]);
             }
             fscanf(in,"%c\n", &c);
             // Initialize a from the file
             if (c=='a'){
                 for(i=0;i<m;i++) {
                     for (j=0;j<n;j++){
                        fscanf(in,"%d\t", &a[i][j]);
                        if (j==n-1) fscanf(in,"\n");
                     }
                 }
             }
             else exit(1);
         }
         else exit(1);
     }
    else exit(1);
    fclose(in);
    // We need to verify that the nb rows of a=nb rows of x and nb columns of a = nb columns of y, but we've already done it
    // Because we read the rows and columns of x and y with m and n (in the loop).
    // Now all the variables are initialized
    // This loop will calculate for each cell of the matrix a[i][j]=alpha*x[i][j]+alpha*x[i][0]*y[0][j]
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            a[i][j]=a[i][j]+alpha*x[i][0]*y[0][j];
            fprintf(out,"a[%d][%d]=%d\n",i,j,a[i][j]);
        }
    }
    fclose(out);
    return 0;
}


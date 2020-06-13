#include "Halide.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace Halide;
int main(int argc, char **argv) {
	// In this code we will initialize the matrix A, the vectors X and Y and the scalar alpha from a file (in.txt)
	// This programme will calculate the 1-rank update of the matrix A := alpha*X*Y' + A
	// "in.txt" file is for reading A,X,Y,m,n,alpha// "outH.txt" file is for writing results
	// m is the number of rows, n is the number of columns, alpha is the scalar
	// You can also declare the values directly as below in comments
	/*int a[3][5]={
	    {
		5,6,5,8,5
	    },
	    {
		1,2,3,4,5
	    },
	    {
		1,5,9,2,6
	    }
	    }; *//*
	int x[3][1]={{1},{4},{7}};
	int y[1][5]={{1,5,2,3,3}};
	int m=3,n=5,alpha=4;
	*/
	const int maxDim=10; // You can change the maxDimention for rows or columns
	// X is a vector (matrix with 1 column and m rows)
        // Y is a vector (matrix with 1 column and n rows)
        // We are declaring y with 1 row and n columns to avoid to calculate the transpose of Y, so y represents Y'
	int x[maxDim][1],y[1][maxDim],a[maxDim][maxDim];
	//Reading values from the file in.txt
	ifstream in("./files/in.txt");
	    if (!in){
	       printf("Error! opening file");
	       // Program exits if the file pointer returns NULL.
	       exit(2);
	      }
	 int m,n,alpha;
	// c is just used to verify the file format (check in file and change the values
	 char c;
	// Reading m and n and alpha and c
	 in >> m >> n >> alpha >> c ;
	 int i=0,j=0;
	 if (c=='x'){ // to verify the file format
	    // Reading x from the file
		for(i=0;i<m;i++) {
			in >> x[i][0];
		 }
		in  >> c;
		if (c=='y'){ // to verify the file format
		    	// Reading y from the file
			for(i=0;i<n;i++) {
				in >> y[0][i];
			 }
			in  >> c;
			if (c=='a'){  
				// Reading a from the file
				 for(i=0;i<m;i++) {
				     for (j=0;j<n;j++){
				    	in >> a[i][j];
				 	}
			    	 }
				
			    } else exit(1);
		} else exit(1);
	} else exit(1);
	in.close();
	// Now the values are ready to use, you can use any methode for initialization
	Halide::Var h,w;
	Halide::Func ger;
	Halide::Buffer<int> matriceA(a);
	Halide::Buffer<int> vectorX(x);
	Halide::Buffer<int> vectorY(y);
        // We don't need to verify dimentions (nb rows of x= nb rows of A and nb columns of y= nb columns of A)
	//Because we read the rows and columns of x and y with m and n (in the loop).
	/* if(! ( (matriceA.width() == vectorY.width()) && (vectorX.height() == matriceA.height())  )){
		printf("Dimentions problem !!\n");
		exit(1);
	    } */

	 
       	// In this code we don't need to calculate the result with a loop (like in C code)
	// But it's more manageable and more flexible to put the loop
	// in the generated code. We do this by defining a "reduction
	RDom rdom(0, 1);
	ger(w,h)=alpha*sum(vectorX(rdom, h) * vectorY(w, rdom))+matriceA(w,h);
	matriceA =ger.realize(n,m);
	//writing results in a file
	ofstream ostrm("./files/outH.txt");
	//matriceA.height=n matriceA.width=m
	for (j = 0; j < matriceA.height(); j++) {
		for ( i = 0; i < matriceA.width(); i++) {
		    ostrm << "a["<< j << "][" << i << "]=" << matriceA(i, j) << "\n";
		    }
		}
	    
	ostrm.close();
	printf("Result written in a file !\n");
	return 0;

	}

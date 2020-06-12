#include "Halide.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace Halide;
int main(int argc, char **argv) {
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
int x[3][1]={{1},{4},{7}};
int y[1][5]={{1,5,2,3,3}};

Halide::Var h,w;
Halide::Func ger;
Halide::Buffer<int> matriceA(a);
Halide::Buffer<int> vectorX(x);
Halide::Buffer<int> vectorY(y);
 if(! ( (matriceA.width() == vectorY.width()) && (vectorX.height() == matriceA.height())  )){
        printf("Dimentions problem !!\n");
        exit(1);
    }
int alpha=4;
 // for (int i = 0; i < 50; i++) {
        //   f(x, i) = f(x, i) * f(x, i);
        // }

        // But it's more manageable and more flexible to put the loop
        // in the generated code. We do this by defining a "reduction
        // domain" and using it inside an update definition:
RDom rdom(0, vectorX.width());
ger(w,h)=alpha*sum(vectorX(rdom, h) * vectorY(w, rdom))+matriceA(w,h);
Buffer<int> output =ger.realize(matriceA.width(),matriceA.height());
ofstream ostrm("outH.txt");
    for (int j = 0; j < output.height(); j++) {
        for (int i = 0; i < output.width(); i++) {
	    
            ostrm << "a["<< j << "][" << i << "]=" << output(i, j) << "\n";
            }
        }
    
ostrm.close();
printf("Result written in a file !\n");

    return 0;

}

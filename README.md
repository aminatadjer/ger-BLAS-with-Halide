# Ger Function with Halide :nerd_face:

Ger is a function that performs a rank-1 of a general matrix, it's a 2 Level Blas routine defined as:
```
A := alpha*x*y'+ A,
```
**alpha** is a scalar,

**x** is an m-element vector,

**y** is an n-element vector,

**A** is an m-by-n general matrix.

*More about [Blas](https://software.intel.com/content/www/us/en/develop/documentation/mkl-developer-reference-fortran/top/blas-and-sparse-blas-routines.html) routines*.

## Getting started
The instructions below :point_down:   will get you a copy of the project up and running on your local machine. It's an implementation with [Halide](https://halide-lang.org/) and C, and comparing results.

### Prerequisites
To run this project, you need to download and install Halide.

#### Halide

Halide is a programming language designed to make it easier to write high-performance image and array processing code on modern machines. Halide currently targets.

[Download a binary release of Halide](https://github.com/halide/Halide/releases). You probably want the version starting with halide_Linux_64_trunk, halide_Darwin_64_trunk, or halide_Windows_64_trunk for Linux, OS X, and Windows respectively.

For the freshest builds, see [the continuous build server](https://buildbot.halide-lang.org/). The status of the build on each platform is [here](https://buildbot.halide-lang.org/master/#/builders?tags=%2Bmaster). If it's green, then it has passed all of our internal tests.

If you would prefer to build Halide from source, see [README](https://github.com/halide/Halide/tree/master/README.md) for instructions.

To get started writing code, look through the [tutorials](https://halide-lang.org/tutorials/tutorial_introduction.html), and the [example apps](https://github.com/halide/Halide/tree/master/apps). The [tests](https://github.com/halide/Halide/tree/master/test) are small self-contained programs that cover all corners of the language, so they can also be instructive. However they're not designed to teach, so you may find them cryptic.

### To do (Linux)

First check this project out from github:
```
% git clone https://github.com/aminatadjer/ger-BLAS-with-Halide.git
% cd ger-BLAS-with-Halide
```

You need to give execution rights to the script:

```
% chmod +x script.sh
```

To execute the script you need to pass Halide path in parameter ``` /path/to/Halide ``` 

 ``` 
 % ./script.sh -p /path/to/Halide
  ``` 
  
 The script will:
 
    1. Compile gerBlas_halide.cpp 
    2. Compile gerBlas_C.c
    3. Run gerBlas_halide and gerBlasC.
    4. Finally, the script will compare between the results (Halide and C versions).
    
 We use the file in.txt to read m,n,alpha,A,X and Y


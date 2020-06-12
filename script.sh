

echo "Compiling halide one..."
g++ ./src/gerBlas_halide.cpp -g -L ../Halide/bin -I ../Halide/include -I ../Halide/tools  -lHalide -ldl -lpthread -std=c++11 -o ./bin/gerBlas_halide

echo "Compiling C code "
 gcc ./src/gerBlas_C.c -o ./bin/gerBlasC

echo "Run halide exec"
LD_LIBRARY_PATH=../Halide/bin ./bin/gerBlas_halide

echo "Run c exec"
 ./bin/gerBlasC

diff --brief <(sort outC.txt) <(sort outH.txt) >/dev/null
comp_value=$?
if [ $comp_value -eq 1 ]
then
    echo "Do something because they're different"
else
    echo "Great!They're identical"
fi

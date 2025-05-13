# Sudoku
Kissat-based Sudoku solver barely implementing all the functionality required to solve sudokus (without optimizing for speed a lot). I do not expect to win any prizes with this; sadly I did not find the time to experiment with optimizations. Yet, I still wanted to submit what I already got.

# Build and Run
Compile kissat before compiling the actual program:

```console
cd kissat_folder/kissat
./configure && make
cd ../..
```
Now we can compile the program
```console
mkdir build && cd build
cmake ..
make target=release
```

And run it for example via:

```console
./sudoku < ../sudokus/easy.txt
```

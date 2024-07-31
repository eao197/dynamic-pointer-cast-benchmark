To compile via command line:

for VC++:

```sh
cl -EHsc -std:c++20 -O2 -Fe:bench_vc.exe *.cpp
```

for GCC (Unix/Linux):

```sh
g++ -O2 -std=c++20 -o bench_gcc *.cpp
```

or for MinGW on Windows:

```sh
g++ -O2 -std=c++20 -o bench_gcc.exe *.cpp
```

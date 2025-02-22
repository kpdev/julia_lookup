# julia_lookup

## Download and build

```
$ git clone https://github.com/JuliaLang/julia.git
$ cd julia
$ git checkout v1.10.8
$ make
$ cd ../
$ git clone https://github.com/kpdev/julia_lookup.git
$ cd julia_lookup
$ mkdir build && cd build
$ cmake -S .. -B .
$ make
```


## Run benchmarks

```
$ ./test_lookup_generic 1000000000
number_of_iters = 1000000000
Time elapsed empty loop: 0.516596
Time elapsed Julia: 12.700353
Time elapsed PP: 3.515374
Time elapsed PP 3D: 3.518901
Time elapsed PP 5D: 3.530386
Time elapsed PP Dispatch: 3.432544
Time elapsed Procedural VT Dispatch: 2.846275
Time elapsed Procedural Switch Dispatch: 1.575103

$ ./test_visitor 1000000000
number_of_iters = 1000000000
Time elapsed Visitor: 3.713588
Time elapsed Visitor3D: 4.573716
```

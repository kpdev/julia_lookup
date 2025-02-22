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
Time elapsed empty loop: 0.238826
Time elapsed Julia: 6.077953
Time elapsed PP: 1.644591
Time elapsed PP 3D: 1.652796
Time elapsed PP 5D: 1.657737
Time elapsed PP Dispatch: 1.620008
Time elapsed Procedural VT Dispatch: 1.392644
Time elapsed Procedural Switch Dispatch: 0.730607
Time elapsed Procedural Switch Dispatch 3D: 0.751020

$ ./test_visitor 1000000000
number_of_iters = 1000000000
Time elapsed Visitor: 1.740013
Time elapsed Visitor3D: 2.146128
```

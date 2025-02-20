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
Time elapsed empty loop: 0.497977
Time elapsed Julia: 12.926793
Time elapsed PP: 3.499814
Time elapsed PP Dispatch: 3.377351
Time elapsed Procedural VT Dispatch: 2.814984
Time elapsed Procedural Switch Dispatch: 1.596492

$ ./test_visitor 1000000000
number_of_iters = 1000000000
Time elapsed Visitor: 3.736285
```

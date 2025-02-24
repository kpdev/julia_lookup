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
$ cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release
$ make
```

## Build with Julia enabled

```
$ cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release -DBUILD_JULIA
```


## Run benchmarks

```
$ ./test_lookup_generic 1000000000
number_of_iters = 1000000000
Time elapsed empty loop: 0.511964
Time elapsed Julia Startup: 64.396078
Time elapsed Julia 2D: 64.429037
Time elapsed Julia 3D: 66.270249
Time elapsed Julia 5D: 94.318739
Time elapsed PP: 3.507944
Time elapsed PP 3D: 3.513362
Time elapsed PP 5D: 3.531232
Time elapsed PP Dispatch: 3.390464
Time elapsed Procedural VT Dispatch: 2.926652
Time elapsed Procedural Switch Dispatch: 1.489415
Time elapsed Procedural Switch Dispatch 3D: 1.606618

$ ./test_visitor 1000000000
number_of_iters = 1000000000
Time elapsed Visitor: 3.710451
Time elapsed Visitor3D: 4.572742
```

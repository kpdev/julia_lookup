# julia_lookup

## Build prerequisites

As a first step it is needed to build clang with procedural-parametric extension
https://github.com/kpdev/llvm-project/tree/pp-extension-v2?tab=readme-ov-file#build-procedural-parametric-extension

And make symbolic link to this version of clang in the following way:

```
ln -s /path/to/clang /usr/bin/ppclang
```

After that `ppclang` will be available in your environment (it is used in build scripts for benchmarks)

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
$ cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release -DBUILD_JULIA=ON
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

-------------------------

Unbuffered writing to a file
(by new lines `-oL`, at all `-o0`)
```
stdbuf -oL ./test_lookup_generic 100000000 1 > ./log_visitor_100.txt
```

------------------------

## Control CPU correctness:

### Get description of CPUs on the machine

```
lscpu
```

### Setup specific CPU to new process

```
taskset --cpu-list 0 ./test_lookup_generic 1000000000
```

### Get PSR (the latest CPU, on which the process was executed)

```
ps -mo pid,tid,%cpu,psr -p `pgrep test_lookup`
```

or

```
cat /proc/$(pgrep test_lookup)/stat | awk '{print "Last CPU: " $40}'
```

https://www.kernel.org/doc/Documentation/filesystems/proc.txt

-----------------

## Control CPU frequency:

### List of supported frequences for specific CPU (#0 in example)

```
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies
```

or

```
cpufreq-info
```

### Lock specific frequency

```
sudo cpufreq-set -c 0 -g userspace
```

```
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
```

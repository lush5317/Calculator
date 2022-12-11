# Build

1. Use `clang` or other CXX compiler, `gcc` or something (**if you don't have clang in your path, you need to revise the `makefile`**).

```bash
  make all
```

    Also, you can use`make clean` to delete the `*.o`.

2. If you don't have `make`, you can compile mannully.

```bash
  $cc main.c utils.c -o main -lm
```

# Test

Need `gtest`. On `Arch Linux`, you can use `pacman` to get the library.

```bash
pacman -S gtest
```

To test the code, you can use `make`.

```bash
make test_cal && ./test_cal
```

Also, you can compile it mannully. ***Remember to use `clang++` because `gtest` is a `C++` testing utility***.

```bash
clang++ test/test.cc -lgtest -lm -o test_cal
```

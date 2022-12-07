# build

1. Need `clang` or other CXX compiler(**if you don't use clang, you need to revise the `makefile`**).
  ```bash
  make all
  ```
    Also, you can use `make clean` to clean up the excutable.
2. If you don't have `make`, you can compile mannully.
  ```bash
  $cc main.c utils.c -o main
  ```
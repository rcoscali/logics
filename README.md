# logics

## Building

``` 
$ mdir build
$ cd build
$ cmake -G Ninja ..
$ ninja
``` 

## Run

Compute logic circuit outputs and flag. Display flag at end.
```
$ ./logics
```

## Unit Tests
Tests logs are in:

```
$ cd build
$ ninja test
$ cat Testing/Temporary/LastTest.log
```

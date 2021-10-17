# logics

## Building

``` 
$ mdir build
$ cmake -G Ninja ..
$ ninja
$ ninja test
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

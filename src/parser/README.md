# Parser

This program parse mini-C symbols and print ast tree.<br/>

## Developing Environment

- OS : Ubuntu 16.04 LTS
- IDE : Visual Studio Code v1.22.2
- Compiler: gcc (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609

## How to use

This parser is only supported in linux.</br>
And if you want to use this parser, you must install flex and bison.</br>

```
$ make
$ ./ast <.mc_file>
```

### If you don't install flex and bison

```
$ sudo apt-get update
$ sudo apt-get install flex
$ sudo apt-get install bison
```

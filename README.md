# study-compiler

2018 Compiler lecture

## Index

1. [Ucode interpreter](./src/ucode)
2. [Lexical Analyzer](./src/lex)
   - reference: [a simple game based on finite automata](https://github.com/KeonHeeLee/simple-pocket-mon-game)
3. [Parser](./src/parser)
4. [Intermediate Language Generator](./src/icg)


## How to use

**0. Installation**

```bash
$ git clone https://github.com/KeonHeeLee/MiniC-Compiler
$ sudo chmod +0777 setup.sh
$ ./setup.sh
```

**1. Generate Intermediate Language**

```bash
$ ./minic <Mini-C file(.mc)>
```

**2. Compile '.uco'(ICG) file**

```bash
$ ./ucodei <ICG file(.uco)>
```

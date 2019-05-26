# <img src="malix.svg" width=28 viewBox="20" > Malix [![Build Status](https://travis-ci.org/malix-foundation/Malix.svg?branch=master)](https://travis-ci.org/malix-foundation/Malix)
Malix programming language

```malix
println "Hello, Word!"
```

## Building

Build malix on UNIX systems:
```bash
$ mkdir build && cd build
$ cmkae ..
$ make
```

Build libmalix on UNIX systems:
```bash
$ mkdir lib && cd lib
$ cmkae -DMALIX_LIBRARY ..
$ make install # build libmalix and genirate header files
```

## Runing malix scripts

To run `.malix` files use command `/path/to/malix /path/to/file.malix`

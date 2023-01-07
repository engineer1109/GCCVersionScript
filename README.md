# GCCVersionScript
Add Version Symbol to Share Library, such as funcA@ funcA@@CLASSA_1.0

# 1. Introduction

This is a cmake sample about GCC version script.  
You can label function symbol with version scripts.  
[**ClassA**](./ClassA.map) is the version script file of the libClassA.so.  

```cmake
set_target_properties (ClassA PROPERTIES LINK_FLAGS "-Wl,--version-script -Wl,${CMAKE_CURRENT_SOURCE_DIR}/ClassA.map")
```
add LINK_FLAGS of the ClassA.map

# 2. Build
Test on the GCC 9.4.0.  
Compile the libClassA.so
```shell
mkdir build
cd build
cmake ..
make
```

validate the symbol
```shell
readelf -s libClassA.so  | grep funcA
readelf -s libClassA.so  | grep funcB
```

You will see:
```shell
    13: 000000000000117a    54 FUNC    GLOBAL DEFAULT   15 funcA@@CLASSA_1.0
    68: 000000000000117a    54 FUNC    GLOBAL DEFAULT   15 funcA
```
```shell
    14: 00000000000011b0    62 FUNC    GLOBAL DEFAULT   15 _ZN2AA5funcBEv@@CLASSA_1.0
    57: 00000000000011b0    62 FUNC    GLOBAL DEFAULT   15 _ZN2AA5funcBEv
```
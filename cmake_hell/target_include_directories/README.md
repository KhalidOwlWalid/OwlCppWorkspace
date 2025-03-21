# Minimal example

The `target_include_directories` command is used to explicitly tell the compiler where to look for the header files. This is particularly useful when we are dealing with the following scenarios:

### Complex project structure
where you might be dealing with a lot of header files, and you probably have not figure out the best place to place the header file. For example, at some point, you decided to move the entire header file in a certain directory into another directory.

Imagine having to change each relative path one by one in different C++ implementation and just hoping that you do not break anything!

### External libraries
If your project depends on external libraries, you need to specify the include directories for those libraries so the compiler can find the header files.

### Visbility for other targets
If your target (e.g. an executable or other library) is **used** by other targets, the `PUBLIC` keyword in `target_include_directories` ensures that the include directories are propagated to those dependent targets.

## Not using target_include_directories

### Example 1
For this example, you can checkout start checking out from the following commit:
```
git checkout 660a647
```

The tree directory looks as follow:
```shell
├── example.cpp
└── tmp
    ├── core.hpp
    └── logger.hpp
```

In this example, in the CMakelists.txt file, I did not include any of the header file using the `target_include_directories` or `include_directories`
function. For a small project, you can always get away by simply including the file as a relative path as shown below:

```cpp
#include "tmp/logger.hpp"
#include "tmp/core.hpp"

// Your code goes here
```

The compiler can resolve the path without any additional include directories since it is relative to the `PROJECT_SOURCE_DIR`. No big deal!

## Example 2


## Using the target_include_directories


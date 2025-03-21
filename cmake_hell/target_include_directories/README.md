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
git checkout 45eae60
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

```shell
git checkout e0ccd2d
```

The tree directory for this example looks as follows:
```shell
├── core
│   └── core.hpp
├── example.cpp
└── utils
    └── logger.hpp
```

Now, in this case, we have re-arranged the directory to be a bit more organized. Now, the previous code, would not compile anymore since we have moved the header file into each of their own respective directories. Hence, a slight tweak is required to make the code work.

```cpp
#include "utils/logger.hpp"
#include "core/core.hpp"

// Your code goes here
```

This now works, but imagine, if you re-arrange this file, but then 100s of files depends on it?! It would be insane for you to change the relative path one-by-one unless. Honestly, this is not a problem at all, because sometimes, being **explicit** on which header file you want the compiler to use avoids the ambiguity of not knowing which header file does the compiler use. However, for the sake of this discussion, what's the fix, in this case?

## Using the include_directories

To avoid having to manually change the relative path for each files, you can simply tell cmake where the include header files are!

```cmake
...
...

add_executable(main example.cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/core
    ${PROJECT_SOURCE_DIR}/utils
)
```

You can then change your source file to use the following instead:
```cpp
#include "logger.hpp"
#include "core.hpp"

// Your code goes here
```

Now, your compiler should just then be able to find the files easily even when you re-arrange the directory (just be sure to update the CMakelists.txt file if you made changes to the directory path).

#### Potential issues with the above implementation

While there are no definite solution to this problem, it is worth for you to note some potential issues you might face by using the approach above.

If for any reason, you are using an external library header, and you have included them as part of your `include_directories` in the cmake file:

```cmake
...
...

add_executable(main example.cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/core
    ${PROJECT_SOURCE_DIR}/utils
    ${EXTERNAL_LIBRARY_HEADER_FILES}
)
```

If both the local and external header file has the same name, the compiler will always opt for the first one (e.g it would use the one from your core include directory instead of external include directory).

**Solution 1**

To avoid this issue, you can simply change your header file to be something a bit more unique to your application.

Example:
If you are developing a gui application, you may name your header file as `gui_core.hpp` to avoid having conflicts on the `core.hpp` filename.

**Solution 2**

Just use relative path for files local to your workspace. This is a lot easier and having an explicit path allows you to avoid any sort of ambiguity in your application and avoid potential future issues!

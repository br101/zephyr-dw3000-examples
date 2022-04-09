Qorvo/Decawave DW3000 Examples for Zephyr

This is a port of the examples of the Qorvo/Decawave DWS3000_Release_v1.1 for Zephyr.

It uses the Zephyr DW3000 driver from https://github.com/br101/zephyr-dw3000-decadriver 
as a git submodule and otherwise tries to make the least amount of changes to the examples
from the original code (the rationale is that they will be updated).

The example to be executed is selected in the CMakeLists.txt thru the definition:

```
add_definitions(-DTEST_READING_DEV_ID)
```

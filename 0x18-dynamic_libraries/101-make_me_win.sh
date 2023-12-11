#!/bin/bash
wget -P .. https://github.com/Sanaalagh/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD="$PWD/../libtest.so"

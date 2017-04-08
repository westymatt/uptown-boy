#!/bin/sh

find src/ -name "*.cpp" | xargs clang-format -i
find src/ -name "*.h" | xargs clang-format -i

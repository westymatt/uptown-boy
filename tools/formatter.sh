#!/bin/sh

find src/ -name "*.cpp" | xargs clang-format -i
find src/ -name "*.h" | xargs clang-format -i
find honeycrisp/src/ -name "*.cpp" | xargs clang-format -i
find honeycrisp/src/ -name "*.h" | xargs clang-format -i

#!/bin/bash
set -e  # Exit on error
cd "$(dirname "$0")"

make -C ../src clean
make -C ../src

mkdir -p ../usr/bin
cp ../src/bubblesort ../usr/bin/


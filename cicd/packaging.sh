#!/bin/bash
set -e

cd "$(dirname "$0")"

cd ..

OUTPUT_DIR="pkg"

if [ ! -f "usr/bin/bubblesort" ]; then
    exit 1
fi

mkdir -p "$OUTPUT_DIR"
dpkg-deb --build . "$OUTPUT_DIR/"

#!/bin/bash
set -e  # Exit on error

# Navigate to script directory
cd "$(dirname "$0")"
make
./run-tests

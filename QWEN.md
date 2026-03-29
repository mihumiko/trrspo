# TRRSPO Project Context

## Project Overview

**TRRSPO** is a C++ project implementing a bubble sort algorithm for integer arrays. The project demonstrates a complete software development lifecycle with:

- Core sorting library (`bubbleSort` function)
- Interactive CLI application
- Unit test suite
- Full CI/CD pipeline with GitHub Actions
- Debian package distribution

### Architecture

```
trrspo/
├── src/           # Source code (main application + sort library)
├── cicd/          # CI/CD scripts, tests, and Docker configuration
├── .github/       # GitHub Actions workflow definitions
├── DEBIAN/        # Debian package metadata
├── usr/           # Installation target directory (binaries)
└── pkg/           # Built Debian packages
```

### Key Components

| Component | Description |
|-----------|-------------|
| `sort.hpp` / `sort.cpp` | Bubble sort implementation with null-pointer safety |
| `main.cpp` | Interactive CLI that reads arrays from stdin and displays sorted output |
| `tests.cpp` | Comprehensive unit tests (7 test cases including edge cases) |

## Building and Running

### Prerequisites

- g++ (C++ compiler)
- make
- dpkg-dev (for packaging)

### Build Commands

```bash
# Build the main application
cd src && make

# Build the test suite
cd cicd && make

# Clean build artifacts
cd src && make clean
cd cicd && make clean
```

### CI/CD Scripts

| Script | Purpose |
|--------|---------|
| `cicd/build.sh` | Builds application and copies binary to `usr/bin/` |
| `cicd/test.sh` | Compiles and runs unit tests |
| `cicd/packaging.sh` | Creates Debian package in `pkg/` directory |

### Running the Application

```bash
# After building
./src/bubblesort

# Or from installed location
./usr/bin/bubblesort
```

The application prompts for:
1. Array size (positive integer)
2. Array elements (integers)

Then displays the original and sorted arrays.

### Running Tests

```bash
cd cicd
./test.sh
# Or manually:
make && ./run-tests
```

Test coverage includes: basic sorting, already sorted, reverse sorted, single element, two elements, duplicates, and null pointer exception handling.

## Development Conventions

### Code Style

- **Naming**: camelCase for functions (`bubbleSort`), PascalCase for headers (`SORT_HPP`)
- **Error Handling**: Exceptions for invalid input (null pointers, invalid stream input)
- **Memory Management**: Manual `new`/`delete[]` for dynamic arrays
- **Headers**: Include guards (`#ifndef SORT_HPP`)

### Testing Practices

- Each test case is a separate function
- Uses `assert()` for validation
- Tests print pass/fail status to stdout
- Exception tests verify correct exception types are thrown

### CI/CD Pipeline

The GitHub Actions workflow (`.github/workflows/github-ci.yml`) runs on push/PR to `main`/`master`:

1. **Build Job**: Compiles source, uploads artifacts
2. **Test Job**: Runs test suite against built artifacts
3. **Packaging Job** (main branch only): Creates and uploads `.deb` package

### Packaging

Debian package configuration in `DEBIAN/control`:
- Package name: `trrspo`
- Version: `1.0-1`
- Architecture: `amd64`
- Maintainer: mihumiko <gavrm04@mail.ru>

Build package: `./cicd/packaging.sh`

## File Reference

| File | Purpose |
|------|---------|
| `src/sort.hpp` | Header with `bubbleSort` function declaration |
| `src/sort.cpp` | Bubble sort implementation |
| `src/main.cpp` | Interactive CLI entry point |
| `src/Makefile` | Build rules for main application |
| `cicd/tests.cpp` | Unit test suite |
| `cicd/Makefile` | Build rules for tests |
| `cicd/build.sh` | Automated build script |
| `cicd/test.sh` | Automated test script |
| `cicd/packaging.sh` | Debian package builder |
| `DEBIAN/control` | Package metadata |
| `.github/workflows/github-ci.yml` | CI/CD pipeline definition |

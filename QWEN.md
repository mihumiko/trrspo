# Project Overview

**trrspo** is a C++ command-line application that implements the bubble sort algorithm for sorting integer arrays. The project includes CI/CD infrastructure for automated building and Debian package deployment.

## Key Features

- Interactive bubble sort implementation with input validation
- Error handling for null pointers and invalid input
- Debian package (`.deb`) distribution ready
- GitHub Actions CI/CD pipeline

## Project Structure

```
trrspo/
├── src/              # Source code
│   ├── main.cpp      # Main application with bubble sort implementation
│   └── Makefile      # Build configuration
├── cicd/             # CI/CD scripts
│   ├── build.sh      # Build script for GitHub Actions
│   ├── test.sh       # Test script (placeholder)
│   ├── deploy.sh     # Deployment script (placeholder)
│   └── tests.cpp     # Test file (placeholder)
├── DEBIAN/           # Debian package metadata
│   └── control       # Package control file
├── usr/              # Installation directory structure
│   └── bin/          # Binary output location
├── pkg/              # Built Debian packages
└── .github/          # GitHub configuration
    └── workflows/    # GitHub Actions workflows
```

## Building and Running

### Prerequisites

- g++ compiler
- GNU Make

### Build Commands

```bash
# Build from source
cd src && make

# Clean build artifacts
cd src && make clean

# Run full CI/CD build (from project root)
./cicd/build.sh
```

### Running the Application

```bash
# Run the compiled binary
./src/bubblesort

# Or after installation
./usr/bin/bubblesort
```

### Interactive Usage

The program prompts for:
1. Array size (positive integer)
2. Array elements (integers)

It then displays the original and sorted arrays.

## Development Conventions

- **Language**: C++ with standard library only
- **Error Handling**: Exception-based (`std::exception`, `std::invalid_argument`)
- **Input Validation**: Robust validation with retry prompts for user input
- **Memory Management**: Manual `new`/`delete` for dynamic arrays
- **Code Style**: 
  - `snake_case` for functions and variables
  - `PascalCase` for types
  - Braces on same line as control statements

## CI/CD Pipeline

The GitHub Actions workflow (`.github/workflows/github-ci.yml`) uses:

- `cicd/build.sh` - Automated build with clean compile
- `cicd/test.sh` - Test execution (to be implemented)
- `cicd/deploy.sh` - Deployment/packaging (to be implemented)

## Debian Package

Package metadata in `DEBIAN/control`:

- **Package**: trrspo
- **Version**: 1.0-1
- **Architecture**: amd64
- **Dependencies**: libc6

Build the `.deb` package using standard Debian packaging tools with the `usr/` and `DEBIAN/` directories.

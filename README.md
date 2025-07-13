# ComplexSolver

A C++ application for solving complex mathematical problems with visualization capabilities.

## Features
- Solves complex equations and geometric problems
- Interactive GUI built with SFML
- Modular architecture with core, geometry, and GUI components
- Event-driven design with observer pattern
- Comprehensive test suite

## Build Instructions

### Prerequisites
- Ubuntu/Debian Linux
- sudo privileges for package installation

### Building
Run the setup script:
```bash
chmod +x setup.sh
./setup.sh
```

This will:
1. Install all required dependencies
2. Build and install SFML
3. Build the ComplexSolver project
4. Run tests

## CI Status

| **CI Service** | Build Status |
|:---------------|-------------:|
| GitHub Actions | [![Build Status (GitHub Actions)](https://github.com/nook0110/ComplexSolver/workflows/CMake%20Tests/badge.svg)](https://github.com/nook0110/ComplexSolver/actions?query=workflow%3A"CMake%20Tests") |

## Project Structure
```
ComplexSolver/
├── core/        # Core solver functionality
├── events/      # Event system
├── geometry/    # Geometric objects and operations  
├── gui/         # User interface components
│   ├── elements/ # GUI element implementations
│   └── utils/    # GUI utility functions
├── observer/    # Observer pattern implementation
├── plane/       # Complex plane visualization
└── utils/       # Utility functions
```

## License
MIT License - see [LICENSE](LICENSE) for details

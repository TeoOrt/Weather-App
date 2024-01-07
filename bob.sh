#!/bin/bash

# Define variables
BUILD_DIR="build"
EXECUTABLE_PATH="./${BUILD_DIR}/bin/weather_app"

# Function to display usage information
usage() {
    echo "Usage: $0 [-R] [--run]"
    echo "  -R: Clean the build directory"
    echo "  --run: Run the weather_app executable"
    exit 1
}

# Check command-line arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        -R)
            # Clean the build directory
            echo "Cleaning the build directory..."
            rm -rf "${BUILD_DIR}"
            shift
            ;;
        --run)
            # Run the weather_app executable
            echo "Running the weather_app executable..."
            ${EXECUTABLE_PATH}
            exit 0
            ;;
        *)
            # Invalid argument
            usage
            ;;
    esac
done

# If no command-line arguments, proceed with the regular build process
echo "Building the project..."
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"
cmake ..
make all
cd ..


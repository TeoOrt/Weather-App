# CMakeLists.txt in the Parser directory

# Include and source directories
include_directories(inc)
aux_source_directory(src SOURCE_FILES)

# Create the library
add_library(weather ${SOURCE_FILES})

target_include_directories(weather PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

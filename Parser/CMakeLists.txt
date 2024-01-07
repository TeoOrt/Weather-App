# CMakeLists.txt in the Parser directory

# Include and source directories
include_directories(inc)
aux_source_directory(src SOURCE_FILES)

# Create the library
add_library(parser ${SOURCE_FILES})

target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
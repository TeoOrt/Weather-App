# CMakeLists.txt in the Parser directory

# Include and source directories
include_directories(inc)
aux_source_directory(src SOURCE_FILES)

# Create the library
add_library(http_handler ${SOURCE_FILES})

target_include_directories(http_handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(http_handler PRIVATE weather)

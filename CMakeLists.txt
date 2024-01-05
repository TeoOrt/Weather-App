cmake_minimum_required(VERSION 3.9.1)

project(WeatherApp)

# Setting standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


# setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_executable(weather_app main.cpp)

add_subdirectory(Parser)

target_link_libraries(weather_app PRIVATE parser)
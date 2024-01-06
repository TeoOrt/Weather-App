cmake_minimum_required(VERSION 3.27)

project(WeatherApp)

# Setting standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# setting output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



add_subdirectory(Weather)
add_subdirectory(HttpHandler)
add_subdirectory(json)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF) 
set(SOURCE_FILES main.cpp)
# Find the Boost library (filesystem in this example)
find_package(Boost 1.81 REQUIRED COMPONENTS program_options  REQUIRED)
find_package(CURL REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
add_executable(weather_app ${SOURCE_FILES}) 

message(STATUS "Boost_VERSION: ${Boost_VERSION}")
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
link_directories(/usr/lib64)


target_link_libraries(weather_app PRIVATE  weather http_handler ${Boost_LIBRARIES} ${CURL_LIBRARIES} )




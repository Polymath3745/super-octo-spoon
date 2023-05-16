cmake_minimum_required(VERSION 3.15)
project(MainApp)
set(CMAKE_BUILD_TYPE Debug)

# sets variable to use
set(LIB lib)

# includes the lib folder
include_directories(${LIB})

# links it to executable
link_directories(${LIB})

add_subdirectory(${LIB})

# this will change based on cpp you want to execute
add_executable(${PROJECT_NAME} template-class.cpp)

# links the files together
target_link_libraries(${PROJECT_NAME} ${LIB})


cmake_minimum_required(VERSION 3.7...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Polylla-Python
    VERSION 1.0
    DESCRIPTION "Python interface for Polylla"
    LANGUAGES CXX
)

add_subdirectory(extern/Polylla)
add_subdirectory(extern/pybind11)

pybind11_add_module(polylla src/main.cpp)

target_link_libraries(polylla
    PRIVATE meshfiles
)

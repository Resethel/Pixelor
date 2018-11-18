cmake_minimum_required (VERSION 2.6)
project (Pixelator)

# The version number.
set (Pixelator_VERSION_MAJOR 1)
set (Pixelator_VERSION_MINOR 0)

#
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Finds SFML package
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED graphics window system)



# Creates the executable
add_executable(

    ${PROJECT_NAME}
    src/Utils.hpp
    src/Utils.cpp
    src/Main.cpp

)




target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${ADDITIONAL_LINK_FLAGS})

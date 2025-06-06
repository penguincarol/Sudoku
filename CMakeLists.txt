cmake_minimum_required(VERSION 3.22)
project(sudoku)

set(CMAKE_CXX_STANDARD 23)

# Add Kissat directory
set(KISSAT_DIR ${CMAKE_SOURCE_DIR}/kissat_folder/kissat)

# Custom target to build Kissat
#add_custom_target(kissat_build
#        COMMAND ./configure && make
#        WORKING_DIRECTORY ${KISSAT_DIR}
#        COMMENT "Building Kissat solver"
#)

include_directories(${KISSAT_DIR}/src)
include_directories(${KISSAT_DIR}/kissat)

# Add executable
add_executable(sudoku main.cpp utils.cpp
        constraints.h
        constraints.cpp
        inputReader.cpp)

# Link Kissat library
target_link_libraries(sudoku PRIVATE ${KISSAT_DIR}/build/libkissat.a)

# Ensure Kissat is built before linking to the main program
#add_dependencies(csc kissat_build)

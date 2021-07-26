cmake_minimum_required(VERSION 3.12)

project(
  biocpp
  VERSION 0.1.0
  DESCRIPTION "Bioinformatics Library for C++"
  HOMEPAGE_URL https://github.com/panda5176/biocpp
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)


### src

file(GLOB SOURCES src/*.cc)
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC inc)


### tests

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

set(TEST ${PROJECT_NAME}_test)
file(GLOB TESTS tests/*.cc)
add_executable(${TEST} ${TESTS})
target_include_directories(${TEST} PUBLIC inc)
target_link_libraries(${TEST} PUBLIC gtest ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${TEST})

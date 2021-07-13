cmake_minimum_required(VERSION 3.12)

project(
  biocpp
  VERSION 0.1.0
  DESCRIPTION "Bioinformatics Library for C++"
  HOMEPAGE_URL https://github.com/panda5176/biocpp
  LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(tests)

set(LIBRARIES algorithms io molecules)

foreach(LIBRARY ${LIBRARIES})
  set(LIB_OBJS ${LIB_OBJS} $<TARGET_OBJECTS:${LIBRARY}>)
endforeach()

add_library(${PROJECT_NAME} STATIC ${LIB_OBJS})

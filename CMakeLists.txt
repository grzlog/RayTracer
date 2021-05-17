cmake_minimum_required(VERSION 3.1)

project(raytracer)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CORE_SOURCES)
SET(CORE_HEADERS)

SET(CORE_SOURCES
     src/core/vector.cpp
)

SET(CORE_HEADERS
     src/core/vector.h
)

INCLUDE_DIRECTORIES(src)

ADD_LIBRARY(tracelibs STATIC
     ${CORE_HEADERS}
     ${CORE_SOURCES}
)

SET(ALL_LIBS
     tracelibs
)

add_executable(render_exe src/main/render.cpp)
TARGET_LINK_LIBRARIES(render_exe ${ALL_LIBS})



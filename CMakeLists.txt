cmake_minimum_required(VERSION 3.1)

project(raytracer)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

###########################################################################
# glog

SET(WITH_GFLAGS OFF CACHE BOOL "Use gflags")
SET(BUILD_SHARED_LIBS OFF CACHE BOOL " " FORCE)
IF(WIN32)
  ADD_DEFINITIONS( -D GOOGLE_GLOG_DLL_DECL= )
ENDIF()
ADD_SUBDIRECTORY(src/ext/glog)
SET_PROPERTY(TARGET glog logging_unittest demangle_unittest utilities_unittest stl_logging_unittest PROPERTY FOLDER "ext")
INCLUDE_DIRECTORIES (
  src/ext/glog/src
  ${CMAKE_BINARY_DIR}/src/ext/glog
)

###########################################################################


SET(CORE_SOURCES)
SET(CORE_HEADERS)

SET(CORE_SOURCES
     src/core/vector.cpp
     src/core/point.cpp
	 src/core/matrix.cpp
)

SET(CORE_HEADERS
     src/core/vector.h
     src/core/render.h
     src/core/point.h
	 src/core/matrix.h
)

INCLUDE_DIRECTORIES(src)

ADD_LIBRARY(tracelibs STATIC
     ${CORE_HEADERS}
     ${CORE_SOURCES}
)

SET(ALL_LIBS
     tracelibs
     glog
)

add_executable(render_exe src/main/render.cpp)
TARGET_LINK_LIBRARIES(render_exe ${ALL_LIBS})



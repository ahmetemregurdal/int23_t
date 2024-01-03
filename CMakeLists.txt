cmake_minimum_required(VERSION 3.5)
project(int23_t VERSION 0.0.1 DESCRIPTION "Since 23 is holy, we created int23_t")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(int23_t SHARED
	src/uint23_t.cpp
)
set_target_properties(int23_t PROPERTIES VERSION ${PROJECT_VERSION}))
set_target_properties(int23_t PROPERTIES PUBLIC_HEADER include/uint23_t.hpp)
include(GNUInstallDirs)
install(TARGETS int23_t
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

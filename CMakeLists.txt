cmake_minimum_required(VERSION 3.24)

project(simple_graphics_engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(
	${PROJECT_SOURCE_DIR}/inc
	${PROJECT_SOURCE_DIR}/src
)


file(GLOB ALL_SRC 
	"${PROJECT_SOURCE_DIR}/inc/*.h"
	"${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(simple_graphics_engine ${ALL_SRC})
find_library(XCB libxcb.a)
find_library(XAU libXau.so.6.0.0)
find_library(XDMCP libXdmcp.so)
target_link_libraries(simple_graphics_engine ${XCB} ${XAU} ${XDMCP})

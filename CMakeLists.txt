cmake_minimum_required(VERSION 3.21)

# set the project name
project(mesh_arrangement)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TBB_TEST OFF CACHE BOOL " " FORCE)
set(TBB_EXAMPLES OFF CACHE BOOL " " FORCE)

add_subdirectory(external/oneTBB)

set( CMAKE_BUILD_TYPE Release)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -fPIC" )

add_library(meshArrangement SHARED meshArrangement.cpp)


target_include_directories(meshArrangement PUBLIC
	./
	code/
	)

target_compile_definitions(meshArrangement PUBLIC TBB_PARALLEL=1)

target_link_libraries(meshArrangement tbb)
target_include_directories(meshArrangement PUBLIC ${PROJECT_SOURCE_DIR}/external/abseil-cpp/)

set(cinolib_DIR ${PROJECT_SOURCE_DIR}/external/Cinolib)
set(CINOLIB_USES_OPENGL_GLFW_IMGUI OFF)
set(CINOLIB_USES_SHEWCHUK_PREDICATES ON)
set(CINOLIB_USES_INDIRECT_PREDICATES ON)

find_package(cinolib REQUIRED)
target_link_libraries(meshArrangement cinolib)


# add the executable
add_executable(${PROJECT_NAME} 
	main.cpp
)

target_link_libraries(${PROJECT_NAME} meshArrangement)
#target_include_directories(${PROJECT_NAME})

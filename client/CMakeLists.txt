file(GLOB_RECURSE SOURCES ./src/*.cpp ./src/*.hpp)

add_executable(${CMAKE_PROJECT_NAME}_client ${SOURCES})
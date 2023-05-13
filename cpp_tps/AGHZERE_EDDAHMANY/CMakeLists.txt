INCLUDE_DIRECTORIES( ./include )
SET ( EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE} )
SET( CMAKE_CXX_FLAGS "-std=c++11")
ADD_EXECUTABLE( main ./src/matrix.cpp ./src/main.cpp)

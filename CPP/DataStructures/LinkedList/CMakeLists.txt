PROJECT(LinkedList)

file(GLOB_RECURSE SRCS *.h *.cpp)
add_executable(${PROJECT_NAME} ${SRCS})

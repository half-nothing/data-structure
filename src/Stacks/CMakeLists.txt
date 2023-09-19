message(STATUS Stacks)

include_directories(include)

add_executable(SequentialStack test/SequentialStackTest.cpp)
add_executable(ChainStack test/ChainStackTest.cpp)
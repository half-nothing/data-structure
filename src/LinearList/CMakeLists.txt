message(STATUS "LinearList")

include_directories(include)

add_executable(Array test/ArrayTest.cpp)
add_executable(DoubleLinkList test/DoubleLinkListTest.cpp)
add_executable(SingleLinkList test/SingleLinkListTest.cpp)
add_executable(CircularlyLinkList test/CircularlyLinkList.cpp)
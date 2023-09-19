message(STATUS Queues)

include_directories(include)

add_executable(SequentialQueue test/SequentialQueueTest.cpp)
add_executable(ChainQueue test/ChainQueueTest.cpp)
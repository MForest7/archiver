cmake_minimum_required(VERSION 3.0)
project(hw-02_huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Werror -std=c++11 -Iinclude")

include_directories("include/")

add_executable(hw-02_huffman src/main.cpp)
add_executable(hw-02_huffman_test test/test.cpp)

set(SOURCES src/archive.cpp src/boolio.cpp src/decoder.cpp src/encoder.cpp src/flags.cpp src/huffman.cpp)

target_sources(hw-02_huffman PRIVATE ${SOURCES})
target_sources(hw-02_huffman_test PRIVATE ${SOURCES})

set(TEST_SOURCES test/huffman_test.cpp test/boolio_test.cpp test/flags_test.cpp test/encoder_test.cpp test/decoder_test.cpp)

target_sources(hw-02_huffman_test PRIVATE ${TEST_SOURCES})

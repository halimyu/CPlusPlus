cmake_minimum_required(VERSION 3.23)
project(hw3)

set(CMAKE_CXX_STANDARD 14)

configure_file(wordList.txt wordList.txt COPYONLY)

add_executable(hw3 main.cpp Wordle.cpp Wordle.h)

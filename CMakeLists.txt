##
## File: CMakeLists.txt
##
## Date: 2/17/22
##

cmake_minimum_required (VERSION 2.8.11)
project (deck-of-cards)

include_directories(include)

add_executable(knuth_shuffle_test test/knuth_shuffle_test.cpp)

add_executable(shuffle_deal_test test/shuffle_deal_test.cpp
    src/playing_card.cpp)

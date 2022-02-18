##
## File: CMakeLists.txt
##
## Date: 2/18/22
##

cmake_minimum_required (VERSION 2.8.11)
project (deck-of-cards)

include_directories(include)

add_executable(knuth_shuffle_test test/knuth_shuffle_test.cpp)

add_executable(shuffle_deal_test test/shuffle_deal_test.cpp
    src/playing_card.cpp)

add_executable(war_card_game_test test/war_card_game_test.cpp
    src/playing_card.cpp
    src/war_card_game.cpp)

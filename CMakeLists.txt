##
## File: CMakeLists.txt
##
## Date: 2/18/22
##

cmake_minimum_required (VERSION 3.16)
project (deck-of-cards)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(knuth_shuffle_test test/knuth_shuffle_test.cpp)
target_compile_features(knuth_shuffle_test PRIVATE
    cxx_std_14
)

add_executable(shuffle_deal_test test/shuffle_deal_test.cpp
    src/playing_card.cpp)
target_compile_features(shuffle_deal_test PRIVATE
    cxx_std_14
)

add_executable(war_card_game_test test/war_card_game_test.cpp
    src/playing_card.cpp
    src/war_card_game.cpp)
target_compile_features(war_card_game_test PRIVATE
    cxx_std_14
)

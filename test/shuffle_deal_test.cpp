/**
 * @file shuffle_deal_test.cpp
 *
 * @author Channing Ko-Madden
 *
 * @date 2/17/2022
 *
 * @brief Test script for creating a 52 card playing deck, shuffling it, and dealing the cards
 *
 */

#include "deck.h"
#include "playing_card.h"
#include <random>
#include <iostream>

int main(int argc, char** argv)
{
    std::random_device randomSeeder;
    std::mt19937 mtGen(randomSeeder()); // randomly seed mt19937

    doc::Deck<doc::PlayingCard> standardDeck(doc::buildStandardDeck(), mtGen);
    std::cout << "Unshuffled deck dealt out: \n";
    while (!standardDeck.empty())
    {
        std::cout << standardDeck.deal_card().str() << "\n";
    }


    std::cout << "Shuffled deck dealt out: \n";
    standardDeck = doc::Deck<doc::PlayingCard>(doc::buildStandardDeck(), mtGen);
    standardDeck.shuffle();
    while (!standardDeck.empty())
    {
        std::cout << standardDeck.deal_card().str() << "\n";
    }

    return 0;
}

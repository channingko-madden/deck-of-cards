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
#include <iostream>

int main(int argc, char** argv)
{
    doc::Deck<doc::PlayingCard> standardDeck(doc::buildStandardDeck());
    std::cout << "Unshuffled deck dealt out: \n";
    while (!standardDeck.empty())
    {
        std::cout << standardDeck.deal_card().str() << "\n";
    }


    std::cout << "Shuffled deck dealt out: \n";
    standardDeck.assign(doc::buildStandardDeck());
    standardDeck.shuffle();
    while (!standardDeck.empty())
    {
        std::cout << standardDeck.deal_card().str() << "\n";
    }

    std::cout << "Comparing shuffle & deal of two separate, newly created, 52 card decks: \n";
    doc::Deck<doc::PlayingCard> firstDeck(doc::buildStandardDeck());
    firstDeck.shuffle();
    doc::Deck<doc::PlayingCard> secondDeck(doc::buildStandardDeck());
    secondDeck.shuffle();
    while (!firstDeck.empty())
    {
        std::cout << firstDeck.deal_card().str() << "    " << secondDeck.deal_card().str() << "\n";
    }
    return 0;
}

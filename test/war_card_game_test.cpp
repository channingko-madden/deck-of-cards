
/**
 * @file shuffle_deal_test.cpp
 *
 * @author Channing Ko-Madden
 *
 * @date 2/17/2022
 *
 * @brief Test script for the WarCardGame class, letting a game of war run automatically.
 *
 * Was also used to debug WAR phase edge cases.
 *
 */

#include "war_card_game.h"
#include "playing_card.h"
#include <vector>

int main(int argc, char** argv)
{
    // use custom deck to test WAR edge cases
    /*
    const doc::PlayingCard singleCard = doc::PlayingCard(
            doc::PlayingCard::Suite::Spades,
            doc::PlayingCard::Rank::Ace);
    const doc::PlayingCard secondCard = doc::PlayingCard(
            doc::PlayingCard::Suite::Spades,
            doc::PlayingCard::Rank::Two);
    std::vector<doc::PlayingCard> testCards(6, singleCard);
    testCards.push_back(secondCard);
    testCards.push_back(secondCard);
    doc::WarCardGame testGame(testCards);
    testGame.autoPlay();
    */

    // play a standard game
    doc::WarCardGame myGame;
    myGame.autoPlay();

    return 0;
}

/*
 * @file war_card_game.cpp
 *
 * @author Channing Ko-Madden
 *
 * @date 2/18/2022
 *
 * @brief Define WarCardGame class, that simulates a game of the card game War, with the results
 * printed to the terminal.
 *
 */

#include "war_card_game.h"
#include "playing_card.h"
#include <iostream>
#include <vector>

namespace doc
{

WarCardGame::WarCardGame()
{
    initialize(doc::buildStandardDeck());
}

WarCardGame::WarCardGame(const std::vector<PlayingCard>& cards)
{
    if ((cards.size() % 2) == 1)
        initialize({cards.begin(), cards.end() - 1});
    else 
        initialize(cards);
}

void WarCardGame::playTurn()
{
    if (!gameOver())
    {
        turnCounter++;
        replenishDecks();

        const PlayingCard card1 = mP1Deck.deal_card();
        const PlayingCard card2 = mP2Deck.deal_card();
        std::cout << "Player 1 shows: " << card1.str() << "  Player 2 shows: " << card2.str() << std::endl;
        if (card1.rank() == card2.rank())
        {
            const int winner = war();
            if (winner == 1)
            {
                std::cout << "Player 1 Won the War\n";
                mP1WinPile.push_back(card1);
                mP1WinPile.push_back(card2);
                mP1WinPile.insert(mP1WinPile.end(), mP1WarCards.begin(), mP1WarCards.end());
                mP1WinPile.insert(mP1WinPile.end(), mP2WarCards.begin(), mP2WarCards.end());
            }
            else if (winner == 2)
            {
                std::cout << "Player 2 Won the War\n";
                mP2WinPile.push_back(card1);
                mP2WinPile.push_back(card2);
                mP2WinPile.insert(mP2WinPile.end(), mP2WarCards.begin(), mP2WarCards.end());
                mP2WinPile.insert(mP2WinPile.end(), mP1WarCards.begin(), mP1WarCards.end());
            }
            else // DRAW! Everyone gets their cards back
            {
                std::cout << " The War was a Draw ... bummer ...\n";
                mP1WinPile.push_back(card1);
                mP2WinPile.push_back(card2);
                mP1WinPile.insert(mP1WinPile.end(), mP1WarCards.begin(), mP1WarCards.end());
                mP2WinPile.insert(mP2WinPile.end(), mP2WarCards.begin(), mP2WarCards.end());
            }
            mP1WarCards.clear();
            mP2WarCards.clear();
        }
        else if (card1.rank() == PlayingCard::Rank::Ace)
        {
            //player 1 wins
            mP1WinPile.push_back(card1);
            mP1WinPile.push_back(card2);
        }
        else if (card2.rank() == PlayingCard::Rank::Ace)
        {
            // player 2 wins
            mP2WinPile.push_back(card1);
            mP2WinPile.push_back(card2);
        }
        else if (card1.rank() > card2.rank())
        {
            //player 1 wins
            mP1WinPile.push_back(card1);
            mP1WinPile.push_back(card2);
        }
        else
        {
            // player 2 wins
            mP2WinPile.push_back(card1);
            mP2WinPile.push_back(card2);
        }

    }
    else
    {
        std::cout << "Cannot play turn, game has already ended.\n";
    }
}

void WarCardGame::printScore() const
{
    const unsigned int p1Score = mP1Deck.size() + mP1WinPile.size();
    const unsigned int p2Score = mP2Deck.size() + mP2WinPile.size();

    std::cout << "Player One has " << p1Score << " cards left.   Player Two has " << p2Score <<
        " cards left.\n";
    if (p1Score == 0)
        std:: cout << "Player Two has won!\n";
    else if (p2Score == 0)
        std:: cout << "Player One has won!\n";
}

void WarCardGame::autoPlay()
{
    printScore();
    while(!gameOver())
    {
        playTurn();
        printScore();
        turnCounter++;
        std::cout << "\n";
    }
    std::cout << turnCounter<< " turns were played\n";
}


bool WarCardGame::gameOver() const
{
    if ((mP1Deck.empty() && mP1WinPile.empty()) ||
        (mP2Deck.empty() && mP2WinPile.empty()))
    {
        return true;
    }
    else
        return false;
}

/*
 * Recursive function if multiple wars occur
 *
 * For war, each player draws 2 cards. First card is "face down", aka just goes straight into
 * the warCards pile. The second is compared to decide who won.
 *
 * Edge cases to handle:
 *  - If player doesn't have enough cards to complete the war, they lose.
 *  - If neither do, the one who runs out first loses.
 *  - If both players run out simultaneously, it's a draw, they both get all their cards back.
 */
int WarCardGame::war()
{
    std::cout << "WAR!\n";
    
    replenishDecks(); // if war continues, need to replenish from win pile to continue the war.

    if (mP1Deck.empty() && mP2Deck.empty())
        return 3;
    else if (mP1Deck.empty())
    {
        std::cout << "Player 1 ran out of cards & could not continue the war\n";
        return 2;
    }
    else if (mP2Deck.empty())
    {
        std::cout << "Player 2 ran out of cards & could not continue the war\n";
        return 1;
    }

    mP1WarCards.push_back(mP1Deck.deal_card()); // face down cards
    mP2WarCards.push_back(mP2Deck.deal_card());

    if (mP1Deck.empty() && mP2Deck.empty())
        return 3;
    else if (mP1Deck.empty())
    {
        std::cout << "Player 1 ran out of cards & could not continue the war\n";
        return 2;
    }
    else if (mP2Deck.empty())
    {
        std::cout << "Player 2 ran out of cards & could not continue the war\n";
        return 1;
    }

    const PlayingCard card1 = mP1Deck.deal_card(); // face up cards to compare
    const PlayingCard card2 = mP2Deck.deal_card();
    mP1WarCards.push_back(card1);
    mP2WarCards.push_back(card2);

    std::cout << "Player 1 shows: " << card1.str() << "  Player 2 shows: " << card2.str() << std::endl;
    if (card1.rank() == card2.rank())
        return war(); // recursive
    else if (card1.rank() == PlayingCard::Rank::Ace || card1.rank() > card2.rank())
        return 1;
    else if (card2.rank() == PlayingCard::Rank::Ace)
        return 2;
    else if (card1.rank() < card2.rank())
        return 2;
    else
        return 1;
}

void WarCardGame::replenishDecks()
{
    if (mP1Deck.empty())
    {
        mP1Deck.assign(mP1WinPile);
        mP1WinPile.clear();
        mP1Deck.shuffle();
    }

    if (mP2Deck.empty())
    {
        mP2Deck.assign(mP2WinPile);
        mP2WinPile.clear();
        mP2Deck.shuffle();
    }
}

void WarCardGame::initialize(const std::vector<PlayingCard>& cards)
{
    Deck<PlayingCard> dealDeck(cards);
    dealDeck.shuffle();
    mP1WinPile.reserve(dealDeck.size()); // max these will ever be is total amount of cards
    mP2WinPile.reserve(dealDeck.size());
    while (!dealDeck.empty())
    {
        mP1WinPile.push_back(dealDeck.deal_card());
        mP2WinPile.push_back(dealDeck.deal_card());
    }

    mP1Deck.assign(mP1WinPile);
    mP2Deck.assign(mP2WinPile);
    mP1WinPile.clear();
    mP2WinPile.clear();
}

} // namespace doc

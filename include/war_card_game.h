/**
 * @file war_card_game.h
 *
 * @author Channing Ko-Madden
 *
 * @date 2/18/2022
 *
 * @brief Declare WarCardGame class, that simulates a game of the card game War, with the results
 * printed to standard out.
 *
 */

#ifndef WAR_CARD_GAME_H
#define WAR_CARD_GAME_H

#include "deck.h"
#include "playing_card.h"
#include <vector>

/**
 * @brief "Deck of Cards" namespace
 */
namespace doc
{

/**
 * @class WarCardGame "war_card_game.h" "war_card_game.h"
 * @brief This class simulates a game of the card game War, played with a standard 52 card deck, with the
 * results printed to standard out.
 *
 * War involves two players, and the goal is to be the first player to win all 52 cards.
 *
 * How to play:
 *  Each player draws a card and shows it. The higher card takes both cards and places them in a separate
 *  'winnings' pile. Ace is high.
 *
 *  If the cards are the same rank a WAR occurs, each player draws two additional cards,
 *  showing the second card drawn. The player with the higher rank card takes all six cards.
 *  If the shown cards are again the same rank, this process continues until there is a winner,
 *  with the winner taking all drawn cards.
 *
 *  When a player has run out of cards in their deck, they take their 'winnings' pile, shuffle it, and it becomes
 *  their deck to continue play with.
 *
 *  The game ends when one plyaer has won all the cards.
 */
class WarCardGame
{
    public:

        /**
         * @brief Constructor sets up standard 52 card game to play
         */
        WarCardGame();

        /**
         * @brief Construct game with custom assortment of playing cards
         *
         * @param[in] cards Cards to shuffle and deal to players
         * Must be an even number of cards for a fair game. If an odd number of cards is passed, the 
         * last card is dropped from the game.
         */
        WarCardGame(const std::vector<PlayingCard>& cards);

        /**
         * @brief Play a turn of the game
         */
        void playTurn();

        /**
         * @brief Prints the current game score to standard output.
         */
        void printScore() const;

        /**
         * @brief Plays the game until there is a winner, printing out the score after each turn, and the
         * total number of turns played.
         */
        void autoPlay();

        /**
         * @brief Returns if the game is over and there is a winner
         * @return True if the game is over, false if not.
         */
        bool gameOver() const;

        /**
         * @brief Returns the number of turns played so far.
         * A turn were one or more wars occur counts as one turn
         * @return Turns played
         */
        unsigned long long turnsPlayed() const;

    private:

        /**
         * @brief Initialize game with cards
         * @param[in] cards Cards to shuffle and deal out to players
         */
        void initialize(const std::vector<PlayingCard>& cards);

        /**
         * @brief Executes war play phase of game and returns the result of the war
         * Recursively calls itself if multiple wars occur
         *
         * The winner of war gets all the cards. If it is a draw, each player gets back
         * all their own cards.
         * @return 1 if Player One won, 2 if Player Two won, or 3 if it was a draw
         */
        int war();

        /**
         * @brief If either Player One's deck or Player Two's deck is empty, assign their win pile to
         * their decks and reshuffle the deck.
         *
         * If a deck is not empty, is it not modified.
         */
        void replenishDecks();

        Deck<PlayingCard> mP1Deck; /**<@brief Player One's deck to play from */
        Deck<PlayingCard> mP2Deck; /**<@brief Player Two's deck to play from */
        std::vector<PlayingCard> mP1WinPile; /**<@brief Player One's win pile, that becomes deck later */
        std::vector<PlayingCard> mP2WinPile; /**<@brief Player Two's win pile, that becomes deck later */
        std::vector<PlayingCard> mP1WarCards; /**<@brief Cards Player 1 has put down for war */
        std::vector<PlayingCard> mP2WarCards; /**<@brief Cards Player 2 has put down for war */
        unsigned long long mTurnCounter = 0; /**<@brief Counter for the number of turns played */

};

} // namespace doc
#endif

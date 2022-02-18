/**
 * @file playing_card.h
 *
 * @author Channing Ko-Madden
 *
 * @date 2/18/2022
 *
 * @brief Declare PlayingCard class, that represents a French-suited playing card of a standard 52-card deck.
 *
 */

#ifndef PLAYING_CARD_H
#define PLAYING_CARD_H

#include <vector>
#include <string>

/**
 * @brief "Deck of Cards" namespace
 */
namespace doc
{

/**
 * @class PlayingCard "playing_card.h" "playing_card.h"
 * 
 * @brief The PlayingCard class represents a French-suited playing card of a standard 52-card deck. Cards can have
 * one four suites (clubs, diamonds, hearts, and spaces), and one of thirteen ranks (Ace, 2-10, Jack, Queen, 
 * King), also known as the face value.
 */
class PlayingCard
{
    public:

        /** @brief Represent the four suites */
        enum class Suite : int {Clubs = 0, Diamonds, Hearts, Spades};

        /** @brief Represent the thirteen ranks */
        enum class Rank : int {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

        /** 
         * @brief Returns string representation of Suite enum
         * @param[in] suite
         * @return String version of suite
         */
        static std::string toString(const Suite suite);

        /** 
         * @brief Returns string representation of Rank enum
         * @param[in] rank 
         * @return String version of rank 
         */
        static std::string toString(const Rank rank);

        /**
         * @brief Return the underlying int value for a Rank enum.
         * Ace is low (Ace == 1)
         * @return Int value of Rank (Ace low)
         */
        static int toInt(const Rank rank);

        /**
         * @brief Construct playing card with suite and rank
         * @param[in] suite One of four suites
         * @param[in] rank One of thirteen ranks
         */
        PlayingCard(const Suite suite, const Rank rank);

        /**
         * @brief Returns the playing card's suite
         * @return suite
         */
        Suite suite() const;

        /**
         * @brief Returns the playing card's rank
         * @return rank 
         */
        Rank rank() const;

        /**
         * @brief Returns the card's suite and rank within a string.
         * Useful for logging or debugging
         */
        std::string str() const;

    private:
        Suite mSuite; /**<@brief Playing Card's suite */
        Rank mRank; /**<@brief Playing Card's rank */

};

std::vector<PlayingCard> buildStandardDeck();

} // namespace doc
#endif

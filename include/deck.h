/**
 * @file deck.h
 *
 * @author Channing Ko-Madden
 *
 * @date 2/16/2022
 *
 * @brief Declare Deck class, that represents a deck of data of any size.
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm> // for std::swap
#include <random>

/**
 * @brief "Deck of Cards" namespace
 */
namespace doc
{

/**
 * @brief Implementation of Knuth Shuffle algorithm, also known as Fisher-Yates shuffle.
 * See https://en.wikipedia.org/wiki/Fisher-Yates_shuffle for background.
 *
 * @param[in] data Datat to shuffle
 * @param[in] randomGenerator 32-bit Mersenne Twister algorithm for generating random numbers.
 *  It is assumed this generator has been seeded appropriately.
 */
template <class T>
void knuthShuffle(std::vector<T>& data, std::mt19937& randomGenerator)
{
    std::uniform_int_distribution<unsigned long long> dist(0, data.size() - 1); // dist is range [a, size-1]
    for (auto& point : data)
    {
        std::swap(point, data.at(dist(randomGenerator)));
    }  
}

/**
 * @brief Exception thrown when cards are dealt from an empty Deck 
 */
class EmptyDeckException : public std::exception
{
    virtual const char * what() const throw ()
    {
        return("Deck is empty");
    }
};

/**
 * @class Deck "deck.h" "deck.h"
 * 
 * @brief Data is internally stored within an std::vector object. The "back" of the vector represents the top
 * of the deck, the "front" of the vector represents the bottom of the deck. A vector was chosen b/c it is efficient
 * at adding & removing from its end, and drawing from the top of the deck is the most common action done with a deck.
 *
 * Other actions such as placing at the bottom of the deck, or placing randomly within the deck, are less common, and
 * I felt did not justify using a different container, such as a list, that are more efficient at inserting or removing
 * elements at positions other than the end.
 *
 * T must meet the requirements of MoveAssignable and MoveConstructible
 */
template <class T>
class Deck
{
    public:

        /**
         * @brief Construct Deck with data
         * @param[in] data 
         * @param[in] randomGenerator Random generator used for shuffling cards
         * Assumes this generator has been seeded appropriately.
         */
        Deck(const std::vector<T>& data, const std::mt19937& randomGenerator);

        /**
         * @brief Shuffle the deck, randomizing its contents
         */
        void shuffle();

        /**
         * @brief Returns if the deck is empty
         * @return True if the deck is empty, false otherwise */
        bool empty() const;

        /**
         * @brief Returns a card from the top of the deck, removing it from the deck.
         *
         * Calling this method on an empty deck will throw an EmptyDeckException
         * @return Card at top of deck
         */
        T deal_card();


    private:

        std::vector<T> mData; /**<@brief Deck's data */
        std::mt19937 mRandomGen; /**<@brief Use for shuffling */

};

// Definition below

template<class T>
Deck<T>::Deck(const std::vector<T>& data, const std::mt19937& randomGenerator) :
    mData(data), mRandomGen(randomGenerator)
{
}

template<class T>
void Deck<T>::shuffle()
{
    knuthShuffle<T>(mData, mRandomGen);
}

template<class T>
bool Deck<T>::empty() const
{
    return mData.empty();
}

template<class T>
T Deck<T>::deal_card()
{
    if (mData.empty())
        throw EmptyDeckException();
    else
    {
        const T card = mData.back();
        mData.pop_back();
        return card;
    }
}

} // namespace doc
#endif

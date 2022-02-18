/**
 * @file deck.h
 *
 * @author Channing Ko-Madden
 *
 * @date 2/18/2022
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
 * This algorithnm's time complexity is O(n).
 *
 * @param[in] data Data to shuffle
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
 * @brief Exception thrown when an attempt to deal a card from an empty Deck occurs.
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
 * at adding & removing from its end (amortized constant O(1), and drawing from the top of the deck is the
 * most common action done with a deck. It is also efficient for random access which is used by the shuffle method
 * to shuffle the deck.
 *
 * Other actions such as placing at the bottom of the deck, or placing randomly within the deck, are less common, and
 * I felt did not justify using a different container.
 *
 * T must meet the requirements of MoveAssignable and MoveConstructible
 */
template <class T>
class Deck
{
    public:

        /** @brief Construct empty deck 
         *
         * Initializes internal random number generator
         */
        Deck();

        /**
         * @brief Construct Deck with data
         *
         * Initializes internal random number generator
         * @param[in] data 
         */
        Deck(const std::vector<T>& data);

        /**
         * @brief No copy constructor to prevent multiple decks using the same seeded random number generator
         */
        Deck(const Deck&) = delete;

        /**
         * @brief No Copy assignment operator to prevent multiple decks using the same seeded random generator
         */
        Deck& operator=(const Deck&) = delete;

        /**
         * @brief Shuffle the deck, randomizing its contents
         */
        void shuffle();

        /**
         * @brief Returns if the deck is empty
         * @return True if the deck is empty, false otherwise */
        bool empty() const;

        /**
         * @brief Returns the size of deck
         * @return Size of the deck
         */
        size_t size() const;

        /**
         * @brief Returns a card from the top of the deck, removing it from the deck and reducing the size by one.
         *
         * Calling this method on an empty deck will throw an EmptyDeckException
         * @return Card at top of deck
         */
        T deal_card();

        /**
         * @brief Returns the contents of this deck, without clearing the deck.
         *
         * This method can be used to create a second Deck with the same contents of this Deck, but without
         * the same random number generator used to shuffle the deck.
         * @return Deck contents
         */
        std::vector<T> contents() const;

        /**
         * @brief Replaces the contents of the Deck
         * @param[in] data Data to replace contents.
         */
        void assign(const std::vector<T>& data);


    private:

        std::vector<T> mData; /**<@brief Deck's data */
        std::mt19937 mRandomGen; /**<@brief Use for shuffling */

};

// Definition below
template<class T>
Deck<T>::Deck()
{
    std::random_device randomSeeder;
    mRandomGen.seed(randomSeeder());
}

template<class T>
Deck<T>::Deck(const std::vector<T>& data) :
    mData(data)
{
    std::random_device randomSeeder;
    mRandomGen.seed(randomSeeder());
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
size_t Deck<T>::size() const
{
    return mData.size();
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

template<class T>
std::vector<T> Deck<T>::contents() const
{
    return mData;
}

template<class T>
void Deck<T>::assign(const std::vector<T>& data)
{
    mData = data;
}

} // namespace doc
#endif

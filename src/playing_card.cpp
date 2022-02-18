/**
 * @file playing_card.cpp
 *
 * @author Channing Ko-Madden
 *
 * @date 2/17/2022
 *
 * @brief Define PlayingCard class, that represents a French-suited playing card of a standard 52-card deck.
 *
 */

#include "playing_card.h"
#include <vector>
#include <sstream>

namespace doc
{
    
// static
std::string PlayingCard::toString(const Suite suite)
{
    switch (suite)
    {
        case Suite::Clubs:
            return "Clubs";
        case Suite::Diamonds:
            return "Diamonds";
        case Suite::Hearts:
            return "Hearts";
        case Suite::Spades:
            return "Spades";
        default:
            return "";
    }
}

// static
std::string PlayingCard::toString(const Rank rank)
{
    switch (rank)
    {
        case Rank::Ace:
            return "A";
        case Rank::Two:
            return "2";
        case Rank::Three:
            return "3";
        case Rank::Four:
            return "4";
        case Rank::Five:
            return "5";
        case Rank::Six:
            return "6";
        case Rank::Seven:
            return "7";
        case Rank::Eight:
            return "8";
        case Rank::Nine:
            return "9";
        case Rank::Ten:
            return "10";
        case Rank::Jack:
            return "J";
        case Rank::Queen:
            return "Q";
        case Rank::King:
            return "K";
        default:
            return "";
    }
}

PlayingCard::PlayingCard(const Suite suite, const Rank rank) : mSuite(suite), mRank(rank)
{
}

PlayingCard::Suite PlayingCard::suite() const
{
    return mSuite;
}

PlayingCard::Rank PlayingCard::rank() const
{
    return mRank;
}

std::string PlayingCard::str() const
{
    std::stringstream outbuffer;
    outbuffer << PlayingCard::toString(mRank) << " " << PlayingCard::toString(mSuite);
    return outbuffer.str();
}

std::vector<PlayingCard> buildStandardDeck()
{
    const std::vector<PlayingCard::Suite> suites = {
        PlayingCard::Suite::Clubs,
        PlayingCard::Suite::Diamonds,
        PlayingCard::Suite::Hearts,
        PlayingCard::Suite::Spades};

    const std::vector<PlayingCard::Rank> ranks = {
        PlayingCard::Rank::King,
        PlayingCard::Rank::Queen,
        PlayingCard::Rank::Jack,
        PlayingCard::Rank::Ten,
        PlayingCard::Rank::Nine,
        PlayingCard::Rank::Eight,
        PlayingCard::Rank::Seven,
        PlayingCard::Rank::Six,
        PlayingCard::Rank::Five,
        PlayingCard::Rank::Four,
        PlayingCard::Rank::Three,
        PlayingCard::Rank::Two,
        PlayingCard::Rank::Ace};

    std::vector<PlayingCard> deck;
    deck.reserve(52);
    for (const auto& suite : suites)
    {
        for (const auto& rank : ranks)
        {
            deck.push_back(PlayingCard(suite, rank));
        }
    }

    return deck;
}

} // namespace doc

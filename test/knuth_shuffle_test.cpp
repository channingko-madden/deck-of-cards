/**
 * @file knuth_shuffle_test.cpp
 *
 * @author Channing Ko-Madden
 *
 * @date 2/17/2022
 *
 * @brief Test script for the Knuth shuffle algorithm
 *
 * This script creates a vector with values from 1 to 10, and then uses the knuthShuffle function to
 * shuffle the vector multiple times, printing the result to the terminal, for the user to visually
 * see if it looks like a random shuffling is occurring.
 */

#include "deck.h"
#include <vector>
#include <numeric>
#include <random>
#include <iostream>
#include <sstream>

void printVector(const std::vector<int>& vect)
{
    std::stringstream outbuffer;
    for (const auto& value : vect)
    {
        outbuffer << value << ", ";
    }
    
    std::cout << outbuffer.str() << "\n";
}

int main(int argc, char** argv)
{

    std::vector<int> testVector(10);
    std::iota(testVector.begin(), testVector.end(), 1); // fill vector from 1 to size-1

    std::random_device randomSeeder;
    std::mt19937 mtGen(randomSeeder()); // randomly seed mt19937

    std::cout << "Initial vector: \n";
    printVector(testVector);
    std::cout << "Knuth shuffles: \n";
    for (int i = 0; i < 10; i ++)
    {
        doc::knuthShuffle(testVector, mtGen);
        printVector(testVector);
    }

    return 0;
}

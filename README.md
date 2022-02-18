# deck-of-cards
Deck of Cards

## Principle of Least Surprise
A component of a system should behave in a way that most users will expect it to behave.
The behavior should not astonish or surprise users.
Formally: "If a necessary feature has a high astonishment factor, it may be necessary to redesign the feature."

### Build Test Scripts
You can build the included test scripts using cmake. 
There is a test script for:
- The Knuth shuffle algorithm [link](test/knuth_shuffle_test.cpp)
- Deck class, which shuffles and deals a Deck of PlayingCard objects [link](test/shuffle_deal_test.cpp)
- WarCardGame class, which runs an automated game of the War card game, written using the Deck and PlayingCard classes. [link](test/war_card_game_test.cpp)
```
mkdir build
cd build
cmake ..
cmake --build .
```

## Classes

### Deck
file: [deck.h](include/deck.h)

### PlayingCard
files: [playing_card.h](include/playing_card.h), [playing_card.cpp](src/playing_card.cpp)

### WarCardGame
files: [war_card_games.h](include/war_card_games.h), [war_card_games.cpp](src/war_card_games.cpp)

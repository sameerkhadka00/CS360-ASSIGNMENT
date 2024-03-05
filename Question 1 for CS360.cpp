#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::shuffle
#include <random>    // for std::default_random_engine
#include <ctime>     // for std::time

class Card {
private:
    int face;
    int suit;
    static const std::vector<std::string> faces;
    static const std::vector<std::string> suits;

public:
    Card(int f, int s) : face(f), suit(s) {}

    std::string toString() const {
        return faces[face] + " of " + suits[suit];
    }
};

const std::vector<std::string> Card::faces = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const std::vector<std::string> Card::suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards {
private:
    static const int totalCards = 52;
    std::vector<Card> deck;
    int currentCard;

public:
    DeckOfCards() {
        currentCard = 0;
        for (int count = 0; count < totalCards; ++count) {
            deck.push_back(Card(count % 13, count % 4));
        }
    }

    void shuffle() {
        std::default_random_engine rng(std::time(nullptr));
        std::shuffle(deck.begin(), deck.end(), rng);
    }

    Card dealCard() {
        return deck[currentCard++];
    }

    bool moreCards() const {
        return currentCard < totalCards;
    }
};

int main() {
    DeckOfCards deck;
    deck.shuffle();

    std::cout << "Dealing the shuffled deck of cards:\n";
    while (deck.moreCards()) {
        std::cout << deck.dealCard().toString() << std::endl;
    }

    return 0;
}

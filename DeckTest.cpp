#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

int main()
{
    Deck<Card> deck;

    for (Rank rank = Rank::Ace; rank <= Rank::King; ++rank)
    {
        for (Suit suit = Suit::Clubs; suit <= Suit::Spades; ++suit)
        {
            deck.add(Card(rank, suit));
        }
    }

    deck.shuffle();

    while (!deck.empty())
    {
        std::cout << deck.draw() << "\n";
    }

    std::cout << "\n\n";
    std::cin.get();
}

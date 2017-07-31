#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

int main()
{
    Deck<Card> deck;

	// add standard 52 cards to deck
    for (Rank rank = Rank::Ace; rank <= Rank::King; ++rank)
    {
        for (Suit suit = Suit::Clubs; suit <= Suit::Spades; ++suit)
        {
            deck.add(Card(rank, suit));
        }
    }
	
	// shuffle, draw, and print each card
    deck.shuffle();
	
    while (!deck.empty())
    {
        std::cout << deck.draw() << "\n";
    }
}
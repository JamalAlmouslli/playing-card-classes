#ifndef CARD_HPP
#define CARD_HPP

#include <iosfwd>
#include <string>

#include <boost/unordered_map.hpp>

enum class Rank : char
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum class Suit : char
{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

class Card
{
private:
    static const boost::unordered_map<Rank, char> ranks;
    static const boost::unordered_map<Suit, char> suits;

    Rank r;
    Suit s;

public:
    Card() = delete;
    Card(Rank rank, Suit suit);
    const std::string to_string() const;
    const Rank& rank() const noexcept;
    const Suit& suit() const noexcept;
};

std::ostream& operator<<(std::ostream& out, Card const& obj);
Rank& operator++(Rank& rank);
Suit& operator++(Suit& suit);
Rank& operator--(Rank& rank);
Suit& operator--(Suit& suit);

#endif

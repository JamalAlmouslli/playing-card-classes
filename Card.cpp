#include "Card.hpp"
#include <ostream>

#include <boost/assign.hpp>

const boost::unordered_map<Rank, char> Card::ranks = boost::assign::map_list_of
    (Rank::Ace,   'A')
    (Rank::Two,   '2')
    (Rank::Three, '3')
    (Rank::Four,  '4')
    (Rank::Five,  '5')
    (Rank::Six,   '6')
    (Rank::Seven, '7')
    (Rank::Eight, '8')
    (Rank::Nine,  '9')
    (Rank::Ten,   'T')
    (Rank::Jack,  'J')
    (Rank::Queen, 'Q')
    (Rank::King,  'K');

const boost::unordered_map<Suit, char> Card::suits = boost::assign::map_list_of
    (Suit::Clubs,    'C')
    (Suit::Diamonds, 'D')
    (Suit::Hearts,   'H')
    (Suit::Spades,   'S');

Card::Card(Rank rank, Suit suit)
    : r(rank)
    , s(suit)
{}

const std::string Card::to_string() const
{
    return { '[', ranks.at(r), suits.at(s), ']' };
}

const Rank& Card::rank() const noexcept
{
    return r;
}

const Suit& Card::suit() const noexcept
{
    return s;
}

std::ostream& operator<<(std::ostream& out, Card const& obj)
{
    return out << obj.to_string();
}

Rank& operator++(Rank& rank)
{
    return rank = Rank(static_cast<int>(rank)+1);
}

Suit& operator++(Suit& suit)
{
    return suit = Suit(static_cast<int>(suit)+1);
}

Rank& operator--(Rank& rank)
{
    return rank = Rank(static_cast<int>(rank)-1);
}

Suit& operator--(Suit& suit)
{
    return suit = Suit(static_cast<int>(suit)-1);
}

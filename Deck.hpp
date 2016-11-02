#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <random>

#include <boost/container/vector.hpp>

template <typename Card>
class Deck
{
private:
	static std::random_device rd;
	static std::mt19937 rng;

	boost::container::vector<Card> original;
	boost::container::vector<Card> playable;

public:
	void add(Card const& card);
	Card draw();
	void reset();
	void shuffle();
	void clear() noexcept;
	auto size() const noexcept;
	bool empty() const noexcept;
};

template <typename Card>
std::random_device Deck<Card>::rd;

template <typename Card>
std::mt19937 Deck<Card>::rng(Deck<Card>::rd());

template <typename Card>
inline void Deck<Card>::add(Card const& card)
{
	original.push_back(card);
	playable.push_back(card);
}

template <typename Card>
inline Card Deck<Card>::draw()
{
	const Card top(playable.back());
	playable.pop_back();
	return top;
}

template <typename Card>
inline void Deck<Card>::reset()
{
	playable = original;
}

template <typename Card>
inline void Deck<Card>::shuffle()
{
	std::shuffle(
		playable.begin(), playable.end(), rng);
}

template <typename Card>
inline void Deck<Card>::clear() noexcept
{
	original.clear();
	playable.clear();
}

template <typename Card>
inline auto Deck<Card>::size() const noexcept
{
	return playable.size();
}

template <typename Card>
inline bool Deck<Card>::empty() const noexcept
{
	return playable.empty();
}

#endif
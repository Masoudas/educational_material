/**
* The card game exercise suggested in this chapter.
* 
* To make matters more interesting, when players deal the four cards, we remove all equivalent pairs.
* But how do we do that? Well, we need to extract equivalent cards and remove them. There are a million ways
* we can do this, including using hashmaps. But the heap based solution seems the best, in that I heapify based
* on index, and then remove equivalent indexes. This method requires less storage than map based methods for 
* detecting unique cards.
* 
* The game is stupid, in the sense that there might be situations, where the game never ends. For example, if
* three players deal the same card. Ok, now I see why the exercise suggets removing only two cards at a time.
*/
#include <array>
#include <algorithm>
#include <random>
#include <list>
#include <iostream>
#include <sstream>

struct card {
	int number;
	enum suits {
		SPADES=0, HEARTS, DIAMONDS, CLUBS
	};

	suits suit;

	std::string to_string() {
		std::ostringstream o{};
		if (number > 0 && number < 10) {
			o << number << " of ";
		}
		else {
			switch (number) {
			case 0:
				o << "Ace of ";
				break;
			case 10:
				o << "Jack of ";
				break;
			case 11:
				o << "Queen of ";
				break;
			case 12:
				o << "King of ";
				break;
			}
		}

		switch (suit)
		{
		case CLUBS:
			o << "Clubs";
			break;
		case SPADES:
			o << "Spades";
			break;
		case DIAMONDS:
			o << "Diamonds";
			break;
		case HEARTS:
			o << "Hearts";
			break;
		}

		return o.str();
	}

	friend suits operator++(suits& m, int) {
		suits temp = m;
		m = static_cast<suits>(m + 1);
		return temp;
	}

	friend suits& operator++(suits& m) {
		m = static_cast<suits>(m + 1);
		return m;
	}

	bool operator==(const card& other) {
		return this->number == other.number;
	}

	bool operator<(const card& other) {
		return this->number < other.number;
	}
};

struct game {
	std::array<card, 13 * 4> deck{};

	std::vector<card> p1{}, p2{}, p3{}, p4{};

	void buildDeck() {
		for (auto suit = card::SPADES; suit <= card::CLUBS; ++suit) {
			for (int i = 0; i < 13; i++)
				deck[13 * suit + i] = card{ i, suit };
		}
	}

	void dealCards() {
		std::random_device rd{};
		std::mt19937 g{ rd() };

		std::shuffle(deck.begin(), deck.end(), g);

		p1 = { deck.begin(), deck.begin() + 13 };
		p2 = { deck.begin() + 13, deck.begin() + 26 };
		p3 = { deck.begin() + 26, deck.begin() + 39 };
		p4 = { deck.begin() + 39, deck.end() };
	}

	void reshuffle() {
		std::random_device rd{};
		std::mt19937 g{ rd() };

		for (int n = 0; n < 4; n++) {
			std::shuffle(this->operator[](n).begin(), this->operator[](n).end(), g);
		}
	}

	std::vector<card>& operator[](int n) {
		switch (n)
		{
		case 1:
			return p1;
		case 2:
			return p2;
		case 3:
			return p3;
		default:
			return p4;
		}
	}
};


void play_single_hand(game& g) {
	std::vector<int> index{ 0, 1, 2, 3 };

	auto cp = [&](int left, int right) {return g[left].back() < g[right].back(); };
	std::make_heap(index.begin(), index.end(), cp);

	int n = 4;
	while (n > 0) {
		std::pop_heap(index.begin(), index.begin() + n--, cp);
		
		int k = 0;
		card c = g[index[n]].back();
		while (n > 0 && g[index[0]].back() == c) {
			k++;
			g[index[n]].pop_back();
			std::pop_heap(index.begin(), index.begin() + n--, cp);
		}

		if (k > 0) {
			g[index[n]].pop_back();

		}
	}	
}

//int main() {
//	game g{};
//	g.buildDeck();
//	g.dealCards();
//
//	while (g[0].size() != 0 && g[1].size() != 0 && g[2].size() != 0 && g[3].size() != 0) {
//		play_single_hand(g);
//		g.reshuffle();
//	}
//	
//	std::cout << "Winners are: ";
//	for (int n = 0; n < 4; n++) {
//		if (g[n].size() == 0) {
//			std::cout << n << "\t";
//		}
//	}
//
//}
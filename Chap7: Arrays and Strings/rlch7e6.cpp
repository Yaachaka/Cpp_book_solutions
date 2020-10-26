/*
--PROGRAM NAME: rlch7e6.cpp
--PROGRAM STATEMENT: In the game of contract bridge, each of four players is 
dealt 13 cards, thus exhausting the entire deck. Modify the CARDARAY program in 
this chapter so that, after shuffling the deck, it deals four hands of 13 cards 
each. Each of the four players’ hands should then be displayed.
*/
#include<iostream>
#include<cstdlib>			//for srand(), rand()
#include<ctime>			//for time() 
using namespace std;

enum Suit {clubs, diamonds, hearts, spades};
//cards from 2 to 10 are integers without names.
const int jack=11;
const int queen=12;
const int king=13;
const int ace=14;

class card		//Each card is specified with a number and suit.
{
	private:
		int number;	//2 to 10, jack, queen, king, ace.
		Suit suit;	//clubs, diamonds, hearts, spades.
	public:
		card(){}		//card constructor
		void set(int n, Suit s)		//Specify a card number and its suit.
			{suit=s;number=n;}
		void display()const;		//Display card number and suit.
};

class players		//Each player holds 13 cards. Each card has a number and belong to a suit.
{
	private:
		card cards[13];
	public:
		void cset(card d,int i)	//i-th card in player's hand with it's no. and suit.
			{cards[i]=d;}
		void disphand()const;		//To display all cards held by the player.
};

int main()
{
	players p[4];		//4 players.
	card deck[52];		//A deck of cards containing all cards of all suits. 
	
	//Make an ordered deck
	for(int i=0;i<4;i++)	//for selecting suit.
		for(int j=2;j<15;j++)	//for selecting card number of the selected suit.
			deck[i*13+j-2].set(j,Suit(i));	//filling the deck.
	
	//Displaying ordered deck
	cout<<"\nOrdered deck:\n";
	for(int i=0;i<52;i++)
	{
		cout<<"  ";	//setting space.
		deck[i].display();
		if(!((i+1)%13))	//new line after every 13 cards
			cout<<endl;
	}
	
	//Shuffling cards in the deck.
		//for each card in the deck, pick another card at random and swap them.
	srand(time(0));	//seed random numbers with time.
	for(int i=0;i<52;i++)
	{
		int k=rand()%52;	//random integer between 0 and 51, includung 0 and 51.
		card temp=deck[i];
		deck[i]=deck[k];
		deck[k]=temp;
	}
	
	//Displaying shuffled deck.
	cout<<"\n\nShuffled deck: \n";
	for(int i=0;i<52;i++)
	{
		cout<<"  ";
		deck[i].display();
		if(!((i+1)%13))	//After displaying 13 cards go to next line.
			cout<<endl;
	}
	
	//Dealing 4 hands of 13 cards each (clockwise).
	for(int i=0,j=0;i<52;i++,j+=25)
		p[i%4].cset(deck[i],int(j/100));
		//p[0].card[0]=deck[0]
		//p[1].card[0]=deck[1]
		//p[2].card[0]=deck[2]
		//p[3].card[0]=deck[3]
		//p[0].card[1]=deck[4]
		//p[1].card[1]=deck[5]
		//goes on.. until last card of the deck.
	
	//Displaying each player's hand.
	for(int i=0;i<4;i++)
	{
		cout<<"Hand of player "<<i<<":\n\t";
		p[i].disphand();
		cout<<endl;
	}
	return 0;
}

void card::display()const
{
	if(number>=2&&number<=10)
		cout<<number;
	else
		switch(number)
		{
			case jack:cout<<"J";break;
			case queen:cout<<"Q";break;
			case king:cout<<"K";break;
			case ace:cout<<"A";
			
		}
	switch(suit)
	{
		case clubs:cout<<"♣";break;	//equivalent unicode: 2663-black club suit, 2667-white club suit.
			//can also be written as: cout<<"\u2663";
		case diamonds:cout<<"♦";break;	//equivalent unicode: 2666-black diamond suit, 2662-white diamond suit.
		case hearts:cout<<"♥";break;	//equivalent unicode: 2665-black heart suit, 2661-white heart suit.
		case spades:cout<<"♠";	//equivalent unicode: 2660-black spade suit, 2664-white spade suit.
		
	}
}

void players::disphand()const
{
	for(int i=0;i<13;i++)
	{
		cout<<" ";
		cards[i].display();
	}
}
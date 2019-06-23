/* Accepted */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct card{
	char suit;
	int value;
};

void  playGame(vector <stack <card> > &cStack)//, vector <queue <card> > cQueue)
{
	int currInt = 13, noTurned = 0;
	card currCard;
	while(!cStack[currInt - 1].empty()){
		currCard = cStack[currInt - 1].top();
		cStack[currInt - 1].pop();
		noTurned++;
		currInt = currCard.value;
	}
	(noTurned < 10) ? cout << "0" << noTurned : cout << noTurned;
	cout << ",";
	switch(currCard.value){
		case 13:
			cout << "K";
			break;
		case 12:
			cout << "Q";
			break;
		case 11:
			cout << "J";
			break;
		case 10:
			cout << "T";
			break;
		default: 
			cout << currCard.value;
			break;
	}
	cout << currCard.suit << "\n";
}

void assign(stack <string> &entradas)
{
	vector <stack <card> > cardStack (13);
	int currInt = 0;
	string cardIn;
	while(!entradas.empty()){
		cardIn = entradas.top();
		card nueva;
		nueva.suit = cardIn[1];
		char valor = cardIn[0];
		switch(valor){
			case 'J':
				nueva.value = 11;
				break;
			case 'Q':
				nueva.value = 12;
				break;
			case 'K':
				nueva.value = 13;
				break;
			case 'T':
				nueva.value = 10;
				break;
			case 'A':
				nueva.value = 1;
				break;
			default:
				nueva.value = valor - '0';
				break;
		}
		cardStack[currInt].push(nueva);
		currInt++;
		currInt %= 13;
		entradas.pop();
	}
	playGame(cardStack);
}

void clean(stack <string> &entradas)
{
	while(!entradas.empty())	
		entradas.pop();
}

int main(void)
{
	string cardIn;
	char hTag;
	stack <string> entradas;
	int deck = 0;
	while(cin >> cardIn){
		if(cardIn == "#")
			return 0;
		entradas.push(cardIn);
		deck++;
		if(deck == 52){
			deck = 0;
			assign(entradas);
			clean(entradas);
		}
	}
	return 0;
}
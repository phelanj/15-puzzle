// Example program
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>


using namespace std;

int closed_nodes[4][4];
int open_nodes[4][4];

class node
{
	int xPos;
	int yPos;
	int lvl;
	int priority;
	int currentArr[4][4];

public:
	node(int xp, int yp, int l, int p) {
		xPos = xp; yPos = yp; lvl = l; priority = p;
	}
		int getXpos() { return xPos; }
		int getYpos() { return yPos; }
		int getLvl() { return lvl; }
		int getPrio() { return priority; }

		void updatePriority(const int & xDest, const int & yDest) {
			priority = lvl + manhattan(xDest, yDest)*10;
		}
		const int & manhattan(const int & xDest, const int & yDest)const {
			int xd, yd, e;
			xd = xDest - xPos;
			yd = yDest - yPos;

			e = abs(xd) + abs(yd);

			return e;
		}


	
};
class Puzzle {
	//int arraySize = 4;
	int puzzArr[4][4];
	int checked[4][4] = { { 1,2,3,4 },
	{ 5,6,7,8 },
	{ 9,10,11,12 },
	{ 13,14,15,0 } };

public:
	void set_values(int(*a)[4][4]);
	void print_current();
	void solve();
};

void Puzzle::set_values(int(*a)[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			puzzArr[i][j] = (*a)[i][j];
		}
	}
}

void Puzzle::print_current() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << puzzArr[i][j] << " ";
			if (j == 3) cout << endl;
		}
	}
}
void Puzzle::solve() {
	priority_queue<node> pq[2];
	int pqi;
	node* n0;
	node* m0;
	int pred[4][4];

	//reset closed / open
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			closed_nodes[x][y] = 0;
			open_nodes[x][y] = 0;
		}
	}

	//create first node, push to open nodes
	n0 = new node(0,0,0,0);
	n0->updatePriority(4, 4);
	pq[pqi].push(*n0);
	open_nodes[x][y] = n0->getPrio();

}

int main()
{
	int Puzz1[4][4] = { { 2,10,3,0 },
	{ 1,6,8,4 },
	{ 5,9,7,12 },
	{ 13,14,11,15 } };
	int(*ip)[4][4] = &Puzz1;

	Puzzle puz1;
	puz1.set_values(ip);
	puz1.print_current();
	cin.get();
	return 0;
}

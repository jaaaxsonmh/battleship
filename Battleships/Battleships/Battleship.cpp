#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>


using namespace std;

class BattleShip {
	string name;
	int length;

	BattleShip(string name, int length, string direction) {
		setName(name);
		//set lenght
		// set direction
	}

	string getName() {
		return name;
	}

	void setName(string shipName) {
		name = shipName;
	}

	string getLength() {
		return name;
	}

	string getDirection() {
		return name;
	}
};



class Grid {
private:
	const static int ROWS = 10; 
	const static int COLUMNS = 10;
	char grid[ROWS][COLUMNS]; 

public:
	void make() {
		for (int x = 0; x < ROWS; x++) {
			for (int y = 0; y < COLUMNS; y++) {
				grid[x][y] = '-';
			}
		}
	}

	void update(bool hit, int xPos, int yPos) {
		if (hit == true) {
			grid[xPos][yPos] = 'X';
		}
		else {
			grid[xPos][yPos] = 'O';
		}
	}

	void print() {
		char verticleAxisValue = 'A';

		cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
		for (int x = 0; x < ROWS; x++) {
			cout << verticleAxisValue << " ";
			verticleAxisValue++;
			for (int y = 0; y < COLUMNS; y++) {
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
	}
};

class Players {
private:
	const static int maximumShips = 5;

public:
	const static int ROWS = 10;
	const static int COLUMNS = 10;
	int grid[ROWS][COLUMNS];


	void resetGrid() {
		for (int y = 0; y < ROWS; y++) {
			for (int x = 0; x < COLUMNS; x++) {
				grid[y][x] = 0; // sets each matrix row and column to 0 this means no ships
			}
		}
	}

	void showGrid() {
		char verticleAxisValue = 'A';

		cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
		for (int x = 0; x < ROWS; x++) {
			cout << verticleAxisValue << " ";
			verticleAxisValue++;
			for (int y = 0; y < COLUMNS; y++) {
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
	}

	void setLocations() {
		
	}

	void setRandomlocation() {
		for (int i = 0; i < maximumShips; i++) {
			// create a random coordinate.
			int xPos = rand() % COLUMNS;
			int yPos = rand() % ROWS;
			
			// check if ship in first coord
			if (grid[xPos][yPos] != 1) {
				//pick random direction to place the ship, if the direction can't be placed, try the other direction.

			}
		}
	}

	bool attack(int xPos, int yPos) {
		if (grid[xPos][yPos] == 1) {
			// set the position to 2, this means hit
			grid[xPos][yPos] = 2;
			return true;
		}
		return false;
	}
};

int main()
{
	bool wantsToPlay = true;

	do {
		//TODO: define the players human and cpu,
		// clear grids for players (clear the matrix)
		Players player;
		Players cpu;

		player.resetGrid();
		cpu.resetGrid();

		Grid playerGrid;
		Grid cpuGrid;

		playerGrid.make();
		playerGrid.print();

		cpuGrid.make();
		cpuGrid.print();

		// set the ships for players
		cpu.setLocations();
		player.setLocations();

		// Some game logic desc

		// cpu picks a location
		int attackPosX = rand() % cpu.COLUMNS;
		int attackPosY = rand() % cpu.ROWS;


		if (cpu.attack(attackPosX, attackPosY)) {
			cpuGrid.update(true, attackPosX, attackPosY);
			// do some logic here to say the cpu has hit a boat, and remove a life from that boat
			// or sink it
			cout << "The Computer has hit! " << "(" << attackPosX << ", " << attackPosY << ")" << endl;
		}
		else {
			cpuGrid.update(false, attackPosX, attackPosY);
			cout << "The Computer has missed! " << "(" << attackPosX << ", " << attackPosY << ")" << endl;
		}
		
		string attackPosHumanY;

		//human input 
		cout << "Please input the location on the grid you think a battleship is (e.g A 2): "; // prompts the user to enter co-ordinates.

		cin >> attackPosHumanY >> attackPosX; // takes the keyboard input and stores it in position 

		while (cin.fail()) // this will inintiate if the user enters a non integer input.
		{
			cin.clear(); // clears the cin.
			cin.ignore(); // ignores so it does not go in to an infinite loop
			cout << "try again: "; cin >> attackPosHumanY >> attackPosX; // re prompts the user to enter their input
		}
		// cast the character/string into a coordinate 

		if (player.attack(attackPosX, attackPosHumanY)) {
			cpuGrid.update(true, attackPosX, attackPosHumanY);
			// do some logic here to say the cpu has hit a boat, and remove a life from that boat
			// or sink it
			cout << "you have hit! " << "(" << attackPosX << ", " << attackPosHumanY << ")" << endl;
		}
		else {
			playerGrid.update(false, attackPosX, attackPosY);
			cout << "you have hit! missed! " << "(" << attackPosX << ", " << attackPosHumanY << ")" << endl;
		}

	} while (wantsToPlay == true);
}

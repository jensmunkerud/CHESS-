#pragma once
#include "mainWindow.h"
#include "pieces/types.h"
#include "saveGame.h"
#include "loadGame.h"

class Cell; // Forward declaration, since we use a pointer this works. Full includ in .cpp file
class Game {
	public:
	MainWindow& mainWindow;
	void viewGame();
	void refreshBoard();
	void clearPaths();
	void drawPath(Position pos);
	void makeMove(Position pos);
	Team checkCell(Position pos);
	Game(MainWindow& mw);
	std::vector<std::vector<Cell*>> board;
	Cell* selectedCell;
	bool isViewingGame = false;
	// Dont need destructor here?? Freeing the board vector
	// gives malloc double free error, think animationwindow takes care of this :)
	
	private:
	bool whiteTurn = true;
	SaveGame* saveGame;
	LoadGame* loadGame;
};




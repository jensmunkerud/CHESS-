#pragma once
#include "cell.h"
#include "mainWindow.h"

class Game {
	public:
	MainWindow& mainWindow;
	void saveGame();
	void loadGame();
	void refreshBoard();
	Team checkCell(Position pos);
	Game(MainWindow& mw);
	// Dont need destructor here?? Freeing the board vector
	// gives malloc double free error, think animationwindow takes care of this :)

	private:
	std::vector<std::vector<Cell*>> board;
	bool isSelected;
	bool whiteTurn;
};




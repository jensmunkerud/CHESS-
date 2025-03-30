#pragma once
#include "mainWindow.h"
#include "pieces/types.h"


class Cell;
class Game {
	public:
	MainWindow& mainWindow;
	void saveGame();
	void loadGame();
	void refreshBoard();
	Team checkCell(Position pos);
	Game(MainWindow& mw);
	std::vector<std::vector<Cell*>> board;
	// Dont need destructor here?? Freeing the board vector
	// gives malloc double free error, think animationwindow takes care of this :)

	private:
	bool isSelected;
	bool whiteTurn;
};




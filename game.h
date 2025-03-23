#pragma once
// #include "pieces/piece.h"
// #include "pieces/bishop.cpp"
#include "cell.h"
#include "mainWindow.h"
#include "pieces/types.h"

class Game {
	public:
	MainWindow mainWindow;
	void saveGame();
	void loadGame();
	void refreshBoard();
	// Piece* checkCell(Position pos);
	Game();
	// Dont need destructor here?? Freeing the board vector
	// gives malloc double free error, think animationwindow takes care of this :)

	private:
	std::vector<std::vector<Cell*>> board;
	bool isSelected;
	bool whiteTurn;
};




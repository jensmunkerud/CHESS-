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
	void promotePiece(Position pos);
	void turnOnSavegame();
	Team checkCell(Position pos); // eg. putting own king in check
	Game(MainWindow& mw);
	std::vector<std::vector<Cell*>> board;
	Cell* selectedCell;
	bool isViewingGame = false;
	bool whiteTurn = true;
	// Dont need destructor here?? Freeing the board vector
	// gives malloc double free error, think animationwindow takes care of this :)
	
	private:
	void undoMode(...); // Used when checking if the move is valid or not
	void nextMove(); // viewGame function
	void prevMove(); // viewGame function
	void loadMoves(std::vector<rawPiece> data);
	TDT4102::Button* nextBtn;
	TDT4102::Button* prevBtn;
	bool isSaving;
	std::vector<rawPiece> data;
	SaveGame* saveGame;
	LoadGame* loadGame;
};




#include "pieces/piece.h"
#include "pieces/bishop.cpp"
#include "mainWindow.h"
#include "iostream"

class Cell {
	public:
	MainWindow mainWindow;
	Game& game;
	Cell(MainWindow& mainWindow, Game& game, Position physicalPosition, Position pos);
	TDT4102::Button* btn;
	void clear();
	void setPiece(Piece* p);
	bool hasPiece();
	void update(MainWindow& mainWindow);
	Position pos; // This cells index on the map
	Position physicalPosition; // This cells graphical location
	Piece* piece; // The piece that is on this cell (nullptr if no piece)
	
	private:
	void btnPressed();
};
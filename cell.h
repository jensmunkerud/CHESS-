#include "pieces/piece.h"
#include "mainWindow.h"

class Cell {
	public:
	Position pos; // This cells index on the map
	Position physicalPosition; // This cells graphical location
	Cell() : piece{nullptr} {}
	void clear();
	void setPiece(Piece* p);
	bool hasPiece();
	void update(MainWindow& mainWindow);
	private:
	Piece* piece; // The piece that is on this cell (nullptr if no piece)
};
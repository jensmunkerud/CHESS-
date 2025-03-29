#pragma once
#include "pieces/bishop.cpp"
#include "pieces/pawn.cpp"
#include "pieces/rook.cpp"
#include "pieces/knight.cpp"
#include "pieces/king.cpp"
#include "pieces/queen.cpp"
#include "mainWindow.h"
#include "iostream"

class Cell {
	public:
	MainWindow& mainWindow;
	Cell(MainWindow& mainWindow, Position physicalPosition, Position pos);
	TDT4102::Button* btn;
	TDT4102::Color col;
	static constexpr int offset = 2;
	void clear();
	void setPiece(Piece* p);
	bool hasPiece();
	void update();
	Position pos; // This cells index on the map
	Position physicalPosition; // This cells graphical location
	Piece* piece; // The piece that is on this cell (nullptr if no piece)
	
	private:
	void btnPressed();
};
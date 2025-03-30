#pragma once
#include "mainWindow.h"
#include "iostream"
#include "game.h"

class Piece;
class Cell {
	public:
	MainWindow& mainWindow;
	Game& game;
	Cell(MainWindow& mainWindow, Game& game, Position physicalPosition, Position pos);
	TDT4102::Button* btn;
	TDT4102::Color col;
	// These offsets are because the TDT4102::Button is not centered.. It seems to have padding
	static constexpr int offset = 2;
	int centerOffset = mainWindow.dimension / 16 + offset;
	void clear();
	void setPiece(Piece* p);
	bool hasPiece();
	void update();
	Position pos; // This cells index on the map
	Position physicalPosition; // This cells graphical location
	Piece* piece; // The piece that is on this cell (nullptr if no piece)
	bool drawPath;
	
	private:
	void btnPressed();
	bool isSelected = false;
};
#pragma once
#include <vector>
#include "types.h"


// ROOT CLASS FOR ALL PIECES
class Piece {
	public:
	Color col;
	Type type;
	Position pos;
	Piece(Color col, Type type, Position pos, bool canBeBlocked, bool infRange);
	virtual void updateValidPositions();
	
	private:
	bool canBeBlocked = false;
	bool infRange = false;
	std::string filePath;
	std::vector<Position> validPositions;
};
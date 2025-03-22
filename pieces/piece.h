#pragma once
#include <vector>
#include "types.h"


// ROOT CLASS FOR ALL PIECES
class Piece { 
	public:
	Team col;
	Type type;
	Position pos;
	std::string filePath;
	Piece(Team col, Type type, Position pos, bool canBeBlocked, bool infRange) :
	col{col}, type{type}, pos{pos}, canBeBlocked{canBeBlocked}, infRange{infRange} {};
	virtual ~Piece() {};
	
	protected:
	bool canBeBlocked = false;
	bool infRange = false;
	std::vector<Position> validPositions;
	virtual void updateValidPositions(const std::vector<std::vector<Piece*>>& board)
	{validPositions.clear();};
};
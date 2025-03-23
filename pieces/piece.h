#pragma once
#include <vector>
#include "types.h"
// #include "game.h"
class Game;


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
	virtual void updateValidPositions(const Game& gamee)
	{validPositions.clear();};
	
	protected:
	bool canBeBlocked = false;
	bool infRange = false;
	std::vector<Position> validPositions;
};
#pragma once
#include <vector>
#include "types.h"
#include "iostream"
// #include "cell.h"
#include "../game.h"

// ROOT CLASS FOR ALL PIECES
class Piece { 
	public:
	Team team;
	Type type;
	Position pos;
	std::string filePath;
	virtual void updateValidPositions(Game& game);  // This func gets run before the class specific ones

	Piece(Team team, Type type, Position pos);
	// virtual ~Piece() = default;

	protected:
	// WE NEED TWO SINCE THE VALIDPOSITIONS SHOULD BE CHECKMATE TESTED!!
	std::vector<Position> testPositions; // updateValidPositions calculates testPositions
	std::vector<Position> validPositions; // and turns valid locations into validPositions
};
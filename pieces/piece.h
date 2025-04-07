#pragma once
#include <vector>
#include "types.h"
#include "iostream"
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
	virtual ~Piece() = default;

	protected:
	const Team enemy;
	void addPosition(Game& game, Position pos);
	std::vector<Position> validPositions;
};
#pragma once
#include <vector>
#include "types.h"
#include "iostream"


// ROOT CLASS FOR ALL PIECES
class Piece { 
	public:
	Team team;
	Type type;
	Position pos;
	std::string filePath;
	virtual void updateValidPositions()
	{validPositions.clear();};

	// Constructor HAS to be defined here for some reason..
	Piece(Team team, Type type, Position pos) :
		team{team}, type{type}, pos{pos}
		{
			filePath = typeToPath.at(type);
			if (team == Team::BLACK) {
				filePath += "1.png";
			} else {
				filePath += ".png";
			}
		};

	protected:
	std::vector<Position> testPositions; // updateValidPositions calculates testPositions
	std::vector<Position> validPositions; // and turns valid locations into validPositions
};


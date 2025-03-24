#pragma once
#include "piece.cpp"
#include <iostream>

class Blockable : public Piece {
	public:
	std::vector<Position> relativeDirections;

	// This function MIGHT be necessary JUST for children to add their relative directions
	Blockable(Team team, Type type, Position pos, const std::vector<Position>& directions) : 
	Piece(team, type, pos), relativeDirections{directions} {
		for (Position& p : relativeDirections) {
			std::cout << "I am a position: " << p.x << ", " << p.y << std::endl;
		}
	}

	// From relative directions, we add each cell in that direction until we hit 
	// board limits or another piece, to Pieces' testPositions
	void updateValidPositions() override {
		Piece::updateValidPositions();
		for (Position p : relativeDirections) {
			for (int range = 1; range < 8; range++) {
				Position testPos {pos.x + p.x*range, pos.y + p.y*range};
				std::cout << "LEZGO" << std::endl;
				// if (gamee.checkCell(testPos) != nullptr) {
				// 	// The board has no pieces on this location
				// 	relativeDirections.push_back(testPos);
				// } else {break;}
			}
		}
	}
};
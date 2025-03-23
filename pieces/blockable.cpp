#include "piece.h"
#include <iostream>

class Blockable : public Piece {
	public:
	std::vector<Position> relativeDirections;

	// This function MIGHT be necessary JUST for children to add their relative directions
	Blockable(Team col, Type type, Position pos, bool canBeBlocked, bool infRange, const std::vector<Position>& directions) : 
	Piece(col, type, pos, canBeBlocked, infRange), relativeDirections{directions} {
		for (Position& p : relativeDirections) {
			std::cout << "I am a position: " << p.x << ", " << p.y << std::endl;
		}
	}

	
	void updateValidPositions(const Game& gamee) override {
		std::cout << "We are trying" << std::endl;
		Piece::updateValidPositions(gamee);
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
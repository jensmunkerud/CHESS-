#include "piece.h"

class Blockable : public Piece {
	public:
	std::vector<Position> relativeDirections;

	void updateValidPositions(const std::vector<std::vector<Piece>>& board) override {
		Piece::updateValidPositions(board);
		for (Position p : relativeDirections) {

		}
	}

	// This function MIGHT be necessary JUST for children to add their relative directions
	Blockable(Color col, Type type, Position pos, bool canBeBlocked, bool infRange, const std::vector<Position>& directions) : 
	Piece(col, type, pos, canBeBlocked, infRange), relativeDirections{directions} {
		
	}
};
#include "piece.h"

class Pawn : public Piece {
	public:
	void updateValidPositions(const std::vector<std::vector<Piece>>& board) override {
		Piece::updateValidPositions(board);
		// Straight forward

		// Diagonal (if piece is of opposite color)
	}
};
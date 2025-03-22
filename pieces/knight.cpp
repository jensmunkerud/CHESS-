#include "piece.h"

class Pawn : public Piece {
	public:
	void updateValidPositions(const std::vector<std::vector<Piece>>& board) override {
		validPositions.clear();
	}
};
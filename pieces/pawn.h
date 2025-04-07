#pragma once
#include "piece.h"

class Pawn : public Piece {
	public:
	Pawn(Team team, Position pos);
	void updateValidPositions(Game& game) override;
	void testPromotion(Game& game);
	Position lastPos; // Used to calculate enPassant
	const int dir;
};
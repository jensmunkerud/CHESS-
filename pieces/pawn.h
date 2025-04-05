#pragma once
#include "piece.h"

class Pawn : public Piece {
	public:
	Pawn(Team team, Position pos);
	void updateValidPositions(Game& game) override;
	void testPromotion(Game& game);

	private:
	const int dir;
	const Team enemy;
};
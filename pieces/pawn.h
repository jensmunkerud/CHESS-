#pragma once
#include "piece.h"

class Pawn : public Piece {
	public:
	Pawn(Team team, Position pos) :
		Piece(team, Type::PAWN, pos) {};
	void updateValidPositions(Game& game) override {
		Piece::updateValidPositions(game);
		std::cout << "PAWN WANTS TO UPDATE POSITION" << std::endl;
		// Straight forward

		// Diagonal (if piece is of opposite color)
	}
};
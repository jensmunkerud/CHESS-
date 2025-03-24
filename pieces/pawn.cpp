#pragma once
#include "piece.cpp"

class Pawn : public Piece {
	public:
	Pawn(Team team, Position pos) :
		Piece(team, Type::PAWN, pos) {};
	void updateValidPositions() override {
		Piece::updateValidPositions();
		// Straight forward

		// Diagonal (if piece is of opposite color)
	}
};
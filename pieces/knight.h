#pragma once
#include "piece.h"

class Knight : public Piece {
	public:
	static constexpr std::array<Position, 8> KNIGHT_DIRECTIONS = {{
		{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}, {1, 2}, {-1, 2}
	}};
	Knight(Team team, Position pos) : Piece(team, Type::KNIGHT, pos) {}
	void updateValidPositions(Game& game) override;
};
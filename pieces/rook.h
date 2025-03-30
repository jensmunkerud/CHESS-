#pragma once
#include "blockable.h"

class Rook : public Blockable {
	public:
	static constexpr std::array<Position, 4> ROOK_DIRECTIONS = {{
		{1, 0}, {0, 1}, {-1, 0}, {0, -1}
	}};
	Rook(Team team, Position pos) : 
		Blockable(team, Type::ROOK, pos, 
		std::vector<Position>(ROOK_DIRECTIONS.begin(), ROOK_DIRECTIONS.end())) {}
	
	void updateValidPositions(Game& game) override {
		Blockable::updateValidPositions(game);
	};
};
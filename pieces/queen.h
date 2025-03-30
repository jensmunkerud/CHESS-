#pragma once
#include "blockable.h"

class Queen : public Blockable {
	public:
	static constexpr std::array<Position, 8> QUEEN_DIRECTIONS = {{
		{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}
	}};
	Queen(Team team, Position pos) : 
	Blockable(team, Type::QUEEN, pos, 
		std::vector<Position>(QUEEN_DIRECTIONS.begin(), QUEEN_DIRECTIONS.end())) {}
	
	void updateValidPositions(Game& game) override {
		Blockable::updateValidPositions(game);
	};
};
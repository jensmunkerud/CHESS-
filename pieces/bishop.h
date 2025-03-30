#pragma once
#include "blockable.h"

class Bishop : public Blockable {
	public:
	static constexpr std::array<Position, 4> BISHOP_DIRECTIONS = {{
		{1, 1}, {-1, 1}, {-1, -1}, {1, -1}
	}};
	Bishop(Team team, Position pos) : 
	Blockable(team, Type::BISHOP, pos, 
		std::vector<Position>(BISHOP_DIRECTIONS.begin(), BISHOP_DIRECTIONS.end())) {}
	
	void updateValidPositions(Game& game) override {
		Blockable::updateValidPositions(game);
	};
};
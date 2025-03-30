#pragma once
#include "piece.h"

class Blockable : public Piece {
	public:
	std::vector<Position> relativeDirections;

	Blockable(Team team, Type type, Position pos, const std::vector<Position>& directions);

	void updateValidPositions(Game& game) override;
	// virtual ~Blockable() = default;
};
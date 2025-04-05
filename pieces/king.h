#include "piece.h"

class King : public Piece {
	public:
	static constexpr std::array<Position, 8> KING_DIRECTIONS = {{
		{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}
	}};
	King(Team team, Position pos) : Piece(team, Type::KING, pos) {}
	void updateValidPositions(Game& game) override;
};
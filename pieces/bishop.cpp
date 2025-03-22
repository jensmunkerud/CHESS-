#include "blockable.cpp"

class Bishop : public Blockable {
	public:
	static constexpr std::array<Position, 4> BISHOP_DIRECTIONS = {{
		{1, 1}, {-1, 1}, {-1, -1}, {1, -1}
	}};
	Bishop(Team col, Position pos) : 
	Blockable(col, Type::BISHOP, pos, true, true, 
		std::vector<Position>(BISHOP_DIRECTIONS.begin(), BISHOP_DIRECTIONS.end())) {}
};
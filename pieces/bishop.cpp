#include "blockable.cpp"

class Bishop : public Blockable {
	public:
	// relativeDirections = {Position{0, 0}};
	void updateValidPositions(const std::vector<std::vector<Piece>>& board) override {
		// might not need this function override
		Blockable::updateValidPositions(board);
	}

	static constexpr std::array<Position, 4> BISHOP_DIRECTIONS = {{
		{1, 1}, {-1, 1}, {-1, -1}, {1, -1}
	}};
	// This is where relative directions are added
	Bishop(Color col, Type type, Position pos, bool canBeBlocked, bool infRange) : 
	Blockable(col, type, pos, canBeBlocked, infRange, std::vector<Position>(BISHOP_DIRECTIONS.begin(), BISHOP_DIRECTIONS.end())) {}
};
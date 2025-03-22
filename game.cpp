#include "game.h"


Piece getPosition(Position p, std::vector<std::vector<Piece>>* board) {
	return (*board).at(0).at(0);
}
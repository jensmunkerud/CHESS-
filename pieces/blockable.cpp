#include "blockable.h"
#include "../game.h"

Blockable::Blockable(Team team, Type type, Position pos, const std::vector<Position>& directions) : 
	Piece(team, type, pos), relativeDirections{directions} {}

// From relative directions, we add each cell in that direction until we hit 
// board limits or another piece, to Pieces' testPositions
void Blockable::updateValidPositions(Game& game) {
	Piece::updateValidPositions(game);
	for (Position p : relativeDirections) {
		for (int range = 1; range < 8; range++) {
			Position testPos {pos.x + p.x*range, pos.y + p.y*range};
			if (testPos.x > 7 || testPos.x < 0 || testPos.y > 7 || testPos.y < 0) {
				break;
			}
			// if (board.at(testPos.x).at(testPos.y) != nullptr) {
			// 	std::cout << "we have a path" << std::endl;
			// 	board.at(testPos.x).at(testPos.y)->drawPath = true;
			// }
			if (game.checkCell(testPos) == Team::NOTEAM) {
				
			}
		}
	}
}
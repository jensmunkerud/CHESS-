#include "blockable.h"

Blockable::Blockable(Team team, Type type, Position pos, const std::vector<Position>& directions) : 
	Piece(team, type, pos), relativeDirections{directions} {}

// From relative directions, we add each cell in that direction until we hit 
// board limits or another piece, to Pieces' testPositions
void Blockable::updateValidPositions(Game& game) {
	Piece::updateValidPositions(game);
	for (Position p : relativeDirections) {
		for (int range = 1; range < 8; range++) {
			Position testPos {pos.x + p.x*range, pos.y + p.y*range};
			// Filter out of board limits
			if (testPos.x > 7 || testPos.x < 0 || testPos.y > 7 || testPos.y < 0) {
				break;
			}
			if (game.checkCell(testPos) == Team::NOTEAM) {
				game.drawPath(testPos);
				validPositions.push_back(testPos);
			} else if (game.checkCell(testPos) != team) {
				// This piece is of opposite team and we MIGHT kill it
				game.drawPath(testPos);
				validPositions.push_back(testPos);
				break;
			} else {
				break;
			}
		}
	}
}
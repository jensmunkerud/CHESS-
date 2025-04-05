#include "knight.h"

void Knight::updateValidPositions(Game& game) {
	for (Position relPos : KNIGHT_DIRECTIONS) {
		Position testPos = Position{pos.x + relPos.x, pos.y + relPos.y};
		if (testPos.x > 7 || testPos.x < 0 || testPos.y > 7 || testPos.y < 0) {
			continue;
		}
		if (game.checkCell(testPos) != team) {
			addPosition(game, testPos);
		}	
	}
}
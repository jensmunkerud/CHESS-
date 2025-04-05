#include "piece.h"

Piece::Piece(Team team, Type type, Position pos) :
	team{team}, type{type}, pos{pos}
	{
		filePath = typeToPath.at(type);
		if (team == Team::BLACK) {
			filePath += "1.png";
		} else {
			filePath += ".png";
		}
};

void Piece::updateValidPositions(Game& game) // This func gets run before the class specific ones
	{validPositions.clear();};

void Piece::addPosition(Game& game, Position pos) {
	validPositions.push_back(pos);
	game.drawPath(pos);
}
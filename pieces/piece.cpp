#include "piece.h"


void Piece::updateValidPositions(Game& game) // This func gets run before the class specific ones
	{validPositions.clear(); std::cout << "PIECE UPDATE WAS RUN" << std::endl;};

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






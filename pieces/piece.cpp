#include "piece.h"
#include "types.h"


Piece::Piece(Team col, Type type, Position pos, bool canBeBlocked, bool infRange) :
col{col}, type{type}, pos{pos}, canBeBlocked{canBeBlocked}, infRange{infRange} 
{
	filePath = typeToPath.at(type);
	if (col == Team::BLACK) {
		filePath = filePath + "1.png";
	} else {
		filePath = filePath + ".png";
	}
};
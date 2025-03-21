#include "piece.h"
#include "types.h"


Piece::Piece(Color col, Type type, Position pos, bool canBeBlocked, bool infRange) :
col{col}, type{type}, pos{pos}, canBeBlocked{canBeBlocked}, infRange{infRange} 
{
	filePath = typeToPath.at(type);
	if (col == Color::BLACK) {
		filePath = filePath + "1.jpg";
	} else {
		filePath = filePath + ".jpg";
	}
};
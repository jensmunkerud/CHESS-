#include "pawn.h"

Pawn::Pawn(Team team, Position pos) :
	Piece(team, Type::PAWN, pos),
	dir{team == Team::BLACK ? 1 : -1} {}


void Pawn::updateValidPositions(Game& game) {
	Piece::updateValidPositions(game);
	lastPos = pos;
	if (pos.y == 1 && team == Team::BLACK || pos.y == 6  && team == Team::WHITE) {
		// Might move twice (first move)
		for (int i = 1; i < 3; i++) {
			if (game.checkCell(Position{pos.x, pos.y + dir*i}) == Team::NOTEAM) {
				addPosition(game, Position{pos.x, pos.y + dir*i});
			} else {break;}
		}
	} else {
		// Moving only once
		if (game.checkCell(Position{pos.x, pos.y + dir}) == Team::NOTEAM) {
			addPosition(game, Position{pos.x, pos.y + dir});
		}
	}
	// Diagonal checking
	for (int i = -1; i < 3; i+=2) {
		if (game.checkCell(Position{pos.x + i, pos.y + dir}) == enemy) {
			addPosition(game, Position{pos.x + i, pos.y + dir});
		}
	}
	
	if (game.enPassantEnabled) {
		if (abs(pos.x - game.enPassantLocation.x) == 1 && abs(pos.y - game.enPassantLocation.y) == 1) {
			// the enPassant location is within bounds
			addPosition(game, game.enPassantLocation);
		}
	}
}


void Pawn::testPromotion(Game& game) {
	if (pos.y == 7 && team == Team::BLACK || pos.y == 0 && team == Team::WHITE) {
		game.promotePiece(pos);
	}
}
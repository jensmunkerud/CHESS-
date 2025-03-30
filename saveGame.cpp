#include "saveGame.h"
#include "cell.h"
#include "pieces/piece.h"
// Each 64'th line is a complete game state, each 8th is a new row from top left
// Format:
// Team,Type

SaveGame::SaveGame(std::vector<std::vector<Cell*>> board) {
	myFile.open(filePath);
	saveGame(board);
}

// Adds a line to the savefile of the containing the whole board
void SaveGame::saveGame(std::vector<std::vector<Cell*>> board) {
	if (myFile.is_open()) {
		for (std::vector<Cell*> row : board) {
			for (Cell* c : row) {
				if (c->hasPiece()) {
					myFile << teamToName.at(c->piece->team) << "," << typeToName.at(c->piece->type)<< std::endl;
					continue;
				}
				myFile << teamToName.at(Team::NOTEAM) << std::endl;
			}
		}
	}
}

SaveGame::~SaveGame() {
	if (myFile.is_open()) {
		myFile.close();
	}
}

void makeSaveFile() {

}
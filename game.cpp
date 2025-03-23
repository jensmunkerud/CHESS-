#include "game.h"


Game::Game() {
	for (int rank = 0; rank < 8; rank++) {
		std::vector<Cell*> row;
		for (int file = 0; file < 8; file++) {
			Cell* c = new Cell(mainWindow, *this, {mainWindow.sidePad + rank*mainWindow.dimension/8, mainWindow.sidePad + file*mainWindow.dimension/8}, Position{rank, file});
			row.push_back(c);
			Piece* p = new Bishop(Team::BLACK, Position{100, 300});
			row.at(file)->setPiece(p);
			// row.at(i)->update(mainWindow);
		}
		board.push_back(row);
	}


	mainWindow.wait_for_close();
}

void Game::refreshBoard() {
	// for (std::vector<Cell&> row : board) {
	// 	for(Cell* c : row) {
	// 		c->update(mainWindow);
	// 	}
	// }
}


// Piece* Game::checkCell(Position pos) {
// 	return nullptr;
// }

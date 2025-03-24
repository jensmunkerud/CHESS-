#include "game.h"


Game::Game(MainWindow& mw) : mainWindow{mw} {
	for (int rank = 0; rank < 8; rank++) {
		std::vector<Cell*> row;
		for (int file = 0; file < 8; file++) {

			// Generates 8x8 grid of buttons
			Cell* c = new Cell(mainWindow, {mainWindow.sidePad + file*mainWindow.dimension/8, mainWindow.sidePad + rank*mainWindow.dimension/8}, Position{file, rank});
			row.push_back(c);
			Team team = rank < 4 ? Team::BLACK : Team::WHITE;

			// Populates row 1 & 6 with black / white pawns
			if (rank == 1 || rank == 6) {
				Piece* p = new Pawn(team, Position{file, rank});
				std::cout << file << std::endl;
				row.at(file)->setPiece(p);
			}
			
			if (rank == 0 || rank == 7) {
				Piece* p;
				switch (file) {
					// Populates rooks
					case 0:
					case 7:
						p = new Rook(team, Position{file, rank}); break;
					
					// Populates knights
					case 1:
					case 6:
						p = new Knight(team, Position{file, rank}); break;
					
					// Populates bishops
					case 2:
					case 5:
						p = new Bishop(team, Position{file, rank}); break;

					// Populates queens
					case 3:
						p = new Queen(team, Position{file, rank}); break;
						
					// Populates kings
					case 4:
						p = new King(team, Position{file, rank}); break;
				}
				row.at(file)->setPiece(p);
			}
		}
		board.push_back(row);
	}
}

void Game::refreshBoard() {
	for (std::vector<Cell*> row : board) {
		for(Cell* c : row) {
			c->update();
		}
	}
}


// Piece* Game::checkCell(Position pos) {
// 	return nullptr;
// }

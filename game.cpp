#include "game.h"
#include "cell.h"
#include "pieces/bishop.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/king.h"
#include "pieces/queen.h"

Piece* createNewPiece(Team team, Type type) { // THIS FUNCTION IS EXCLUSIVELY USED FOR VIEWING GAMES
	Position pos = Position{0, 0};
	Piece* p;
	switch (type) {
		case Type::BISHOP:
			p = new Bishop(team, pos); break;
		case Type::ROOK:
			p = new Rook(team, pos); break;
		case Type::PAWN:
			p = new Pawn(team, pos); break;
		case Type::KNIGHT:
			p = new Knight(team, pos); break;
		case Type::KING:
			p = new King(team, pos); break;
		case Type::QUEEN:
			p = new Queen(team, pos); break;
		default:
			std::cout << "UNEXPECTED ERROR WHEN VIEWING GAME" << std::endl;
	}
	return p;
}


Game::Game(MainWindow& mw) : mainWindow{mw} {
	for (int rank = 0; rank < 8; rank++) {
		std::vector<Cell*> row;
		for (int file = 0; file < 8; file++) {

			// Generates 8x8 grid of buttons
			Cell* c = new Cell(mainWindow, *this, {mainWindow.sidePad + file*mainWindow.dimension/8, mainWindow.sidePad + rank*mainWindow.dimension/8}, Position{file, rank});
			row.push_back(c);
			Team team = rank < 4 ? Team::BLACK : Team::WHITE;

			// Populates row 1 & 6 with black / white pawns
			if (rank == 1 || rank == 6) {
				Piece* p = new Pawn(team, Position{file, rank});
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

	// Initilizes save / load game
	isSaving = false;
	nextBtn = new TDT4102::Button(TDT4102::Button {{mainWindow.dimension/2+mainWindow.sidePad, 5}, 75, 50, "Next"});
	prevBtn = new TDT4102::Button(TDT4102::Button {{mainWindow.dimension/2-10, 5}, 75, 50, "Prev"});
	mainWindow.add(*nextBtn);
	mainWindow.add(*prevBtn);
	nextBtn->setCallback([&] () {nextMove();}); // USED AI FOR THIS LINE
	prevBtn->setCallback([&] () {prevMove();}); // USED AI FOR THIS LINE
	nextBtn->setVisible(isViewingGame);
	prevBtn->setVisible(isViewingGame);
}


void Game::turnOnSavegame() {
	saveGame = new SaveGame(board);
	isSaving = true;
}


void Game::refreshBoard() {
	for (std::vector<Cell*> row : board) {
		for(Cell* c : row) {
			c->update();
		}
	}
	if (selectedCell == nullptr) {
		clearPaths();
	}
}


Team Game::checkCell(Position pos) {
	if (pos.x > 7 || pos.x < 0 || pos.y > 7 || pos.y < 0) {
		return Team::NOTEAM;
	}
	if (board.at(pos.y).at(pos.x)->piece != nullptr) {
		return board.at(pos.y).at(pos.x)->piece->team;
	}
	return Team::NOTEAM;
}


void Game::clearPaths() {
	for (std::vector<Cell*> row : board) {
		for (Cell* c : row) {
			c->drawPath = false;
		}
	}
}


void Game::drawPath(Position pos) {
	if (pos.x > 7 || pos.x < 0 || pos.y > 7 || pos.y < 0) {
		std::cout << "Tested a position out of borders" << std::endl;
		return;
	}
	board.at(pos.y).at(pos.x)->drawPath = true;
}


void Game::makeMove(Position pos) {
	selectedCell->piece->pos = pos;
	board.at(pos.y).at(pos.x)->setPiece(selectedCell->piece);
	selectedCell->clear();
	selectedCell = nullptr;
	whiteTurn = !whiteTurn;
	if (Pawn* p = dynamic_cast<Pawn*>(board.at(pos.y).at(pos.x)->piece)) {
		if (enPassantEnabled) {
			// GO IN FOR THE KILL
			if (Pawn* P = dynamic_cast<Pawn*>(board.at(p->pos.y - p->dir).at(p->pos.x)->piece)) {
				board.at(p->pos.y - p->dir).at(p->pos.x)->clear();
			}
		}

		// Enables en passant if a pawn moved twice on its first move
		enPassantEnabled = std::abs(p->lastPos.y - p->pos.y) == 2;
		if (enPassantEnabled) {
			// The cell BEHIND the just moved pawn is now tagged as the enPassantLocation
			enPassantLocation = Position{p->pos.x, p->pos.y - p->dir};
		}
	} else {
		// enPassant must be done BY A PAWN in the NEXT MOVE
		enPassantEnabled = false;
	}
	if (isSaving) {saveGame->saveGame(board);}
}

void Game::promotePiece(Position pos) {
	Piece* p = new Queen(board.at(pos.y).at(pos.x)->piece->team, pos);
	board.at(pos.y).at(pos.x)->setPiece(p);
}


void Game::viewGame() {
	loadGame = new LoadGame();
	isViewingGame = loadGame->openFile();
	nextBtn->setVisible(isViewingGame);
	prevBtn->setVisible(isViewingGame);
}


void Game::nextMove() {
	loadMoves(loadGame->getNext(true));
}


void Game::prevMove() {
	loadMoves(loadGame->getNext(false));
}


void Game::loadMoves(std::vector<rawPiece> data) {
	// Wants to clear the whole board, populate the 64 cells with the right pieces
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			board.at(row).at(col)->clear();
			if (data.at(row*8 + col).team != Team::NOTEAM) {
				Piece* p = createNewPiece(data.at(row*8 + col).team, data.at(row*8 + col).type);
				board.at(row).at(col)->setPiece(p);
			}
		}
	}
}
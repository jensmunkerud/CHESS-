#include "cell.h"
#include "pieces/piece.h"
#include "pieces/pawn.h"

Cell::Cell(MainWindow& mainWindow, Game& game, Position physicalPosition, Position pos) :
	mainWindow{mainWindow}, game{game}, physicalPosition{physicalPosition} , pos{pos}{
	btn = new TDT4102::Button {TDT4102::Point{physicalPosition.x, physicalPosition.y}, static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), ""};
	mainWindow.add(*btn);
	btn->setCallback([&] () {btnPressed();});
	btn->setButtonColor(TDT4102::Color::beige);
	btn->setButtonColorActive(TDT4102::Color::beige);
	// Color here is not important, but when tdt4102::button CHANGES color,
	// we want to set alpha value to 1 (basically transparent)
	// NOTE! meson --reconfigure builddir RESETS this alpha value change
	// since it rebuilds the project...
	if ((pos.x + pos.y) % 2 == 0 ) {
		col = TDT4102::Color::beige;
	} else {
		col = TDT4102::Color::green;
	}
}

void Cell::clear() {
	piece = nullptr;
}

void Cell::setPiece(Piece* p) {
	piece = p;
	if (Pawn* P = dynamic_cast<Pawn*>(p)) { // USED AI
		P->testPromotion(game);
	}
}

bool Cell::hasPiece() {
	return piece != nullptr;
}

void Cell::update() {
	mainWindow.draw_rectangle(TDT4102::Point{physicalPosition.x + offset, physicalPosition.y + offset}, static_cast<uint>(mainWindow.dimension/8 + offset), static_cast<uint>(mainWindow.dimension/8 + offset), col);
	if (hasPiece()) {
		TDT4102::Image im (piece->filePath);
		mainWindow.draw_image(TDT4102::Point{physicalPosition.x + 8, physicalPosition.y + 10}, im, static_cast<uint>(mainWindow.dimension/10), static_cast<uint>(mainWindow.dimension/10));
	}
	if (drawPath) {
		mainWindow.draw_circle(TDT4102::Point{physicalPosition.x + centerOffset, physicalPosition.y + centerOffset}, 16, TDT4102::Color::grey);
	}
}

void Cell::btnPressed() {
	if (game.isViewingGame) {
		return;
	}
	// We are either a path or off the path
	if (game.selectedCell != nullptr) {
		if (!drawPath) {
			game.selectedCell = nullptr;
		} else {
			// A move might be made TO THIS cell!
			game.makeMove(pos);
		}
	} else {
		if (piece != nullptr) {
			if (piece->team == Team::WHITE && game.whiteTurn || piece->team == Team::BLACK && !game.whiteTurn) {
				piece->updateValidPositions(game);
				game.selectedCell = this;
			}
		}
	}
}

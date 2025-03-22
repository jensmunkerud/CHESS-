#include "cell.h"

void Cell::clear() {
	piece = nullptr;
}

void Cell::setPiece(Piece* p) {
	piece = p;
}

bool Cell::hasPiece() {
	return piece != nullptr;
}

void Cell::update(MainWindow& mainWindow) {
	TDT4102::Image im ("graphics/bishop.png");
	mainWindow.draw_image(TDT4102::Point{physicalPosition.x, physicalPosition.y}, im);
}
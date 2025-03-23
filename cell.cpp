#include "cell.h"

Cell::Cell(MainWindow& mainWindow, Game& game, Position physicalPosition, Position pos) :
	mainWindow{mainWindow}, game{game}, physicalPosition{physicalPosition} , pos{pos}{
	update(mainWindow);
	btn = new TDT4102::Button {TDT4102::Point{physicalPosition.x, physicalPosition.y}, static_cast<uint>(mainWindow.dimension/6), static_cast<uint>(mainWindow.dimension/6), ""};
	mainWindow.add(*btn);
	btn->setCallback([&] () {btnPressed();});
	if ((pos.x + pos.y) % 2 == 0 ) {
		btn->setButtonColor(TDT4102::Color::beige);
	} else {
		btn->setButtonColor(TDT4102::Color::green);
	}
}

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
	mainWindow.draw_image(TDT4102::Point{physicalPosition.x, physicalPosition.y}, im, static_cast<uint>(mainWindow.dimension/9), static_cast<uint>(mainWindow.dimension/9));
}

void Cell::btnPressed() {
	std::cout << "My position: " << pos.x  << ", " << pos.y << std::endl;
	if (piece != nullptr) {
		piece->updateValidPositions(game);
	} else {
		std::cout << "WE HAVE A NULLPTR" << std::endl;
	}
	// Was working here...
	// Just made a link between cell and piece, so that buttonpress will run the
	// updateValidPositions function on the cells' own piece!! sick
}

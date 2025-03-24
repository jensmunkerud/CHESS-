#include "cell.h"

Cell::Cell(MainWindow& mainWindow, Position physicalPosition, Position pos) :
	mainWindow{mainWindow}, physicalPosition{physicalPosition} , pos{pos}{
	btn = new TDT4102::Button {TDT4102::Point{physicalPosition.x, physicalPosition.y}, static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), ""};
	std::cout << mainWindow.dimension/8 << std::endl;
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

void Cell::update() {
	if (hasPiece()) {
		TDT4102::Image im (piece->filePath);
		mainWindow.draw_image(TDT4102::Point{physicalPosition.x + 8, physicalPosition.y + 10}, im, static_cast<uint>(mainWindow.dimension/10), static_cast<uint>(mainWindow.dimension/10));
	}
}

void Cell::btnPressed() {
	std::cout << "My position: " << pos.x  << ", " << pos.y << std::endl;
	if (piece != nullptr) {
		// piece->updateValidPositions();
		// update();
		setPiece(nullptr);
	} else {
		std::cout << "WE HAVE A NULLPTR" << std::endl;
	}
}

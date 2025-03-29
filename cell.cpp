#include "cell.h"

Cell::Cell(MainWindow& mainWindow, Position physicalPosition, Position pos) :
	mainWindow{mainWindow}, physicalPosition{physicalPosition} , pos{pos}{
	btn = new TDT4102::Button {TDT4102::Point{physicalPosition.x, physicalPosition.y}, static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), static_cast<uint>(mainWindow.dimension/8 + mainWindow.dimension/28), ""};
	std::cout << mainWindow.dimension/8 << std::endl;
	mainWindow.add(*btn);
	btn->setCallback([&] () {btnPressed();});
	btn->setButtonColor(TDT4102::Color::beige);
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
}

void Cell::btnPressed() {
	std::cout << "My position: " << pos.x  << ", " << pos.y << std::endl;
	if (piece != nullptr) {
		piece->updateValidPositions();
	} else {
		// Nothing happens here (cell is empty)
	}
}

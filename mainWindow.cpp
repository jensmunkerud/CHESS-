#include "mainWindow.h"
#include "Color.h"

MainWindow::MainWindow() : 
	AnimationWindow{posX, posY, windowWidth, windowHeight, title} {
	drawBoard();
	drawPieces();
	flipButton = new TDT4102::Button {{69, 69}, 100, 50, "flippy"};
	add(*flipButton);
};

void MainWindow::drawBoard() {
	int dimension = std::min(windowWidth, windowHeight) - 2*sidePad;
	for (int rank = 0; rank < 8; rank++) {
		std::vector<TDT4102::Button*> row;
		for (int file = 0; file < 8; file++) {
			// row.emplace_back(
			// TDT4102::Button{TDT4102::Point{sidePad + rank*dimension/8, sidePad + file*dimension/8}, 50, 50, "hey"}
			// );
			// add(row.at(file));
			// std::filesystem::path biskepusen {"graphics/bishop"};
			// TDT4102::Image* bishop = new TDT4102::Image {biskepusen};
			TDT4102::Button* btn = new TDT4102::Button {TDT4102::Point{sidePad + rank*dimension/8, sidePad + file*dimension/8}, static_cast<uint>(dimension/6), static_cast<uint>(dimension/6), ""};
			add(*btn);
			if ((file + rank) % 2 == 0 ) {
				btn->setButtonColor(TDT4102::Color::beige);
			} else {
				btn->setButtonColor(TDT4102::Color::green);
			}
			// row.push_back(std::move(btn));
		}
		// boardButtons.push_back(std::move(row));
	}
}

void MainWindow::drawPieces() {
	TDT4102::Image bishop ("graphics/bishop.png");
	for (int i = 0; i < 8; i++) {
		draw_image(TDT4102::Point{sidePad + i*400/8, sidePad + i*400/8}, bishop);
	}
}
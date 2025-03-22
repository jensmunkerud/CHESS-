#include "std_lib_facilities.h"
#include "mainWindow.h"
#include "pieces/bishop.cpp"
#include "pieces/types.h"
#include "iostream"
#include "game.h"

int main() {
	// Bishop peter {Team::BLACK, Position{0, 0}};
	// Bishop* peter = new Bishop(Team::BLACK, Position{100, 300});
	// MainWindow mainWindow;
	// Piece& peterRef = peter;
	// mainWindow.drawPiece(peter);
	// mainWindow.wait_for_close();
	Game game;
	// while(mainWindow.should_close()) {
	// 	peter->pos.x += 10;
	// 	if (peter->pos.x > 600) {
	// 		peter->pos.x = 0;
	// 	}
	// 	mainWindow.draw_circle(TDT4102::Point{peter->pos.x, peter->pos.y}, 50, TDT4102::Color::dark_green);
	// 	std::cout << "tick" << std::endl;
	// 	mainWindow.next_frame();
	// }
	// delete(peter);
	return 0;
}
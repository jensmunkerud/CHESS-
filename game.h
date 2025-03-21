#include "piece.h"

class Game {
	public:
	void saveGame();
	void loadGame();

	private:
	std::vector<std::vector<Piece>> board;
};
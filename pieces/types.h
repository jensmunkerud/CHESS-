#pragma once
#include <unordered_map>
#include <string>

enum class Team {
	BLACK,
	WHITE,
	NOTEAM
};

enum class Type {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

// 0x0
// |
// |
// |
// |
// 8x0-------8x8
// .at(y).at(x)

struct Position{
	int x;
	int y;
};

const std::unordered_map<Type, int> typeValue {
	{Type::PAWN, 1},
	{Type::KNIGHT, 3},
	{Type::BISHOP, 3},
	{Type::ROOK, 5},
	{Type::QUEEN, 9},
};

const std::unordered_map<Type, std::string> typeToPath {
	{Type::PAWN, "graphics/pawn"},
	{Type::KNIGHT, "graphics/knight"},
	{Type::BISHOP, "graphics/bishop"},
	{Type::ROOK, "graphics/rook"},
	{Type::QUEEN, "graphics/queen"},
	{Type::KING, "graphics/king"},
};


// The next types are used for SAVING / LOADING
const std::unordered_map<Type, std::string> typeToText {
	{Type::PAWN, "Pawn"},
	{Type::KNIGHT, "Knight"},
	{Type::BISHOP, "Bishop"},
	{Type::ROOK, "Rook"},
	{Type::QUEEN, "Queen"},
	{Type::KING, "King"},
};

const std::unordered_map<std::string, Type> textToType {
	{"Pawn", Type::PAWN},
	{"Knight", Type::KNIGHT},
	{"Bishop", Type::BISHOP},
	{"Rook", Type::ROOK},
	{"Queen", Type::QUEEN},
	{"King", Type::KING},
};

const std::unordered_map<Team, std::string> teamToText {
	{Team::BLACK, "BLACK"},
	{Team::WHITE, "WHITE"},
	{Team::NOTEAM, "NOTEAM"},
};

const std::unordered_map<std::string, Team> textToTeam {
	{"BLACK", Team::BLACK},
	{"WHITE", Team::WHITE},
	{"NOTEAM", Team::NOTEAM},
};

struct rawPiece {
	Team team;
	Type type;
};
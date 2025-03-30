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

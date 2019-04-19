#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& inGfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	bool IsInsideBoard(const Location& loc) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	static constexpr int dimensionX = 32;
	static constexpr int dimensionY = 24;
	static constexpr int width = 24;
	static constexpr int height = 24;
	static constexpr int boardX = 12;
	static constexpr int boardY = 12;
	Graphics& gfx;
};

#include "Board.h"
#include <assert.h>

Board::Board(Graphics& inGfx)
	:
	gfx(inGfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	assert(loc.x + width < 799);
	assert(loc.y + height < 599);
	gfx.DrawRectDim((loc.x * dimensionX)+boardX, (loc.y * dimensionY)+boardY, width, height-4, c);
}

void Board::DrawBorder()
{
	for (int i = boardX-1; i < boardX + (dimensionX*width); i++)
	{
		gfx.PutPixel(i, boardY-1, Colors::White);
		gfx.PutPixel(i, (boardY + (dimensionY*height)), Colors::White);
	}

	for (int i = boardY-1; i < boardY + (dimensionY*height); i++)
	{
		gfx.PutPixel(boardX-1, i, Colors::White);
		gfx.PutPixel((boardX + (dimensionX*width)), i, Colors::White);
	}
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x <= width-1 &&
		loc.y >= 0 && loc.y <= height-1;
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

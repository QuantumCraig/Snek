#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snk)
{
	Respawn(rng, brd, snk);
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snk)
{
	std::uniform_int_distribution<int> xDist(1, brd.GetWidth() - 2);
	std::uniform_int_distribution<int> yDist(1, brd.GetHeight() - 2);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snk.IsInTile(newLoc));
	loc = newLoc;
}

const Location & Goal::GetLocation() const
{
	return loc;
}

#include "PieceBishop.h"

PieceBishop::PieceBishop(const ChessTeam team)
	: Piece(team, PIECE_BISHOP)
{ }

PieceBishop::~PieceBishop()
{ }

bool PieceBishop::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (fromPosition.x == toPosition.x || fromPosition.y == toPosition.y) 
		return false;
	const ChessIVec2 direction = fromPosition - toPosition;
	if (direction.x == 0 || direction.y == 0) return false;

	if (direction.x < 0 && direction.y < 0) //North West
	{
		for(int i = 1; true; i++)
		{
			if (fromPosition.x - i < 0 || fromPosition.y - i < 0 || fromPosition.x - i > 7 || fromPosition.y - i > 7) 
				return false;
			if (_board[fromPosition.x - i][fromPosition.y - i] != PIECE_NONE) 
				return false;
			if (fromPosition.x - i == toPosition.x && fromPosition.y - i == toPosition.y) 
				return true;
		}
	}
	if (direction.x > 0 && direction.y < 0) //North East 
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x + i < 0 || fromPosition.y - i < 0 || fromPosition.x + i > 7 || fromPosition.y - i > 7)
				return false;
			if (_board[fromPosition.x + i][fromPosition.y - i] != PIECE_NONE)
				return false;
			if (fromPosition.x + i == toPosition.x && fromPosition.y - i == toPosition.y)
				return true;
		}
	}
	if (direction.x > 0 && direction.y > 0) // South East
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x + i < 0 || fromPosition.y + i < 0 || fromPosition.x + i > 7 || fromPosition.y + i > 7)
				return false;
			if (_board[fromPosition.x + i][fromPosition.y + i] != PIECE_NONE)
				return false;
			if (fromPosition.x + i == toPosition.x && fromPosition.y + i == toPosition.y)
				return true;
		}
	}
	if (direction.x < 0 && direction.y > 0) // South West
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x - i < 0 || fromPosition.y + i < 0 || fromPosition.x - i > 7 || fromPosition.y + i > 7)
				return false;
			if (_board[fromPosition.x - i][fromPosition.y + i] != PIECE_NONE)
				return false;
			if (fromPosition.x - i == toPosition.x && fromPosition.y + i == toPosition.y)
				return true;
		}
	}
	return false;
}

bool PieceBishop::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (fromPosition.x == toPosition.x || fromPosition.y == toPosition.y)
		return false;
	const ChessIVec2 direction = fromPosition - toPosition;
	if (direction.x == 0 || direction.y == 0) return false;

	if (direction.x < 0 && direction.y < 0) //North West
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x - i < 0 || fromPosition.y - i < 0 || fromPosition.x - i > 7 || fromPosition.y - i > 7)
				return false;
			if (fromPosition.x - i == toPosition.x && fromPosition.y - i == toPosition.y)
				return true;
			if (_board[fromPosition.x - i][fromPosition.y - i] != PIECE_NONE)
				return false;
		}
	}
	if (direction.x > 0 && direction.y < 0) //North East 
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x + i < 0 || fromPosition.y - i < 0 || fromPosition.x + i > 7 || fromPosition.y - i > 7)
				return false;
			if (fromPosition.x + i == toPosition.x && fromPosition.y - i == toPosition.y)
				return true;
			if (_board[fromPosition.x + i][fromPosition.y - i] != PIECE_NONE)
				return false;
		}
	}
	if (direction.x > 0 && direction.y > 0) // South East
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x + i < 0 || fromPosition.y + i < 0 || fromPosition.x + i > 7 || fromPosition.y + i > 7)
				return false;
			if (fromPosition.x + i == toPosition.x && fromPosition.y + i == toPosition.y)
				return true;
			if (_board[fromPosition.x + i][fromPosition.y + i] != PIECE_NONE)
				return false;
		}
	}
	if (direction.x < 0 && direction.y > 0) // South West
	{
		for (int i = 1; true; i++)
		{
			if (fromPosition.x - i < 0 || fromPosition.y + i < 0 || fromPosition.x - i > 7 || fromPosition.y + i > 7)
				return false;
			if (fromPosition.x - i == toPosition.x && fromPosition.y + i == toPosition.y)
				return true;
			if (_board[fromPosition.x - i][fromPosition.y + i] != PIECE_NONE)
				return false;
		}
	}
	return false;
}

#include "PieceQueen.h"
 
PieceQueen::PieceQueen(const ChessTeam team)
	: Piece(team, PIECE_QUEEN)
{ } 

PieceQueen::~PieceQueen()
{ }

bool PieceQueen::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (fromPosition.x == toPosition.x)
	{
		if (fromPosition.y > toPosition.y)
		{
			for (int i = fromPosition.y; i < toPosition.y; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		if (fromPosition.y < toPosition.y)
		{
			for (int i = toPosition.y; i < fromPosition.y; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		return false;
	}
	if (fromPosition.y == toPosition.y)
	{
		if (fromPosition.x > toPosition.x)
		{
			for (int i = fromPosition.x; i < toPosition.x; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		if (fromPosition.x < toPosition.x)
		{
			for (int i = toPosition.x; i < fromPosition.x; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		return false;
	}
	const ChessIVec2 direction = fromPosition - toPosition;
	if (direction.x == 0 || direction.y == 0) return false;

	if (direction.x < 0 && direction.y < 0) //North West
	{
		for (int i = 1; true; i++)
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

bool PieceQueen::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (_board[toPosition.x][toPosition.y] != PIECE_KING) return false;
	if (fromPosition.x == toPosition.x)
	{
		if (fromPosition.y > toPosition.y)
		{
			for (int i = fromPosition.y; i < toPosition.y; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		if (fromPosition.y < toPosition.y)
		{
			for (int i = toPosition.y; i < fromPosition.y; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		return false;
	}
	if (fromPosition.y == toPosition.y)
	{
		if (fromPosition.x > toPosition.x)
		{
			for (int i = fromPosition.x; i < toPosition.x; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		if (fromPosition.x < toPosition.x)
		{
			for (int i = toPosition.x; i < fromPosition.x; i++)
				if (_board[i][fromPosition.y] != PIECE_NONE) return false;
			return true;
		}
		return false;
	}
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
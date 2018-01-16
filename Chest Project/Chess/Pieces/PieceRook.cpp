#include "PieceRook.h"

PieceRook::PieceRook(const ChessTeam team)
	: Piece(team, PIECE_ROOK)
{ }

PieceRook::~PieceRook()
{ }

bool PieceRook::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition)
{
	int from = 0, to = 0;
	if (fromPosition.x == toPosition.x)
	{
		if (fromPosition.y > toPosition.y)
		{
			from = fromPosition.y;
			to = toPosition.y;
		}
		else if (fromPosition.y < toPosition.y)
		{
			from = toPosition.y;
			to = fromPosition.y;
		}
		else return false;
	}
	else if (fromPosition.y == toPosition.y)
	{
		if (fromPosition.x > toPosition.x)
		{
			from = fromPosition.x;
			to = toPosition.x;
		}
		else if (fromPosition.x < toPosition.x)
		{
			from = toPosition.x;
			to = fromPosition.x;
		}
		else
			return false;
	}
	else
		return false;
	for (int i = from; i < to; i++)
		if (_board[i][fromPosition.y] != PIECE_NONE) return false;
	return true;
}

bool PieceRook::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition)
{
	return (_board[toPosition.x][toPosition.y] != PIECE_KING) && CanMoveTo(fromPosition, toPosition);
}
#include "PieceKnight.h"

PieceKnight::PieceKnight(const ChessTeam team)
	: Piece(team, PIECE_KNIGHT)
{ }

PieceKnight::~PieceKnight()
{ }

bool PieceKnight::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition)
{
	if (fromPosition.y - 2 == toPosition.y)
	{
		if (fromPosition.x - 1 == toPosition.x) return true;
		if (fromPosition.x + 1 == toPosition.x) return true;
	}
	if (fromPosition.y + 2 == toPosition.y)
	{
		if (fromPosition.x - 1 == toPosition.x) return true;
		if (fromPosition.x + 1 == toPosition.x) return true;
	}
	if (fromPosition.x - 2 == toPosition.x)
	{
		if (fromPosition.y - 1 == toPosition.y) return true;
		if (fromPosition.y + 1 == toPosition.y) return true;
	}
	if (fromPosition.x + 2 == toPosition.x)
	{
		if (fromPosition.y - 1 == toPosition.y) return true;
		if (fromPosition.y + 1 == toPosition.y) return true;
	}
	return false;
}

bool PieceKnight::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition)
{
	return (_board[toPosition.x][toPosition.y] != PIECE_KING) && CanMoveTo(fromPosition, toPosition);
}
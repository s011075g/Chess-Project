#include "PiecePawn.h"

PiecePawn::PiecePawn(const ChessTeam team) 
	: Piece(team, PIECE_PAWN)
{ }

PiecePawn::~PiecePawn()
{ }

bool PiecePawn::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (_moveCounter != 0)
		return (fromPosition.y + (1 * _team) == toPosition.y) && fromPosition.x == toPosition.x;
	//Pawns can move forward 2 on its first go, if they so choose, as long there is no piece in front of them
	return (fromPosition.y + (1 * _team) == toPosition.y || (fromPosition.y + (2 * _team) == toPosition.y) && fromPosition.x == toPosition.x && _board[fromPosition.x][fromPosition.y] == PIECE_NONE);
}

bool PiecePawn::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	if (_board[toPosition.x][toPosition.y] == PIECE_KING) return false;
	if (fromPosition.y + _team != toPosition.y) return false;
	return fromPosition.x + 1 == toPosition.x || fromPosition.x - 1 == toPosition.x;
}
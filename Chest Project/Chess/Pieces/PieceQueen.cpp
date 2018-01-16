#include "PieceQueen.h"
 
PieceQueen::PieceQueen(const ChessTeam team)
	: Piece(team, PIECE_QUEEN)
{ } 

PieceQueen::~PieceQueen()
{ }

bool PieceQueen::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	return false;
}

bool PieceQueen::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	return false;
}
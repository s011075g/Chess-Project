#include "PieceKing.h"
std::array<std::array<Piece*, 8>, 8> PieceKing::_detailedBoard = std::array<std::array<Piece*, 8>, 8>{ {nullptr}};

PieceKing::PieceKing(const ChessTeam team)
	: Piece(team, PIECE_KING)
{ }

PieceKing::~PieceKing()
{ }

bool PieceKing::CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const 
{
	const ChessIVec2 distance = fromPosition - toPosition;
	if (abs(distance.x) != 1 || abs(distance.y) != 1) return false;
	return !IsInCheck(toPosition);
}

bool PieceKing::CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const
{
	return _board[toPosition.x][toPosition.y] != PIECE_KING && CanMoveTo(fromPosition, toPosition);
}

bool PieceKing::IsInCheck(const ChessIVec2& position)
{
	for (int x = 0; x < _detailedBoard.size(); x++)
		for (int y = 0; y < _detailedBoard[x].size(); y++)
		{
			if (_detailedBoard[x][y] && _detailedBoard[x][y]->CanAttack(ChessIVec2(x, y), position)) return true;
		}
	return false;
}
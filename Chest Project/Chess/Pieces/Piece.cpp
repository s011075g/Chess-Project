#include "Piece.h"
//Sets an empty array
std::array<std::array<char, 8>, 8> Piece::_board = std::array<std::array<char, 8>, 8>{{0}};

Piece::Piece(const ChessTeam team, const ChessPiece piece)
	: _team (team), _piece(piece), _moveCounter(0u)
{ }

Piece::Piece()
	: _team(TEAM_NONE), _piece(PIECE_NONE), _moveCounter(0u)
{ }

Piece::~Piece()
{ }

//Return false as they will be overriden by a derived class

bool Piece::CanMoveTo(const ChessIVec2 & fromPosition, const ChessIVec2 & toPosition)
{
	return false;
}

bool Piece::CanAttack(const ChessIVec2 & fromPosition, const ChessIVec2 & toPosition)
{
	return false;
}

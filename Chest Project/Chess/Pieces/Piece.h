#pragma once
#include <array>
#include "../Enum.h"
#include "../Struct.h"
class Piece
{
protected:
	ChessTeam _team;
	ChessPiece _piece;
	unsigned int _moveCounter;

	static std::array<std::array<char, 8>, 8> _board;

public:
	Piece(const ChessTeam team, const ChessPiece piece);
	Piece();

	virtual ~Piece();
	virtual bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition);
	virtual bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition);

	ChessTeam GetTeam() const { return _team; }
	ChessPiece GetPiece() const { return _piece; }
	unsigned int GetMoveCount() const { return _moveCounter; }

	//Increases the number of movements the piece has taken
	void PieceMoved() { _moveCounter++; }

	static void SetBoard(const std::array<std::array<char, 8>, 8>& board) { _board = board; }
};
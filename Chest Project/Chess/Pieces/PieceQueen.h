#pragma once
#include "Piece.h"
class PieceQueen : public Piece
{
public:
	PieceQueen(const ChessTeam team);
	~PieceQueen();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;
};
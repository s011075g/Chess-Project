#pragma once
#include "Piece.h"

class PieceRook : public Piece
{
public:
	PieceRook(const ChessTeam team);
	~PieceRook();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
};
#pragma once
#include "Piece.h"
class PieceBishop : public Piece
{
public:
	PieceBishop(const ChessTeam team);
	~PieceBishop();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
};
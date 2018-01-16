#pragma once
#include "Piece.h"
class PieceKnight : public Piece
{
public:
	PieceKnight(const ChessTeam team);
	~PieceKnight();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;
};
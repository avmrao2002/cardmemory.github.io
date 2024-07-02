#include "stdafx.h"
#include "ChessBoard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CRect CChessBoard::GetRect()
{
	return m_rect;
}
void CChessBoard::SetRect(CRect &inrect)
{
	m_rect = inrect;
}
void CChessBoard::SetColorType(COLOR_TYPE sq_type)
{
	m_sq_type = sq_type;
}
COLOR_TYPE CChessBoard::GetColorType()
{
	return m_sq_type;
}
void CChessBoard::SetPieceType(PIECE_TYPE piece_type)
{
	m_piece_type = piece_type;
}
PIECE_TYPE CChessBoard::GetPieceType()
{
	return m_piece_type;
}
void CChessBoard::SetPieceColor(COLOR_TYPE piece_color)
{
	m_piece_color = piece_color;
}
COLOR_TYPE CChessBoard::GetPieceColor()
{
	return m_piece_color;
}
void CChessBoard::SetPieceId(int piece_id)
{
	m_pieceid = piece_id;
}
int CChessBoard::GetPieceId()
{
	return m_pieceid;
}
void CChessBoard::SetPieceData(int piece_id,COLOR_TYPE piece_color,PIECE_TYPE piece_type, STATE piece_state)
{
	m_piece_color = piece_color;
	m_pieceid = piece_id;
	m_piece_type = piece_type;
	m_piece_state = piece_state;
}
void CChessBoard::GetPieceData(int &piece_id,COLOR_TYPE &piece_color,PIECE_TYPE &piece_type, STATE& piece_state)
{
	piece_color = m_piece_color;
	piece_id = m_pieceid;
	piece_type = m_piece_type;
	piece_state = m_piece_state;
 
}
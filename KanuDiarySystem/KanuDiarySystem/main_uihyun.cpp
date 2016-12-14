
bool MoveUp();
bool MoveDown();


bool calendarmanager::MoveUp()
{
	m_rgDay[m_nRow][m_nCol].SetSeleted(false);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[--m_nRow][m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();
	return true;
}
bool calendarmanager::MoveDown()
{
	m_rgDay[m_nRow][m_nCol].SetSeleted(false);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[++m_nRow][m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();
	return true;
}
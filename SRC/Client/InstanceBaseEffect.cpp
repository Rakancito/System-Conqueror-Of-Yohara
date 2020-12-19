//In function

UINT CInstanceBase::GetNameColorIndex()

//Search

	if (IsPC())
	{

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		if (m_dwConquerorLevel)
		{
			return NAMECOLOR_CONQUEROR;
		}
#endif

//In function

void CInstanceBase::AttachTextTail()
{

//Search

	if (m_dwLevel)
	{
		UpdateTextTailLevel(m_dwLevel);
	}

//Replace with

#ifdef ENABLE_CONQUEROR_LEVEL
	if (m_dwConquerorLevel)
	{
		UpdateTextTailConquerorLevel(m_dwConquerorLevel);
	}
	else if (m_dwLevel)
	{
		UpdateTextTailLevel(m_dwLevel);
	}
#else
	if (m_dwLevel)
	{
		UpdateTextTailLevel(m_dwLevel);
	}	
#endif

//Search this function

void CInstanceBase::RefreshTextTail()

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
void CInstanceBase::UpdateTextTailConquerorLevel(DWORD level)
{
	static D3DXCOLOR s_kLevelColor = D3DXCOLOR(0.0f, 191.0f, 255.0f, 255.0f);
	char szText[256];
	sprintf(szText, "Lv %d ", level);
	CPythonTextTail::Instance().AttachLevel(GetVirtualID(), szText, s_kLevelColor);
}
#endif

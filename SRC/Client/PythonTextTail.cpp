//Search

void CPythonTextTail::DetachLevel(DWORD dwVID)
{

        [...]

}

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
void CPythonTextTail::AttachConquerorLevel(DWORD dwVID, const char* c_szText)
{
	if (!bPKTitleEnable)
		return;

	TTextTailMap::iterator itor = m_CharacterTextTailMap.find(dwVID);
	if (m_CharacterTextTailMap.end() == itor)
		return;

	TTextTail* pTextTail = itor->second;

	CGraphicTextInstance*& prLevel = pTextTail->pLevelTextInstance;
	if (!prLevel)
	{
		prLevel = CGraphicTextInstance::New();
		prLevel->SetTextPointer(ms_pFont);
		prLevel->SetOutline(true);

		prLevel->SetHorizonalAlign(CGraphicTextInstance::HORIZONTAL_ALIGN_RIGHT);
		prLevel->SetVerticalAlign(CGraphicTextInstance::VERTICAL_ALIGN_BOTTOM);
	}

	prLevel->SetValue(c_szText);
	prLevel->SetColor(140.0f / 255.0f, 200.0f / 255.0f, 255.0f / 255.0f, 1.0f);
	prLevel->SetOutLineColor(140.0f / 255.0f * 0.5f, 200.0f / 255.0f * 0.5f, 255.0f / 255.0f * 0.5f, 1.0f);
	prLevel->Update();
}

#endif

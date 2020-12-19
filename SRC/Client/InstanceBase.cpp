//In the function
bool CInstanceBase::Create(const SCreateData& c_rkCreateData)


//Search
	__Create_SetName(c_rkCreateData);

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	if(IsPC())
		m_dwConquerorLevel = c_rkCreateData.m_dwConquerorLevel;
#endif

//Search

void CInstanceBase::SetPKMode(BYTE byPKMode)
{

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
void CInstanceBase::SetConquerorLevelText(int sLevel)
{
	m_dwConquerorLevel = sLevel;
	UpdateTextTailConquerorLevel(sLevel);
}
#endif

//Search

m_dwLevel = 0;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	m_dwConquerorLevel = 0;
#endif


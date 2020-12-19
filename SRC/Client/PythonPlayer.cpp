//Search

	if (dwType == POINT_LEVEL)
	{
		CInstanceBase* pkPlayer = NEW_GetMainActorPtr();

		if (pkPlayer)
			pkPlayer->UpdateTextTailLevel(lValue);
	}

//Add after

	if (dwType == POINT_CONQUEROR_LEVEL)
	{
		CInstanceBase* pkPlayer = NEW_GetMainActorPtr();

		if (pkPlayer)
			pkPlayer->UpdateTextTailConquerorLevel(lValue);
	}

//Search

	m_ppyGameWindow = NULL;

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	m_kMap_dwAffectIndexToSkillIndex.insert(make_pair(int(CInstanceBase::AFFECT_CHEONUN), 182));
#endif
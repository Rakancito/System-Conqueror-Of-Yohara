//Search

			DWORD	m_dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
			DWORD	m_dwConquerorLevel;
#endif

//Search

			NAMECOLOR_WAYPOINT,

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
			NAMECOLOR_CONQUEROR,
#endif

//Search

		void					UpdateTextTailLevel(DWORD level);

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		void					UpdateTextTailConquerorLevel(DWORD level);
#endif

//Search

void					SetPKMode(BYTE byPKMode);

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
		void					SetConquerorLevelText(int iLevel);
#endif

//Search

DWORD					m_dwLevel;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		DWORD					m_dwConquerorLevel;
#endif


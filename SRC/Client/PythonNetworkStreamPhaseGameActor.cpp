//Search

	kNetActorData.m_dwLevel = 0;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	kNetActorData.m_dwConquerorLevel = 0;
#endif


//Search

		kNetActorData.m_dwGuildID = chrInfoPacket.dwGuildID;
		kNetActorData.m_dwLevel = chrInfoPacket.dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		kNetActorData.m_dwConquerorLevel = chrInfoPacket.dwConquerorLevel;
#endif

//Search

	kNetActorData.m_dwLevel = 0;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	kNetActorData.m_dwConquerorLevel = 0;
#endif


//Search

	kNetUpdateActorData.m_dwLevel=chrUpdatePacket.dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	kNetUpdateActorData.m_dwConquerorLevel=chrUpdatePacket.dwConquerorLevel;
#endif
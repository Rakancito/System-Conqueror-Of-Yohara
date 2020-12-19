//Search

	m_dwLevel = src.m_dwLevel;
	m_stName = src.m_stName;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	m_dwConquerorLevel = src.m_dwConquerorLevel;
#endif


//Search

	m_stName="";

	m_kAffectFlags.Clear();
}


//Add before

#ifdef ENABLE_CONQUEROR_LEVEL
	m_dwConquerorLevel=0;
#endif

//Search

	CInstanceBase::SCreateData kCreateData;
	kCreateData.m_bType=rkNetActorData.m_bType;
	kCreateData.m_dwLevel=rkNetActorData.m_dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	kCreateData.m_dwConquerorLevel=rkNetActorData.m_dwConquerorLevel;
#endif

//Search

		pkInstFind->SetAlignment(c_rkNetUpdateActorData.m_sAlignment);

//Add before

#ifdef ENABLE_CONQUEROR_LEVEL
		if(c_rkNetUpdateActorData.m_dwConquerorLevel > 0)
			pkInstFind->SetConquerorLevelText(c_rkNetUpdateActorData.m_dwConquerorLevel);
#endif

//Search

	rkNetActorData.m_dwMovSpd=c_rkNetUpdateActorData.m_dwMovSpd;
	rkNetActorData.m_dwAtkSpd=c_rkNetUpdateActorData.m_dwAtkSpd;
	rkNetActorData.m_dwArmor=c_rkNetUpdateActorData.m_dwArmor;
	rkNetActorData.m_dwWeapon=c_rkNetUpdateActorData.m_dwWeapon;

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	rkNetActorData.m_dwConquerorLevel=c_rkNetUpdateActorData.m_dwConquerorLevel;
#endif


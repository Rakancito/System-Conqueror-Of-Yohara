//Search

		FLY_QUIVER_ATTACK_NORMAL,

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		FLY_CONQUEROR_EXP,
#endif

//If you don't have QUIVER_SYSTEM (why are you without quiver lol?), only search
		FLY_SKILL_MUYEONG,

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		FLY_CONQUEROR_EXP,
#endif

//Search

	PyModule_AddIntConstant(poModule, "FLY_SKILL_MUYEONG",		FLY_SKILL_MUYEONG);

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	PyModule_AddIntConstant(poModule, "FLY_CONQUEROR_EXP", FLY_CONQUEROR_EXP);	
#endif
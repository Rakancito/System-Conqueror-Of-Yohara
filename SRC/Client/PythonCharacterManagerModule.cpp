//Search

	PyModule_AddIntConstant(poModule, "NAMECOLOR_EXTRA", CInstanceBase::NAMECOLOR_EXTRA);

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	PyModule_AddIntConstant(poModule, "NAMECOLOR_CONQUEROR", CInstanceBase::NAMECOLOR_CONQUEROR);
#endif


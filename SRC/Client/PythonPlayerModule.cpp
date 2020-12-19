//Search

PyObject * playerGetEXP(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwEXP = CPythonPlayer::Instance().GetStatus(POINT_EXP);
	return Py_BuildValue("l", dwEXP);
}

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
PyObject * playerGetConquerorEXP(PyObject* poSelf, PyObject* poArgs)
{
	DWORD dwEXP = CPythonPlayer::Instance().GetStatus(POINT_CONQUEROR_EXP);
	return Py_BuildValue("l", dwEXP);
}
#endif


//Search

		{ "GetEXP",						playerGetEXP,						METH_VARARGS },

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		{ "GetConquerorEXP",			playerGetConquerorEXP,				METH_VARARGS },
#endif

//Search

	PyObject* poModule = Py_InitModule("player", s_methods);

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL	
	PyModule_AddIntConstant(poModule, "CONQUEROR_LEVEL", POINT_CONQUEROR_LEVEL);
	PyModule_AddIntConstant(poModule, "CONQUEROR_LEVEL_STEP", POINT_CONQUEROR_LEVEL_STEP);
	PyModule_AddIntConstant(poModule, "SUNGMA_STR", POINT_SUNGMA_STR);
	PyModule_AddIntConstant(poModule, "SUNGMA_HP", POINT_SUNGMA_HP);
	PyModule_AddIntConstant(poModule, "SUNGMA_MOVE", POINT_SUNGMA_MOVE);
	PyModule_AddIntConstant(poModule, "SUNGMA_INMUNE", POINT_SUNGMA_INMUNE);
	PyModule_AddIntConstant(poModule, "CONQUEROR_POINT", POINT_CONQUEROR_POINT);
	PyModule_AddIntConstant(poModule, "CONQUEROR_EXP", POINT_CONQUEROR_EXP);
	PyModule_AddIntConstant(poModule, "CONQUEROR_NEXT_EXP", POINT_CONQUEROR_NEXT_EXP);
#endif	

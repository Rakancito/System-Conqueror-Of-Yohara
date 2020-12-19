//Search

PyObject * chrCreateInstance(PyObject* poSelf, PyObject* poArgs)
{

		...
		CInstanceBase::SCreateData kCreateData;
		kCreateData.m_bType=CActorInstance::TYPE_PC;
		kCreateData.m_dwLevel = 0;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		kCreateData.m_dwConquerorLevel = 0;
#endif

//Search

	PyModule_AddIntConstant(poModule, "NEW_AFFECT_MALL",					CInstanceBase::NEW_AFFECT_MALL);

//Add before

#ifdef ENABLE_CONQUEROR_LEVEL
	PyModule_AddIntConstant(poModule, "AFFECT_CHEONUN", CInstanceBase::AFFECT_CHEONUN);
#endif


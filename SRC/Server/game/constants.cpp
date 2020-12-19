//Search

};

const int aiItemMagicAttributePercentHigh[ITEM_ATTRIBUTE_MAX_LEVEL] =
{

//Add before

#ifdef ENABLE_CONQUEROR_LEVEL
	{ POINT_SUNGMA_STR, },
	{ POINT_SUNGMA_HP, },
	{ POINT_SUNGMA_MOVE, },
	{ POINT_SUNGMA_INMUNE, },
	{ POINT_CONQUEROR_POINT, },
#endif

//Search


    { NULL,		0			}
};
// from import_item_proto.c

long FN_get_apply_type(const char *apply_type_string)
{

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	{ "SUNGMA_STR", APPLY_SUNGMA_STR },
	{ "SUNGMA_HP", APPLY_SUNGMA_HP },
	{ "SUNGMA_MOVE", APPLY_SUNGMA_MOVE },
	{ "SUNGMA_INMUNE", APPLY_SUNGMA_INMUNE },
#endif


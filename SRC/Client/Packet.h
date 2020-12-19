//Search

typedef struct packet_char_additional_info
{
	...
	DWORD   dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	DWORD	dwConquerorLevel;
#endif

//Search

typedef struct packet_update_char
{

	...
	DWORD		dwLevel;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	DWORD		dwConquerorLevel;
#endif

//Search
	POINT_MIN_WEP = 200,
	POINT_MAX_WEP,
	POINT_MIN_MAGIC_WEP,
	POINT_MAX_MAGIC_WEP,
	POINT_HIT_RATE,
//Add after

#ifdef ENABLE_CONQUEROR_LEVEL	
	POINT_CONQUEROR_LEVEL,
	POINT_CONQUEROR_LEVEL_STEP,
	POINT_SUNGMA_STR,
	POINT_SUNGMA_HP,
	POINT_SUNGMA_MOVE,
	POINT_SUNGMA_INMUNE,
	POINT_CONQUEROR_POINT,
	POINT_CONQUEROR_EXP,
	POINT_CONQUEROR_NEXT_EXP,
#endif

//Search
enum
{
	FLY_NONE,
	FLY_EXP,
	FLY_HP_MEDIUM,
	FLY_HP_BIG,
	FLY_SP_SMALL,
	FLY_SP_MEDIUM,
	FLY_SP_BIG,
	FLY_FIREWORK1,
	FLY_FIREWORK2,
	...
};

enum EDamageType
{

//Add before

#ifdef ENABLE_CONQUEROR_LEVEL
	FLY_CONQUEROR_EXP,
#endif


//In struct

typedef struct character_point
{


//add after

	long long		gold;

//this

#ifdef ENABLE_CONQUEROR_LEVEL
	BYTE	conquerorlevel;
	DWORD	conqueror_exp;
#endif

//Search

		void			SetLevel(BYTE level);


//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		int			GetConquerorLevel() const		{ return m_points.conquerorlevel;	}
		void			SetConquerorLevel(BYTE level);
		DWORD			GetConquerorExp() const		{ return m_points.conqueror_exp;	}
		void			SetConquerorExp(DWORD exp)	{ m_points.conqueror_exp = exp;	}
		DWORD			GetConquerorNextExp() const;
#endif

//Search

};

enum EPKModes
{

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	POINT_CONQUEROR_LEVEL = 205,
	POINT_CONQUEROR_LEVEL_STEP = 206,
	POINT_SUNGMA_STR = 207,
	POINT_SUNGMA_HP = 208,
	POINT_SUNGMA_MOVE = 209,
	POINT_SUNGMA_INMUNE = 210,
	POINT_CONQUEROR_POINT = 211,
	POINT_CONQUEROR_EXP = 212,
	POINT_CONQUEROR_NEXT_EXP = 213,
#endif

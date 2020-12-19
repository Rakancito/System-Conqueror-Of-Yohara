//Search

ACMD(do_stat);

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
ACMD(do_conqueror_stat);
#endif

//Search

	{ "stat",		do_stat,		0,			POS_DEAD,	GM_PLAYER	},

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	{ "conqueror_stat",		do_conqueror_stat,		0,			POS_DEAD,	GM_PLAYER	},
#endif


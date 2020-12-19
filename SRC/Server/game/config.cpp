//Search

int gPlayerMaxLevel = 99;

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
int gPlayerConquerorMaxLevel = 30;
#endif

//Search

		TOKEN("max_level")
		{
			str_to_number(gPlayerMaxLevel, value_string);

			gPlayerMaxLevel = MINMAX(1, gPlayerMaxLevel, PLAYER_MAX_LEVEL_CONST);

			fprintf(stderr, "PLAYER_MAX_LEVEL: %d\n", gPlayerMaxLevel);
		}

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		TOKEN("max_conqueror_level")
		{
			str_to_number(gPlayerConquerorMaxLevel, value_string);

			gPlayerConquerorMaxLevel = MINMAX(1, gPlayerConquerorMaxLevel, PLAYER_MAX_LEVEL_CONST);

			fprintf(stderr, "PLAYER_CONQUEROR_MAX_LEVEL: %d\n", gPlayerConquerorMaxLevel);
		}
#endif


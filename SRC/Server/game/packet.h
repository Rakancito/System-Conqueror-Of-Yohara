//Search

typedef struct packet_char_additional_info
{
	...
	DWORD   dwLevel;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	DWORD	dwConquerorLevel;
#endif

//Search

typedef struct packet_update_char
{

	...
	DWORD   dwLevel;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	DWORD	dwConquerorLevel;
#endif


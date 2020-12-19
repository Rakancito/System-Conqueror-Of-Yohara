//Search

ACMD(do_pvp)
{

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
ACMD(do_conqueror_stat)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (!*arg1)
		return;

	if (ch->IsPolymorphed())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT(TRANSLATE_LANGUAGE, "?? ??? ??? ?? ? ????."));
		return;
	}

	if (ch->GetPoint(POINT_CONQUEROR_POINT) <= 0)
		return;

	BYTE idx = 0;

	if (!strcmp(arg1, "smh_str"))
		idx = POINT_SUNGMA_STR;
	else if (!strcmp(arg1, "smh_hp"))
		idx = POINT_SUNGMA_HP;
	else if (!strcmp(arg1, "smh_move"))
		idx = POINT_SUNGMA_MOVE;
	else if (!strcmp(arg1, "smh_inmune"))
		idx = POINT_SUNGMA_INMUNE;
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT(TRANSLATE_LANGUAGE, "Error!"));
		return;
	}

	if (ch->GetRealPoint(idx) >= MAX_STAT)
		return;

	ch->SetRealPoint(idx, ch->GetRealPoint(idx) + 1);
	ch->SetPoint(idx, ch->GetPoint(idx) + 1);
	ch->ComputePoints();
	ch->PointChange(idx, 0);

	if (idx == POINT_SUNGMA_HP)
	{
		ch->PointChange(POINT_MAX_HP, 0);
	}

	ch->PointChange(POINT_CONQUEROR_POINT, -1);
	ch->ComputePoints();
}
#endif

//Search

		case POINT_RESIST_SURA:		return LC_TEXT(DEFAULT_LANGUAGE, "????? %d%% ??");
		case POINT_RESIST_SHAMAN:	return LC_TEXT(DEFAULT_LANGUAGE, "????? %d%% ??");

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		case POINT_SUNGMA_STR:           return LC_TEXT(DEFAULT_LANGUAGE, "");
		case POINT_SUNGMA_HP:           return LC_TEXT(DEFAULT_LANGUAGE, "");
		case POINT_SUNGMA_MOVE:           return LC_TEXT(DEFAULT_LANGUAGE, "");
		case POINT_SUNGMA_INMUNE:           return LC_TEXT(DEFAULT_LANGUAGE, "");
		case POINT_CONQUEROR_POINT:           return LC_TEXT(DEFAULT_LANGUAGE, "");
#endif


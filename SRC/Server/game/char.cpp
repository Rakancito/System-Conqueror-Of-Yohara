//Search

		{
			addPacket.dwLevel = GetLevel();
		}
		else
		{
			addPacket.dwLevel = 0;
		}

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		if (IsPC() == true)
			addPacket.dwConquerorLevel = GetConquerorLevel();
#endif


//Search

	pack.dwLevel = GetLevel();

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	pack.dwConquerorLevel = GetConquerorLevel();
#endif

//Search

	tab.horse = GetHorseData();
}

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	tab.conqueror_exp	= GetConquerorExp();
	tab.conquerorlevel = GetConquerorLevel();
	tab.conqueror_level_step = GetPoint(POINT_CONQUEROR_LEVEL_STEP);
	tab.sungma_str = GetRealPoint(POINT_SUNGMA_STR);
	tab.sungma_hp = GetRealPoint(POINT_SUNGMA_HP);
	tab.sungma_move = GetRealPoint(POINT_SUNGMA_MOVE);
	tab.sungma_inmune = GetRealPoint(POINT_SUNGMA_INMUNE);
	tab.conqueror_point = GetPoint(POINT_CONQUEROR_POINT);
#endif

//Search

	pack.points[POINT_STAMINA]		= GetStamina();
	pack.points[POINT_MAX_STAMINA]	= GetMaxStamina();

	for (int i = POINT_ST; i < POINT_MAX_NUM; ++i)
		pack.points[i] = GetPoint(i);

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	pack.points[POINT_CONQUEROR_LEVEL]		= GetConquerorLevel();
	pack.points[POINT_CONQUEROR_EXP]		= GetConquerorExp();
	pack.points[POINT_CONQUEROR_NEXT_EXP]		= GetConquerorNextExp();
#endif

//Search

void CHARACTER::SetEmpire(BYTE bEmpire)

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
void CHARACTER::SetConquerorLevel(BYTE level)
{
	m_points.conquerorlevel = level;
}
#endif

//Search

	SetMapIndex(t->lMapIndex);
	SetXYZ(t->x, t->y, t->z);

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	SetConquerorLevel(t->conquerorlevel);
	SetConquerorExp(t->conqueror_exp);

	SetPoint(POINT_CONQUEROR_LEVEL_STEP, t->conqueror_level_step);
	SetRealPoint(POINT_CONQUEROR_LEVEL_STEP, t->conqueror_level_step);

	SetRealPoint(POINT_SUNGMA_STR, t->sungma_str);
	SetRealPoint(POINT_SUNGMA_HP, t->sungma_hp);
	SetRealPoint(POINT_SUNGMA_MOVE, t->sungma_move);
	SetRealPoint(POINT_SUNGMA_INMUNE, t->sungma_inmune);

	SetPoint(POINT_SUNGMA_STR, t->sungma_str);
	SetPoint(POINT_SUNGMA_HP, t->sungma_hp);
	SetPoint(POINT_SUNGMA_MOVE, t->sungma_move);
	SetPoint(POINT_SUNGMA_INMUNE, t->sungma_inmune);
	SetPoint(POINT_CONQUEROR_POINT, t->conqueror_point);
#endif

//Search

	memset(m_pointsInstant.points, 0, sizeof(m_pointsInstant.points));
	BuffOnAttr_ClearAll();
	m_SkillDamageBonus.clear();

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
	long lConquerorStat = GetPoint(POINT_CONQUEROR_POINT);
	long lConquerorLevelStep = GetPoint(POINT_CONQUEROR_LEVEL_STEP);
#endif

//Search

	SetPoint(POINT_DX, GetRealPoint(POINT_DX));
	SetPoint(POINT_IQ, GetRealPoint(POINT_IQ));

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
	SetPoint(POINT_CONQUEROR_POINT, lConquerorStat);
	SetPoint(POINT_CONQUEROR_LEVEL_STEP, lConquerorLevelStep);

	SetPoint(POINT_SUNGMA_STR, GetRealPoint(POINT_SUNGMA_STR));
	SetPoint(POINT_SUNGMA_HP, GetRealPoint(POINT_SUNGMA_HP));
	SetPoint(POINT_SUNGMA_MOVE, GetRealPoint(POINT_SUNGMA_MOVE));
	SetPoint(POINT_SUNGMA_INMUNE, GetRealPoint(POINT_SUNGMA_INMUNE));
	
#endif

//Search

void CHARACTER::PointChange(BYTE type, long long amount, bool bAmount, bool bBroadcast)
{
	long long val = 0;

	switch (type)
	{
		case POINT_NONE:
			return;

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
		case POINT_CONQUEROR_LEVEL:
			if ((GetConquerorLevel() + amount) > gPlayerConquerorMaxLevel)
				return;

			SetConquerorLevel(GetConquerorLevel() + amount);
			val = GetConquerorLevel();

			sys_log(0, "CONQUEROR_LEVELUP: %s %d NEXT EXP %d", GetName(), GetConquerorLevel(), GetConquerorNextExp());
#ifdef ENABLE_WOLFMAN_CHARACTER
			if (GetJob() == JOB_WOLFMAN)
			{
				if ((5 <= val) && (GetSkillGroup()!=1))
				{
					ClearSkill();
					SetSkillGroup(1);
					SetRealPoint(POINT_SKILL, GetLevel()-1);
					SetPoint(POINT_SKILL, GetRealPoint(POINT_SKILL));
					PointChange(POINT_SKILL, 0);
				}
			}
#endif
			PointChange(POINT_CONQUEROR_NEXT_EXP,	GetConquerorNextExp(), false);

			//if (amount)
			//{
				//quest::CQuestManager::instance().LevelUp(GetPlayerID());

				//LogManager::instance().LevelLog(this, val, GetRealPoint(POINT_PLAYTIME) + (get_dword_time() - m_dwPlayStartTime) / 60000);

				//if (GetParty())
				//{
				//	GetParty()->RequestSetConquerorMemberLevel(GetPlayerID(), GetConquerorLevel());
				//}
			//}
			break;
		case POINT_CONQUEROR_NEXT_EXP:
			val = GetConquerorNextExp();
			bAmount = false;
			break;

		case POINT_CONQUEROR_EXP:
			{
				DWORD exp = GetConquerorExp();
				DWORD next_exp = GetConquerorNextExp();
				
				if (block_exp)
					return;

				if ((amount < 0) && (exp < (DWORD)(-amount)))
				{
					sys_log(1, "%s AMOUNT < 0 %d, CUR CONQUEROR EXP: %d", GetName(), -amount, exp);
					amount = -exp;

					SetConquerorExp(exp + amount);
					val = GetExp();
				}
				else
				{
					if (gPlayerConquerorMaxLevel <= GetConquerorLevel())
						return;

					if (test_server)
						ChatPacket(CHAT_TYPE_INFO, "You have gained %d conqueror exp.", amount);

					DWORD iExpBalance = 0;

					// ?? ?!
					if (exp + amount >= next_exp)
					{
						iExpBalance = (exp + amount) - next_exp;
						amount = next_exp - exp;

						SetConquerorExp(0);
						exp = next_exp;
					}
					else
					{
						SetConquerorExp(exp + amount);
						exp = GetConquerorExp();
					}

					DWORD q = DWORD(next_exp / 4.0f);
					int iLevStep = GetRealPoint(POINT_CONQUEROR_LEVEL_STEP);

					// iLevStep? 4 ???? ??? ???? ??? ??? ? ? ?? ???.
					if (iLevStep >= 4)
					{
						sys_err("%s CONQUEROR_LEVEL_STEP bigger than 4! (%d)", GetName(), iLevStep);
						iLevStep = 4;
					}

					if (exp >= next_exp && iLevStep < 4)
					{
						for (int i = 0; i < 4 - iLevStep; ++i)
							PointChange(POINT_CONQUEROR_LEVEL_STEP, 1, false, true);
					}
					else if (exp >= q * 3 && iLevStep < 3)
					{
						for (int i = 0; i < 3 - iLevStep; ++i)
							PointChange(POINT_CONQUEROR_LEVEL_STEP, 1, false, true);
					}
					else if (exp >= q * 2 && iLevStep < 2)
					{
						for (int i = 0; i < 2 - iLevStep; ++i)
							PointChange(POINT_CONQUEROR_LEVEL_STEP, 1, false, true);
					}
					else if (exp >= q && iLevStep < 1)
						PointChange(POINT_CONQUEROR_LEVEL_STEP, 1);

					if (iExpBalance)
					{
						PointChange(POINT_CONQUEROR_EXP, iExpBalance);
					}

					val = GetConquerorExp();
				}
			}
			break;
		case POINT_CONQUEROR_LEVEL_STEP:

			if (amount > 0)
			{
				val = GetPoint(POINT_CONQUEROR_LEVEL_STEP) + amount;
				switch (val)
				{
					case 1:
					case 2:
					case 3:
						{
							if ((GetConquerorLevel() <= g_iStatusPointGetLevelLimit) && (GetConquerorLevel() <= gPlayerConquerorMaxLevel) )
								PointChange(POINT_CONQUEROR_POINT, 1);
						}
						break;
					case 4:
						{
							PointChange(POINT_CONQUEROR_LEVEL, 1, false, true);
							val = 0;
						}
						break;

				}

				SetPoint(POINT_CONQUEROR_LEVEL_STEP, val);
				SetRealPoint(POINT_CONQUEROR_LEVEL_STEP, val);

				Save();
			}
			else
				val = GetPoint(POINT_CONQUEROR_LEVEL_STEP);

			break;

		case POINT_SUNGMA_STR:
		case POINT_SUNGMA_HP:
		case POINT_SUNGMA_MOVE:
		case POINT_SUNGMA_INMUNE:
			SetPoint(type, GetPoint(type) + amount);
			val = GetPoint(type);
			break;
		case POINT_CONQUEROR_POINT:
			SetPoint(type, GetPoint(type) + amount);
			val = GetPoint(type);

			SetRealPoint(type, val);
			break;
#endif

//Search

			ComputeBattlePoints();
			break;
		case POINT_MAX_HP:
		case POINT_MAX_SP:
		case POINT_MAX_STAMINA:
			break;

//Add before


#ifdef ENABLE_CONQUEROR_LEVEL
		case POINT_CONQUEROR_LEVEL:
		case POINT_SUNGMA_STR:
		case POINT_SUNGMA_HP:
		case POINT_SUNGMA_MOVE:
		case POINT_SUNGMA_INMUNE:
#endif

//Search

			PointChange(aApplyInfo[bApplyType].bPointType, iVal);
			break;

		default:
			sys_err("Unknown apply type %d name %s", bApplyType, GetName());
			break;

//add before

#ifdef ENABLE_CONQUEROR_LEVEL
		case APPLY_SUNGMA_STR:
		case APPLY_SUNGMA_HP:
		case APPLY_SUNGMA_MOVE:
		case APPLY_SUNGMA_INMUNE:
#endif

//Search

DWORD CHARACTER::GetNextExp() const
{
	if (PLAYER_MAX_LEVEL_CONST < GetLevel())
		return 2500000000u;
	else
		return exp_table[GetLevel()];
}

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
DWORD CHARACTER::GetConquerorNextExp() const
{
	if (PLAYER_MAX_LEVEL_CONST < GetConquerorLevel())
		return 2500000000u;
	else
		return exp_table[GetConquerorLevel()];
}

#endif

//add after all code


#ifdef ENABLE_CONQUEROR_LEVEL
bool CHARACTER::IsConquerorMap(int iMapIndex)
{
	if (iMapIndex == EASTPLAIN_01)
		return true;
	else if(iMapIndex == EASTPLAIN_02)
		return true;
	else if(iMapIndex == EASTPLAIN_03)
		return true;
	else if(iMapIndex == EMPIRECASTLE)
		return true;		
	return false;
}
#endif


//Search

void CPythonCharacterManager::ShowPointEffect(DWORD ePoint, DWORD dwVID)
{
		...
		case POINT_LEVEL:
			pkInstSel->LevelUp();
			break;
		case POINT_LEVEL_STEP:
			pkInstSel->SkillUp();
			break;

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		case POINT_CONQUEROR_LEVEL:
			pkInstSel->LevelUp();
			break;
		case POINT_CONQUEROR_LEVEL_STEP:
			pkInstSel->SkillUp();
			break;
#endif

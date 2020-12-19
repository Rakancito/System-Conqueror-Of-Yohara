//Search

bool CPythonNetworkStream::RecvPointChange()
{
			...
			case POINT_LEVEL:
			case POINT_ST:
			case POINT_DX:
			case POINT_HT:
			case POINT_IQ:

//add after

#ifdef ENABLE_CONQUEROR_LEVEL
			case POINT_CONQUEROR_LEVEL:
			case POINT_SUNGMA_STR:
			case POINT_SUNGMA_HP:
			case POINT_SUNGMA_MOVE:
			case POINT_SUNGMA_INMUNE:			
#endif
//Search all

	to->PointChange(POINT_EXP, iExp, true);
	from->CreateFly(FLY_EXP, to);

//Replace with

#ifdef ENABLE_CONQUEROR_LEVEL
	if (to->IsConquerorMap(to->GetMapIndex()))
	{
		to->PointChange(POINT_CONQUEROR_EXP, iExp, true);
		from->CreateFly(FLY_CONQUEROR_EXP, to);
	}	
	else
	{
		to->PointChange(POINT_EXP, iExp, true);
		from->CreateFly(FLY_EXP, to);
	}
#else
	to->PointChange(POINT_EXP, iExp, true);
	from->CreateFly(FLY_EXP, to);
#endif


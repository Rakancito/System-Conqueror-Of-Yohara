//Search

			"alignment = %ld, "

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
			"conquerorlevel = %d, "
			"conqueror_level_step = %d, "
			"sungma_str = %d, "
			"sungma_hp = %d, "
			"sungma_move = %d, "
			"sungma_inmune = %d, "
			"conqueror_exp = %u, "
			"conqueror_point = %d, "
#endif


//Search

		pkTab->lAlignment,

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		pkTab->conquerorlevel,
		pkTab->conqueror_level_step,
		pkTab->sungma_str,
		pkTab->sungma_hp,
		pkTab->sungma_move,
		pkTab->sungma_inmune,
		pkTab->conqueror_exp,
		pkTab->conqueror_point,
#endif	

//Search

		snprintf(queryStr, sizeof(queryStr),
				"SELECT "
				"id,name,job,voice,dir,x,y,z,map_index,exit_x,exit_y,exit_map_index,hp,mp,stamina,random_hp,random_sp,playtime,"
				"gold,gem,level,level_step,st,ht,dx,iq,exp,"
				"stat_point,skill_point,sub_skill_point,stat_reset_count,part_base,part_hair,part_acce, part_aura,"
				"skill_level,quickslot,skill_group,alignment,conquerorlevel,conqueror_level_step,sungma_str,sungma_hp,sungma_move,sungma_inmune,conqueror_exp,conqueror_point,"
				"mobile,horse_level,horse_riding,horse_hp,horse_hp_droptime,horse_stamina,"
				"UNIX_TIMESTAMP(NOW())-UNIX_TIMESTAMP(last_play),horse_skill_point, UNIX_TIMESTAMP(gem_next_refresh),gem_items FROM player%s WHERE id=%d",
				GetTablePostfix(), packet->player_id);


//Okey, i will send you my all query, but you will need check for you, i have a some system's, the important part it's:
			,conquerorlevel,conqueror_level_step,sungma_str,sungma_hp,sungma_move,sungma_inmune,conqueror_exp,conqueror_point,

//after alignment :)

// My Query


#ifdef ENABLE_CONQUEROR_LEVEL
		snprintf(queryStr, sizeof(queryStr),
				"SELECT "
				"id,name,job,voice,dir,x,y,z,map_index,exit_x,exit_y,exit_map_index,hp,mp,stamina,random_hp,random_sp,playtime,"
				"gold,gem,level,level_step,st,ht,dx,iq,exp,"
				"stat_point,skill_point,sub_skill_point,stat_reset_count,part_base,part_hair,part_acce, part_aura,"
				"skill_level,quickslot,skill_group,alignment,prestige,lkill_point,conquerorlevel,conqueror_level_step,sungma_str,sungma_hp,sungma_move,sungma_inmune,conqueror_exp,conqueror_point,"
				"mobile,horse_level,horse_riding,horse_hp,horse_hp_droptime,horse_stamina,"
				"UNIX_TIMESTAMP(NOW())-UNIX_TIMESTAMP(last_play),horse_skill_point, UNIX_TIMESTAMP(gem_next_refresh),gem_items FROM player%s WHERE id=%d",
				GetTablePostfix(), packet->player_id);
#else
		snprintf(queryStr, sizeof(queryStr),
				"SELECT "
				"id,name,job,voice,dir,x,y,z,map_index,exit_x,exit_y,exit_map_index,hp,mp,stamina,random_hp,random_sp,playtime,"
				"gold,gem,level,level_step,st,ht,dx,iq,exp,"
				"stat_point,skill_point,sub_skill_point,stat_reset_count,part_base,part_hair,part_acce, part_aura,"
				"skill_level,quickslot,skill_group,alignment,conquerorlevel,conqueror_level_step,sungma_str,sungma_hp,sungma_move,sungma_inmune,conqueror_exp,conqueror_point,"
				"mobile,horse_level,horse_riding,horse_hp,horse_hp_droptime,horse_stamina,"
				"UNIX_TIMESTAMP(NOW())-UNIX_TIMESTAMP(last_play),horse_skill_point, UNIX_TIMESTAMP(gem_next_refresh),gem_items FROM player%s WHERE id=%d",
				GetTablePostfix(), packet->player_id);
#endif

//Search

	str_to_number(pkTab->lAlignment, row[col++]);

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
	str_to_number(pkTab->conquerorlevel, row[col++]);
	str_to_number(pkTab->conqueror_level_step, row[col++]);	
	str_to_number(pkTab->sungma_str, row[col++]);	
	str_to_number(pkTab->sungma_hp, row[col++]);	
	str_to_number(pkTab->sungma_move, row[col++]);	
	str_to_number(pkTab->sungma_inmune, row[col++]);	
	str_to_number(pkTab->conqueror_exp, row[col++]);	
	str_to_number(pkTab->conqueror_point, row[col++]);
#endif		


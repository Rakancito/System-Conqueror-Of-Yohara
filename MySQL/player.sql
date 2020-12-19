ALTER TABLE `player`
ADD COLUMN `conquerorlevel`  tinyint(2) NOT NULL DEFAULT 0 AFTER `lkill_point`,
ADD COLUMN `conqueror_level_step`  tinyint(1) NOT NULL DEFAULT 0 AFTER `conquerorlevel`,
ADD COLUMN `sungma_str`  smallint(3) NOT NULL DEFAULT 0 AFTER `conqueror_level_step`,
ADD COLUMN `sungma_hp`  smallint(3) NOT NULL DEFAULT 0 AFTER `sungma_str`,
ADD COLUMN `sungma_move`  smallint(3) NOT NULL DEFAULT 0 AFTER `sungma_hp`,
ADD COLUMN `sungma_inmune`  smallint(3) NOT NULL DEFAULT 0 AFTER `sungma_move`,
ADD COLUMN `conqueror_exp`  bigint(255) NOT NULL DEFAULT 0 AFTER `sungma_inmune`;
ADD COLUMN `conqueror_point`  smallint(3) NOT NULL DEFAULT 0 AFTER `conqueror_exp`,
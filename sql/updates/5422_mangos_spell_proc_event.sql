DELETE FROM `spell_proc_event` WHERE `entry` IN ( 15600 );
INSERT INTO `spell_proc_event` VALUES 
(15600,0,0,0,0,0x0000000000000000,0x00000001,0.6);

DELETE FROM `spell_proc_event` WHERE `entry` IN (33881,33882,33883);
INSERT INTO `spell_proc_event` VALUES 
(33881,0,0,0,0,0x0000000000000000,0x00842000,0),
(33882,0,0,0,0,0x0000000000000000,0x00842000,0),
(33883,0,0,0,0,0x0000000000000000,0x00842000,0); 

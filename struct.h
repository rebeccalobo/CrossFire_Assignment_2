#ifndef STRUCT_H
#define STRUCT_H



enum playerclass{
	Elf, Human, Ogre, Wizard
};

enum slottype{
	LevelGround, Hill, City
};


struct player{
	char playername[20];
	enum playerclass class;
	enum slottype type;
	int  slotNum;
	int  lifepts;
	int  intelligence;
	int  strength;
	int  magic;
	int luck_and_dex;

}players[7];



#endif /* relates to STRUCT_H */


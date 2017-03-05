enum playerclass{
	Elf, Human, Ogre, Wizard
};


struct player{
	char playername[20];
	enum playerclass class;
	int  lifepts;
	int  intelligence;
	int  strength;
	int  magic;
	int luck_and_dex;

}players[7];

enum slottype{
	LevelGround=1, Hill=2, City=3
};



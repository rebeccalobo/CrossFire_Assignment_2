enum playerclass{
	Elf=1, Human=2, Ogre=3, Wizard=4
};

struct player
{
	char playername[20];
	enum playerclass class;
	int  lifepts;
	int  intelligence;
	int  strength;
	int  magic;
	int luck;
	int dexterity;

}players[7];



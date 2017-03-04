enum playerclass{
	Elf=1, Human=2, Ogre=3, Wizard=4
};

struct players
{
	char playername[20];
	enum playerclass class;
	int  lifepts;
	int capabilities;
	int  intelligence;
	int  strength;
	int  magic;
	int luck;
	int dexterity;
	int playersize;
}players[10];



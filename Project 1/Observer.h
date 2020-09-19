class Observer
{
public:
	Observer() { ++numConstructions; }
	~Observer() { ++numDestructions;  }
	static int numConstructions;
	static int numDestructions;
};

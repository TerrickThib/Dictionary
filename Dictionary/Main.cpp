#include <iostream>
#include "Dictionary.h"

int main()
{
	Dictionary<const char*, int> testDictionary = Dictionary<const char*, int>();

	testDictionary.additem("T", 1);
	testDictionary.additem("E", 2);
	testDictionary.additem("D", 3);
	int value;

	testDictionary.tryGetValue("E", value);

	if (value == 2) //Checks if if value for e is 2 if it is respond with text
	{
		std::cout << "You did it" << std::endl;
	}
	system("pause");
}
#include <iostream>
#include "Dictionary.h"

int main()
{
	Dictionary<const char*, int> testDictionary = Dictionary<const char*, int>();

	testDictionary.additem("T", 1);
	testDictionary.additem("E", 2);
	testDictionary.additem("D", 3);

	if (testDictionary.containsKey("E"))
	{
		std::cout << "work" << std::endl;
	}
	int value;

	testDictionary.tryGetValue("E", value);

	if (value == 2) //Checks if if value for e is 2 if it is respond with text
	{
		std::cout << "You did it" << std::endl;
	}
	system("pause");

	Dictionary<const char*, int> newDictionary = Dictionary<const char*, int>();

	newDictionary = testDictionary;

	if (newDictionary.containsValue(3)) //Checks if if value for e is 2 if it is respond with text
	{
		std::cout << "You did it" << std::endl;
	}
	else
	{
		std::cout << "It failed" << std::endl;
	}
	system("pause");

	int taco = 0;
	testDictionary.remove("E", taco);
	std::cout << taco;

	newDictionary = testDictionary;

	if (newDictionary.containsKey("E"))
	{
		std::cout << "You did it" << std::endl;
	}
	
	newDictionary.remove("T", taco);
	std::cout << taco;
	system("pause");
	return 0;
}
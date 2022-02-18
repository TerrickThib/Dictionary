#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();

	//Copys the vales of another dictnary
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other) 
	{
		*this = other;
	}

	//Clears the dictionary
	~Dictionary<TKey, TValue>({ clear(); })

	/// <summary>
	/// deletes all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Trys to find the item that matches the given key and spit back the value
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	bool tryGetValue(const TKey key, const TValue& value)const;

	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	void additem(const TKey& key, const TValue& value);//creates a new item with the given key and value and adds it to the dictionary

	bool remove(const TKey key);//Removes the item that has the given key

	bool remove(const TKey key, TValue& value);//Removes the item that has the given key and gives back the value of the item that was removed

	int getCount() const;//gets the number of items in the dictionary

	const operator = (const Dictionary<TKey, TValue>other) Dictionary<TKey, TValue>&;

private:

	struct Item
	{
		TKey itemkey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
	
};


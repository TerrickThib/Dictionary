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
	~Dictionary<TKey, TValue>() { clear(); }

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
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;

};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	delete[] m_items;
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//Goes through list
	for (int i = 0; i < getCount(); i++)
	{
		//If the key is the same as object
		if (m_items[i].itemKey == object)
		{
			return true;
		}
		return false;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//Goes through list
	for (int i = 0; i < getCount(); i++)
	{
		//If the key is the same as object
		if (m_items[i].itemKey == object)
		{
			return true;
		}
		return false;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value) const
{
	//Goes Through list
	for (int i = 0; i < getCount(); i++)
	{
		//If the key is the same as the given key
		if (m_items[i].itemKey == key)
		{
			//set value equel to to the keys value
			value = m_items[i].itemValue;
			return true;
		}
	}
	return false;
}

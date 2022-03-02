#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();

	//Copys the vales of another dictnary
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other)
	{
		clear();//Clears the data from the dictionary
		for (int i = 0; i < other.getCount(); i++)
		{
			additem(other.m_items[i].itemKey, other.m_items[i].itemValue);//adds item at the index of i
		}
		m_count = other.getCount();
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
	bool tryGetValue(const TKey key,TValue& value)const;

	void additem(const TKey& key, const TValue& value);//creates a new item with the given key and value and adds it to the dictionary

	bool remove(const TKey key);//Removes the item that has the given key

	bool remove(const TKey key, TValue& value);//Removes the item that has the given key and gives back the value of the item that was removed

	int getCount() const { return m_count; }//gets the number of items in the dictionary

	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);//copies the values of one dictnary on to another

	TValue operator [](const TKey key);
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
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//Goes through list
	for (int i = 0; i < getCount(); i++)
	{
		//If the key is the same as object
		if (m_items[i].itemValue == object)
		{
			return true;
		}
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key,TValue& value) const
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

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::additem(const TKey& key, const TValue& value)
{
	//Creates a temp aray with 1 more than normal arrray
	Item* tempArray = new Item[getCount() + 1];

	//Copys all the values from old array to new
	for (int i = 0; i < getCount(); i++)
	{
		tempArray[i].itemKey = m_items[i].itemKey;
		tempArray[i].itemValue = m_items[i].itemValue;
	}

	tempArray[m_count].itemKey = key; //Adds key to temp array
	tempArray[m_count].itemValue = value;//Adds value to temp array

	delete[] m_items;
	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	if (!containsKey(key))
	{
		return false;
	}

	//Creates a item pointer 1 smaller
	Item* tempArray = new Item[getCount() - 1];

	//Gets length of aray
	for (int i = 0; i < getCount() - 1; i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[i] = m_items[i];//temp aray values equel items values
		}
	}

	delete[] m_items;
	m_items = tempArray;
	m_count--;
	return true;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	if (!containsKey(key))
	{
		return false;
	}

	//Creates a item pointer 1 smaller
	Item* tempArray = new Item[getCount() - 1];

	//Gets length of aray
	for (int i = 0; i < getCount() - 1; i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[i] = m_items[i];//temp aray values equel items values
		}
		else
		{
			value = m_items[i].itemValue;
		}
	}

	delete[] m_items;
	m_items = tempArray;
	m_count--;
	return true;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	clear();//Deletes all items in dictionary  

	for (int i = 0; i < other.getCount(); i++)//Iterarates through wile less than count
	{
		//m_items[i] = other.m_items[i];//Copys dictionarys data into this one
		additem(other.m_items[i].itemKey, other.m_items[i].itemValue);
	}

	m_count = other.getCount();//Copys the item count

	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value;

	tryGetValue(key, value);

	return value;
}

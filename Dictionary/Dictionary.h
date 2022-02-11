#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>();
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
	bool tryGetValue(const TKey key, const TValue& value)const;

	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	void additem(const TKey& key, const TValue& value);
	bool remove(const TKey key);
	bool remove(const TKey key, TValue& value);
	int getCount() const;
	const operator = (const Dictionary<TKey, TValue>other) Dictionary<TKey, TValue>&;

private:
	m_items Item<TKey, TValue>* = nullptr;
	m_count int = 0;
};


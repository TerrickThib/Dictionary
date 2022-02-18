**Terrick Thibodeaux**  
S218032
Dictionary 
Algorithms and Data Structures C++ 
# I.Requirments  
**1.Description of Problem**    

**Problem Statment**  
The creation of a dictinary that stores items wich can be called from a char  

**Problem Specifications:**  
- Implment Uml properly   

**Input Information** 
- Input a list of items with a key and value  

**Output Information**  
- Ablity to get a value or a key win the dictionary  

# II.Design 
1. *System Architecture*   

Uses Functions and dictionarys to excute project susfully  

2. *Object Information*  
- **File Name:** Dictionary.h  

Name: Dictionary<TKey, TValue>()  
Description: Is the base constructer  
Visablity: Public  

Name: Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other)  
Description: Copys the values of another dictinary  
Visablity: Public  

Name: ~Dictionary<TKey, TValue>()  
Description: Clears the dictinary  
Visablity: Public  

Name: clear()  
Description: deletes all items in dictinary  
Visablity: Public   

Name: containsKey(const TKey object) const  
Description: checks to see if an item that has the given value is in the dictionary  
Visablity: Public  

Name: containsValue(const TValue object) const  
Description: checks to see if an item that has the given value is in the dictionary  
Visablity: Public  

Name: tryGetValue(const TKey key,TValue& value)const  
Description: Trys to find the item that matches the given key and spit back the value  
Visablity: Public  

Name: additem(const TKey& key, const TValue& value) 
Description: creates a new item with the given key and value and adds it to the dictionary  
Visablity: Public  

Name: remove(const TKey key)   
Description: Removes the item that has the given key  
Visablity: Public  

Name: remove(const TKey key, TValue& value)  
Description: Removes the item that has the given key and gives back the value of the item that was removed  
Visablity: Public  

Name: getCount() const  
Description: gets the number of items in the dictionary  
Visablity: Public  

Name: Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other)  
Description: copies the values of one dictnary on to another  
Visablity: Public  


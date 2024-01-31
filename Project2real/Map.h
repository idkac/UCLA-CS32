#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <string>

using KeyType = std::string;
using ValueType = double;

class Map
{
  public:
    Map();
    ~Map();
    bool empty() const;
    int size() const;
    bool insert(const KeyType& key, const ValueType& value);
    bool update(const KeyType& key, const ValueType& value);
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
    bool erase(const KeyType& key);
    bool contains(const KeyType& key) const;
    bool get(const KeyType& key, ValueType& value) const;
    bool get(int i, KeyType& key, ValueType& value) const;
    void swap(Map& other);
    Map (const Map& other);
    Map& operator=(const Map& other);

  private:
    struct ValueHolder
    {
        KeyType key;
        ValueType value;

        ValueHolder* previous;
        ValueHolder* next;

        KeyType returnKey() const;
        ValueType returnValue() const;
        void setKey(KeyType inputKey);
        void setValue (ValueType inputValue);
    };

    void clear();
    int m_size;
    ValueHolder* tailsGuard;
    ValueHolder* dummy;
};

bool merge(const Map& m1, const Map& m2, Map& result);
void reassign(const Map& m, Map& result);

#endif // MAP_H_

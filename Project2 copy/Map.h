#ifndef PROJECT2_MAP_H
#define PROJECT2_MAP_H


#include <string>
#include <iostream>

using KeyType = std::string;
using ValueType = double;


class Map
{
 public:
    Map();         // Create an empty map (i.e., one whose size() is 0).

    bool empty() const;  // Return true if the map is empty, otherwise false.

    int size() const;    // Return the number of key/value pairs in the map.


    bool insert(const KeyType& key, const ValueType& value);

    bool update(const KeyType& key, const ValueType& value);

    bool insertOrUpdate(const KeyType& key, const ValueType& value);

    bool erase(const KeyType& key);

    bool contains(const KeyType& key) const;

    bool get(const KeyType& key, ValueType& value) const;

    bool get(int i, KeyType& key, ValueType& value) const;

    void swap(Map& other);

    private:
        int map_size;
        struct ValueHolder {
            KeyType key;
            ValueType value;

            KeyType returnKey() const;
            ValueType returnValue() const;
            void setKey(KeyType inputKey);
            void setValue (ValueType inputValue);
        };
        static const int DEFAULT_MAX_ITEMS = 150;
        ValueHolder array[DEFAULT_MAX_ITEMS];
};
#endif //PROJECT2_GAMERMAP_H
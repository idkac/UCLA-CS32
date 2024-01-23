#include "Map.h"

#include <iostream>
#include <string>



KeyType Map::ValueHolder::returnKey() const{
    return key;
}

ValueType Map::ValueHolder::returnValue() const{
    return value;
}

void Map::ValueHolder::setKey(KeyType inputKey)
{
    key = inputKey;
}

void Map::ValueHolder::setValue (ValueType inputValue) {
    value = inputValue;
}

Map::Map()
{
   map_size = 0;
}         // Create an empty map (i.e., one whose size() is 0).

bool Map::empty() const
{
    return map_size == 0;
}
// Return true if the map is empty, otherwise false.
int Map::size() const
{
    return map_size;
}
// Return the number of key/value pairs in the map

bool Map::insert(const KeyType& key, const ValueType& value)
{
    if (map_size >= DEFAULT_MAX_ITEMS)
        return false;
    else {
        if (this->contains(key))
            return false;
        else
        {
            array[map_size].setKey(key);
            array[map_size].setValue(value);
            map_size++;
            return true;
        }
    }
}
/* If key is not equal to any key currently in the map and if the
 key/value pair can be added to the map, then do so and return true.
 Otherwise, make no change to the map and return false (indicating
 that either the key is already in the map, or the map has a fixed
 capacity and is full).
*/

bool Map::update(const KeyType& key, const ValueType& value)
{
    if (this->contains(key))
    {
        for (int i = 0; i < map_size; i++)
        {
            if (array[i].returnKey() == key) {
                array[i].setValue(value);
                return true;
            }
        }
    }
  return false;
}
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value that it currently maps to, but instead map to
      // the value of the second parameter; in this case, return true.
      // Otherwise, make no change to the map and return false.

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    if (this->update(key, value))
        return true;
    else if (this->insert(key, value))
        return true;
    else
        return false;
}
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value that it currently maps to, but instead map to
      // the value of the second parameter; in this case, return true.
      // If key is not equal to any key currently in the map, and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that the key is not already in the map and the map has a fixed
      // capacity and is full).

bool Map::erase(const KeyType& key)
{
  for (int i = 0; i < map_size; i++)
  {
    if (array[i].returnKey() == key)
    {
        for (int j = i; j < map_size - 1; j++)
        {
            array[j].setValue(array[j+1].returnValue());
            array[j].setKey(array[j+1].returnKey());
        }
        map_size--;
        return true;
    }
  }

  return false;
}
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.

bool Map::contains(const KeyType& key) const
{
  for (int i = 0; i < map_size; i++)
  {
    if (array[i].returnKey() == key)
      return true;
  }
  return false;
}
      // Return true if key is equal to a key currently in the map, otherwise
      // false.

bool Map::get(const KeyType& key, ValueType& value) const
{
  for (int i = 0; i < map_size; i++)
  {
    if (array[i].returnKey() == key)
    {
      value = array[i].returnValue();
      return true;
    }
  }
  return false;
}
      // If key is equal to a key currently in the map, set value to the
      // value in the map which the key maps to, and return true.  Otherwise,
      // make no change to the value parameter of this function and return
      // false.

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    for (int j = 0; j < map_size; j++)
    {
        int count = 0;
        for (int k = 0; k < map_size; k++)
        {
            if (array[j].returnKey() > array[k].returnKey())
                count++;
        }
        if (count == i)
        {
            key = array[j].returnKey();
            value = array[j].returnValue();
            return true;
        }
    }
  return false;
}
      // If 0 <= i < size(), copy into the key and value parameters the
      // key and value of the key/value pair in the map whose key is strictly
      // greater than exactly i keys in the map and return true.  Otherwise,
      // leave the key and value parameters unchanged and return false.

void Map::swap(Map& other)
{
  int temp = map_size;
  map_size = other.map_size;
  other.map_size = temp;
  for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
  {
    KeyType keyTemp = array[i].returnKey();
    ValueType valueTemp = array[i].returnValue();


    array[i].setKey(other.array[i].returnKey());
    array[i].setValue(other.array[i].returnValue());

    other.array[i].setValue(valueTemp);
    other.array[i].setKey(keyTemp);
  }
}
    // Exchange the contents of this map with the other one.



#include "Map.h"

#include <__config>
#include <iostream>
#include <iterator>
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
    dummy = new ValueHolder;
    m_size = 0;
    tailsGuard = new ValueHolder;
    dummy -> next = tailsGuard;
    tailsGuard -> previous = dummy;
}

void Map::clear()
{
    ValueHolder* temp = dummy;
    while (temp != nullptr)
    {
        ValueHolder* n = temp -> next;
        delete temp;
        temp = n;
    }
    dummy = nullptr;
    m_size = 0;
}

Map::~Map()
{
    clear();
}

Map::Map(const Map& other)
{
    dummy = new ValueHolder;
    tailsGuard = new ValueHolder;
    dummy -> next = tailsGuard;
    tailsGuard -> previous = dummy;
    m_size = 0;

    ValueHolder* input = other.dummy -> next;
    for (int i = 0; i < other.size(); i++)
    {
        this -> insert(input -> returnKey(), input -> returnValue());
        input = input -> next;
    }
}

Map& Map::operator=(const Map &other)
{
    if (this != &other)
    {
        clear();
        dummy = new ValueHolder;
        tailsGuard = new ValueHolder;
        dummy -> next = tailsGuard;
        tailsGuard -> previous = dummy;

        ValueHolder* input = other.dummy -> next;
        for (int i = 0; i < other.size(); i++)
        {
            this -> insert(input -> returnKey(), input -> returnValue());
            input = input -> next;
        }
    }

    return *this;
}

bool Map::empty() const
{
    return m_size == 0;
}

int Map::size() const
{
    return m_size;
}

bool Map::insert(const KeyType &key, const ValueType &value)
{
    if (this -> contains(key))
        return false;
    else
    {
        ValueHolder* temp = dummy;
        while (temp -> next != tailsGuard && temp -> next -> returnKey() <= key)
        {
            temp = temp -> next;
        }
        ValueHolder* newHolder = new ValueHolder;
        newHolder -> setKey(key);
        newHolder -> setValue(value);

        newHolder -> previous = temp;
        newHolder -> next = temp -> next;
        temp -> next -> previous = newHolder;
        temp -> next = newHolder;
        // previous newholder temp
        // temp newholder
        // temp-> next = newholder -> next;

        m_size++;
        return true;
    }
}

bool Map::update(const KeyType &key, const ValueType &value)
{
    if (!(this -> contains(key)))
        return false;
    else
    {
        ValueHolder* temp = dummy;
        while (temp -> next != tailsGuard && temp -> returnKey() != key)
            temp = temp -> next;
        if (temp -> returnKey() == key)
        {
            temp -> setValue(value);
            return true;
        }
        else
            return false;
    }
}

bool Map::insertOrUpdate(const KeyType &key, const ValueType &value)
{
    if (this -> insert(key, value))
        return true;
    else if (this -> update(key, value))
        return true;
    else
        return false;
}

bool Map::erase(const KeyType &key)
{
    if (!(this -> contains(key)))
        return false;
    else
    {
        ValueHolder* temp = dummy;
        while (temp -> next != tailsGuard && temp -> returnKey() != key)
            temp = temp -> next;
        if (temp -> returnKey() == key)
        {
            temp -> previous -> next = temp -> next;
            temp -> next -> previous = temp -> previous;
            delete temp;
            m_size--;
            return true;
        }
        else
            return false;
    }
}

bool Map::contains(const KeyType &key) const
{
    ValueHolder* temp = dummy;
    if (temp -> next == tailsGuard)
    {
        return false;
    }
    else
        temp = temp -> next;
    while (temp -> next != tailsGuard && temp -> returnKey() != key)
        temp = temp -> next;
    return temp -> returnKey() == key;
}

bool Map::get(const KeyType& key, ValueType& value) const
{
    if (!(this -> contains(key)))
        return false;
    else
    {
        ValueHolder* temp = dummy;
        while (temp -> next != tailsGuard && temp -> returnKey() != key)
            temp = temp -> next;
        if (temp -> returnKey() == key)
        {
            value = temp -> returnValue();
            return true;
        }
        else
            return false;
    }
}

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if (i >= m_size)
        return false;
    else
    {
        ValueHolder *temp = dummy;
        for (int j = 0; j <= i; j++)
            temp = temp -> next;
        key = temp -> returnKey();
        value = temp -> returnValue();
        return true;
    }
}

void Map::swap(Map &other)
{
    int tempSize = other.size();
    other.m_size = m_size;
    m_size = tempSize;
    ValueHolder* temp = dummy;
    dummy = other.dummy;
    other.dummy = temp;
}


bool merge(const Map& m1, const Map& m2, Map& result)
{
    bool returnVal;
    Map m1temp = m1;
    Map m2temp = m2;

    while (m1temp.size() != 0 || m2temp.size() != 0)
    {

        if (m1temp.size() != 0)
        {
            KeyType tempKey;
            ValueType tempValue;
            ValueType tempValue2;
            m1temp.get(0, tempKey, tempValue);
            if (m2temp.get(tempKey, tempValue2)) {
                if (tempValue == tempValue2) {
                    result.insert(tempKey, tempValue2);
                    m1temp.erase(tempKey);
                    m2temp.erase(tempKey);
                } else
                {
                    m1temp.erase(tempKey);
                    m2temp.erase(tempKey);
                    returnVal = false;
                }
            }
            else
            {
                result.insert(tempKey, tempValue);
                m1temp.erase(tempKey);
            }
        }
        else if (m2temp.size() != 0)
        {

            KeyType tempKey;
            ValueType tempValue;
            ValueType tempValue2;
            m2temp.get(0, tempKey, tempValue);
            if (m1temp.get(tempKey, tempValue2))
            {
                if (tempValue == tempValue2)
                {
                    result.insert(tempKey, tempValue2);
                    m1temp.erase(tempKey);
                    m2temp.erase(tempKey);
                }
                else
                    returnVal = false;
            }
            else
            {
                result.insert(tempKey, tempValue);
                m2temp.erase(tempKey);
            }
        }
    }
    return returnVal;
}

void reassign(const Map& m, Map& result)
{
    ValueType tempFinal, tempFinal3;
    KeyType tempFinal1, tempFinal2;
    m.get(0, tempFinal1, tempFinal);
    for (int i = 0; i < m.size() - 1; i++)
    {
        ValueType tempValue, tempValue2;
        KeyType tempKey, tempKey2;
        m.get(i, tempKey, tempValue);
        m.get(i + 1, tempKey2, tempValue2);
        result.insertOrUpdate(tempKey, tempValue2);
        result.insertOrUpdate(tempKey2, tempValue);
    }
    result.get(m.size() - 1, tempFinal2, tempFinal3);
    result.update(tempFinal2, tempFinal);
}

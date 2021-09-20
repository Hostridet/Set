#include <iostream>

#pragma once

class Set
{
private:
    struct Element
    {
        int Value;
        Element* next;
    };
    Element* Head;

protected:

public:
    Set();
    Set(const Set &sets);
    int length();
    bool TryToFind(int a);
    Set operator+(int a);
    Set operator/(int a);
    Set operator/(Set Second);
    Set operator+(Set Second);
    friend Set operator+(int a, Set& Second);
    Set operator*(int a);
    Set operator*(Set Second);
    friend Set operator*(int a, Set& Second);
    friend std::ostream &operator<<(std::ostream &out, Set s);
    ~Set();
};
void Sieve(unsigned short int n);
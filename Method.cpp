#include <iostream>
#include "Method.h"

using namespace std;
Set::Set()
{
    Head = NULL;
}

Set::Set(const Set &sets)
{
    Head = sets.Head;
}

int Set::length()
{
    unsigned short int countelem = 0;
    if (Head == NULL)
    {
        return 0;
    }
    Element* cur1 = Head;
    Element* cur2 = cur1->next;
    if (cur1 == cur2)
    {
        return 1;
    }
    else
    {
        countelem += 1;
        while ((cur2 != 0))
        {
            cur1 = cur2;
            cur2 = cur1->next;
            countelem += 1;
        }
        return countelem;
    }
}

ostream &operator<<(ostream &out, Set s) {
    if (s.Head == NULL) {
        cout << "- set is empty" << endl;
    } else {
        Set::Element *cur1 = s.Head;
        Set::Element *cur2 = cur1->next;
        if (cur1 == cur2) {
            cout << cur1->Value << endl;
            cout << "- set is consist " << s.length() << " elementary." << endl << endl << endl;
        } else {
            while ((cur2 != 0)) {
                cout << cur1->Value << ", ";
                cur1 = cur2;
                cur2 = cur2->next;
            }
            cout << cur1->Value << endl;
            cout << "- set is consist " << s.length() << " elementary." << endl << endl << endl;
        }
    }
}

bool Set::TryToFind(int a)
{
    if (Head == NULL)
    {
        return 0;
    }
    Element* cur1 = Head;
    Element* cur2 = cur1->next;
    if ((cur1->Value==a))
    {
        return true;
    }
    else
    {
        while ((cur2 != 0))
        {
            cur1 = cur2;
            cur2 = cur1->next;
            if ((cur1->Value==a))
            {
                return true;
            }
            if (cur2 != 0)
            {
                if ((cur2->Value==a))
                {
                    return true;
                }
            }
        }
        return false;
    }
}

Set Set::operator+(int a)
{

    Set Se1 = *this;
    if (Se1.TryToFind(a)==0)
    {
        Element* elem = new Element();
        elem->Value = a;
        elem->next = Head;
        Se1.Head = elem;
    }
    return Se1;
}

Set Set::operator/(int a)
{
    Set Se1 = *this;
    Set Se2;
    if (Se1.length()==0)
    {
        return Se1;
    }
    else
    {
        int nc = Se1.length();
        if (Se1.TryToFind(a))
        {
            nc = nc-1;
        }
        int j = 0;
        int SecMas[nc];
        for (unsigned short int i=0; i<nc; ++i)
        {
            SecMas[i] = 0;
        }

        if (Se1.Head == NULL)
        {
            return Se1;
        }
        else {
            Element *cur1 = Se1.Head;
            Element *cur2 = cur1->next;
            if (cur1 == cur2)
            {
                if (cur1->Value != a)
                {
                    SecMas[j]=cur1->Value;
                    ++j;
                }
            }
            else
            {
                while ((cur2 != 0))
                {
                    if (cur1->Value != a)
                    {
                        SecMas[j]=cur1->Value;
                        ++j;
                    }
                    cur1 = cur2;
                    cur2 = cur2->next;
                }
                if (cur1->Value != a)
                {
                    SecMas[j]=cur1->Value;
                    ++j;
                }
            }
        }
        for (unsigned short int i=0; i<nc; ++i)
        {
            Se2 = Se2 + SecMas[i];
        }
        return Se2;
    }
}

Set Set::operator/(Set Second)
{
    Set Se1 = *this;
    Set Se3;
    int mc = Se1.length();
    int z = 0;
    int FirMas[mc];
    for (unsigned short int i=0; i<mc; ++i)
    {
        FirMas[i] = 0;
    }

    if (Se1.Head == NULL)
    {
        return Se3;
    }
    else {
        Element *cur1 = Se1.Head;
        Element *cur2 = cur1->next;
        if (cur1 == cur2)
        {
            FirMas[z]=cur1->Value;
            ++z;
        }
        else
        {
            while ((cur2 != 0))
            {
                FirMas[z]=cur1->Value;
                ++z;
                cur1 = cur2;
                cur2 = cur2->next;
            }
            FirMas[z]=cur1->Value;
            ++z;
        }
    }
    for (unsigned short int i=0; i<mc; ++i)
    {
        if (Second.TryToFind(FirMas[i]) == 0)
        {
            Se3 = Se3 + FirMas[i];
        }
    }
    cout << endl;
    return Se3;
}

Set Set::operator+(Set Second)
{
    Set Se1 = *this;
    int nc = Second.length();
    int j = 0;
    int SecMas[nc];
    for (unsigned short int i=0; i<nc; ++i)
    {
        SecMas[i] = 0;
    }

    if (Second.Head == NULL)
    {
        return Se1;
    }
    else {
        Element *cur1 = Second.Head;
        Element *cur2 = cur1->next;
        if (cur1 == cur2)
        {
            SecMas[j]=cur1->Value;
            ++j;
        }
        else
        {
            while ((cur2 != 0))
            {
                SecMas[j]=cur1->Value;
                ++j;
                cur1 = cur2;
                cur2 = cur2->next;
            }
            SecMas[j]=cur1->Value;
            ++j;
        }
    }

    for (unsigned short int i=0; i<nc; ++i)
    {
        Se1 = Se1+SecMas[i];
    }
    return Se1;
}

Set operator+(int a, Set &Second) {
    return Second + a;
}

Set Set::operator*(int a)
{
    Set Third;
    Set Se1 = *this;
    if (Se1.length()==0)
    {
        return Se1;
    }
    else
    {
        if (Se1.TryToFind(a) == 1)
        {
            Third = Third+a;
            return Third;
        }
        else
        {
            return Third;
        }
    }
}

Set Set::operator*(Set Second)
{
    Set Se1 = *this;
    Set Se3;
    int nc = Second.length();
    int mc = Se1.length();
    int j = 0;
    int z = 0;
    int FirMas[mc];
    int SecMas[nc];
    for (unsigned short int i=0; i<nc; ++i)
    {
        SecMas[i] = 0;
    }
    for (unsigned short int i=0; i<mc; ++i)
    {
        FirMas[i] = 0;
    }

    if (Second.Head == NULL)
    {
        return Se3;
    }
    else {
        Element *cur1 = Second.Head;
        Element *cur2 = cur1->next;
        if (cur1 == cur2)
        {
            SecMas[j]=cur1->Value;
            ++j;
        }
        else
        {
            while ((cur2 != 0))
            {
                SecMas[j]=cur1->Value;
                ++j;
                cur1 = cur2;
                cur2 = cur2->next;
            }
            SecMas[j]=cur1->Value;
            ++j;
        }
    }
    if (Se1.Head == NULL)
    {
        return Se3;
    }
    else {
        Element *cur1 = Se1.Head;
        Element *cur2 = cur1->next;
        if (cur1 == cur2)
        {
            FirMas[z]=cur1->Value;
            ++z;
        }
        else
        {
            while ((cur2 != 0))
            {
                FirMas[z]=cur1->Value;
                ++z;
                cur1 = cur2;
                cur2 = cur2->next;
            }
            FirMas[z]=cur1->Value;
            ++z;
        }
    }
    for (unsigned short int i=0; i<mc; ++i)
    {
        for (unsigned short int q=0; q<nc; ++q)
        {
            if (FirMas[i]==SecMas[q])
            {
                Se3 = Se3 + FirMas[i];
            }
        }
    }
    cout << endl;
    return Se3;
}

Set operator*(int a, Set &Second)
{
    return Second * a;
}

Set::~Set()
{
    Head = NULL;
}

void Sieve(unsigned short int n)
{
    {
        Set M;
        for (int i = n-1; i >= 2; i--)
        {
            M = M + i;
        }
        int a = 2;
        while(a != n)
        {
            for (int i = a + 1; i < n; ++i)
            {
                if (i % a == 0)
                    M = M / i;
            }
            ++a;
        }
        cout << "Sieve of Eratosfena on Set from 2 to " << n << " : " << endl << M;
    }
}



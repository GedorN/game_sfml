#pragma once
#include<SFML/Graphics.hpp>
#include<stdlib.h>

template<class TIP>
class Element
{
    private:
    TIP* current;
    Element<TIP> *next;

    public:
    Element();
    ~Element();
    
    void add(TIP* info);
    void setNext(Element<TIP>* info);

    TIP* getCurrent();
    Element<TIP>* getNext();
};

template<class TIP>
Element<TIP>::Element()
{
    current= NULL;
    next= NULL;
}

template<class TIP>
Element<TIP>::~Element()
{
    delete current;
}

template<class TIP>
void Element<TIP>::add(TIP* info)
{
    current= info;
}

template<class TIP>
void Element<TIP>::setNext(Element<TIP>* info)
{
    next= info;
}
template<class TIP>
TIP* Element<TIP>::getCurrent()
{
    return current;
}

template<class TIP>
Element<TIP>* Element<TIP>::getNext()
{
    return next;
}

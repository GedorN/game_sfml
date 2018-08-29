#include"../Headers/LevelList.hpp"
#include<stdlib.h>
#include<stdio_ext.h>
LevelList::LevelList()
{
    n= 0;
    first = NULL;
    current = NULL;
}

LevelList::~LevelList()
{
    Element<Level> *aux;
    Element<Level> *aux2;

    aux = first;
    aux2= aux;

    while(aux2 != NULL )
    {
        printf("\nVou matar ein");
        aux2= aux2->getNext();
        delete aux;
        aux = aux2;
        n--;
    }

    first = NULL;
    current= NULL;
}

void LevelList::add(Level *info)
{
    Element<Level> *aux= NULL;
    aux = new Element<Level>();

    aux->add(info);

    if(aux != NULL)
    {
        if(first == NULL)
        {
            first = aux;
            current = aux;
        }
        else
        {
            current->setNext(aux);
            current= current->getNext();
        }
        n++;
    } 
    else 
    {
        printf("\nFALHA AO ADICIONAR LEVEL!");
    }
}

Level* LevelList::getCurrentLevel(unsigned int x)
{
    Element<Level> *aux= NULL;
    if(x <= n )
    {
            aux= first;

        for(int i =1; i < x; i++)
        {
            aux = aux->getNext();
        }
    }
    return (aux->getCurrent());
}

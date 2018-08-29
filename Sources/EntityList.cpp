#include "../Headers/EntityList.hpp"
#include <stdlib.h>
#include <stdio.h>
EntityList::EntityList()
{
    n = 0;
    first = NULL;
    current = NULL;
    printf("\nCriado!!!!");
}

EntityList::~EntityList()
{

    Element<Entity> *aux1;
    Element<Entity> *aux2;

    aux1 = first;
    aux2 = aux1;

    while (aux1 != NULL)
    {
        aux2 = aux2->getNext();
        delete aux1;
        aux1 = aux2;
        n--;
    }

    first = NULL;
    current = NULL;
}

void EntityList::add(Entity *info)
{
    Element<Entity> *aux = new Element<Entity>();
    aux->add(info);

    if (aux != NULL)
    {
        if (first == NULL)
        {
            first = aux;
            current = aux;
        }
        else
        {
            current->setNext(aux);
            current = current->getNext();
        }
        n++;
        printf("\nITEM ADICIONADO!");
    }
    else
    {
        printf("\nFALHA AO ADICIONAR ITEM");
    }
}

void EntityList::update(unsigned int frame)
{
    Element<Entity> *aux = first;
    Entity *character;
    while (aux != NULL)
    {
        character = aux->getCurrent();
        character = static_cast<Character *>(character);
        character->update(frame);
        aux = aux->getNext();
    }
}

void EntityList::getMovement()
{
    Element<Entity> *aux = first;
    Entity *character;
    while (aux != NULL)
    {
        character = aux->getCurrent();
        character->getMovement();
        aux = aux->getNext();
    }
}

void EntityList::move()
{

    Element<Entity> *aux = first;
    Entity *character;
    while (aux != NULL)
    {
        character = aux->getCurrent();
        character->move();
        aux = aux->getNext();
    }
}

void EntityList::draw(sf::RenderWindow *window)
{
    Element<Entity> *aux = first;
    Entity *character;
    while (aux != NULL)
    {
        character = aux->getCurrent();
        character->draw(window);
        aux = aux->getNext();
    }
}

Entity *EntityList::getEntity(int x)
{
    Element<Entity> *aux = first;
    for (int i = 0; i < n; i++)
    {
        if (i == x)
        {

            break;
        }
        aux = aux->getNext();
    }

    return (aux->getCurrent());
}

int EntityList::getN()
{
    return n;
}

void EntityList::free()
{
    Element<Entity> *aux = first;
    Element<Entity> *aux2 = NULL;
    Entity *info;
    while (aux != NULL)
    {
        info = aux->getCurrent();
        if (info->getHealth() <= 0)
        {
            if (aux == first)
            {
                aux2 = aux;
                delete aux;
                first = aux2;
                n--;
            }
            else
            {
                aux2->setNext(aux->getNext());
                delete aux;
                aux = aux2;
                n--;
            }
        }
        aux2 = aux;
        aux = aux->getNext();
    }
}
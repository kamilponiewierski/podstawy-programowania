#include <malloc.h>
#include "list.h"

struct List
{
    Node *first;
    Node *last;
};

struct Node
{
    Node *next;
    Node *previous;
    T value;
};


Node *getNode(T a)
{
    Node *node = malloc(sizeof(Node));
    node->value = a;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

List *constructList(T a)
{
    List *list = malloc(sizeof(List));

    Node *node = getNode(a);
    list->first = node;
    list->last = list->first;
    return list;
}

List *constructListN(size_t elements, T value)
{
    List *list = constructList(value);

    for (int i = 0; i < elements - 1; i++)
    {
        push_back(list, value);
    }

    return list;
}


List *constructListFromRange(const T *from, const T *to)
{
    List *list = NULL;
    T *iter = from;
    while (iter <= to)
    {
        if (list == NULL)
        {
            list = constructList(*iter);
        } else
        {
            push_back(list, *iter);
        }
        iter++;
    }
    return list;
}

void destruct(List *l)
{
    while (l->last != NULL) pop_back(l);
    free(l);
    l = NULL;
}

List *cloneList(const List *l)
{
    List *listCopy = constructList(l->first->value);

    Node *origIter = l->first->next;

    while (origIter != NULL)
    {
        push_back(listCopy, origIter->value);
        origIter = origIter->next;
    }
    return listCopy;
}

size_t size(const List *l)
{
    int size = 0;
    Node *currentNode = l->first;
    while (currentNode != NULL)
    {
        size++;
        if (currentNode->next != NULL)
            currentNode = currentNode->next;
        else break;
    }
    return size;
}

bool empty(const List *l)
{
    return l->last == NULL;
}

T *front(List *l)
{
    return &l->first->value;
}

T *back(List *l)
{
    return &l->last->value;
}

void push_front(List *l, T element)
{
    Node *newFirst = getNode(element);
    newFirst->next = l->first;
    l->first->previous = newFirst;
    l->first = newFirst;
}

void pop_front(List *list)
{
    Node *poppedNode = list->first;
    int s = size(list);
    if (s > 0)
    {
        if (s == 1)
        {
            list->first = NULL;
            list->last = NULL;
        } else
        {
            list->first = poppedNode->next;
            list->first->previous = NULL;
        }

        free(poppedNode);
    }
}

void push_back(List *l, T element)
{
    Node *newLast = getNode(element);
    newLast->previous = l->last;
    l->last->next = newLast;
    l->last = newLast;
}

void pop_back(List *list)
{
    Node *poppedNode = list->last;
    int s = size(list);
    if (s > 0)
    {
        if (s == 1)
        {
            list->first = NULL;
            list->last = NULL;
        } else
        {
            list->last = poppedNode->previous;
            list->last->next = NULL;
        }

        free(poppedNode);
    }
}

void printList(List *l)
{
    Node *curr = l->first;

    if (curr == NULL)
        printf("Empty list!");

    while (curr != NULL)
    {
        printf("%ld", curr->value);
        curr = curr->next;
    }
}


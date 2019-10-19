#include "StringList.h"
#include <string>
#include <iostream>

StringList::StringList()
{
  _head = NULL;
  _tail = NULL;
  _size = 0;
}

StringList::StringList(const StringList& other)
{
  _head = other._head;
  _tail = other._tail;
  _size = other._size;
}
StringList::~StringList()
{
  while(!empty())
    pop_front();
}

StringList& StringList::operator=(const StringList& other)
{
 clear();
 for(llist *ptr = other._head; ptr != NULL; ptr = ptr->next)
 {
	push_back(ptr->str);
 }
 _size = other._size;
 return *this;
}

size_t StringList::getSize()
{
  return _size;
}
std::string& StringList::front()
{
  return _head->str;
}
std::string& StringList::back()
{
  return _tail->str;
}

void StringList::push_front(std::string str)
{
  llist *newItem = new llist;
  newItem->str = str;
  newItem->next = _head;
  newItem->prev = NULL;
  if (_head != NULL)
    _head->prev = newItem;
  if (_tail == NULL)
    _tail = newItem;
  _head = newItem; //update head
  _size++;
}
void StringList::push_back(std::string str)
{
    llist *newItem = new llist;
    newItem->str = str;
    newItem->next = NULL;
    newItem->prev = _tail;
    if (_tail != NULL)
      _tail->next = newItem;
    if (_head == NULL)
      _head = newItem;
    _tail = newItem; //update tail
    _size++;
}

void StringList::pop_front()
{
  llist *ptr = _head;
  _head = _head->next;
  //head->prev = NULL;
  if (_head != NULL)
    _head->prev = _head->prev->prev;
  else
    _tail = NULL;
  delete ptr;
  _size--;
}
void StringList::pop_back()
{
  llist *ptr = _tail;
  _tail = _tail->prev;
  if (_tail != NULL)
    _tail->next = _tail->next->next;
  else
    _head = NULL;
  delete ptr;
  _size--;
}

bool StringList::empty() const
{
  return (_head == NULL) && (_tail == NULL);
}
void StringList::clear()
{
  while(!empty())
    pop_front();
  _size = 0;
}

void StringList::reverse()
{
  llist *temp;
  for(llist *ptr = _head; ptr != 0; ptr = ptr->prev)
	{
	  temp = ptr;
	  ptr->next = ptr->prev;
	  ptr->prev = temp;
	}
  temp = _tail;
  _tail = _head;
  _head = temp;
}

void StringList::unique()
{
  for(llist *ptr = _head; ptr != NULL; ptr = ptr->next)
    {
    while ((ptr->next != NULL) && (ptr->str == ptr->next->str))
      {
        llist *saveptr = ptr->next;
        ptr->next = saveptr->next;

        if (saveptr->next != NULL)
          saveptr->next->prev = ptr;
        else
          _tail = ptr;

        delete saveptr;
        _size--;
      }
    }
}

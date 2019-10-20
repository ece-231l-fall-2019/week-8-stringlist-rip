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
  _head = other.getHead();
  _tail = other.getTail();
  _size = other.size();
}
StringList::~StringList()
{
  while(!empty())
    pop_front();
}

StringList& StringList::operator=(const StringList& other)
{
 clear(); //clear a List first
 for(llist *ptr = other.getHead(); ptr != NULL; ptr = ptr->next)
	   push_back(ptr->str);
 _size = other._size;
 return *this;
}
StringList::llist * StringList::getHead() const
{
  return _head;
}
StringList::llist * StringList::getTail() const
{
  return _tail;
}
size_t StringList::size() const
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
bool StringList::empty() const
{
  return _head == NULL;
}
void StringList::clear()
{
  while(!empty())
    pop_front();
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
    if (!empty()) //if list is empty, don't need to pop_front
    {             //it will return error if not have this condition
      llist *ptr = _head;
      _head = _head->next;
      if (_head != NULL)
        _head->prev = _head->prev->prev;
      else
        _tail = NULL;
      delete ptr;
      _size--;
    }
}
void StringList::pop_back()
{
  if (!empty()) //if list is empty, don't need to pop_back
  {             //it will return error if not have this condition
    llist *ptr = _tail;
    _tail = _tail->prev;
    if (_tail != NULL)
      _tail->next = _tail->next->next;
    else
      _head = NULL;
    delete ptr;
    _size--;
  }
}

void StringList::reverse()
{
  if ((!empty()) && (_head->next != NULL)) //check if the list is not empty and not have a single element
  {
    llist *temp;
    llist *ptr = _head;

    while (ptr != NULL)
    {
      temp = ptr->prev;
      ptr->prev = ptr->next;
      ptr->next = temp;
      ptr = ptr->prev;
    }

    temp = temp->prev; //temp become new head
    _tail = _head;   //update tail
    _head = temp;     //update head
  }

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

void StringList::printstr()
{
  for (llist *ptr = _head; ptr != NULL; ptr = ptr->next)
      std::cout << ptr->str << " ";
  std::cout << std::endl;
}

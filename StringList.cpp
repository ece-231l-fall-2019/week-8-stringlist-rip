#inlude "StringList.h"
#include <string>

StringList::StringList()
{
  head = NULL;
  tail = NULL;
}

StringList::StringList(const StringList&);

StringList::~StringList()
{
  while(!empty())
    pop_front();
}

StringList& StringList::operator=(const StringList&)
{

}

int StringList::getSize()
{
  return _size;
}
std::string& StringList::front()
{
  return head->str;
}
std::string& StringList::back()
{
  return tail->str;
}

void push_front(std::string str)
{
  llist *newItem = new llist;
  newItem->str = str;
  newItem->next = head;
  newItem->prev = NULL;
  if (head != NULL)
    head->prev = NewItem;
  if (tail == NULL)
    tail = NewItem;
  head = newItem; //update head
  _size++;

}
void push_back(std::string str)
{
    llist *newItem = new llist;
    NewItem->str = str;
    NewItem->next = NULL;
    NewItem->prev = tail;
    if (tail != NULL)
      tail->next = NewItem;
    if (head == NULL)
      head = NewItem;
    tail = NewItem; //update tail
    _size++;
}

void pop_front()
{
  llist *ptr = head;
  head = head->next;
  //head->prev = NULL;
  if (head != NULL)
    head->prev = head->prev->prev;
  else
    tail = NULL;
  delete ptr;
  _size--;
}
void pop_back()
{
  llist *ptr = tail;
  tai = tail->prev;
  if (tail != NULL)
    tail->next = tail->prev->prev;
  else
    head = NULL;
  delete ptr;
  _size--;
}

bool StringList::empty() const
{
  return head == tail == NULL;
}
bool StringList::clear() const
{
  while(!empty())
    pop_front();
}

void StringList::unique()
{
  for(llist *ptr = head; ptr != NULL; ptr = ptr->next)
  {
    while (ptr->next != NULL) && (ptr->str = ptr->next->str)
      {
        llist *saveptr = ptr->next
        ptr->next = saveptr->next;
        if (saveptr->next != NULL)
          saveptr->next->prev = ptr;
        else back = ptr;
        delete saveptr;
        _size--;
      }
  }
}
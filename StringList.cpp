#inlude "StringList.h"
#include <string>

StringList::StringList()
{
  this->head = NULL;
  this->tail = NULL;
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

int StringList::size()
{
  return _length;
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
  head = newItem;
  _length++;
}
void push_back(std::string str)
{
    llist *newItem = new llist;
    NewItem->str = str;
    NewItem->next = NULL;
    NewItem->prev = tail;
    tail = NewItem;
    _length++;
}

void pop_front()
{
  llist *ptr = head;
  head = head->next;
  head->prev = NULL;
  delete ptr;
  length--;
}
void pop_back()
{
  llist *ptr = tail;
  tai = tail->prev;
  tail->next = NULL;
  delete ptr;
  length--;
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

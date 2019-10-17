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
string *temp = StringList;
while(temp._data != StringList._data)
{
*temp++ = *StringList++;
}
return *this;
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
    if(head !=0)
	    head->next=NewList
    if(back==0)
	    back=NewItem;
  head = newItem;
  _length++;
}
void push_back(std::string str)
{
    llist *newItem = new llist;
    NewItem->str = str;
    NewItem->next = NULL;
    NewItem->prev = tail;
    if(tail !=0)
	    tail->next=NewList;
    if(front==0)
	    front=NewItem;
    tail = NewItem;
    _length++;
}

void pop_front()
{
  llist *ptr = head;
  head = head->next;
  if(head){
  head->prev = head->prev->prev;// it was head ->prev = null;
  }
  else{
	  back=0;
}
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
void StringList::reverse()
{
llist *temp;
for(llist *ptr = front, ptr != 0; ptr=ptr->prev)
	{
	temp=ptr;
	ptr->next = ptr ->prev
	ptr->prev = temp;
	}	
temp=back;
back=front;
front=temp;	
}
void StringList::unique();
{
for(llist *ptr = front;ptr!=0;ptr=ptr->next;
{	while(ptr->next != 0 && ptr->str==ptr->next->str)
	{
	llist *saveptr = ptr->next;
	ptr->next= ptr->saveptr->next;
	if(saveptr->next != 0)
	saveptr->next->prev= ptr;
	else
	back = ptr;
	delete saveptr;
	length--;
	}

}
}

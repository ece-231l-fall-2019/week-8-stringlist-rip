#include <iostream>
#include <string>

class StringList
{
	private:

	typedef struct llist {
		std::string str;
		struct llist *next;
	} llist;

	llist *_data;

	public:
	
	// default constructor
	StringList()
	{
		_data = 0;
	}

	// copy constructor
	StringList(const StringList&);

	// destructor
	~StringList()
	{
		clear();
	}

	// copy operator
	StringList& operator=(const StringList&);

	std::string& front()
	{
		return _data->str;
	}
	std::string& back()
	{
		for(llist = _data; llist != null;llist->next)
		return llist;		
	}

	void push_front(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->next = _data;
		_data = newItem;
	}

	void pop_front()
	{
		llist *front = _data;
		_data = front->next;
		delete front;
	}

	bool empty() const
	{
		return _data == 0;
	}
	void clear()
	{
	while(!empty())
		pop_front();
	}
	int StringList::size()
	{
	size = 0;
	if(size == null)
		return null;

	for(llist *head = _data; head->next != NULL; size++)
		{
		head = head->next;
		}	
	return size;
	}

	
	

};


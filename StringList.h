#include <iostream>
#include <string>

class StringList
{
	private:
	int _size;
	typedef struct llist {
		std::string str;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *head;
	llist *tail;

	public:

	// default constructor
	StringList();
	// copy constructor
	StringList(const StringList&);
	// destructor
	~StringList();

	// copy operator
	StringList& operator=(const StringList& other);

	int getSize();
	std::string& front();
	std::string& back();
	bool empty() const;
	bool clear() const;

	void push_front(std::string str);
	void push_back(std::string str);

	void pop_front();
	void pop_back();

	void unique();
	void reverse();
};

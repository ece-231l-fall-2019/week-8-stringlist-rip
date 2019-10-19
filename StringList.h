#include <iostream>
#include <string>

class StringList
{
	private:
	size_t _size;
	typedef struct llist {
		std::string str;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_head;
	llist *_tail;

	public:

	// default constructor
	StringList();
	// copy constructor
	StringList(const StringList& other);
	// destructor
	~StringList();

	// copy operator
	StringList& operator=(const StringList& other);

	size_t getSize();
	std::string& front();
	std::string& back();
	bool empty() const;
	void clear();

	void push_front(std::string str);
	void push_back(std::string str);

	void pop_front();
	void pop_back();

	void unique();
	void reverse();
	void printstr();
};

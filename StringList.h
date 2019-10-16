#include <iostream>
#include <string>

class StringList
{
	private:

	typedef struct llist {
		std::string str;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *head;
	llist *tail;
	int _length = 0;
	public:

	// default constructor
	StringList();

	// copy constructor
	StringList(const StringList&);

	// destructor
	~StringList()

	// copy operator
	StringList& operator=(const StringList&);

	int size();
	std::string& front();
	std::string& back();

	void push_front(std::string str);
	void push_back(std::string str);

	void pop_front();
	void pop_back();

	bool empty() const;
};

#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#if 1
#include "StringList.h"
#else
#include <list>
#include <string>
typedef std::list<std::string> StringList;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write *at least* 15 more tests to fully test
	// your class.

	StringList a;

	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");

	Assert(a.getSize() == 5, "size method");

	Assert(a.front() == "D", "front method");
	a.pop_front();
	Assert(a.front() == "C", "pop_front method");
	Assert(a.back() == "E", "back method");
	a.pop_back();
	Assert(a.back() == "B", "pop_back method");
	a.pop_front();
	Assert(a.front() == "A", "front method");
	a.pop_back();
	Assert(a.back() == "A", "back method");

	StringList x;
	x.push_back("H");
	x.push_back("e");
	x.push_back("l");
	x.push_back("l");
	x.push_back("o");
	x.push_back(" ");
	x.push_back("D");
	x.push_back("a");
	x.push_back("v");
	x.push_back("i");
	x.push_back("d");
	Assert(x.getSize()==11, "size");
	x.reverse();
	//std::cout<<x<<std::endl;
	x.reverse();
	x.unique();
	//std::cout<<x<<std::endl;
	Assert(x.getSize() == 10, "size");
	x.pop_back();
	Assert(x.back()== "i", "pop back");
	x.pop_front();
	Assert(x.front() == "e", "pop front");
	x.clear();
	Assert(x.empty() == true, "empty");
	StringList y;
	y.push_back("C");
	y.push_back("h");
	y.push_back("a");
	y.push_back("s");
	y.push_back("e");
	StringList z;
	z=y;
	z.reverse();
	z.pop_front();
	y=z;
	//std::cout<<y<<std::endl;
	StringList c;
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	//c.unique;
	//Assert(c._size == 1, "unique with 5 c's");

	return 0;
}

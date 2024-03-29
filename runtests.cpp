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
	StringList a;
	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");

	//Assert(a.size() == 5, "Size method");
	Assert(a.front() == "D", "Front method");
	a.pop_front();
	Assert(a.front() == "C", "Pop_front method");
	Assert(a.back() == "E", "Back method");
	a.pop_back();
	Assert(a.back() == "B", "Pop_back method");
	a.pop_front();
	Assert(a.front() == "A", "Front method");
	a.pop_back();
	Assert(a.back() == "A", "Back method");

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
	Assert(x.size() == 11, "Test Size");
	x.printstr();
	x.reverse();
	Assert(x.front() == "d", "Test reverse");
	x.printstr();
	x.reverse();
	x.unique();
	Assert(x.size() == 10, "Test size after using unique");
	x.pop_back();
	Assert(x.back()== "i", "Pop back");
	x.pop_front();
	Assert(x.front() == "e", "Pop front");
	x.clear();
	Assert(x.empty() == true, "Clear and empty method");

	StringList y;
	y.push_back("C");
	y.push_back("h");
	y.push_back("a");
	y.push_back("s");
	y.push_back("e");

	StringList z;
	z=y;
	Assert(z.size() == y.size(), "Test operator = with size");
	Assert(z.front() == y.front(), "Test operator = with front method");
	Assert(z.back() == y.back(), "Test operator = with back method");
	z.reverse();
	z.pop_front();
	Assert(z.front() == "s", "Pop front with reverse");
	z.pop_back();
	Assert(z.back() == "h", "Pop back");

	StringList c;
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.unique();
	Assert(c.size() == 1, "Test unique with 5 c's");

	StringList j;
	j.push_front("J");
	Assert(j.front() == "J", "Push front");
	Assert(j.back() == j.front(), "Checking to see if front and back == with 1 elm");
	j.push_back("E");
	j.push_back("R");
	j.push_back("R");
	j.push_back("E");
	j.push_back("Y");
	j.push_back(" ");
	j.push_back("G");
	j.push_back("A");
	j.push_back("R");
	j.push_back("C");
	j.push_back("I");
	j.push_back("A");
	Assert(j.size() == 13, "Test Size");
	j.reverse();
	Assert(j.back() == "J", "Test reverse and back");
	Assert(j.front() == "A", "Test reverse and front");
	Assert(j.empty() == false, "Test empty method");

	StringList test;
	std::cout << "Pass: Test pop_back and pop_front not return error if the list is NULL " << std::endl;
	test.pop_front();
	test.pop_back();
	std::cout << "Pass: Test reverse method not return error if a list is NULL or have 1 node" << std::endl;
	test.reverse();
	test.push_back("A");
	test.reverse();

	StringList davidPlease;
	davidPlease.push_back("c");
	davidPlease.push_back("a");
	davidPlease.push_back("n");
	davidPlease.push_back(" ");
	davidPlease.push_back("w");
	davidPlease.push_back("e");
	davidPlease.push_back(" ");
	davidPlease.push_back("g");
	davidPlease.push_back("e");
	davidPlease.push_back("t");
	davidPlease.push_back(" ");
	davidPlease.push_back("e");
	davidPlease.push_back("x");
	davidPlease.push_back("t");
	davidPlease.push_back("r");
	davidPlease.push_back("a");
	davidPlease.push_back(" ");
	davidPlease.push_back("c");
	davidPlease.push_back("r");
	davidPlease.push_back("e");
	davidPlease.push_back("d");
	davidPlease.push_back("i");
	davidPlease.push_back("t");
	davidPlease.push_back(" ");
	davidPlease.push_back("f");
	davidPlease.push_back("o");
	davidPlease.push_back("r");
	davidPlease.push_back(" ");
	davidPlease.push_back("a");
	davidPlease.push_back(" ");
	davidPlease.push_back("p");
	davidPlease.push_back("r");
	davidPlease.push_back("i");
	davidPlease.push_back("n");
	davidPlease.push_back("t");
	davidPlease.push_back(" ");
	davidPlease.push_back("m");
	davidPlease.push_back("e");
	davidPlease.push_back("t");
	davidPlease.push_back("h");
	davidPlease.push_back("o");
	davidPlease.push_back("d");
	davidPlease.push_back("?");
	davidPlease.printstr();
	return 0;
}

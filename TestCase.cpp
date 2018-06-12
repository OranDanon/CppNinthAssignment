#include "TestCase.hpp"



TestCase::TestCase(const string st, ostream& myStream): name(st), output(&myStream), succeed(0), faild(0), total(0)
{
}

TestCase& TestCase::print()
{
	//Test int operators: 2 failed, 5 passed, 7 total.
	*output << name << ": " << faild << " failed, " << succeed << " passed, " << total << " total" << endl;
	*output << "---" << endl;
	return *this;
}

TestCase::~TestCase()
{
}


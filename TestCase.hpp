#pragma once
#ifndef TEST_CASE_H
#include <string>
#include <stdio.h>
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

class TestCase
{
private:
	string name;
	size_t succeed;
	size_t faild;
	size_t total;
	ostream* output;
public:

	TestCase(const string st, ostream& myStream);

	template<typename T>
	inline TestCase& check_equal(T a, T b)
	{
		total++;
		if (a == b)
		{
			succeed++;
		}
		else
		{
			*output << name << "Failure in test number" << total << "Arguments are not equal" << endl;
			faild++;
		}
		return *this;
	}
	
	template<typename T>
	TestCase& check_different(T a, T b)
	{
		total++;
		if (a == b)
		{
			faild++;
		}
		else
		{
			*output << name << "Failure in test number" << total << "Arguments are equal" << endl;
			succeed++;
		}
		return *this;
	}

	template<typename T>
	TestCase& check_output(T element, string desired)
	{
		total++;
		std::stringstream ss;
		ss << element;
		if (!ss.str().compare(desired))
		{
			succeed++;
		}
		else
		{
			faild++;
		}
		return *this;
	}

	template<typename T, typename S>
	TestCase& check_function(S(*func) (T val), T element, S desired)
	{
		total++;
		if (func(element) == desired)
		{
			succeed++;
		}
		else
		{
			faild++;
		}
		return *this;
	}

	template<typename T, typename R>
	TestCase & check_function(R(*func)(const T &v), const T element, R desired)
	{
		total++;
		if (func(element) == desired)
		{
			succeed++;
		}
		else
		{
			faild++;
		}
		return *this;
	}

	template<typename T, typename R>
	TestCase & check_function(function<R(const T& v)> & f, const T elem, R desired)
	{
		total++;
		if (f(elem) == desired)
		{
			succeed++;
		}
		else
		{
			faild++;
		}
		return *this;
	}

	template<typename func, typename V, typename R>
	TestCase & check_function(func f, V elem, R desired)
	{
		total++;
		if (f(elem) == desired)
		{
			succeed++;
		}
		else
		{
			faild++;
		}
		return *this;
	}

	TestCase& print();

	~TestCase();
};

#endif // !TEST_CASE_H



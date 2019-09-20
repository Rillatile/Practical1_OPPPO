#pragma once

#include <memory>
#include <iostream>

#include "cl_iterator.h"
#include "node.h"

using namespace std;

struct CircularList
{
	private:
		shared_ptr<node> m_first;
		weak_ptr<node> m_last;
		unsigned int m_size;

	public:
		CircularList();
		void push_back(item value);
		//void print(ofstream& out);
		void sort();
		CLIterator begin() const;
		CLIterator end() const;
		unsigned int size();
};
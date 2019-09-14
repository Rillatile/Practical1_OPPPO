#pragma once

#include <memory>
#include <iostream>

#include "node.h"

using namespace std;

struct CircularList
{
	private:
		shared_ptr<node> m_first;
		weak_ptr<node> m_last;

	public:
		void push_back(item value);
		void print(ofstream& out);
};
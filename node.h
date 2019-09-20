#pragma once

#include <memory>

#include "auxiliary_function.h"
#include "item_struct.h"

using namespace std;

struct node
{
	ItemStruct m_value;
	shared_ptr<node> m_next;

	node(item value);
	friend bool operator> (node& n1, node& n2);
	friend bool operator< (node& n1, node& n2);
};
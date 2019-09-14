#pragma once

#include <memory>

#include "auxiliary_function.h"
#include "item.h"

using namespace std;

struct node
{
	item m_value;
	shared_ptr<node> m_next;

	node(item value);
	string getContent();
};
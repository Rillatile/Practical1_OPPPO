#pragma once

#include <memory>

#include "node.h"
#include "item_struct.h"

using namespace std;

struct CLIterator
{
	weak_ptr<node> m_ptr;

	explicit CLIterator(shared_ptr<node> ptr);
	ItemStruct operator*() const;
	CLIterator& operator++();
	bool operator!=(const CLIterator& other) const;
};
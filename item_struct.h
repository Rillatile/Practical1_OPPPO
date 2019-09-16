#pragma once

#include "item.h"

struct ItemStruct
{
	item m_value;

	friend std::ofstream& operator<< (std::ofstream& out, const ItemStruct& value);
	int getTitleLength();
};


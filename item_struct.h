#pragma once

#include "item.h"

struct ItemStruct
{
	item m_value;

	void swap(ItemStruct& other);
	friend std::ofstream& operator<< (std::ofstream& out, const ItemStruct& value);
	int getTitleLength();
	float getRating();
};


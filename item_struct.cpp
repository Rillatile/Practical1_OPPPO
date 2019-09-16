#include "item_struct.h"

std::ofstream& operator<< (std::ofstream& out, const ItemStruct& value)
{
	out << value.m_value;

	return out;
}

int ItemStruct::getTitleLength()
{
	switch (this->m_value.index())
	{
	case 1:
		return get<CartoonFilm>(this->m_value).m_title.length();
	case 2:
		return get<FeatureFilm>(this->m_value).m_title.length();
	case 3:
		return get<HorrorFilm>(this->m_value).m_title.length();
	}
}

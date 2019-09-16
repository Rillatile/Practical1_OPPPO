#include "item.h"

std::ofstream& operator<< (std::ofstream& out, const item& value)
{
	switch (value.index())
	{
		case 1:
			out << get<CartoonFilm>(value);
			break;
		case 2:
			out << get<FeatureFilm>(value);
			break;
		case 3:
			out << get<HorrorFilm>(value);
			break;
	}

	return out;
}
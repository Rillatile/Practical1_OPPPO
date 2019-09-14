#include "item.h"

string unboxItem(item value)
{
	switch (value.index())
	{
		case 1:
			return get<CartoonFilm>(value).getContent();
		case 2:
			return get<FeatureFilm>(value).getContent();
	}
}
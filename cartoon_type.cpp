#include "cartoon_type.h"

#include <algorithm>
#include <vector>

CartoonType toCartoonType(std::string type)
{
	transform(type.begin(), type.end(), type.begin(), tolower);

	std::vector<std::string> strTypes = { "drawn", "dollish", "plasticine" };
	int idx = distance(strTypes.begin(), find(strTypes.begin(), strTypes.end(), type));

	if (idx < strTypes.size())
		return CartoonType(idx);
	else
		return CartoonType::unknown;
}

std::string getStringCartoonType(CartoonType type)
{
	switch (type)
	{
		case CartoonType::drawn:
			return "drawn";
		case CartoonType::dollish:
			return "dollish";
		case CartoonType::plasticine:
			return "plasticine";
		case CartoonType::unknown:
			return "unknown";
		default:
			return "incorrect type";
	}
}
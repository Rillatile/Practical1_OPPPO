#pragma once

#include <string>

enum class CartoonType
{
	drawn,
	dollish,
	plasticine,
	unknown
};

CartoonType toCartoonType(std::string type);

std::string getStringCartoonType(CartoonType type);
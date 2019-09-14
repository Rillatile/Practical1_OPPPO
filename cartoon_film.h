#pragma once

#include <string>

#include "cartoon_type.h"

struct CartoonFilm
{
	std::string m_title;
	CartoonType m_type;

	std::string getContent();
};
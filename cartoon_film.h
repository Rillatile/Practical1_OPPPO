#pragma once

#include <string>

#include "cartoon_type.h"

struct CartoonFilm
{
	std::string m_title;
	CartoonType m_type;
	float m_rating;

	std::string getContent();
};
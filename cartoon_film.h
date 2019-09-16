#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "cartoon_type.h"

struct CartoonFilm
{
	std::string m_title;
	CartoonType m_type;
	float m_rating;

	friend std::ofstream& operator<< (std::ofstream& out, const CartoonFilm& cf);
};
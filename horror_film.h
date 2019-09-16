#pragma once

#include <string>
#include <fstream>
#include <iostream>

struct HorrorFilm
{
	std::string m_title;
	std::string m_producer;
	float m_rating;

	friend std::ofstream& operator<< (std::ofstream& out, const HorrorFilm& hf);
};


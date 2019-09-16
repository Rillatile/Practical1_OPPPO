#pragma once

#include <string>

struct HorrorFilm
{
	std::string m_title;
	std::string m_producer;
	float m_rating;

	std::string getContent();
};


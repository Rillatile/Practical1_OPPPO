#pragma once

#include <string>

struct FeatureFilm
{
	std::string m_title;
	std::string m_producer;
	float m_rating;

	std::string getContent();
};
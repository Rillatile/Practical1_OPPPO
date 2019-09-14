#include "feature_film.h"

std::string FeatureFilm::getContent()
{
	return "Title: " + this->m_title + ", producer: " + this->m_producer;
}
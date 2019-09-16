#include "cartoon_film.h"

std::string CartoonFilm::getContent()
{
	return "Title: " + this->m_title + ", type: " + getStringCartoonType(this->m_type) + ", rating: " + std::to_string(this->m_rating);
}
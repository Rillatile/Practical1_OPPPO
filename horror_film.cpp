#include "horror_film.h"

std::string HorrorFilm::getContent()
{
	return "Title: " + this->m_title + ", producer: " + this->m_producer + ", rating: " + std::to_string(this->m_rating);
}

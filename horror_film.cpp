#include "horror_film.h"

std::ofstream& operator<< (std::ofstream& out, const HorrorFilm& hf)
{
	out << "Title: " + hf.m_title + ", producer: " + hf.m_producer + ", rating: " + std::to_string(hf.m_rating);

	return out;
}

#include "cartoon_film.h"

std::ofstream& operator<< (std::ofstream& out, const CartoonFilm& cf)
{
	out << "Title: " + cf.m_title + ", type: " + getStringCartoonType(cf.m_type) + ", rating: " + std::to_string(cf.m_rating);;

	return out;
}
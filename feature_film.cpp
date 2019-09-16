#include "feature_film.h"

std::ofstream& operator<< (std::ofstream& out, const FeatureFilm& ff)
{
	out << "Title: " + ff.m_title + ", producer: " + ff.m_producer + ", rating: " + std::to_string(ff.m_rating);

	return out;
}
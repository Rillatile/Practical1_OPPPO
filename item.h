#pragma once

#include <variant>

#include "cartoon_film.h"
#include "feature_film.h"
#include "horror_film.h"

using namespace std;

using item = variant<monostate, CartoonFilm, FeatureFilm, HorrorFilm>;

string unboxItem(item value);
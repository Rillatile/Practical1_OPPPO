#pragma once

#include <variant>

#include "cartoon_film.h"
#include "feature_film.h"

using namespace std;

using item = variant<monostate, CartoonFilm, FeatureFilm>;

string unboxItem(item value);
#pragma once

#include "auxiliary_function.h"
#include "item.h"

using namespace std;

namespace factory
{
	item parse(string source, int line_number);
}
#include <algorithm>

#include "factory.h"

bool isItemType(string type)
{
	transform(type.begin(), type.end(), type.begin(), tolower);

	vector<string> correctTypes = { "feature", "cartoon", "horror" };

	if (find(correctTypes.begin(), correctTypes.end(), type) != correctTypes.end())
		return true;
	else
		return false;
}

item getItem(vector<string> params)
{
	transform(params[1].begin(), params[1].end(), params[1].begin(), tolower);

	vector<string> types = { "feature", "cartoon", "horror" };
	int idx = distance(types.begin(), find(types.begin(), types.end(), params[1]));

	switch (idx)
	{
		case 0:
			return FeatureFilm { params[0], params[2] };
		case 1:
			return CartoonFilm { params[0], toCartoonType(params[2]) };
		case 2:
			return HorrorFilm { params[0], params[2] };
	}
}

item factory::parse(string source, int lineNumber)
{
	const unsigned int paramsCount = 3;
	vector<string> params = split(source, ";");

	if (params.empty() || params.size() != paramsCount)
	{
		string message = "An incorrect input data in line " + to_string(lineNumber) + ": " + source;

		throw message;
	}
	else
	{
		if (!isItemType(params[1]))
		{
			string message = "An incorrect type of film in line " + to_string(lineNumber) + ": " + params[1];

			throw message;
		}

		return getItem(params);
	}
}
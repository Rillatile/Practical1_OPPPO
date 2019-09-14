#include "auxiliary_function.h"

vector<string> getLines(ifstream& in)
{
	string buffer = "";
	vector<string> lines;

	while (getline(in, buffer))
		lines.push_back(buffer);

	return lines;
}

vector<string> split(string source, string delimiter)
{
	vector<string> result;
	size_t pos = 0;

	while ((pos = source.find(delimiter)) != string::npos)
	{
		result.push_back(source.substr(0, pos));
		source.erase(0, pos + delimiter.length());
	}

	if (source != "")
		result.push_back(source);

	return result;
}

void log(string message)
{
	clog << message << endl;
}
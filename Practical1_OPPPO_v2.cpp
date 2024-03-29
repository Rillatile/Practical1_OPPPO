#include <iostream>
#include <Windows.h>

#include "auxiliary_function.h"
#include "circular_list.h"
#include "factory.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);

	if (argc < 3)
	{
		cout << "Not enough input parameters." << endl;
		return 1;
	}

	string inputFilePath = argv[1];
	string outputFilePath = argv[2];

	ifstream in(inputFilePath, ios_base::in);

	if (!in.is_open())
	{
		cout << "Can't open an input file." << endl;
		return 1;
	}

	vector<string> lines = getLines(in);
	auto cl = make_unique<CircularList>();

	for (int i = 0; i < lines.size(); i++)
	{
		item value = monostate();

		try
		{
			value = factory::parse(lines[i], i + 1);
		}
		catch (string message)
		{
			log(message);
		}

		if (value.index() != 0)
			cl->push_back(value);
	}

	ofstream out(outputFilePath, ios_base::out);

	if (!out.is_open())
	{
		cout << "Can't open an output file." << endl;
		return 1;
	}

	cl->sort();
	cl->remove(7.0);

	CLIterator it = cl->begin();

	do
	{
		out << (*it) << endl;
		++it;

	} while (it != cl->end());

	return 0;
}

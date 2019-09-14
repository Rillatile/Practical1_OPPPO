#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getLines(ifstream& in);

vector<string> split(string source, string delimiter);

void log(string message);
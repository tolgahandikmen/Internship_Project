#pragma once

#include "Graph.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;
using namespace System;

class ReadFile
{
public:
	static string fileSource;

	static list <Graph> readFile(std::ifstream &file_);
};
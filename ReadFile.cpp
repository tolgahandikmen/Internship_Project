#include "ReadFileHeader.h"

Graph edge;

string fileSource_;

list <Graph> ReadFile::readFile(std::ifstream &file)
{
	//ifstream file(gotFile);
	//ifstream file("C:\\Users\\tolgahandikmen\\Documents\\Visual Studio 2013\\Projects\\Project1\\Project1\\Coordinates.csv");


	if (!file.is_open()){
		





		/***  File not found!  ***/
	}

	list <Graph> listOfObjects;
	vector <vector<double>> lines;

	/* 
	
		Read .cvs file and transfer to a vector
		
	*/
	while (file.good()){
		if (file) {
			string line;
			while (getline(file, line)) {
				stringstream sep(line);
				string field;
				lines.push_back(vector<double>());
				while (getline(sep, field, ';')) {
					string str(field);
					lines.back().push_back(stod(str));
				}
			}
		}

		/*
		
			Creating Graph pattern
		
		*/

		std::vector<vector<double>>::iterator temp_itr = lines.begin();; temp_itr != lines.end();

		for (std::size_t i = 0; i < lines.size();){
			for (std::size_t j = 1; j <= lines.size();){
				if (j != lines.size()){
					edge.setEdge(temp_itr->front(), temp_itr->back(), (temp_itr + 1)->front(), (temp_itr + 1)->back());
					listOfObjects.push_back(edge);
					temp_itr++;
				}
				else{
					edge.setEdge(temp_itr->front(), temp_itr->back(), lines.front().front(), lines.front().back());
					listOfObjects.push_back(edge);
				}
				i++, j++;
			}	
		}

	}
	file.close();
	return listOfObjects;
}
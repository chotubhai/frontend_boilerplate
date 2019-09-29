#include <iostream>
#include <cstring>
#include <map>
#include <regex>
#include <utility>
#include <fstream>

using namespace std;

#include "../include/function.cpp"
#include "../include/cssFunction.cpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		cout << "enter command";

	fstream file1, file2;
	file1.open("data/start.html");
	file2.open("data/new.html", ios::out);
	pre("start", file1, file2);

	for (int i = 1; i < argc; i++)
	{
		int sub_code = (atoi(argv[i])) % 10;
		int data_code = (atoi(argv[i])) / 10;
		appendHtmlCode(sub_code, data_code);
		appendCssCode(sub_code, data_code);
	}

	pre("end", file1, file2);
	return 0;
}
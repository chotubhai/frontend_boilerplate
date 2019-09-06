#include<iostream>
#include<fstream>

using namespace std;

int main(){
	int flag=0,divcount = 0;
	string str = "21";
	fstream file2, file1("new.html", ios::app);
	string s1;
	file2.open("header.html");
	while (true)
	{
		file2.clear();
		file2.sync();
		getline(file2, s1);
		if (s1.find(str) != string::npos)
		{
			flag = 1;
		}
		if (flag)
		{
			file1 << s1;
			if (s1.find("<div") != string::npos)
			{
			   divcount++;
			}
			if (s1.find("/div") != string::npos)
			{
				divcount--;
			}
			if(divcount == 0)
			{
				break;
			}
		}
	}
	file1.close();
	file2.close();
}
#include<iostream>
#include<fstream>
#include<regex>

using namespace std;

int main(){
	int flag=0,divcount = 0;
	string str = "11";
	fstream file2, file1("new.html", ios::app);
	string s1;
	file2.open("nav.html");
			smatch m;

	while (file2.eof())
	{ 
		file2.clear();
		file2.sync();
		getline(file2, s1);
		if (s1.find(str) != string::npos)
		{
		cout<<"in loop";
			flag = 1;
			regex r("[A-Za-z]+\\s");
			regex_search(s1,m,r);
            for (auto x: m)
			 cout<<x;
		}
		if (flag)
		{   
			file1 << s1;
			if (s1.find(m.str()) != string::npos)
			{
			   divcount++;
			}
			if (s1.find('/'+m.str()) != string::npos)
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
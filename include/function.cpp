void pre(string task, fstream &file1, fstream &file2)
{
	if (task == "start")
	{

		if (file1.is_open())
		{
			string data1;

			while (!file1.eof())
			{
				file1.clear();
				file1.sync();
				getline(file1, data1);
				file2 << data1 + '\n';
			}
			file1.close();
			file2.close();
		}
	}
	else
	{
		string data1;
		file2.close();
		file2.open("new.html", ios::app);
		while (!file1.eof())
		{
			file1.clear();
			file1.sync();
			getline(file1, data1);
			file2 << data1 + '\n';
		}
		file1.close();
		file2.close();
	}
}

void copyNav(string str)
{
	fstream file2, file1("new.html", ios::app);
	string s1;
	int flag = 0;
	file2.open("nav.html");
	while (true)
	{
		file1.clear();
		file1.sync();
		getline(file2, s1);
		if (s1.find(str) != string::npos)
		{
			flag = 1;
		}
		if (flag)
		{
			file1 << s1;
			if (s1.find("/nav") != string::npos)
			{
				break;
			}
		}
	}
	file1.close();
	file2.close();
}
void copyheaderDiv(string str)
{
	int flag = 0, divcount = 0;
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
			if (divcount == 0)
			{
				break;
			}
		}
	}
	file1.close();
	file2.close();
}
void copyHeader(string str)
{
	cout << "header is running" << str << endl;
	fstream file2, file1("new.html", ios::app);
	string s1;
	int flag = 0;
	file2.open("header.html");
	while (true)
	{
		file2.clear();
		file2.sync();
		getline(file2, s1);
		if (s1.find(str) != string::npos)
		{
			flag = 1;
			cout << "header found";
		}
		if (s1.find(str) != string::npos && s1.find("div"))
		{
			cout << "hedaer not found";
			file1.close();
			file2.close();
			copyheaderDiv(str);
			break;
		}
		if (flag)
		{
			file1 << s1;
			if (s1.find("/header") != string::npos)
			{
				break;
			}
		}
	}
	file1.close();
	file2.close();
}
void copyContent {
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
			regex r("\<[A-Za-z]+\s");
			smatch m;
			
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
void appendHtmlCode(int sub_code, int data_code)
{
	string str = to_string(data_code) + to_string(sub_code);
	switch (data_code)
	{
	case 1:
		copyNav(str);
		break;
	case 2:
		copyHeader(str);
		break;
	}
}

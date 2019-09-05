void pre(string task, fstream &file1, fstream &file2)
{
	if (task == "start")
	{
		file1.open("start.html");
		if (file1.is_open())
		{
			file1.seekg(0, ios::beg);
			long int init = file1.tellg();
			file1.seekg(0, ios::end);
			long int end = file1.tellg();
			file1.seekg(0, ios::beg);
			long int size = end - init;
			char data[size];
			string data1;
			file2.open("new.html", ios::out);
			while (!file1.eof())
			{
				file1.clear();
				file1.sync();
				getline(file1, data1);
				file2 << data1 + ' ';
			}
			file1.close();
			file2.close();
		}
	}
	else
	{
		file1.open("end.html");
		file1.seekg(0, ios::beg);
		long int init = file1.tellg();
		file1.seekg(0, ios::end);
		long int end = file1.tellg();
		file1.seekg(0, ios::beg);
		long int size = end - init;
		char data[size];
		string data1;
		file2.open("new.html", ios::app);
		while (!file1.eof())
		{
			file1.clear();
			file1.sync();
			getline(file1, data1);
			file2 << data1 + ' ';
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
	fstream file2, file1("new.html", ios::app);
	string s1;
	int flag = 0, divCount = 0;
	file2.open("header.html");
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
			if (s1.find("<div") != string::npos)
				divCount++;

			if (s1.find("</div") != string::npos)
				divCount--;

			file1 << s1;
			if (divCount)
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
	fstream file2, file1("new.html", ios::app);
	string s1;
	int flag = 0;
	file2.open("header.html");
	while (true)
	{
		file1.clear();
		file1.sync();
		getline(file2, s1);
		if (s1.find(str) != string::npos && s1.find("header"))
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
void appendCode(int sub_code, int data_code, char argv[])
{
	fstream file1;
	file1.open("new.html", ios::app);

	string str = to_string(data_code) + to_string(sub_code);
	switch (data_code)
	{
	case 1:
		copyNav(str);
	case 2:
		copyHeader(str);
	}
}


void copyCssNav(string str)
{
	fstream file1("navbar_main.css"), file2("main.css", ios::ate);
	while (true)
	{
		int flag = 0;
		string s1;
		file1.clear();
		file1.sync();
		getline(file1, s1);
		if (s1.find(str) != string::npos)
		{
			if (flag)
			{
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag)
		{
			file2 << str;
		}
	}
}
void preCssAppend()
{
	cout<<"preCssAppend\n";
	string str;
	fstream file1("preCss.css"), file2("main.css",ios::ate);
	while (!file1.eof())
	{
		file1.clear();
		file1.sync();
		getline(file1, str);
		file2 << str;
	}
	cout<<"end preCssAppend\n";
}
void appendCssCode(int sub_code, int data_code)
{
	cout<<"appendCssCode"<<endl;
	string str = to_string(data_code) + to_string(sub_code);
	preCssAppend();
	 switch (data_code)
	{
	case 1:
		copyCssNav(str);
		break;
	}
}

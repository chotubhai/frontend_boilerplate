#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
using namespace std;

#include "includes/function.cpp"

int main(int argc,char* argv[])
{
	if(argc == 1 )
	cout<<"enter command";

	fstream file1, file2;
 
 	pre("start", file1, file2);
    
    int code[argc-1];

	for(int i =1 ;i<argc;i++)
     {
		 int sub_code = (atoi(argv[i])) % 10;
		 int data_code = (atoi(argv[i])) / 10;
		 appendCode(sub_code,data_code,argv[i]);
	 }

	pre("end", file1, file2);
	return 0;
}
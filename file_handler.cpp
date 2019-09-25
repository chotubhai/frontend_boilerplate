#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#include "includes/headers/function.h"
#include "includes/headers/cssFunction.h"

#include "includes/function.cpp"
#include "includes/cssFunction.cpp"

int main(int argc,char* argv[])
{
	if(argc == 1 )
	cout<<"enter command";

	fstream file1, file2;
 
 	pre("start", file1, file2);
    
	for(int i =1 ;i<argc;i++)
     {
		 int sub_code = (atoi(argv[i])) % 10;
		 int data_code = (atoi(argv[i])) / 10;
		 appendHtmlCode(sub_code,data_code);
         appendCssCode(sub_code,data_code);
	 }

	pre("end", file1, file2);
	return 0;
}
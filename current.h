#include <stdio.h>
#ifdef LINUX
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd 
#endif
#include <iostream>

using namespace std;

string GetCurrentWorkingDir(void)
{
	char buff_size[FILENAME_MAX];
	GetCurrentDir(buff_size, FILENAME_MAX);
	string current_working_dir(buff_size);
	return current_working_dir;
}
#include <unistd.h>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

void ft_add_history(vector<string> & history, string input)
{
	history.push_back(input);
}

void history(vector<string> & history)
{
	int i; 
	for(auto it = history.begin(); it != history.end(); ++it)
        cout<< *it <<"\n";
}

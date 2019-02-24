<<<<<<< HEAD
#include "includes.h"

using namespace std;




void ft_add_history(vector<string> & history, string input)
{
	history.push_back(input);
}

void history(vector<string> & history)
{
	for(auto it=history.begin(); it!=history.end();++it)
        cout << *it <<"\n";
}


int main ()
{

	vector<string> history1;
	string command;

	while(command != "exit")
	{
		
		if (command == "list")
		{
			ft_add_history(history1, command);
			system("ls");
=======
#include "pwdFun.cpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main(){
	string command = "";//store command inputs
	string errMessage = "ERROR";

	while(command != "exit"){
                if(command.substr(0, 4) == "list"){
			if(command == "list"){
				system("ls");
			}
			else{
				DIR *directory;
				struct dirent *file;

				directory = opendir( (command.substr(5, command.length())).c_str() );
				
				if(directory == NULL){
					cout << "***ERROR: INVALID PATH***" << endl;
				}
				else{
					cout << "DIRECTORY: " << command.substr(5, command.length()) << endl; 
					while((file = readdir(directory)) != NULL){
						cout << "\t" << file->d_name  << endl;
					}
					cout << "\n";
				}
			}				
>>>>>>> 6972926d193975c95c8dd90a4569b6aa616618a8
		}
		else if(command == "history")
		{
			ft_add_history(history1, command);
			history(history1);
		}
		else if(command == "printwd")
		{
			ft_add_history(history1, command);
			printwd();
		}
		else if(command.substr(0, 5) == "chdir")
		{
			ft_add_history(history1, command);
			if(command.length() > 5 && command.substr(5, 6) == " " 
				&& chdir(command.substr(6, command.length()).c_str()) == 0 )
			{
				chdir(command.substr(6, command.length()).c_str());
			}
			else
			{
				cout << "***ERROR: INVALID PATH***" << endl;
			}
		}
		else if(command != "\0")
		{
			system(command.c_str());
		}	
		else if (command== "exit")
			exit(EXIT_SUCCESS);

			cout << "Enter command: ";
			cin >> command;
	}

	cout<<"Current directory: "<<GetCurrentWorkingDir()<<'\n';
	return 0;
}



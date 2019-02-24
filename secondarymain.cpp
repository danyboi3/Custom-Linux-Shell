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



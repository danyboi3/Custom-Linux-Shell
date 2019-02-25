
#include "includes.h"
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main()
{
	vector<string> history1;
	string		command;

	while(command != "exit")
	{
		if(command.substr(0, 4) == "list")
		{
			if (command == "list")
				system("ls");
			else
			{
				command = command.substr(5, command.length());
				command = "ls " + command;
				system(command.c_str());
			}	
		}

		else if(command == "history")
			history(history1);

		else if(command == "printwd")
			printwd();

		else if(command.substr(0, 5) == "chdir")
		{
			if(command[5] != ' ')
				cout << "Error!\n";
			else
			{
				command = command.substr(6,command.length());
				int isError = chdir(command.c_str());

				if(isError)
					cout <<"-bash: chdir: "<<command<< ": No such file or directory\n";		
			}
		}

		else if(command != "\0")
			system(command.c_str());

	
		cout << "UnknownShell#: " << GetCurrentWorkingDir() << ": ";
		getline(cin, command);
		ft_add_history(history1, command);

	
	}
	return 0;
}




#include "includes.h"
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main ()
{
	vector<string> history1;
	string		command;

	while(command != "exit")
	{
		if(command.substr(0, 4) == "list")
		{
			if (command == "list")
			{
				//ft_add_history(history1, command);
				system("ls");
			}
			else
			{
				/*DIR *directory;
				struct dirent *file;

 				directory = opendir( (command.substr(5, command.length())).c_str() );

 				if(directory == NULL)
 				{
					cout << "***ERROR: INVALID PATH***" << endl;
				}
				else
				{
					cout << "DIRECTORY: " << command.substr(5, command.length()) << endl; 
						while((file = readdir(directory)) != NULL)
						{
							cout << "\t" << file->d_name  << endl;
						}
					cout << "\n";
				}*/
				command = command.substr(5, command.length());
				command = "ls " + command;
				system(command.c_str());
			}	
		}			
		else if(command == "history")
		{
			//ft_add_history(history1, command);
			history(history1);
		}
		else if(command == "printwd")
		{
			//ft_add_history(history1, command);
			printwd();
		}
		else if(command.substr(0, 5) == "chdir")
		{
			//ft_add_history(history1, command);
			/*if(command.length() > 5 && command.substr(5, 1) == " "
				&& chdir(command.substr(6, command.length()).c_str()) == 0 )
			{
				chdir(command.substr(6, command.length()).c_str());
			}
			else
			{
				cout << "***ERROR: INVALID PATH***" << endl;
			}*/
			if(command[5] != ' '){
				cout << "Error!\n";
			}
			else{
				command = command.substr(6,command.length());
				int isError =chdir(command.c_str());
				if(isError){
					cout << "***ERROR: INVALID PATH***\n";	
				}
			
			}
		}
		else if(command != "\0")
		{
			system(command.c_str());
		}	
		/*else if (command == "exit")
			exit(EXIT_SUCCESS);*/

			cout << GetCurrentWorkingDir() << ": ";
			//cin >>command; 
			getline(cin, command);
			ft_add_history(history1, command);

	
	}
//	cout << "Current directory: " << GetCurrentWorkingDir() << endl;
	//}
	return 0;
}



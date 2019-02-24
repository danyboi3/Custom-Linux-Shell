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
		}
		else if(command == "history"){
			//history();
		}
		else if(command == "printwd"){
			//printwd();
			printwd();	
		}		
		else if(command.substr(0, 5) == "chdir"){
			if(command.length() > 5 && command.substr(5, 6) == " " 
				&& chdir(command.substr(6, command.length()).c_str()) == 0 ){
				chdir(command.substr(6, command.length()).c_str());
			}
			else{
				cout << "***ERROR: INVALID PATH***" << endl;
			}
		}
		else if(command != "\0"){
			system(command.c_str());
		}	
		
		cout<<"UnknownShell#: "<<get_current_dir_name()<<" -->";
		getline(cin,command);
		
	}
  

	return 0;
}

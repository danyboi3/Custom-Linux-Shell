#include "pwdFun.cpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(){
	string command;//store command inputs
	string errMessage = "ERROR";

	while(command != "exit"){
                if(command == "list"){
			system("ls");				
		}
		else if(command == "history"){
			//history();
		}
		else if(command == "printwd"){
			//printwd();
			printwd();	
		}		
		else if(command.substr(0, 5) == "chdir"){
			if(command.length() > 5){
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

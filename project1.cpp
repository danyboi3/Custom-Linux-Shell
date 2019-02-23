#include "pwdFun.cpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

// history();
// printwd();
// chdir();

int main(){
	string command;//store command inputs
	string cd = "";//if user type "chdir", cd = "chdir"
	string gofile = "";//store destination file
	
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
			chdir(command.substr(6, command.length()).c_str());
		}
		//else if(){
			//run an external program
		//}
		else if(command != "\0"){
			cout << "ERROR\n";
		}	
		
		cout<<"UnknownShell#: "<<get_current_dir_name()<<" -->";
		getline(cin,command);
		cd =command.substr(0,5);
	
		if(command.size() > 6){
			 gofile = command.substr(6, command.length()-5);
		}else{
			gofile = "";
		}

	}
  

	return 0;
}

#include <stdio.h>
#include <string.h>

void chdir(String path) { 
   if(path == ""){
      system("cd");
   }
   else if((std::all_of(path.begin(), path.end(), isspace)){
      system("cd");
   }
   else{
      system("cd" + path);
   }
}
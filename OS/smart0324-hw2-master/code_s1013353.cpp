#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <sys/wait.h>


#define MAX 1023

using namespace std;

int main(){

	char command[MAX];
	char hostname[1024];
  gethostname(hostname, 1024);
	cout << hostname << " $" ;
	while(cin.getline(command,MAX)){

			if(strcmp(command,"exit") == 0)
				break;

			pid_t pID = fork();
			if(pID == -1){
				cout << "**Error: forking child process failed" << endl;
			}else if(pID == 0){
				string arr[2];
				int i = 0;
				stringstream ssin(command);
				while (ssin.good() && i < 4){
						ssin >> arr[i];
						++i;
				}

				if(arr[0] == "pwd"){
					execl("/bin/pwd", "pwd", 0, 0);
				}else if(arr[0] == "date"){
					execl("/bin/date", "date", 0, 0);
				}else if(arr[0] == "touch"){
					execl("/usr/bin/touch","touch", arr[1].c_str(), 0);
				}else if(arr[0] == "mkdir"){
					execl("/bin/mkdir","mkdir",arr[1].c_str(),0);
				}else if(arr[0] == "cd"){
					if(arr[1].empty()){
						char const* tmp = getenv( "HOME" );
						chdir(tmp);
					}else{
						char const* tmp = arr[1].c_str();
						chdir(tmp);
					}
				}else if(arr[0]  == "ls"){
					if(arr[1]  == "-al"){
						execl("/bin/ls", "ls","-al", 0, 0);
					}else{
						execl("/bin/ls", "ls", 0, 0);
					}
				}else if(arr[0]  == "pwd"){
					execl("/bin/pwd", "pwd", 0, 0);
				}else{
					cout << "Unable to find command..." << endl;
				}

			}
			else{
				wait(NULL);
			}
			cout << hostname << " $" ;
	}
	cout << "Bye!";
}

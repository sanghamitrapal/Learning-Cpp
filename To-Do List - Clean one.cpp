#include <iostream>
#include <string>
using namespace std;
class Task{
	int id;
	string des;
	bool status;
	public:
		Task(int i=1, string input=" "){
		id = i;
		des = input;
		status = false;	
		};
};
Task addTask(int i){
	string input;
	cout << "Which task you wanna add? ";
	cin >> input;
	Task a(i,input);
	return a;
}
int main(){
	Task list[20];
	int choice, i, j=0;
	cout << "MENU\n 1.Add Task\n 2.View To-Do List\n 3.Mark Done\n 4.Delete Task\n Enter the option(only the number) you wanna perform: ";
	cin >> choice;
	switch(choice){
		case 1:
			list[j]=addTask(j+1);
			j++;
			break;
	}
}

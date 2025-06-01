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
		void display();
		void stsChange();
};

void Task::display(){
	cout<<"\n"<<id<<"."<<des;
	if(status==true){
		cout<<"    Done!";
	} else{
		cout<<"    Due";
	}
}
Task addTask(int i){
	string input;
	cout << "Which task you wanna add? ";
	cin.ignore();//Clears the buffer, else the getline() will take the leftover \n instead of the intended input.
	getline(cin,input);
	Task a(i,input);
	return a;
}
void Task::stsChange(){
	status= !status;
}
	
	
int main(){
	Task list[20];
	int choice=0, i, j=0, id;
	cout << "MENU\n 1.Add Task\n 2.View To-Do List\n 3.Change Status(Done/Due)\n 4.Delete Task\n 5.Exit\n Enter the option(only the number) you wanna perform: ";
	do{
		cin >> choice;
		switch(choice){
			case 1:
				list[j]=addTask(j+1);
				list[j].display();
				j++;
				break;
			case 2:
				cout<<"\nYOUR TO-DO LIST";
				for(i=0;i<j;i++){
					list[i].display();
				}
				break;
			case 3:
				cout<<"You did it! Which task did you completed? Please enter the number as the following list and I'll mark it completed for you...";
				for(i=0;i<j;i++){
					list[i].display();
				}
				cin >> id;
				list[id-1].stsChange();
				cout<<"The updated list...";
				for(i=0;i<j;i++){
					list[i].display();
				}
				break;
			case 4:
				cout<<"Which task you wanna delete? Enter the number as the following list...";
				for(i=0;i<j;i++){
					list[i].display();
				}
				cin >> id;
				for(i=id-1;i<j;i++){
					list[id-1]=list[id];
				}
				j--;
				cout<<"\nDeleted! The updated list...";
				for(i=0;i<j;i++){
					list[i].display();
				}
				break;
			case 5:
				cout<<"\nGoodbye!";
				return 0;
		}
		cout<<"\nWanna do anything else from the above menu? "; 
	} while(choice!=5);
}

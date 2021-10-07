#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
bool IsLoggedIn()
{
    string username,password,un,pwd;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: "<<endl;
    cin>>password;
    ifstream read("data\\" +username+ ".txt");
    getline(read,un);
    getline(read,pwd);
    if(un==username && pwd==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int choice;
    cout<<"1:Register\n2:Sign in\n3:Enter your choice";
    cin>>choice;
    if(choice==1){
        string username,password;
        cout<<"Select a username: ";
        cin>>username;
        cout<<"Select a password: "<<endl;
        cin>>password;
        ofstream file;
        file.open("data\\" +username+ ".txt");
        file<<username<<endl<<password;
        file.close();
        main();
    }
    else if(choice==2)
    {
        bool status=IsLoggedIn();
        if(!status)
        {
            cout<<"Invalid Sign in!"<<endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout<<"Successfully signed in!";
            system("PAUSE");
            return 1;
        }
    }
}
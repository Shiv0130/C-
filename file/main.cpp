#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    /*file.open("Shiv.txt",ios::out);//write
    if (file.is_open()){
        file<<"Om namah Shiva"<<endl;
        file<<"Om namah Shiva"<<endl;
        file.close();
    }*/

       /*file.open("Shiv.txt",ios::app);//append
    if (file.is_open()){
        file<<"Om namah Shiva"<<endl;
        file<<"Om namah Shiva"<<endl;
        file<<"Om Triyambakum Yajamahe"<<endl;
        file.close();
    }*/

    file.open("Shiv.txt",ios::in);//read
    if(file.is_open()){
        string line;
        while(getline(file,line)){
                cout<< line <<endl;

        }
    }





    return 0;
}

/*#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>intList;
    intList.push_back(13);
    intList.push_back(75);
    intList.push_back(28);
    intList.push_back(100);
    cout<<"Vector Elements";
    for(int i = 0;i < 4;i++)
        cout<<intList[i]<<" " ;
     cout<<endl;


     for(int i = 0;i < 4;i++)
            intList[i]*=2;
     cout<<"List Elements:";
      for(int i = 0;i < 4;i++)
            cout<<intList[i]<<" ";
      cout<<endl;

      vector<int>::iterator vecit;
      cout<<"List Elements:";
       for(vecit= intList.begin();vecit!= intList.end();vecit++)
         cout<<*vecit<<" ";
       cout<<endl;

    vecit = intList.begin();
        ++vecit;
        ++vecit;

       intList.insert(vecit,1000);

      cout<<"New line Elements:";
      for(vecit=intList.begin();vecit!=intList.end();vecit++)
        cout<<*vecit<<" ";
        cout<<endl;

        cout<<"New line Elements:";
      for(vecit=intList.begin();vecit!=intList.end();vecit++)
        cout<<*vecit<<" ";
        cout<<endl;

    return 0;
}

Deque*/

#include <iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int>intDeq;
    intDeq.push_back(13);
    intDeq.push_back(80);
    intDeq.push_back(35);
    intDeq.push_back(75);

    cout<<"List Elements:";
    for(int i = 0;i<intDeq.size() ;i++)
        cout<<intDeq[i]<< " ";
        cout<<endl;
    intDeq.push_front(0);
    intDeq.push_back(100);

    cout<<"New List Elements:";

    for(int i = 0;i<intDeq.size() ;i++)
        cout<<intDeq[i]<< " ";
        cout<<endl;

    intDeq.pop_front();
    intDeq.pop_front();

    cout<<"New List Elements after removing first:";

    for(int i = 0;i<intDeq.size() ;i++)
        cout<<intDeq[i]<< " ";
        cout<<endl;
    intDeq.pop_back();
    intDeq.pop_back();
     cout<<"New List Elements after removing last:";

    for(int i = 0;i<intDeq.size() ;i++)
        cout<<intDeq[i]<< " ";
        cout<<endl;


    return 0;
}

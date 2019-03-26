#include "header.h"
#include<bits/stdc++.h>

using namespace std;

int main()
{  

project p;      
string sal;
p.myfunc2();
while(1)
{ 

cout<<" Enter the string to be searched. Enter , to stop "<<endl;
cin>>sal;   

if(sal==",")
 break;
 
 p.myfunc(sal);
}

p.WRITE_TO_FILE();

  return 0;
}

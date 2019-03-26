#include<bits/stdc++.h>
using namespace std;

  int main() 
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
    ifstream fin("words.txt");
    ofstream fou("New_Word.txt",ios::trunc);
    
    if(!fin || !fou)
   	{    cout<<"File cannot be opened."<<endl;
		 return 0;
    }
   	string s;
   	
   	while(getline(fin,s))
      fou<<s<<" "<<"0"<<"\n";
    
    
	
	fou.close();
	fin.close();
	
	return 0;
}  

#include "header.h"
#include<bits/stdc++.h>
#define len 31
#define N 1

using namespace std;


bool comp(pair<string,int>& p1,pair<string,int>& p2)
{   
    if(p1.second!=p2.second)
	return p1.second>p2.second;
	else
	return p1.first<=p2.first;
}

bk_node* project:: make_bk_node(string& x)
{
	bk_node* ptr=new bk_node;
	ptr->word=x;
	for(int i=0;i<20;i++)
    ptr->next[i]=NULL;
}

void project::myfunc2()
{
	root=read_from_file();
}

void project::myfunc(string&sal)
{ 
 
SEARCHED.resize(0);  
searchstring(root,sal);  

sort(SEARCHED.begin(),SEARCHED.end(),comp);

for(int i=0;i<min(5,int(SEARCHED.size()));i++)
 cout<<SEARCHED[i].first<<endl;
 
  cout<<"Enter the selected Word."<<endl;
  string word;
  cin>>word;
  FREQ[word]++;
}


int project:: pdistance(string& a,string& b)
{int m=a.length();
int n=b.length();

int dp[m+1][n+1];

dp[0][0]=0;

for(int i=1;i<=n;i++)
dp[0][i]=i;

for(int i=1;i<=m;i++)
dp[i][0]=i;

for(int i=1;i<=m;i++)
{
	for(int j=1;j<=n;j++)
	{  if(a[i-1]==b[j-1])
	     dp[i][j]=dp[i-1][j-1];
	     
	   else
	dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
}

}
   
return dp[m][n];
}


bk_node* project:: add_to_bktree(bk_node* root,string& s)
{
	if(root==NULL)
	{
		root=make_bk_node(s);
		return root;
	}
	
	int d=pdistance(root->word,s);
	if(root->next[d]==NULL)
{	root->next[d]=make_bk_node(s);
    return root;
}
	
	else
	{
	root->next[d]=add_to_bktree(root->next[d],s);
	return root;
    }
}

void project::getSimilarWords(bk_node* root,string& s) 
{ 
    if (root ==NULL) 
       return; 
    int dist = pdistance(root->word,s); 
    if (dist <= N) 
   SEARCHED.push_back(make_pair(root->word,FREQ[root->word])); 
    
    
    int start = dist - N; 
    if (start < 0) 
       start = 0; 
  
    while (start <= dist + N) 
    {  getSimilarWords(root->next[start],s); 
        start++; 
    } 
}

t_node*project:: create_t_node()
{
	t_node* ptr=new t_node;
	ptr->isend=false;
	
	for(int i=0;i<26;i++)
	ptr->arr[i]=NULL;
	
	return ptr;
}



void project:: insert_to_trie(string& key)
{ 
    t_node* temp=roott;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(temp->arr[index]==NULL)
		temp->arr[index]=create_t_node();
		
		temp=temp->arr[index];
	}
	temp->isend=true;

}

bool project:: islastnode(t_node *ptrr)
{
	for(int i=0;i<26;i++)
	{
		if(ptrr->arr[i]!=NULL)
		return false;
	}
	
	return true;
}


void project::suggest(t_node* ptr,string& str )
{

	if(ptr->isend==true)
	SEARCHED.push_back(make_pair(str,FREQ[str]));
	
	if(islastnode(ptr))
	return;
	
	for(int i=0;i<26;i++)
	{
		if(ptr->arr[i]!=NULL)
		{
			str.push_back(i+97);
			
			suggest(ptr->arr[i],str);              //my discovery.
			
			str.erase(str.length()-1,1);
		}
	}
}

vector<string>project:: separate(string& str) 
{ 
    
    istringstream ss(str); 
    vector <string> sal;
    
    do { 
        string word; 
        ss >> word; 
		sal.push_back(word);  
    } while (ss); 
    
    return sal;
} 


bk_node*project:: read_from_file()
{
    int count=0,lenn=-8;
    string word;  
    ifstream fin("new_word.txt");  
    
    if(!fin)
    {
    	cout<<"file cannot be opened"<<endl;
    	return NULL;
	}
	
    while(getline(fin,word))  
    { 
        vector<string> sal=separate(word);
	    insert_to_trie(sal[0]);
        root=add_to_bktree(root,sal[0]);
        stringstream k(sal[1]);
        int xx=0;
        k>>xx;
        FREQ[sal[0]]=xx;
        lenn=max(len,int(sal[0].length()));
        count++;
    }  
    
    cout<<"Total number of words read: "<<count<<endl;
    cout<<"Length of maximum word: "<<lenn<<endl;
    return root;
}




void project :: searchstring(bk_node* root,string& key)
{
	t_node* ptr=roott;
	for(int i=0;i<key.length();i++)
	{
		if(ptr->arr[key[i]-'a']==NULL)
		{
		cout<<" Did you mean : "<<endl;
		getSimilarWords(root,key);
		return;
	    }
		ptr=ptr->arr[key[i]-'a'];
	}

	
	 if(ptr->isend==true)
     {
     	 cout<<" Word found : "<<endl;
     	 SEARCHED.push_back(make_pair(key,FREQ[key]));
	 }
	 else
     {
	 cout<<" Word not found.You may these words: "<<endl;
  	 suggest(ptr,key);
     }
}


string project::IntToString(int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

void project:: WRITE_TO_FILE()
{
    ofstream fou("new_word.txt",ios_base::trunc);
    
    if(!fou)
    {
    	cout<<"Error in opening the file. "<<endl;
    	return;
	}
	
	for(map<string,int>::iterator it=FREQ.begin();it!=FREQ.end();it++)
	{
		  fou<<it->first<<" "<<IntToString(it->second)<<"\n";
	}
	
	fou.close();
}

//In the name of allah the most merciful
#include<bits/stdc++.h>
#define ll long long int
#define N 2
#define len 31
//#include "bk_trees.h"


using namespace std;


struct t_node
{
    bool isend;
    t_node* arr[26];      
};

t_node* create_t_node()
{   
    t_node* ptr=new t_node;
    ptr->isend=false;
    for(int i=0;i<26;i++)
      ptr->arr[i]=NULL;
    return ptr;
}


struct bk_node
{
    string word;
    bk_node* next[2*len];
};

bk_node* make_bk_node(string& x)
{
	bk_node* ptr=new bk_node;
	ptr->word=x;
    for(int i=0;i<2*len;i++)
    ptr->next[i]=NULL;
}

int distance(string& a,string& b)
{
int m=a.length();
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
	{  
	   if(a[i-1]==b[j-1])
         dp[i][j]=dp[i-1][j-1];

	    else
        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
    }
}
return dp[m][n];
}


bk_node* add_to_bktree(bk_node* root,string s)
{
	if(root==NULL)
   {
     	root=make_bk_node(s);
		return root;
	}

	int d=distance(root->word,s);
	if(root->next[d]==NULL)
{
	root->next[d]=make_bk_node(s);
    return root;
}
	else
{
	root->next[d]=add_to_bktree(root->next[d],s);
    return root;
}}

void get_similar_words(bk_node* ptr,string& s)
{
	if(ptr==NULL)
	 return;
	 
	 int dist=distance(ptr->word,s);
	 
	 if(dist<=2)
	 cout<<ptr->word;
	 
	 int i=max(0,dist-N);
	 
	 while(i<=dist+N)
	 {
	 	 get_similar_words(ptr->next[i],s);
	 	 i++;
	 }
 
}

t_node* roott=create_t_node();

void insert_to_trie(string key)
{  
  t_node* temp=roott;
    for(int i=0;i<key.length();i++)
	{	int index=key[i]-'a';
      	if(temp->arr[index]==NULL)
       temp->arr[index]=create_t_node();
        temp=temp->arr[index];
	}
	temp->isend=true;
}

bk_node* read_from_file(bk_node* ptr)
{
   ifstream in("words.txt");

  if(!in)
   {
    cout << "Cannot open input file.\n";
    return ;
  }

  string kaif;
  int count=0;
  int len=-2;
  while(getline(in,kaif))
  {
     insert_to_trie(kaif);
     ptr=add_to_bktree(ptr,kaif);
     
     len=max(len,int(kaif.length()));
     count++;
  }
  //cout<<"Total no. of words read "<<count<<" "<<len<<endl;
  return ptr;
}

bool islastnode(t_node *ptrr)
{
	for(int i=0;i<26;i++)
	{
		if(ptrr->arr[i]!=NULL)
		return false;
	}

	return true;
}



void suggest(t_node* ptr,string& str)
{

	if(ptr->isend==true)
	{
		cout<<str<<endl;
	}
	
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



 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
     
    bk_node* p=NULL;
    p=read_from_file(p);
    
    
    return 0;
}  

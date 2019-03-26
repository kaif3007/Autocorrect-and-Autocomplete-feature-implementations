#ifndef header
#define header
#define len 31
#include<bits/stdc++.h>


struct t_node
{
    bool isend;
	t_node* arr[26];        	
};

struct bk_node
{
	std::string word;
	bk_node* next[2*len];
};

bool comp(std::pair<std::string,int>& p1,std::pair<std::string,int>& p2);

class project
{  
    private:
    	std::map<std::string,int> FREQ;
        std::vector< std::pair<std::string,int> > SEARCHED;
        bk_node* root;
        t_node* roott;
    	
	public:
	project()
	{
		SEARCHED.resize(0);
		root=NULL;
		roott=create_t_node();
	}	 
	bk_node* make_bk_node(std::string& x);
	int pdistance(std::string& a,std::string& b);	
	bk_node* add_to_bktree(bk_node* root,std::string& s);
	void getSimilarWords(bk_node* root,std::string& s);
	t_node* create_t_node();
	void insert_to_trie(std::string& key);
	bool islastnode(t_node *ptrr);
	std::vector<std::string> separate(std::string& str);
	bk_node* read_from_file();
	void searchstring(bk_node* root,std::string& key);
	std::string IntToString (int a);
	void WRITE_TO_FILE();
	void suggest(t_node* ptr,std::string& str);
	void myfunc(std::string & sal);
	void myfunc2();
};


#endif

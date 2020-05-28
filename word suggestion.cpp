#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int sp=0;
class Node
{
	friend class Trie;
private:
	char c;
	bool word; //  end of word
	Node* child[128]; // next node ASCII  (0-127)
public:
	Node();
	~Node() {}
	void setWord(int boo) {this->word = boo;}
	bool isWord() {return this->word;}
	void setChar(char ch) {this->c = ch;}
	char getChar() const {return this->c;}
};





class Trie
{
	friend class Node;
private:
	bool space;
	string no_prefix;
	Node* root;
public:
	Trie() {root = new Node(); this->space = false;}
	~Trie() {}
	void is_space(string data); //space and set bool
	bool getSpace() {return space;}
	void insert(string data);
	void search(string data);
	void print_tree(Node* root, string data, string str);
	void print_tree(Node* root, string str);
	void remove_prefix(string data);
	string getNo_prefix() {return no_prefix;}
	string break_string(string);
};







Node::Node()
{
	this->setChar('\0');
	this->setWord(false);
	for (int i = 0; i < 128; i++)
		this->child[i] = NULL;
}



void Trie::insert(string data)
{
	Node* tmp = root;
	char cstr[data.length()];

	data.copy(cstr, data.length()); //char array containing data from string object
	for (int i = 0; i < data.length(); i++)
	{
		if (tmp->child[static_cast<int>(cstr[i])] != NULL)
			tmp = tmp->child[static_cast<int>(cstr[i])];
		else
		{
			tmp->child[static_cast<int>(cstr[i])] = new Node();
			tmp = tmp->child[static_cast<int>(cstr[i])];
			tmp->setChar(cstr[i]);
		}
	}
	tmp->setWord(true);
}

void Trie::print_tree(Node* root, string data, string str)
{
	for (int i = 97; i < 128; i++) // all 128 pointers in node to check if there's a child
	{
		Node* adv = root;
		if (adv->child[i] != NULL) //child exists
		{
			adv = adv->child[i];
			str += adv->getChar(); // char to end of prefix
			if (adv->isWord()) //if point at end of word, print word
			{
				if (this->getSpace() == true)
					cout << this->getNo_prefix();
				cout << str << "     ";sp++;
				if(sp==10)
                {
                    sp=0;cout<<endl;
                }
			}
			print_tree(adv, str);
		}
		str = data; //reset string
	}
}

void Trie::print_tree(Node* root, string str)
{
	string str_tmp = str;

	for (int i = 97; i < 128; i++)
	{
		Node* adv = root;
		if (adv->child[i] != NULL)
		{
			adv = adv->child[i];
			str += adv->getChar();
			if (adv->isWord())
			{
				if (this->getSpace() == true)
					cout << this->no_prefix;
				cout << str <<"       ";sp++;
				if(sp==10)
		{sp=0;cout<<endl;}
			}
			print_tree(adv, str);
		}
		str = str_tmp;

	}
}

void Trie::search(string data)
{
	Node* tmp = root;
	char cstr[data.length()];

	data.copy(cstr, data.length(), 0);
	for (int i = 0; i < data.length(); i++)
		{if ((tmp->child[static_cast<int>(cstr[i])] == NULL) )
		{
			cout << "error:  string not found" << endl;
			return;
		}
		else
			tmp = tmp->child[static_cast<int>(cstr[i])];
		if (tmp->getChar() != cstr[i]) //if prefix not in dictionary
		{
			cout << "error:  string not found" << endl;
			return;
		}
	}
	string str = data;
	print_tree(tmp, data, str);
}

void Trie::is_space(string data)
{
	char cstr[data.length()];

	data.copy(cstr, data.length());
	for (int i = 0; i < data.length(); i++)
	{
		if (cstr[i] == ' ')
		{
			space = true;
			return;
		}
		else
			continue;
	}
}

string Trie::break_string(string data)
{
	char cstr[data.length()];
	string str;
	data.copy(cstr, data.length());

	for (int i = data.length(); i-- > 0;)
	{
		if (cstr[i] == ' ')
			 break;
		else
			str.insert(str.begin(),cstr[i]);
	}
	return str;
}

void Trie::remove_prefix(string data)
{
	char cstr[data.length()];
	data.copy(cstr, data.length());

	for (int i = data.length(); i-- > 0;)
	{
		if (cstr[i] == ' ')
			break;
		else
			cstr[i] = '\0';
	}
	no_prefix = cstr;
}





int main(int argc, char const *argv[])
{
	string data="";
 cout<<endl<< "HELLO!"<<endl<<"AUTO SUGGEST !! "<<endl;
	cout<<endl<<"DATA STRUCTURES AND ALGORITHM'S PROJECT MADE BY :"<<endl<<endl<<"MADHAV AGRAWAL "<<endl;
fstream dictionary;
	Trie complete_query;

	dictionary.open("dictionary.txt", fstream::in); //read dictionary file into trie
	if (dictionary.is_open())
	{
		while (dictionary)
		{
			dictionary >> data;
			complete_query.insert(data);
		}
	}
	else
	{
		cout << "Error:  File Not Opened." << endl;
		return -1;
	}
	dictionary.close();
	data.clear();
	while(true)
    {

	cout<<endl<<"ENTER 1 TO ADD A NEW WORD , 2 TO USE OUR SUGGEST FEATURE AND ANY OTHER TO EXIT ! "<<endl;
	int choic;cin>>choic;
	if(choic==1)
    {
//
	cout<<"Enter New Word"<<endl;
	string my;
	cin>>my;
	cout<<endl<<my<<" has been Successfully Added !"<<endl;
		complete_query.insert(my);
	fstream dictionary2;

	dictionary2.open("dictionary.txt",fstream::app);
	if (dictionary2.is_open())
	{
		dictionary2<<my;
	}
	else
	{
		cout << "Error:  File Not Opened." << endl;
		return -1;
	}
	dictionary2.close();
    }
//
else if(choic==2)
	{
data="";
	while(true){
            cout<<endl<< "HELLO!"<<endl<<"AUTO SUGGEST !! "<<endl;
	cout<<endl<<"DATA STRUCTURES AND ALGORITHM'S PROJECT MADE BY :"<<endl<<endl<<"MADHAV AGRAWAL";
	cout<<endl<<"PLEASE ENTER YOUR QUERY! "<<endl<<endl<<endl;
	cout<<data;
            char ch;bool space=false;
           // cin>>ch;
            ch=_getch();system("cls");
            if((ch>=97&&ch<=122))
            {
                data+=ch;
            }
            else if(ch==8)
            {
                data=data.substr(0,data.length()-1);

            }
            else if((ch==32))
            {
                space=true;
            }
            else{
                break;
            }


	//getline(cin, data);
	cout<<endl;
	complete_query.is_space(data);
	cout << "Your search Results Are:  " << endl<<endl;
	if(data.length()!=0)
    {

if(data[data.length()-1]!=32)
{


	if (complete_query.getSpace() == true)
	{
		complete_query.remove_prefix(data);
		complete_query.search(complete_query.break_string(data));
	}
	else
		complete_query.search(data);
    }

    }
		Sleep(500);

		if(space) data+=" ";

	}
	}
	else
    {
     cout<<endl<<"Thank You ! "<<endl;
	return 0;
    }
    }
}

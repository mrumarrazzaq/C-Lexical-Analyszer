#include<iostream>
#include <fstream>
#include<cctype>
#include<string.h>
#include <bits/stdc++.h>
#include<windows.h>
#include <stdlib.h>
#define N 37
using namespace std;
char id_buffer[15];
char numeric_buffer[15];
char oop_buffer[2];
char str_buffer[50];
int index=0;
char keywords[37][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","if","cout","cin","operator","string"};


void setColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void object_code()
{
	char ch;
	
	ifstream readFile;
	readFile.open("program.txt");
	if(!readFile.is_open())
	{
		cout<<"Error while opening the file\n";
		exit(0);
	}
	readFile.get(ch);
	while(!readFile.eof())
	{
		cout<<ch;
		readFile.get(ch);
	}
	readFile.close();
}




void Lexecial()
{
	char ch;
	int j=0;
	int key=0,id=0,oop=0,num=0,str=0,lines=0;
	int flag=0;
	ifstream readFile;
	readFile.open("program.txt");
	if(!readFile.is_open())
	{
		cout<<"Error while opening the file\n";
		exit(0);
	}
	readFile.get(ch);
	
	
	while(!readFile.eof())
	{
		
		if(ch=='\n')
		{
			lines++;
		}
		if(ch=='"')
		{
			str_buffer[index++]=ch;
			readFile.get(ch);
			while(ch !='"')
			{
				str_buffer[index++]=ch;		
				readFile.get(ch);
			}
			str_buffer[index++]=ch;
			cout<<str_buffer<<"\t\t :  string \n";
			str++;
				for(int i=0;i<50;i++)
				str_buffer[i]='\0';
				index=0;
		}
//		if(isalpha(ch))
//		{
//			alpha_buffer[j++]=ch;
//		}
//		else
//		{
//			if(alpha_buffer[0]!='\0')
//			{
//				
//				for(int i = 0; i < N; ++i)
//				{
//					if(strcmp(keywords[i], alpha_buffer) == 0)
//					{
//						flag = 1;
//						break;
//					}
//				}
//				if(flag==1)
//				{
//					cout<<alpha_buffer<<"\t\t :";setColor(4);cout<<"  keyword\n";setColor(7 );
//					key++;
//					flag=0;
//				}
//				else
//				{
//					cout<<alpha_buffer<<"\t\t :";setColor(3);cout<<"  identifer\n";setColor(7 );
//					id++;
//				}
//				
//				for(int i=0;i<15;i++)
//				alpha_buffer[i]='\0';
//				j=0;
//			}
//		}

		if(isalpha(ch))
		{
			id_buffer[index++]=ch;
			readFile.get(ch);
			while((isalpha(ch)||isdigit(ch)) && !readFile.eof())
			{
				id_buffer[index++]=ch;		
				readFile.get(ch);
			}
				for(int i = 0; i < N; ++i)
				{
					if(strcmp(keywords[i], id_buffer) == 0)
					{
						flag = 1;
						break;
					}
				}
				if(flag==1)
				{
					cout<<id_buffer<<"\t\t :";setColor(4);;cout<<"  keyword\n";setColor(7);
					key++;
					flag=0;
				}
				else
				{
					cout<<id_buffer<<"\t\t :";setColor(3);;cout<<"  identifer\n";setColor(7);
					id++;
				}
				for(int i=0;i<15;i++)
				id_buffer[i]='\0';
				index=0;
		}
		if(isdigit(ch))
		{
			numeric_buffer[index++]=ch;
		}
		else
		{
			if(numeric_buffer[0]!='\0')
			{
				cout<<numeric_buffer<<"\t\t :";setColor(6);cout<<"  number\n";setColor(7);
				num++;
				for(int i=0;i<15;i++)
				numeric_buffer[i]='\0';
				index=0;
			}
		}
		if(ch=='='||ch=='!'||ch=='+'||ch=='-'||ch=='<'||ch=='>')
		{
			oop_buffer[j++]=ch;
		}
		else
		{
			if(oop_buffer[0]!='\0')
			{
				cout<<oop_buffer<<"\t\t :";setColor(2);cout<<"  operator\n";setColor(7);
				oop++;
				for(int i=0;i<2;i++)
				oop_buffer[i]='\0';
				j=0;
			}
		}
		if(ch=='*'||ch=='/'||ch=='%'||ch==','||ch=='.'||ch=='|'||ch==';'||ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='('||ch==')'||ch=='&')
		{
			cout<<ch<<"\t\t :";setColor(2);cout<<"  operator\n";setColor(7);
			oop++;
		}
		
		readFile.get(ch);
	}
	readFile.close();
	cout<<"\n--------------------------------\n";
	cout<<"No of KEYWORS       : "<<key<<endl;
	cout<<"No of IDENTIFERS    : "<<id<<endl;
	cout<<"No of OPERATORS     : "<<oop<<endl;
	cout<<"No of Numbers       : "<<num<<endl;
	cout<<"No of Strings       : "<<str<<endl;
	cout<<"No of Lines         : "<<lines+1<<endl;
}
int main()
{
	object_code();	
	cout<<"\n___________________________\n";
	cout<<"Lexeme"<<"\t\t :  Token\n";
	cout<<"___________________________\n\n";
	Lexecial();
	
	return 0;
}

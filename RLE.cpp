#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<fstream>
using namespace std;



void encoder();
void decoder();


int main()
{

	encoder();
	// decoder();

}


void encoder()
{
	ifstream fin;
	ofstream fout;
	string filename;
	cout << "Enter the file name & Destination:  ";
	cin >> filename;
	fin.open(filename);
	int count = 1, counter = 0;
	char ch,previous;
	while(fin.get(ch)){
		//fin>>ch;
		if(ch == '\n'){
			ch ='`';
		}
		if(ch == ' '){
			ch ='~';
		}
		//cout<<ch<<endl;
		if (counter == 0){
			previous = ch;
			counter++;
			continue;	
		}
		
		if(ch == previous){	
			count++;
		}
		else{
			fout.open("compressed.cmp", ios::out | ios::app);
			fout<<count<<previous;
			fout<<endl;
			fout.close();
			previous = ch;
			count = 1;
		}
	}
	fin.close();	
}



void decoder()
{
	
	ifstream fin;
	ofstream fout;
	string filename;

	cout << "Enter FileName which is to be decompressed:  ";
	cin >> filename;

	fin.open(filename);
	if(fin.is_open()){	
	string line;
	
	while(getline(fin, line)){
		int integer;
		char ch;	
		stringstream(line)>>integer>>ch;
		cout<<integer<<endl;
		cout<<ch<<endl;
		fout.open(filename, ios::out | ios::app);
		for(int i=0; i < integer; i++){
			if(ch == '`'){
				fout<<endl;
			}
			else if(ch == '~'){
				fout<<" ";
			}
			else{
				fout<<ch;	
			}
			
		}
		fout.close();
	}
	
	}
	else{
		cout<<" i ma in"<<endl;
	}
	fin.close();
}
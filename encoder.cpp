#include "RLE.h"

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
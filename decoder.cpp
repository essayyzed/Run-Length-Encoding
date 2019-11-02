#include "RLE.h"

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
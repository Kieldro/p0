/*
Ian Buitrago
ib
1-26-2012
CS 337
discussion: Th 9a
project 0

notes:
c++ source
run with:
g++ -o Encode Encode.cc; ./Encode
*/

#include <iostream>
#include <fstream>

using namespace std;

const bool DEBUG = 1;

int main(){
	
	ifstream inFile ("project0.txt");
	ofstream outFile ("project0.enc");
	char * b;
	*b =  'T';		// byte, u
	
	while(inFile.good() ){
		inFile.read(b, 1);
		if(DEBUG) cout << hex << unsigned int(b) << endl;
		
		bool odd = 0;
		for(int x = 0; x < 7; ++x){
			unsigned char t = *b;
			t >>= x;
			t &= 01;		// octal notation
			if(t)
				odd = !odd;
		}
		
		if(odd){
			b |= 0x80;		// add parity bit
			if(DEBUG) cout << "Parity bit added." << endl;}
		
		if(DEBUG) cout << hex << unsigned int(b) << endl;
		if(DEBUG) cout << hex << b << endl;
		if(DEBUG) cout << hex << (unsigned int)b << endl;
		
		outFile.write(b, 1);
	}
	
	inFile.close();
	
	return 0;
}

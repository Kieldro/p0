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
	
	while(inFile.good() ){
		char * b = new char;		// allocate memory or get seg fault
		inFile.read(b, 1);
		if(DEBUG) cout << hex << *b << endl;
		if(DEBUG) cout << hex << int(*b) << endl;
		
		bool odd = 0;
		for(int x = 0; x < 7; ++x){
			unsigned char byte = *b;
			byte >>= x;
			byte &= 01;		// octal notation
			if(byte)
				odd = !odd;
		}
		
		if(odd){
			*b |= 0x80;		// add parity bit
			if(DEBUG) cout << "Parity bit added." << endl;}
		else
			if(DEBUG) cout << "byte unchanged." << endl;
		
		if(DEBUG) cout << hex << *b << endl;
		if(DEBUG) cout << hex << (unsigned int)(*b) << endl;
		
		outFile.write(b, 1);
	}
	
	inFile.close();
	outFile.close();		// writes buffer to file
	
	
	return 0;
}

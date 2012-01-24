/*
Ian Buitrago: Slip days used for this project: 0  Slip days used (total): 0
ib
1-26-2012
CS 337
discussion: Th 9a
project 0

notes:
java source
run with:
javac Encode.java; java Encode
check with: diff project0.enc project0test.enc
*/

import java.io.*;

public class Encode{		// java: everything is in a class
	static final boolean DEBUG = true;
	
	public static void main(String[] args) throws Exception{		// throws because of file io
		
		int character;
		FileReader inFile = new FileReader("project0.txt");
		
		while ( -1 != (character = inFile.read()) ){
			if(DEBUG) System.out.println( (char) character);
			if(DEBUG) System.out.println( String.format("0x%1$X", character) );
			
			boolean odd = false;
			for(int i = 0; i < 7; ++i){
				int c = character;
				c >>= i;
				c &= 01;		// octal notation
				if(c == 1)
					odd = !odd;
			}
		
			if(odd){
				character |= 0x80;		// add parity bit
				if(DEBUG) System.out.println( "Parity bit added." );
				if(DEBUG) System.out.println( String.format("0x%1$X", character) );
				if(DEBUG) System.out.println( (char) character);}
			else
				if(DEBUG) System.out.println( "byte unchanged." );
			
			if(DEBUG) System.out.println( );
			
		}
		
		inFile.close();
		/*
		while( true ){
			byte * b = new byte;		// allocate memory or get seg fault
			inFile.read(b, 1);
			if( !inFile.good() )
				break;
		
			bool odd = 0;
			for(int x = 0; x < 7; ++x){
				byte Byte= *b;
				Byte >>= x;
				Byte &= 01;		// octal notation
				if(Byte)
					odd = !odd;
			}
		
			if(odd){
				*b |= 0x80;		// add parity bit
				if(DEBUG) System.out.println( "Parity bit added." );
				if(DEBUG) System.out.println( b );
				if(DEBUG) System.out.println( (char) b);}
			else
				if(DEBUG) System.out.println( "byte unchanged." );
		
			outFile.write(b, 1);
		}
		*/
	}
}

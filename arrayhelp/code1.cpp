#include <iostream>

using namespace std;

#include "arrays.cpp"

unsigned char center[12][24] = {	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,19,16,17,18,20,21,22,23},
                                	{12,1,2,15,0,5,6,3,4,9,10,7,8,13,14,11,16,17,18,19,20,21,22,23},
                                	{0,13,14,3,4,1,2,7,8,5,6,11,12,9,10,15,16,17,18,19,20,21,22,23},
	                                {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,20},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,15,12,13,14,16,17,18,19,20,21,22,23},
        	                        {20,21,2,3,4,5,6,7,8,9,16,17,12,13,14,15,0,1,18,19,10,11,22,23},
					{0,1,22,23,4,5,6,7,18,19,10,11,12,13,14,15,16,17,2,3,20,21,8,9},
                                        {0,1,2,3,5,6,7,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {3,0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,23,20,6,7,8,9,10,11,12,13,17,18,16,4,5,19,15,21,22,14},
                                        {0,1,2,3,4,5,21,22,8,9,10,11,19,16,14,15,7,17,18,6,20,12,13,23},
                                        {0,1,2,3,4,5,6,7,9,10,11,8,12,13,14,15,16,17,18,19,20,21,22,23}};

int main(int argc, char** argv) {

  for (int i=0;i<12;i++){
    for (int j=0;j<24;j++){
     centermove[3*i][j]=center[i][j];
     centermove[3*i+1][j]=center[i][center[i][j]];
     centermove[3*i+2][j]=center[i][center[i][center[i][j]]];
    }
  }
  
  cout << "unsigned char centermove[36][24] =  {   ";
  for (int i=0;i<35;i++){
    cout << "                                        {";
    for (int j=0;j<23;j++) cout << centermove[i][j]+0 << ",";
    cout << centermove[i][23]+0 << "},\n";
  }
  cout << "                                        {";
  for (int j=0;j<23;j++) cout << centermove[35][j]+0 << ",";
  cout << centermove[35][23]+0 << "}};\n";

}
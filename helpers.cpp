/*
int LoadFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::in | ios::binary);
	if(!File.read(mem, size)) {File.clear(); return 1;} else return 0;  // return 1 in case of read error
}

int WriteFile(unsigned char* mem, string filename, int size) {
	fstream File(filename.c_str(), ios::out | ios::binary);
	if(!File.write(mem, size)) {File.clear(); return 1;} else return 0;
}
*/

/*inline*/ void turncube (unsigned char* CubePos,unsigned char* WritePos,unsigned char Move){
 *WritePos=edgeturn[Move][*CubePos];
 *(WritePos+1)=edgeturn[Move][*(CubePos+1)];
 *(WritePos+2)=edgeturn[Move][*(CubePos+2)];
 *(WritePos+3)=edgeturn[Move][*(CubePos+3)];
 *(WritePos+4)=edgeturn[Move][*(CubePos+4)];
 *(WritePos+5)=edgeturn[Move][*(CubePos+5)];
 *(WritePos+6)=edgeturn[Move][*(CubePos+6)];
 *(WritePos+7)=cornerturn[Move][*(CubePos+7)];
 *(WritePos+8)=cornerturn[Move][*(CubePos+8)];
 *(WritePos+9)=cornerturn[Move][*(CubePos+9)];
 *(WritePos+10)=cornerturn[Move][*(CubePos+10)];
 *(WritePos+11)=cornerturn[Move][*(CubePos+11)];
 *(WritePos+12)=cornerturn[Move][*(CubePos+12)];
 *(WritePos+13)=cornerturn[Move][*(CubePos+13)];
 *(WritePos+14)=cornerturn[Move][*(CubePos+14)];
 *(WritePos+15)=cornerturn[Move][*(CubePos+15)];
 *(WritePos+16)=cornerturn[Move][*(CubePos+16)];
 *(WritePos+17)=cornerturn[Move][*(CubePos+17)];
 *(WritePos+18)=cornerturn[Move][*(CubePos+18)];
 *(WritePos+19)=cornerturn[Move][*(CubePos+19)];
 *(WritePos+20)=cornerturn[Move][*(CubePos+20)];
 *(WritePos+21)=cornerturn[Move][*(CubePos+21)];
 *(WritePos+22)=cornerturn[Move][*(CubePos+22)];
 *(WritePos+23)=cornerturn[Move][*(CubePos+23)];
 *(WritePos+24)=cornerturn[Move][*(CubePos+24)];
 *(WritePos+25)=cornerturn[Move][*(CubePos+25)];
 *(WritePos+26)=cornerturn[Move][*(CubePos+26)];
 *(WritePos+27)=cornerturn[Move][*(CubePos+27)];
 *(WritePos+28)=cornerturn[Move][*(CubePos+28)];
 *(WritePos+29)=cornerturn[Move][*(CubePos+29)];
 *(WritePos+30)=cornerturn[Move][*(CubePos+30)];
 *(WritePos+31)=centerturn[Move][*(CubePos+31)];
 *(WritePos+32)=centerturn[Move][*(CubePos+32)];
 *(WritePos+33)=centerturn[Move][*(CubePos+33)];
 *(WritePos+34)=centerturn[Move][*(CubePos+34)];
 *(WritePos+35)=centerturn[Move][*(CubePos+35)];
 *(WritePos+36)=centerturn[Move][*(CubePos+36)];
 *(WritePos+37)=centerturn[Move][*(CubePos+37)];
 *(WritePos+38)=centerturn[Move][*(CubePos+38)];
 *(WritePos+39)=centerturn[Move][*(CubePos+39)];
 *(WritePos+40)=centerturn[Move][*(CubePos+40)];
 *(WritePos+41)=centerturn[Move][*(CubePos+41)];
 *(WritePos+42)=centerturn[Move][*(CubePos+42)];
 *(WritePos+43)=centerturn[Move][*(CubePos+43)];
 *(WritePos+44)=centerturn[Move][*(CubePos+44)];
 *(WritePos+45)=centerturn[Move][*(CubePos+45)];
 *(WritePos+46)=centerturn[Move][*(CubePos+46)];
 *(WritePos+47)=centerturn[Move][*(CubePos+47)];
 *(WritePos+48)=centerturn[Move][*(CubePos+48)];
 *(WritePos+49)=centerturn[Move][*(CubePos+49)];
 *(WritePos+50)=centerturn[Move][*(CubePos+50)];
 *(WritePos+51)=centerturn[Move][*(CubePos+51)];
 *(WritePos+52)=centerturn[Move][*(CubePos+52)];
 *(WritePos+53)=centerturn[Move][*(CubePos+53)];
 *(WritePos+54)=centerturn[Move][*(CubePos+54)];
}

/*inline*/ void movecube (unsigned char* CubePos,unsigned char* WritePos,unsigned char Move){
 unsigned char tmp=edgemap[Move];if(tmp!=18){			//check wether we have to act on the edge positions at all
   *WritePos=edgemove[tmp][*CubePos];
   *(WritePos+1)=edgemove[tmp][*(CubePos+1)];
   *(WritePos+2)=edgemove[tmp][*(CubePos+2)];
   *(WritePos+3)=edgemove[tmp][*(CubePos+3)];
   *(WritePos+4)=edgemove[tmp][*(CubePos+4)];
   *(WritePos+5)=edgemove[tmp][*(CubePos+5)];
   *(WritePos+6)=edgemove[tmp][*(CubePos+6)];}
 *(WritePos+7)=cornermove[Move][*(CubePos+7)];
 *(WritePos+8)=cornermove[Move][*(CubePos+8)];
 *(WritePos+9)=cornermove[Move][*(CubePos+9)];
 *(WritePos+10)=cornermove[Move][*(CubePos+10)];
 *(WritePos+11)=cornermove[Move][*(CubePos+11)];
 *(WritePos+12)=cornermove[Move][*(CubePos+12)];
 *(WritePos+13)=cornermove[Move][*(CubePos+13)];
 *(WritePos+14)=cornermove[Move][*(CubePos+14)];
 *(WritePos+15)=cornermove[Move][*(CubePos+15)];
 *(WritePos+16)=cornermove[Move][*(CubePos+16)];
 *(WritePos+17)=cornermove[Move][*(CubePos+17)];
 *(WritePos+18)=cornermove[Move][*(CubePos+18)];
 *(WritePos+19)=cornermove[Move][*(CubePos+19)];
 *(WritePos+20)=cornermove[Move][*(CubePos+20)];
 *(WritePos+21)=cornermove[Move][*(CubePos+21)];
 *(WritePos+22)=cornermove[Move][*(CubePos+22)];
 *(WritePos+23)=cornermove[Move][*(CubePos+23)];
 *(WritePos+24)=cornermove[Move][*(CubePos+24)];
 *(WritePos+25)=cornermove[Move][*(CubePos+25)];
 *(WritePos+26)=cornermove[Move][*(CubePos+26)];
 *(WritePos+27)=cornermove[Move][*(CubePos+27)];
 *(WritePos+28)=cornermove[Move][*(CubePos+28)];
 *(WritePos+29)=cornermove[Move][*(CubePos+29)];
 *(WritePos+30)=cornermove[Move][*(CubePos+30)];
 *(WritePos+31)=centermove[Move][*(CubePos+31)];
 *(WritePos+32)=centermove[Move][*(CubePos+32)];
 *(WritePos+33)=centermove[Move][*(CubePos+33)];
 *(WritePos+34)=centermove[Move][*(CubePos+34)];
 *(WritePos+35)=centermove[Move][*(CubePos+35)];
 *(WritePos+36)=centermove[Move][*(CubePos+36)];
 *(WritePos+37)=centermove[Move][*(CubePos+37)];
 *(WritePos+38)=centermove[Move][*(CubePos+38)];
 *(WritePos+39)=centermove[Move][*(CubePos+39)];
 *(WritePos+40)=centermove[Move][*(CubePos+40)];
 *(WritePos+41)=centermove[Move][*(CubePos+41)];
 *(WritePos+42)=centermove[Move][*(CubePos+42)];
 *(WritePos+43)=centermove[Move][*(CubePos+43)];
 *(WritePos+44)=centermove[Move][*(CubePos+44)];
 *(WritePos+45)=centermove[Move][*(CubePos+45)];
 *(WritePos+46)=centermove[Move][*(CubePos+46)];
 *(WritePos+47)=centermove[Move][*(CubePos+47)];
 *(WritePos+48)=centermove[Move][*(CubePos+48)];
 *(WritePos+49)=centermove[Move][*(CubePos+49)];
 *(WritePos+50)=centermove[Move][*(CubePos+50)];
 *(WritePos+51)=centermove[Move][*(CubePos+51)];
 *(WritePos+52)=centermove[Move][*(CubePos+52)];
 *(WritePos+53)=centermove[Move][*(CubePos+53)];
 *(WritePos+54)=centermove[Move][*(CubePos+54)];
}

bool solved(unsigned char* Position){
  for(unsigned char i=0;i<7;i++){if(*(Position+i)!=3*i)return false;}
  for(unsigned char i=0;i<24;i++){if(*(Position+i+7)!=i||*(Position+i+31)!=i)return false;}
  return true;
}

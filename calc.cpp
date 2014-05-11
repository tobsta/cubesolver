inline uchar sethalfbyte(uchar a/*Eingangsbyte*/,uchar b/*Modifikation*/,uchar c/*lower(0) or upper half(1)*/){
  return (b<<4*c)|(a&(240-225*c));			//returns the upper part of the byte when c==1 otherwise the lower part
}

inline uchar readhalfbyte(uchar a/*Eingangsbyte*/, uchar c/*lower(0) or upper half(1)*/){
  return (a>>4*c)&15;					//sets the upper part of the byte when c==1 otherwise the lower part
}

//inline uchar sethalfbyte(uchar a/*Eingangsbyte*/,uchar b/*Modifikation*/,uchar c/*lower(0) or upper half(1)*/){
////  if(c)return (b<<4)|(a&15); else return b|(a&240);
//  return c ? (b<<4)|(a&15) : b|(a&240);
//}
//
//inline uchar readhalfbyte(uchar a/*Eingangsbyte*/, uchar c/*lower(0) or upper half(1)*/){
////  if(c)return a>>4; else return a&15
//  return c ? a>>4 : a&15;
//}

uint posedges(uchar a,uchar b,uchar c,uchar d,uchar e,uchar f,uchar g){
 uchar B=b,C=c,D=d,E=e,F=f,G=g; 		//calculates a unique linear position for every possible edgeposition

 if (a<B) b-=3;
 if (a<C) c-=3;
 if (B<C) c-=3;
 if (a<D) d-=3;
 if (B<D) d-=3; 
 if (C<D) d-=3;
 if (a<E) e-=3;
 if (B<E) e-=3;
 if (C<E) e-=3;
 if (D<E) e-=3;
 if (a<F) f-=3;
 if (B<F) f-=3;
 if (C<F) f-=3;
 if (D<F) f-=3;
 if (E<F) f-=3;
 if (a<G) g-=3;
 if (B<G) g-=3;
 if (C<G) g-=3;
 if (D<G) g-=3;
 if (E<G) g-=3;
 if (F<G) g-=3;
return (3674160*a+174960*b+9720*c+648*d+54*e+6*f+g);
}

uint poscorners(uchar a,uchar b,uchar c,uchar d,uchar e,uchar f){
 uchar B=b,C=c,D=d,E=e,F=f;			//the same for the corners

 if (a<B) b--;		//the order might be changed by using <= signs
 if (a<C) c--;
 if (B<C) c--;
 if (a<D) d--;
 if (B<D) d--;
 if (C<D) d--;
 if (a<E) e--;
 if (B<E) e--;
 if (C<E) e--;
 if (D<E) e--;
 if (a<F) f--;
 if (B<F) f--;
 if (C<F) f--;
 if (D<F) f--;
 if (E<F) f--;
return (4037880*a+175560*b+7980*c+380*d+19*e+f);
}

uint poscenters(uchar a,uchar b,uchar c,uchar d,uchar e,uchar f,uchar g, uchar h){
//and the same again for the centers, this is more difficult because 4 center pieces are equivalent
//but therefore the memory usage is also reduced by a factor of 24^2.
/*
  if (a>b){uchar tmp=b;b=a;a=tmp;}		//the values are sorted by size, each group of 4 elements on its own,
  if (b>c){uchar tmp=c;c=b;b=tmp;}		//with increasing size from a-d;e-h
  if (c>d){uchar tmp=d;d=c;c=tmp;}
  if (a>b){uchar tmp=b;b=a;a=tmp;}
  if (b>c){uchar tmp=c;c=b;b=tmp;}
  if (a>b){uchar tmp=b;b=a;a=tmp;}

  if (e>f){uchar tmp=f;f=e;e=tmp;}
  if (f>g){uchar tmp=g;g=f;f=tmp;}
  if (g>h){uchar tmp=h;h=g;g=tmp;}
  if (e>f){uchar tmp=f;f=e;e=tmp;}
  if (f>g){uchar tmp=g;g=f;f=tmp;}
  if (e>f){uchar tmp=f;f=e;e=tmp;}
*/
  if (a>b)swap(a,b);              			//the values are sorted by size, each group of 4 elements on its own,
  if (c>d)swap(c,d);              			//with increasing size from a-d;e-h
  if (a>c)swap(a,c);
  if (b>d)swap(b,d);
  if (b>c)swap(b,c);

  if (e>f)swap(e,f);
  if (g>h)swap(g,h);
  if (e>g)swap(e,g);
  if (f>h)swap(f,h);
  if (f>g)swap(f,g);

  if (h>d) h--;						//decrease some values of the secondary positions, if these are already taken
  if (h>c) h--;
  if (g>d) g--;
  if (h>b) h--;
  if (f>d) f--;
  if (g>c) g--;
  if (h>a) h--;
  if (e>d) e--;
  if (f>c) f--;
  if (g>b) g--;
  if (e>c) e--;
  if (f>b) f--;
  if (g>a) g--;
  if (e>b) e--;
  if (f>a) f--;
  if (e>a) e--;

  h-=g;							//decrease every value so that the magic formula can be applied
  d-=c;
  g-=f;
  c-=b;
  f-=e;
  b-=a;

  h--;
  g--;
  f--;
  d--;
  c--;
  b--;

//  return 4842-(1615*(a*a*a*a-90*a*a*a+a*a*(3035-12*b)-6*a*(7575-88*b+2*b*b-4*c)-4*(-66*b*b+b*b*b+b*(1451-6*c)+129*c-3*c*c+6*d)))/8- 
//     ((e-17)*(1094*e-57*e*e+e*e*e-7104))/24+((1+f)*(1032+3*e*e+3*e*(f-37)-55*f+f*f))/6-((1+g)*(2*e+2*f+g-36))/2+h;
  return (b*(28120380+b*(19380*b-1279080)-116280*c)+a*(220205250+b*(58140*b-2558160)+a*((436050-4845*a)*a+58140*b-14704575)-116280*c)+
   (2500020-58140*c)*c+116280*d+f*(3884+f*(4*f-216)-24*g)+e*(25234+f*(12*f-432)+e*((74-e)*e+12*f-2051)-24*g)+(420-12*g)*g+24*h)/24;
// This is the Horner-Form of the commented Formula, hopefully faster to calculate
}

uchar max(uchar* i){
  uint address[8]={posedges(*i,*(i+1),*(i+2),*(i+3),*(i+4),*(i+5),*(i+6)),	//calc all the addresses
    poscorners(*(i+7),*(i+8),*(i+9),*(i+10),*(i+11),*(i+12)),
    poscorners(cornerturn[*(i+13)][2],cornerturn[*(i+14)][2],cornerturn[*(i+15)][2],cornerturn[*(i+16)][2],
      cornerturn[*(i+17)][2],cornerturn[*(i+18)][2]),
    poscorners(cornerturn[*(i+19)][1],cornerturn[*(i+20)][1],cornerturn[*(i+21)][1],cornerturn[*(i+22)][1],
      cornerturn[*(i+23)][1],cornerturn[*(i+24)][1]),
    poscorners(cornerturn[*(i+25)][0],cornerturn[*(i+26)][0],cornerturn[*(i+27)][0],cornerturn[*(i+28)][0],
      cornerturn[*(i+29)][0],cornerturn[*(i+30)][0]),
    poscenters(*(i+31),*(i+32),*(i+33),*(i+34),*(i+39),*(i+40),*(i+41),*(i+42)),
    poscenters(centerturn[*(i+35)][3],centerturn[*(i+36)][3],centerturn[*(i+37)][3],centerturn[*(i+38)][3],
      centerturn[*(i+43)][3],centerturn[*(i+44)][3],centerturn[*(i+45)][3],centerturn[*(i+46)][3]),
    poscenters(centerturn[*(i+47)][0],centerturn[*(i+48)][0],centerturn[*(i+49)][0],centerturn[*(i+50)][0],
      centerturn[*(i+51)][0],centerturn[*(i+52)][0],centerturn[*(i+53)][0],centerturn[*(i+54)][0])};
//    cout << address[6]+0 << "\n";
	//The cubeturns are beeing made to map the different final places of the pieces to the table-pieces.
  uchar values[8]={readhalfbyte(*(edges+address[0]/2),address[0]&1),	//lookup the associated depth values
    readhalfbyte(*(corners+address[1]/2),address[1]&1),
    readhalfbyte(*(corners+address[2]/2),address[2]&1),
    readhalfbyte(*(corners+address[3]/2),address[3]&1), 
    readhalfbyte(*(corners+address[4]/2),address[4]&1),
    readhalfbyte(*(centers+address[5]/2),address[5]&1),
    readhalfbyte(*(centers+address[6]/2),address[6]&1),
    readhalfbyte(*(centers+address[7]/2),address[7]&1)};
  uchar tmp=values[0];
  for(uchar i=1;i<8;i++) if(tmp<values[i])tmp=values[i];		//select the maximum
  return tmp;									//and return it
}
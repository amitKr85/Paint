#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
void openfile(fstream &f);
 struct palettetype pal;
 int slidR,slidG,slidB ;
  struct colour
    {   int R,G,B;
    };
    class pallet
    {    colour C[16];

      public:
	 pallet()
	 {
	     C[0].R=0;    C[0].G=0;    C[0].B=0;
	     C[1].R=0;    C[1].G=0;    C[1].B=42;
	     C[2].R=0;    C[2].G=42;   C[2].B=0;
	     C[3].R=0;    C[3].G=42;   C[3].B=42;
	     C[4].R=42;   C[4].G=0;    C[4].B=0;
	     C[5].R=42;   C[5].G=0;    C[5].B=42;
	     C[6].R=42;   C[6].G=21;   C[6].B=0;
	     C[7].R=42;   C[7].G=42;   C[7].B=42;
	     C[8].R=21;   C[8].G=21;   C[8].B=21;
	     C[9].R=21;   C[9].G=21;   C[9].B=58;
	     C[10].R=22;  C[10].G=59;  C[10].B=22;
	     C[11].R=22;  C[11].G=60;  C[11].B=60;
	     C[12].R=60;  C[12].G=21;  C[12].B=21;
	     C[13].R=60;  C[13].G=21;  C[13].B=60;
	     C[14].R=60;  C[14].G=60;  C[14].B=22;
	     C[15].R=60;  C[15].G=60;  C[15].B=60;

	 }
	 pallet(pallet &p)
	 {
	     for(int i=0;i<16;++i)
	     {
		C[i].R=p.C[i].R;
		C[i].G=p.C[i].G;
		C[i].B=p.C[i].B;
	     }
	 }
	 void getRGB(int i,int &r,int &g,int &b)
	 {      r=C[i].R;
		g=C[i].G;
		b=C[i].B;
	 }
	 void setRGB(int i,int r,int g,int b)
	 {      C[i].R=r;
		C[i].G=g;
		C[i].B=b;
	 }
    }Pallet,CrntPallet;

void main()
{      	getpalette(&pal);

       int gdriver = DETECT, gmode;
       initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
       fstream fl;
	   fl.open("sample2.jpg",ios::in|ios::binary);  //opening file///
	   if(!fl)     //if error//
	   {   gotoxy(18,7);
	       cout<<"                                       ";
	       gotoxy(18,7);
	       cout<<"file can't open or doesn't exist !!";
	       delay(1000);
	       gotoxy(18,7);
	       cout<<"                                     ";

	       return;
	   }
	   openfile(fl);
	   fl.close();
       getch();
}
void openfile(fstream &f)
{
       int i=0,j=116;    ////starting point of canvas///
       int c;    /////color value////
       int l,b;   ////dimension of image///

       ///reading crnt  RGB values
	      f.read((char *)&CrntPallet,sizeof(CrntPallet));
       for(int z=0;z<16;++z)                                           /// setting RGB values
       {    CrntPallet.getRGB(z,slidR,slidG,slidB);
	    setrgbpalette(pal.colors[z],slidR,slidG,slidB);
       }

       f.read((char *)&l,sizeof(l));  ///gettting lenth//
       f.read((char *)&b,sizeof(b));  ///getting breadth//
					     ///////////////////
       while(j<=b)
       {
	     f.read((char *)&c,sizeof(c));
	     putpixel(i,j,c);
	     ++i;
	     if(i>l)
	     {    i=0;
		  ++j;
	     }
       }
}

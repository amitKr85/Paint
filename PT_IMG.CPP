/*#include<fstream.h>
#include<conio.h>
#include<graphics.h>
*/
void Print(char filename[],int x1,int y1,int l2,int b2,int x,int y)
{
    palettetype pal;
    getpalette(&pal);
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
    }CrntPallet;
    fstream f;
    f.open(filename,ios::in|ios::binary);  //opening file///
	   if(!f)     //if error//
	   {   cout<<"file can't open or doesn't exist !!";
	       return;
	   }
       int c;    /////color value////
       int l,b;   ////dimension of image///

       ///reading crnt  RGB values
       f.read((char *)&CrntPallet,sizeof(CrntPallet));
       int slidR,slidG,slidB;
       for(int z=0;z<16;++z)                                           /// setting RGB values
       {    CrntPallet.getRGB(z,slidR,slidG,slidB);
	    setrgbpalette(pal.colors[z],slidR,slidG,slidB);
       }

       f.read((char *)&l,sizeof(l));  ///gettting lenth//
       f.read((char *)&b,sizeof(b));  ///getting breadth//
       b=b-116;
       int i=0,j=0;
       int xP=x,yP=y;					     ///////////////////
       while(j<=b)
       {
	     f.read((char *)&c,sizeof(c));
	     if((i>=x1) && (i<=x1+l2) && (j>=y1) && (j<=y1+b2))
	     {	   putpixel(x,y,c);
		   ++x;
		   if(x>xP+l2)
		   {  x=0;
		      ++y;
		   }
	     }
	     ++i;
	     if(i>l)
	     {    i=0;
		  ++j;
	     }
       }
    f.close();
}
/*void main()
{
       int gdriver = DETECT, gmode;
       initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  //     Print("algoexp.jpg",0,0,0,479-116,0,0);
	 Print("algoexp.jpg",60,330-116,180,100,0,0);      //rec
   //	 Print("algoexp.jpg",480,180-116,120,120,0,0);      //cir
   //	 Print("algoexp.jpg",200,180-116,200,125,0,0);      //cur

     /*  ////rectangle///
	60,330||240,430; l=180,b=100
	////circle////
	480,180||600,300; l=120,b=120
	///curve///
	200,180||400,305; l=200,b=125
    */
 /*      putpixel(80,50,0);
       getch();
}  */
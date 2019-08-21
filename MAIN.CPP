

/////////////////////GUIDED BY SAMEER SIR///////////////////////////
////////////////////////CREATED BY AMIT////////////////////////////

#include "dos.h"
#include "graphics.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "fstream.h"

////////// variable initialised globaly so that all funtion can use them/////////

    union REGS i,o;          //////for mouse///////
    int tabi,style=1,pcolor,color,tm,thick,brush=1,shape;
    int aa,bb,aa2,bb2,sx,sy,ex,ey,tool=2,defcolor=15,selected,slidR,slidG,slidB;
    int defbk=15,defstyle=1,txtfont=1,txtsize=1,vert=0,len=10,paste=0;
    int maxx,maxy,x,y,button,prevx,prevy;
    struct palettetype pal;
    void far *mem=NULL;
    char cx[5],txt[50],str[5],cy[5],clen[5],filename[15]="";

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
    static char patterns[][8] = {
    { 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55 },
    { 0x33, 0x33, 0xCC, 0xCC, 0x33, 0x33, 0xCC, 0xCC },
    { 0xF0, 0xF0, 0xF0, 0xF0, 0x0F, 0x0F, 0x0F, 0x0F },
    { 0x00, 0x10, 0x28, 0x44, 0x28, 0x10, 0x00, 0x00 },
    { 0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00 },
    { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00 },
    { 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00 },
    { 0x00, 0x00, 0x22, 0x08, 0x00, 0x22, 0x1C, 0x00 },
    { 0xFF, 0x7E, 0x3C, 0x18, 0x18, 0x3C, 0x7E, 0xFF },
    { 0x00, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00 },
    { 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00 },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00 },
    { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f }
    };                                        ///user defined fill style patterns
	  ///  including files  having user defined funtions   ////
#include "pt_strtn.cpp"
#include "pt_mouse.cpp"
#include "pt_file.cpp"
#include "pt_home.cpp"
#include "pt_text.cpp"
#include "pt_fill.cpp"
#include "pt_color.cpp"
#include "pt_dwork.cpp"
void main()
{  	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	getpalette(&pal);
	maxx=getmaxx();                    ///maximum X
	maxy=getmaxy();                    ///maximum Y
	starting();
	setcolor(BLUE);
	rectangle(0,0,maxx,maxy);
	setviewport(1,1,maxx-1,maxy-1,1);    ///settting view port//

	///restricting mouse poiter from getting out to th given coordinates
	restrictmouseptr (1,1,maxx-1,maxy-1);
	firstbkgrnd();                       ///making background
	randomize();
	homebkgrnd();                        ///making bakground of home tab
	if(initmouse() ==0)                  ////initialising mouse
	{
		closegraph();
		restorecrtmode();
		printf("Mouse driver not loaded");
		exit (1);
	}

	showmouseptr();                    ///showing pointer

	char ch;
	while (ch!='=')
	{       if(kbhit())
		 ch=getch();
		getmousepos (&button, &x, &y);  ///getting mouse position
		if((button &1)==1)              ///if mouse is left clicked
		{      ////cheking whether mouse is clicked on canvas or tools
			check();
			coord();             ////showing mouse coordinates

		}
		restrictmouseptr (1,1,maxx-1,maxy-1);

	}
      delete mem;                            ////deleting pointer '*mem'
      closegraph();
}


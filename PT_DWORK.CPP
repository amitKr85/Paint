void dowork();
void check()
{
    if(y<115)
    {
	 hidemouseptr();      ///hiding mouse pointer for overcome overlapping

    /*	 if(y<10)
	 {   if(x>620&&x<635)
	       exit(0);
	 }
    */	 if(y>10&&y<30)
	 {    if(x>0&&x<30)       ///if clicked on file tab
		 if(tabi!=4)
		     filebkgrnd();      ///creating file background
	      if(x>30&&x<60)            ///if clicked on home tab
		  if(tabi!=1)
		     homebkgrnd();      //creating home background
	      if(x>60&&x<90)            ///if clicked on text tab
		  if(tabi!=2)
		     textbkgrnd();       ///creating text bkground
	      if(x>90&&x<120)            //if clicked on fill tab
		  if(tabi!=3)
		     fillbkgrnd();       ///creating fill bkground
	      if(x>120&&x<212)           //if clicked on colr chngr tab
		  if(tabi!=5)
		     colorbkgrnd();       //making bkground
	 }
	 if(y>30&&y<90)                    ///checking which is active tab
	 {   if(tabi==1)
	      homework();
	     if(tabi==2)
	      textwork();
	     if(tabi==3)
	      fillwork();
	     if(tabi==4)
	       filework();
	     if(tabi==5)
	       colorwork();
	 }
       showmouseptr();
    }
    else if(y>115)
      dowork();                 ///if clicked or dragged on canvas

}
void coord()
{  itoa(x,cx,10);
   itoa(y,cy,10);
   setcolor(0);
   settextstyle(1,HORIZ_DIR,1);
   outtextxy(10,90,"лллл");
   outtextxy(60,90,"лллл");
   setcolor(15);
   outtextxy(10,90,cx);
   outtextxy(55,90,",");
   outtextxy(60,90,cy);
}


void dowork()
{   	hidemouseptr();
	int i;
	if(paste)              //paste
	{  if(mem!=NULL)
	    putimage(x,y,mem,COPY_PUT);
	}
	else
	if(tool)
	{     if(tool==1)       //spray
	      {
		 while((button &1)==1&&y-len>115)
		 {
		       putpixel(x-len+random(2*len),y-len+random(2*len),defcolor);
		       getmousepos(&button,&x,&y);
		       for(i=0;i<10000;++i);

		 }
	      }
	      if(tool==2)           //pencil
	      {      if(brush==1)
		     {  if(len>10)  thick=3;
			else        thick=1;
			prevx=x;
			prevy=y;
			while ((button &1)==1&&y-len>115)
			{      	setcolor(defcolor);
				setlinestyle(0,1,thick);
			       line (prevx,prevy,x,y);
				prevx=x;
				prevy=y;
				getmousepos(&button,&x,&y);
				coord();
			}
		     }
		     if(brush==2)
		    {	while ((button &1)==1&&y-len>115)
			{       if(style==1)
				 setfillstyle(defstyle,defcolor);
				if(style==2)
				 setfillpattern(&patterns[defstyle][0],defcolor);

				setcolor(defcolor);
				fillellipse(x,y,len,len);
				getmousepos(&button,&x,&y);
				coord();
			}
		     }
		     if(brush==3)
		     {	while ((button &1)==1&&y-len>115)
			{       if(style==1)
				 setfillstyle(defstyle,defcolor);
				if(style==2)
				 setfillpattern(&patterns[defstyle][0],defcolor);

				bar(x-len,y-len,x+len,y+len);
				getmousepos(&button,&x,&y);
				coord();
			}
		     }

	     }
	     if(tool==3)      ///fill
	     {     pcolor=getpixel(x,y-5);
		   int i=6;
		   do
		   {   color=getpixel(x,y-i);
		       ++i;
		   }while(pcolor==color);
		   if(style==1)
		   setfillstyle(defstyle,defcolor);
		   if(style==2)
		   setfillpattern(&patterns[defstyle][0],defcolor);
		   floodfill(x,y-5,color);
	     }
	     if(tool==4)       //text
	     {     gotoxy(18,7);
		   cout<<"                                  ";
		   gotoxy(18,7);
		   cout<<"Enter your Text Here :";
		   gets(txt);
		   gotoxy(18,7);
		   cout<<"                                                 ";

		   setcolor(defcolor);
		   settextstyle(txtfont,vert,txtsize);
		   outtextxy(x,y,txt);
	     }
	     if(tool==5||tool==7)    ///if invert or select
	     {     prevx=aa=x;         ///////////copy frm hre///////////////////////////
		   prevy=bb=y;   /////NOTE:  place restrictmouseptr()  at end of while in main()
		   delete mem;  //////       int sx,sy,ex,ey;
		   mem=NULL;
		   while(((button &1)==1)&&(y>115))
		   {   if(prevx!=x||prevy!=y)
		       { if(mem!=NULL)
			 { sx=aa<prevx?aa:prevx;       //getting top x,y
			   sy=bb<prevy?bb:prevy;
			   putimage(sx-1, sy-1, mem, 0);
			 }
			 delete mem;
			 aa<x?(sx=aa,ex=x):(sx=x,ex=aa);    //getting top & bottom x,y
			 bb<y?(sy=bb,ey=y):(sy=y,ey=bb);
			 mem=malloc(imagesize(sx-1, sy-1, ex+1, ey+1 ));
			 getimage(sx-1, sy-1, ex+1, ey+1, mem);
			 setcolor(0);
			 setlinestyle(2,1,1);
			 rectangle(aa,bb,x,y);
		       }
		     prevx=x;  prevy=y;
		     getmousepos(&button,&x,&y);
		     coord();
	      /*	     gotoxy(18,7);
		     cout<<"                  ";
		     gotoxy(18,7);
		     cout<<imagesize(aa,bb,x,y);
	      */   if(imagesize(aa,bb,x,y)>25000) //50000
		     {
			restrictmouseptr (aa,bb,x,y);
		     }
		     else
		       restrictmouseptr (1,1,maxx-2,maxy-2);


		   }
		   if(mem!=NULL)
		   { sx=aa<prevx?aa:prevx;
		     sy=bb<prevy?bb:prevy;
		     putimage(sx-1, sy-1, mem, 0);
		   }

		   aa2=x;
		   bb2=y;
		   if(tool==7)
		   {
		     gotoxy(18,7);
		     cout<<"selected !";
		     delay(1000);
		     gotoxy(18,7);
		     cout<<"            ";
		   }
		   if(tool==5)              ///inverting the image
		   {  putimage(aa>aa2?aa2:aa, bb>bb2?bb2:bb, mem, NOT_PUT);
		      delete mem;
		      mem=NULL;
		   }
		    ///////////to here///////////////////////////

	     }
	     if(tool==6)          //eraser
	     {   //  showmouseptr();

		       prevx=x;
		       prevy=y;
		       while ((button &1)==1&&y-len>115)
			{       setfillstyle(1,defbk);
				setcolor(defbk);
				bar(prevx-len,prevy-len,prevx+len,prevy+len);
				setcolor(1);
				setlinestyle(0,0,0);
				rectangle(x-len,y-len,x+len,y+len);

				prevx=x;
				prevy=y;
				getmousepos(&button,&x,&y);
				coord();
			}
			if(prevy-len>115)
			{
			  setfillstyle(1,defbk);
			  setcolor(defbk);
			  bar(prevx-len,prevy-len,prevx+len,prevy+len);
			}

	     }
	     if(tool==8)              //pick
	     {     defcolor=getpixel(x,y);
		   setfillstyle(1,defcolor);
		   bar(456,41,474,84);
	     }
	}
	else
	if(shape)            ///working of shapes//
	{       if(len>10)  thick=3;
		else        thick=1;

		setlinestyle(0,0,thick);
		if(shape<=3||shape>=7)
		{
		   prevx=aa=x;
		   prevy=bb=y;
		   delete mem;
		   mem=NULL;

		   while(((button &1)==1)&&(y>115))
		   { if(prevx!=x||prevy!=y)
		     {  if(mem!=NULL)
			{ sx=aa<prevx?aa:prevx;
			  sy=bb<prevy?bb:prevy;
			  putimage(sx-1, sy-1, mem, 0);
			}
			delete mem;
			aa<x?(sx=aa,ex=x):(sx=x,ex=aa);      ///getting top & bottom x,y
			bb<y?(sy=bb,ey=y):(sy=y,ey=bb);
			mem=malloc(imagesize(sx-1, sy-1, ex+1, ey+1 ));
			getimage(sx-1, sy-1, ex+1, ey+1, mem);

			setcolor(defcolor);
			if(shape==1)
			  line(aa,bb,x,y);
			else if(shape==3)
			   rectangle(aa,bb,x,y);
			else if(shape==2)
			{      /////x center               y center                 radius
			   circle((sx+(ex-sx)/2), (sy+(ey-sy)/2), ((ex-sx)<(ey-sy)?(ex-sx):(ey-sy))/2);
			}
			 if(shape==7)
			 {        //// x center     y center       0         x radius    y radius
			   ellipse((sx+(ex-sx)/2), (sy+(ey-sy)/2), 0, 360, (ex-sx)/2, (ey-sy)/2 );
			 }
			 if(shape==8)
			 {    ////star ////
			       line( sx+(ex-sx)/2, sy+(ey-sy)/2, sx+(ex-sx)/2, sy );
			       line( sx+(ex-sx)/2, sy+(ey-sy)/2, sx, sy+(ey-sy)/3 );
			       line( sx+(ex-sx)/2, sy+(ey-sy)/2, ex, sy+(ey-sy)/3 );
			       line( sx+(ex-sx)/2, sy+(ey-sy)/2, sx, ey );
			       line( sx+(ex-sx)/2, sy+(ey-sy)/2, ex, ey );

			 }
		     }
		     prevx=x;  prevy=y;
		     getmousepos(&button,&x,&y);
		     coord();
		     if(imagesize(aa,bb,x,y)>50000) //50000
		     {
			restrictmouseptr (aa,bb,x,y);
		     }
		     else
		       restrictmouseptr (1,1,maxx-2,maxy-2);


		   }
		   delete mem;
		   mem=NULL;


		}
		if(shape==4)
		{   int i=2;
		     prevx=x;prevy=y;
		    while(((button &1)==1)&&(y>120))
		    {
			setcolor(defcolor);
			if(i%2==0)
			{  line(prevx,prevy,x,y-5);
			   prevx=x;prevy=y-5;
			}
			else
			{  line(prevx,prevy,x,y+5);
			   prevx=x;
			   prevy=y+5;
			 }
			 ++i;
			 getmousepos(&button,&x,&y);
			 coord();

		    }
		}
		if(shape==5)
		{     prevx=x;prevy=y;
		      while(((button &1)==1)&&(y>120))
		      {     setcolor(defcolor);
			     line(x,y,prevx,prevy);
			     coord();
			     getmousepos(&button,&x,&y);

		      }
		}
		if(shape==6)
		{
		     if(tm==1)
		     { sx=prevx=x;
		       sy=prevy=y;
		       ++tm;            ///i ' here
		     }
		     else if(x>sx-2&&x<sx+2 && y>sy-2&&y<sy+2)
			tm=1;

		     setcolor(defcolor);
		     line(prevx,prevy,x,y);
		     prevx=x;
		     prevy=y;
		     delay(200);
		}


	}
	showmouseptr();
}

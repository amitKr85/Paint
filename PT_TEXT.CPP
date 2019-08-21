void textbkgrnd()
{     setlinestyle(0,1,1);
      if(tabi!=2)
      {   setfillstyle(1,15);
	  bar(0,31,maxx,89);
      }
       tabi=2;
       setcolor(BLUE);
       line(0,30,maxx,30);
       setcolor(15);
       line(61,30,89,30);

	 ////
       setcolor(1);
       settextstyle(1,0,4);
       outtextxy(10,35,"A");
       settextstyle(2,0,10);
       outtextxy(45,30,"A");
       settextstyle(3,0,4);
       outtextxy(78,34,"A");
       settextstyle(4,0,4);
       outtextxy(110,34,"A");
       settextstyle(5,0,4);
       outtextxy(148,29,"A");
       settextstyle(6,0,4);
       outtextxy(183,31,"A");
       settextstyle(7,0,4);
       outtextxy(215,35,"A");
       settextstyle(8,0,4);
       outtextxy(248,31,"A");
       settextstyle(10,0,1);
       outtextxy(280,31,"A");

       setfillstyle(1,15);
       bar(590,40,630,85);
       rectangle(590,40,630,85);
       settextstyle(1,0,1);
       if(vert)
       outtextxy(605,45,"V");
       else
       outtextxy(605,45,"H");
       line(610,75,610,80);
       line(610,80,607,77);
       line(610,80,613,77);
	/////////size///
       bar(530,40,580,85);
       rectangle(530,40,580,85);
       line(530,53,530,53);
       line(533,68,538,68);
       line(533,68,536,65);
       line(533,68,536,71);//----///
       line(572,68,577,68);
       line(577,68,574,65);
       line(577,68,574,71);
       settextstyle(2,0,4);
       outtextxy(545,42,"SIZE");
       settextstyle(1,0,1);
       itoa(txtsize,str,10);
       outtextxy(550,55,str);

       ///show selected////
       setfillstyle(1,2);
       setcolor(2);
       bar((txtfont-1)*35,70,(txtfont*35)-1,72);
}
void textwork()
{      if(y>35&&y<70)
       {   if(x>0&&x<305)
	   {   setfillstyle(1,15);
	       setcolor(15);
	       bar(0,70,305,72);
	       setfillstyle(1,2);
	       setcolor(2);
	       if(x>0&&x<35)
	       {   txtfont=1;
		   bar(0,70,34,72);
	       }
	       else if(x>=35&&x<70)
	       {   txtfont=2;
		   bar(35,70,69,72);
	       }
	       else if(x>=70&&x<105)
	       {   txtfont=3;
		   bar(70,70,104,72);
	       }
	       else if(x>105&&x<140)
	       {   txtfont=4;
		   bar(105,70,139,72);
	       }
	       else if(x>=140&&x<175)
	       {   txtfont=5;
		   bar(140,70,174,72) ;
	       }
	       else if(x>=175&&x<210)
	       {   txtfont=6;
		   bar(175,70,209,72)  ;
	       }
	       else if(x>210&&x<240)
	       {   txtfont=7;
		   bar(210,70,239,72)   ;
	       }
	       else if(x>=240&&x<275)
	       {   txtfont=8;
		   bar(240,70,274,72);
	       }
	       else if(x>=275&&x<305)
	       {   txtfont=10;
		   bar(275,70,305,72) ;
	       }

	   }
       }
       if(y>40&&y<85)
       {  if(x>530&&x<540)
	  {   setfillstyle(1,15);
	      setcolor(15);
	      bar(545,55,570,80);
	      if(txtsize>1)
	       --txtsize;
	      setcolor(1);
	      itoa(txtsize,str,10);
	      outtextxy(550,55,str);

	  }
	  if(x>570&&x<580)
	  {   setcolor(15);
	      setfillstyle(1,15);
	      setcolor(15);
	      bar(545,55,570,80);
	      if(txtsize<10)
	      ++txtsize;
	      setcolor(1);
	      itoa(txtsize,str,10);
	      outtextxy(550,55,str);

	  }
	  if(x>590&&x<630)
	    if(y>75)
	    {    if(vert)
		    vert=0;
		 else
		    vert=1;
		 setfillstyle(1,15);
		 bar(595,45,625,70);
		 settextstyle(1,0,1);
		 setcolor(1);
		 if(vert)
		   outtextxy(605,45,"V");
		 else
		   outtextxy(605,45,"H");
	    }

	   delay(100);
       }
}

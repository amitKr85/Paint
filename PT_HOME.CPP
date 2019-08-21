void homebkgrnd()
{      setlinestyle(0,1,1);
       if(tabi!=1)
       {   setfillstyle(1,15);
	   bar(0,31,maxx,89);
       }
       tabi=1;
       setcolor(BLUE);
       line(0,30,maxx,30);
       setcolor(15);
       line(31,30,59,30);

       /////////size///
       setcolor(1);
       /////cut paste////
       rectangle(5,65,35,85);
       line(7,71,33,71);
       line(7,76,33,76);
       line(7,81,33,81);
       //
       rectangle(5,40,15,55);
       setfillstyle(1,15);
       bar(10,45,20,60);
       rectangle(10,45,20,60);
       line(12,47,18,47);
       line(12,50,18,50);
       line(12,54,18,54);
       line(12,58,18,58);
       /////
       line(25,40,34,54);
       line(25,40,33,54);
       line(34,40,25,54);
       line(34,40,26,54);
       circle(33,57,3);
       circle(26,57,3);

       /////
       rectangle(400,40,450,85);
       line(400,53,450,53);
       line(403,68,408,68);
       line(403,68,406,65);
       line(403,68,406,71);//----///
       line(442,68,447,68);
       line(447,68,444,65);
       line(447,68,444,71);
       settextstyle(2,0,4);
       outtextxy(415,42,"SIZE");
       settextstyle(1,0,1);
       itoa(len,str,10);
       outtextxy(415,55,str);
       ////color////
       for(int i=40,k=0;i<=70;i+=25)
       for(int j=620;j>=480;j-=20,++k)
       {    setfillstyle(1,k);
	    bar(j,i,j+15,i+20);
	    setcolor(1);
	    rectangle(j,i,j+15,i+20);
       }
       setfillstyle(1,defcolor);
       rectangle(455,40,475,85);
       bar(456,41,474,84);
       ///////
       setfillstyle(1,15);
       bar(40,40,160,85);
       rectangle(40,40,160,85);
       bar(170,40,200,85);
       rectangle(170,40,200,85);
       bar(210,40,330,85);
       rectangle(210,40,330,85);
       ////////tools////////////

       setfillstyle(1,BLUE);
       setcolor(1);
       settextstyle(2,0,2);
       outtextxy(82,32,"T O O L S");
       outtextxy(172,32,"BRUSHES");
       outtextxy(250,32,"S H A P E S");
       ////spray//
       bar(46,47,49,58);
       line(48,45,48,52);
       for(i=0;i<20;++i)
       putpixel(random(10)+50,random(5)+45,BLUE);
       ///pen//////
       line(85,45,75,55);
       line(86,45,76,55);
       line(84,45,74,55);
       arc(76,56,180,360,2);
       arc(81,56,0,180,3);
       //////fill/////
       setfillstyle(1,RED);
       fillellipse(105,57,2,2);
       setfillstyle(1,BLUE);
       fillellipse(109,50,2,2);
       setfillstyle(1,GREEN);
       fillellipse(113,57,2,2);
       //////text/////
       settextstyle(1,0,1);
       outtextxy(135,41,"S");
       //////invert//
       setcolor(0);
       rectangle(45,65,60,80);
       setfillstyle(1,0);
       bar(53,65,60,80);
       ////rubber//////
       setfillstyle(1,BLUE);
       bar3d(75,75,85,80,7,1);
       ///select///
       setcolor(BLUE);
       setlinestyle(1,1,1);
       rectangle(103,70,115,80);
       setlinestyle(0,1,1);
       ///pick/////
       fillellipse(143,71,2,2);
       line(138,69,145,76);
       line(139,69,146,76);
       line(143,71,136,78);
       line(142,71,135,78);
       /////brush////
       line(180,50,190,50);

       ////cir///
       fillellipse(185,63,4,4);
       ///bar////
       bar(175,73,195,79);
       ////shapes////
       line(230,45,220,52);
       line(231,45,221,52);
       /////circle////
       circle(250,50,5);
       ////rec6t/////
       rectangle(270,45,295,55);
       ////dezzz/////
       line(302,55,305,45);
       line(305,45,310,55);
       line(310,55,315,45);
       line(315,45,318,55);
       line(318,55,323,45);
       /////dezzz/////
       line(215,70,235,70);
       line(225,70,225,73);
       line(217,67,232,73);
       line(215,73,232,67);
       //////dezzzzz//
       line(253,67,247,73);
       line(247,73,255,73);
       line(255,73,261,67);
       line(253,67,261,67);
       ////ellipse////
       ellipse(283,70,0,360,7,4);
       ////star////
    //   rectangle(305,65,320,73);
       line(305,73,312,65);
       line(312,65,320,73);
       line(320,73,305,68);
       line(305,68,320,68);
       line(320,68,305,73);
    //show selected////
       //brush selection////
       setcolor(2);
       setfillstyle(1,2);
       if(brush==1)
	 bar(171,55,199,56);
       if(brush==2)
	 bar(171,70,199,71);
       if(brush==3)
	 bar(171,83,199,84);
       ///tool selection//
       if(tool==1)
	 bar(41,60,64,61);
       else if(tool==2)
	 bar(65,60,94,61);
       else if(tool==3)
	 bar(95,60,124,61);
       else if(tool==4)
	 bar(125,60,159,61);
       else if(tool==5)
	 bar(41,83,64,84);
       else if(tool==6)
	 bar(65,83,94,84);
       else if(tool==7)
	 bar(95,83,124,84);
       else if(tool==8)
	 bar(125,83,159,84);
       ///shapes selection//
       if(shape==1)
	 bar(211,58,239,59);
       else if(shape==2)
	 bar(240,58,264,59);
       else if(shape==3)
	 bar(265,58,299,59);
       else if(shape==4)
	 bar(300,58,329,59);
       else if(shape==5)
	 bar(211,75,239,76);
       else if(shape==6)
	 bar(241,75,264,76);
       else if(shape==7)
	 bar(268,75,295,76);
       else if(shape==8)
	 bar(302,75,325,76);

}
void homework()
{
     if(y>40&&y<85)
     {  if(y>40&&y<57)
	{  if(x>25&&x<35)
	  {   setfillstyle(1,defbk);
	      bar(aa,bb,aa2,bb2);
	  }
	}
	if((y>65&&y<getmaxy())&&(x>5&&x<35))
	{
	      paste=1;
	}
	else
	   paste=0;
	if(x>40&&x<160)
	{   setcolor(15);
	    setfillstyle(1,15);
	    bar(41,60,159,61);
	    bar(41,83,159,84);
	    bar(211,58,329,59);
	    bar(211,75,329,76);
	    shape=0;
	    tool=1;
	    setcolor(2);
	    setfillstyle(1,2);
	    if(y>40&&y<60)
	    {    if(x>40&&x<65)
		 {   tool=1  ;
		     bar(41,60,64,61);
		 }
		 if(x>=65&&x<95)
		 {   tool=2;
		     bar(65,60,94,61);
		 }
		 if(x>=95&&x<125)
		 {   tool=3;
		     bar(95,60,124,61);
		 }
		 if(x>=125&&x<160)
		 {   tool=4;
		     bar(125,60,159,61);
		 }
	    }
	    if(y>=60&&y<85)
	    {   if(x>40&&x<65)
		 {   tool=5  ;
		     bar(41,83,64,84);
		 }
		 if(x>=65&&x<95)
		 {   tool=6;
		     bar(65,83,94,84);
		 }
		 if(x>=95&&x<125)
		 {   tool=7;
		     bar(95,83,124,84);
		 }
		 if(x>=125&&x<160)
		 {   tool=8;
		     bar(125,83,159,84);
		 }
	    }

	}
	if(x>170&&x<200)
	{   setcolor(15);
	    setfillstyle(1,15);
	    bar(171,55,199,56);
	    bar(171,70,199,71);
	    bar(171,83,199,84);
	    setcolor(2);
	    setfillstyle(1,2);
	    if(y>40&&y<55)
	    {   brush=1;
		bar(171,55,199,56);
	    }
	    if(y>=55&&y<70)
	    {  brush=2;
	       bar(171,70,199,71);
	    }
	    if(y>=70&&y<85)
	    {  brush=3;
	       bar(171,83,199,84);
	    }
	}
	if(x>210&&x<330)
	{
	    setcolor(15);
	    setfillstyle(1,15);
	    bar(41,60,159,61);
	    bar(41,83,159,84);
	    bar(211,58,329,59);
	    bar(211,75,329,76);
	    setcolor(2);
	    setfillstyle(1,2);
	     tool=0;
	     shape=1;
	     if(y>40&&y<55)
	     {    if(x>210&&x<240)
		  { shape=1;
		    bar(211,58,239,59);
		  }
		  if(x>=240&&x<265)
		  { shape=2;
		    bar(240,58,264,59);
		  }
		  if(x>=265&&x<300)
		  { shape=3;
		    bar(265,58,299,59);
		  }
		  if(x>=300&&x<330)
		  { shape=4;
		    bar(300,58,329,59);
		  }
	     }
	     if(y>=60&&y<75)
	     {    if(x>210&&x<240)
		  { shape=5;
		    bar(211,75,239,76);
		  }
		  if(x>=240&&x<265)
		  {   shape=6;tm=1;
		     bar(241,75,264,76);
		  }
		  if(x>=265&&x<300)
		  { shape=7;
		     bar(268,75,295,76);
		  }
		  if(x>=300&&x<330)
		  { shape=8;
		    bar(302,75,325,76);
		  }
	     }

	}
	//////////
	if((x>400&&x<410)||(x>440&&x<450))
	{     prevx=len;
	      if(x>400&&x<410)
	      {  if(len>5)
		  len-=5;

	      }
	      if(x>440&&x<450)
	      {
		 if(len<=25)
		  len+=5;

	      }
	      setcolor(15);
	      itoa(prevx,clen,10);
	      settextstyle(1,0,1);
	      outtextxy(415,55,clen);
	      itoa(len,clen,10);
	      setcolor(1);
	      settextstyle(1,0,1);
	      outtextxy(415,55,clen);
	      delay(200);
	}
	if(x>480&&x<635)
	{

	     for(int i=40,k=0;i<=70;i+=25)
	       for(int j=620;j>=480;j-=20,++k)
		{    if(x>j&&x<j+15&&y>i&&y<i+20)
		     {       defcolor=k;
			   setfillstyle(1,defcolor);
			   bar(456,41,474,84);
			    goto out;
		     }
	      }
	      out:
	}

    }

}

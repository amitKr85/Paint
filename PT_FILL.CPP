void fillbkgrnd()
{     setlinestyle(0,1,1);
      if(tabi!=3)
      {   setfillstyle(1,15);
	  bar(0,31,maxx,89);
      }
      int i,j;
       tabi=3;
       setcolor(BLUE);
       line(0,30,maxx,30);
       setcolor(15);
       line(91,30,119,30);
       setcolor(1);
       for(i=5,j=1;i<=255;i+=25,++j)
       {    setfillstyle(j,2);
	    bar(i,35,i+20,75);
       }
       for(i=280,j=0;j<14;++j,i+=25)
       {    setfillpattern(&patterns[j][0],2);
	    bar(i,35,i+20,75);
       }
       ///show selected//
       setfillstyle(1,1);
       setcolor(1);
       if(style==1) bar(5+(defstyle-1)*25,78,5+(defstyle)*25-5,80);
       else         bar(280+(defstyle)*25,78,280+(defstyle+1)*25-5,80);
}
void fillwork()
{    int i,j;
     if(y>35&&y<75)
     { for(i=5,j=1;i<=255;i+=25,++j)
       {    if(x>i&&x<i+20)
	    {    style=1;
		 defstyle=j;
		 setfillstyle(1,15);
		 bar(0,78,635,80);
		 setfillstyle(1,1);
		 bar(i,78,i+20,80);
	    }
       }
       for(i=280,j=0;j<14;++j,i+=25)
       {    if(x>i&&x<i+20)
	    {     style=2;
		  defstyle=j;
		  setfillstyle(1,15);
		  bar(0,78,635,80);
		  setfillstyle(1,1);
		  bar(i,78,i+20,80);
	    }
       }
     }
}

void starting()
{
     setfillstyle(1,1);
     setcolor(1);
     bar(100,100,maxx-100,maxy-100);
     settextstyle(10,0,6);
     moveto(maxx/2-140,80);

     setcolor(4);
     outtext("P");
     setfillstyle(1,4);
     floodfill(getx()-45,gety()+80,4);

     setcolor(14);
     outtext("a");
     setfillstyle(1,14);
     floodfill(getx()-15,gety()+80,14);

     setcolor(2);
     outtext("i");
     setfillstyle(1,2);
     floodfill(getx()-20,gety()+80,2);
     floodfill(getx()-20,gety()+40,2);
     setcolor(3);
     outtext("n");
     setfillstyle(1,3);
     floodfill(getx()-10,gety()+80,3);

     setcolor(10);
     outtext("t");
     setfillstyle(1,10);
     floodfill(getx()-20,gety()+80,10);

     setcolor(5);
     outtext("'");
     setfillstyle(1,5);
     floodfill(getx()-14,gety()+40,5);

     setcolor(12);
     outtext("z");
     setfillstyle(1,12);
     floodfill(getx()-35,gety()+80,12);

     settextstyle(10,0,4);
     setcolor(11);
     moveto(getx(),gety()+40);
     outtext("z");
     setfillstyle(1,11);
     floodfill(getx()-20,gety()+50,11);   ////i ' m here/////

     settextstyle(2,0,4);
     setcolor(15);
     outtextxy(getx(),gety()+60,"V5.2.1002");

     settextstyle(2,0,5);
     outtextxy(105,maxy-250,"Developer:");
     outtextxy(105,maxy-235,"Amit Kumar");
     outtextxy(105,maxy-215,"Under Guidence of:");
     outtextxy(105,maxy-200,"Sameer Sir (P.G.T Comp. Science)");

     setfillstyle(1,14);
     setcolor(14);
     bar(100,maxy-120,maxx-100,maxy-115);

     setcolor(15);
     outtextxy(105,maxy-140,"Loading Modules...");

     setfillstyle(1,4);
     setcolor(4);
     for(int i=100;i<maxx-400;++i)
     {  bar(100,maxy-120,i,maxy-115);
	delay(10);
     }
     delay(200);
     ///modules done////////
     setcolor(1);
     outtextxy(105,maxy-140,"Loading Modules...");
     setcolor(15);
     outtextxy(105,maxy-140,"Loading Tools...");

     setfillstyle(1,4);
     setcolor(4);
     for(;i<maxx-200;++i)
     {  bar(100,maxy-120,i,maxy-115);
	delay(10);
     }
     /////tools done////
     delay(200);
     setcolor(1);
     outtextxy(105,maxy-140,"Loading Tools...");
     setcolor(15);
     outtextxy(105,maxy-140,"Loading Brushes...");

     setfillstyle(1,4);
     setcolor(4);
     for(;i<maxx-99;++i)
     {  bar(100,maxy-120,i,maxy-115);
	delay(10);
     }

     setcolor(1);
     outtextxy(105,maxy-140,"Loading Brushes...");

     setcolor(15);
     outtextxy(105,maxy-140,"Starting...");

     delay(1000);
     setfillstyle(1,0);
     setcolor(0);
     bar(0,0,maxx,maxy);

}
void firstbkgrnd()
{
       setfillstyle(1,1);
       bar(0,0,maxx,10);
       setcolor(BLUE);
       setfillstyle(1,15);
       bar(0,10,maxx,40);
       setfillstyle(1,15);
       bar(0,15,212,30);
       settextstyle(2,0,4);
       line(0,15,212,15);
       line(0,30,maxx,30);
       outtextxy(5,17,"FILE");
       line(30,15,30,30);
       outtextxy(35,17,"HOME");
       line(60,15,60,30);
       outtextxy(65,17,"TEXT");
       line(90,15,90,30);
       outtextxy(95,17,"FILL");
       line(120,15,120,30);
       outtextxy(125,17,"COLOR REPLACER");
       line(212,15,212,30);
       bar(0,31,maxx,90);
       setcolor(15);
       line(0,90,maxx,90);
       line(0,114,maxx,114);
       setcolor(0);
       line(0,115,maxx,115);
       settextstyle(7,0,1);
       setcolor(1);

       setfillstyle(1,15);
       bar(110,91,120,113);
//       gotoxy(18,7);       cout<<"a";
       setfillstyle(1,defbk);
       bar(0,116,maxx,maxy);

}

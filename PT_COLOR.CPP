void colorbkgrnd()
{   /////background////
    setlinestyle(0,1,1);
    setfillstyle(1,15);
    bar(0,31,maxx,89);
    tabi=5;
    setcolor(BLUE);
    line(0,30,maxx,30);
    setcolor(15);
    line(121,30,211,30);
    ///////
    ///colors////
    for(int i=40,k=0;i<=70;i+=25)
       for(int j=10;j<=150;j+=20,++k)
       {    setfillstyle(1,k);
	    setcolor(1);
	    bar(j,i,j+15,i+20);
	    rectangle(j,i,j+15,i+20);
       }
       rectangle(180,40,200,85);
    ///////
    settextstyle(2,0,4);
    outtextxy(210,40,"RED");
    outtextxy(210,58,"GREEN");
    outtextxy(210,75,"BLUE");
    /////lines///
    line(250,50,370,50);
    line(250,68,370,68);
    line(250,85,370,85);
    ///slider////
    setfillstyle(1,1);
    bar(250,40,251,49);
    bar(250,58,251,67);
    bar(250,75,251,84);
    /////button///
    outtextxy(400,72,"Reset To Default");
    rectangle(390,70,500,85);
    outtextxy(515,72,"Ok");
    rectangle(510,70,530,85);
    outtextxy(545,72,"Cancel");
    rectangle(540,70,590,85);
    //setting values////
    selected=-1;
    slidG=slidR=slidB=0;

}
void colorwork()
{   //////choosing color/////
    for(int i=40,k=0;i<=70;i+=25)
       for(int j=10;j<=150;j+=20,++k)
       {    if(y>i&&y<i+20)
	      if(x>j&&x<j+15)
	      {
		    if(k<3||k==4||k==15)
		    {   gotoxy(18,7);
			cout<<"                                    ";
			gotoxy(18,7);
			cout<<"Basic Color Cannot be Selected !!";
			delay(1000);
			gotoxy(18,7);
			cout<<"                                    ";

			continue;
		    }
		    selected=k;
		    setfillstyle(1,k);
		    bar(181,41,199,84);
		    setfillstyle(1,15);
		    bar(250,40,372,49);
		    bar(250,58,372,67);
		    bar(250,75,372,84);
		    CrntPallet.getRGB(k,slidR,slidG,slidB);   ////
		    setfillstyle(1,1);
		    bar(250+slidR*2,40,251+slidR*2,49);
		    bar(250+slidG*2,58,251+slidG*2,67);
		    bar(250+slidB*2,75,251+slidB*2,84);
	      }
       }
       ///////working of sliders////
    if(selected>=0)
    {
       if(x>=250&&x<370)
       {
	   if(y>40&&y<=55)            ///red slider///
	   {    setfillstyle(1,15);
		bar(250,40,x,49);
		bar(x+2,40,372,49);
		setfillstyle(1,1);
		bar(x,40,x+1,49);
		slidR=(x-250)/2;
		setrgbpalette(pal.colors[selected],slidR ,slidG , slidB);

	   }
	   if(y>55&&y<=72)        ////green slider///
	   {    setfillstyle(1,15);
		bar(250,58,x,67);
		bar(x+2,58,372,67);
		setfillstyle(1,1);
		bar(x,58,x+1,67);
		slidG=(x-250)/2;
		setrgbpalette(pal.colors[selected],slidR ,slidG , slidB);

	   }
	   if(y>72&&y<=87)         ///blue slider////
	   {    setfillstyle(1,15);
		bar(250,75,x,84);
		bar(x+2,75,372,84);
		setfillstyle(1,1);
		bar(x,75,x+1,84);
		slidB=(x-250)/2;
		setrgbpalette(pal.colors[selected],slidR ,slidG , slidB);

	   }
       }
       if(x>510&&x<530&&y>70&&y<85)          //for ok button///
       {  ///setting crnt RGB of the color//
	     CrntPallet.setRGB(selected,slidR,slidG,slidB);   ////
       }
       if(x>540&&x<590&&y>70&&y<85)          //for cancel button//
       { 	 CrntPallet.getRGB(selected,slidR,slidG,slidB);  /////
		 setrgbpalette(pal.colors[selected],slidR ,slidG , slidB);
		 ///resetting sliders/////
		 setfillstyle(1,15);
		 bar(250,40,372,49);
		 bar(250,58,372,67);
		 bar(250,75,372,84);
		 setfillstyle(1,1);
		 bar(250+slidR*2,40,251+slidR*2,49);
		 bar(250+slidG*2,58,251+slidG*2,67);
		 bar(250+slidB*2,75,251+slidB*2,84);

       }
    }      ///end of if(selected>=0)
    if(x>390&&x<500&&y>70&&y<85)     /////reseting  to default////
    {
	  for(int i=0;i<16;++i)
	  {  Pallet.getRGB(i,slidR,slidG,slidB);
	     setrgbpalette(pal.colors[i],slidR,slidG,slidB);      //////
	  }
	  ///resetting sliders/////
	  setfillstyle(1,15);
	  bar(250,40,372,49);
	  bar(250,58,372,67);
	  bar(250,75,372,84);
	  bar(181,41,199,84); ///resetting selected color//
	  setfillstyle(1,1);
	  bar(250,40,251,49);
	  bar(250,58,251,67);
	  bar(250,75,251,84);
	  ////resetting values///
	  selected=-1;
	  slidR=slidG=slidB=0;
    }
}

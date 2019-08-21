void openfile(fstream &);
void savefile(fstream &);

void filebkgrnd()
{     setlinestyle(0,1,1);
      if(tabi!=4)
      {   setfillstyle(1,15);
	  bar(0,31,maxx,89);
      }
       setcolor(BLUE);
       line(0,30,maxx,30);
       setcolor(15);
       line(0,30,29,30);

       tabi=4;
       settextstyle(2,0,4);
       setcolor(1);
       for(int i=5;i<=250;i+=55)    ///for making buttons///
	 rectangle(i,35,i+50,85);
       outtextxy(20,35,"NEW");       ////naming buttons////
       outtextxy(73,35,"OPEN");
       outtextxy(128,35,"SAVE");
       outtextxy(175,35,"SAVE AS");
       outtextxy(240,35,"QUIT");
       rectangle(15,60,45,80);      ///designing 'new' button///
       outtextxy(42,54,"*");

       line(66,62,70,75);         ///designing 'open' button///
       line(70,75,75,60);
       line(75,60,90,60);
       line(90,60,95,55);
       line(95,55,105,55);
       line(105,55,95,75);
       line(95,75,70,75);
       line(66,62,75,62);

       rectangle(130,55,150,80);  //designing   'save'  button
       rectangle(133,55,147,60);
       line(133,65,147,65);
       line(133,70,147,70);
       line(133,75,147,75);

       rectangle(185,55,205,80);  //designing   'save as'  button
       rectangle(188,55,202,60);
       line(188,65,202,65);
       line(188,70,202,70);
       line(188,75,202,75);
       outtextxy(203,68,"*");

       line(240,55,260,76);  ///designing 'quit' button
       line(235,82,260,50);
       line(235,82,260,49);
}
void filework()
{
    if(y>35&&y<85)
    {
      if((x>5&&x<55)||(x>225&&x<275))  ///click on new  or quit///
      {   int inew;
	   if(x>5&&x<55)
	      inew=1;   ///if clicked on new///
	   else
	      inew=0;    //if clicked on quit///
	   if(strcmp(filename,"")==0)
	   {
	     gotoxy(18,7);
	     cout<<"                                       ";
	     gotoxy(18,7);
	     cout<<"Do you want to save the file (y/n/c):";
	     char ch;
	     cin>>ch;
	     if(ch=='c')
	     {  gotoxy(18,7);
		cout<<"                                       ";
		return;
	     }
	     if(ch!='y')
		goto last;
	     gotoxy(18,7);
	     cout<<"                                     ";
	     gotoxy(18,7);
	     cout<<"Enter file name:";
	     gets(filename);     ///getting file name//
	     fstream fl;
	     fl.open(filename,ios::out|ios::binary);//opening file//
	     if(!fl)     //if error//
	     {   gotoxy(18,7);
	       cout<<"                                      ";
	       gotoxy(18,7);
	       cout<<"file can't open or doesn't exist !!";
	       delay(1000);
	       gotoxy(18,7);
	       cout<<"                                     ";

	       return;
	     }
	     savefile(fl);
	     fl.close();
	   }
	   last:
	   if(inew)             ///if selected item is new
	   {    setfillstyle(1,defbk);
		bar(0,116,maxx,maxy);
		strcmp(filename,"");
	   }
	   else              ////if selected item is quit
	   {    delete mem;
		exit(0);
	   }
      }
      if(x>60&&x<110)  ////click on open///
      {
	   gotoxy(18,7);
	   cout<<"                                        ";
	   gotoxy(18,7);
	   cout<<"Enter file name:";
	   gets(filename);     ///getting file name//
	   fstream fl;
	   fl.open(filename,ios::in|ios::binary);  //opening file///
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
      }
      if(x>115&&x<165)  ///click on save//
      {
	   if(strcmp(filename,"")==0)   ////if no file had been choosed//
	   {
		gotoxy(18,7);
		cout<<"                                      ";
		gotoxy(18,7);
		cout<<"Enter file name:";
		gets(filename);     ///getting file name//
	   }
	   fstream fl;
	   fl.open(filename,ios::out|ios::binary);//opening file//
	   if(!fl)     //if error//
	   {   gotoxy(18,7);
	       cout<<"                                           ";
	       gotoxy(18,7);
	       cout<<"file can't open or doesn't exist !!";
	       delay(1000);
	       gotoxy(18,7);
	       cout<<"                                     ";

	       return;
	   }
	   savefile(fl);
	   fl.close();
      }
      if(x>170&&x<220) ////click on save as///
      {
	     gotoxy(18,7);
	     cout<<"                                            ";
	     gotoxy(18,7);
	     cout<<"Enter file name:";
	     gets(filename);     ///getting file name//
	     fstream fl;
	     fl.open(filename,ios::out|ios::binary);//opening file//
	     if(!fl)     //if error//
	     {   gotoxy(18,7);
	       cout<<"                                         ";
	       gotoxy(18,7);
	       cout<<"file can't open or doesn't exist !!";
	       delay(1000);
	       gotoxy(18,7);
	       cout<<"                                     ";

	       return;
	     }
	     savefile(fl);
	     fl.close();
      }

    }
    gotoxy(18,7);
    cout<<"                                       ";

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
void savefile(fstream &f)
{     ///writing crnt  RGB values
      f.write((char *)&CrntPallet,sizeof(CrntPallet));/////
      f.write((char *)&maxx,sizeof(maxx));    //writing length & breadth//
      f.write((char *)&maxy,sizeof(maxy));

      int i=0,j=116;   ///starting point of canvas///
      int c;  ///color value///
      while(j<=maxy)       ///writing image///
      {
	     c=getpixel(i,j);
	     f.write((char *)&c,sizeof(c));
	     ++i;
	     if(i>maxx)
	     {   i=0;
		 ++j;
	     }
      }
					   /////////////////////
}

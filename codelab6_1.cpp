# include <iostream>
# include <graphics.h>
# include  <conio.h>
# include  <math.h>
# define Xc -0.3
# define Yc  0.3
# define Zc -1.0


 void show_screen( );

 void draw_3d_polygon(int [5][3],int [8][2],int [5][5]);
 void get_projected_point(int&,int&,int&);

 void Line(const int,const int,const int,const int);


 int main( )
    {
       int driver=VGA;
       int mode=VGAHI;

       initgraph(&driver,&mode,"..\\Bgi");

       show_screen( );

       int vertices[5][3]={
			    {245,325,75},      //  base front left
			    {395,325,75},      //  base front right
			    {395,325,-75},     //  base back right
			    {245,325,-75},     //  base back left
			    {320,125,0}        //  top
			  };

       int edges[8][2]={
			 // first is starting point vertex number
			 // second is ending point vertex number
			 {0,3} , {3,2} , {2,1} , {1,0} , {0,4} ,
			 {3,4} , {2,4} , {1,4}
		       };

       int surfaces[5][5]={
			     // First entry is number of edges
			     // Rest entries are edge numbers
			     {4,0,1,2,3}, {3,0,4,5} , {3,1,5,6} ,
			     {3,2,6,7} , {3,3,4,7}
			  };

       for(int i=0;i<5;i++)
	  get_projected_point(vertices[i][0],vertices[i][1],vertices[i][2]);

       setcolor(15);
	 draw_3d_polygon(vertices,edges,surfaces);

       settextstyle(2,0,4);
	 setcolor(11);
	   outtextxy(300,355,"S1");
	   outtextxy(260,270,"S2");
	   outtextxy(310,250,"S3");
	   outtextxy(370,280,"S4");
	   outtextxy(310,317,"S5");

	 setcolor(10);
	   outtextxy(255,315,"E1");
	   outtextxy(320,291,"E2");
	   outtextxy(403,315,"E3");
	   outtextxy(310,337,"E4");
	   outtextxy(250,250,"E5");
	   outtextxy(288,240,"E6");
	   outtextxy(390,240,"E7");
	   outtextxy(356,260,"E8");

	 setcolor(14);
	   outtextxy(212,344,"V1");
	   outtextxy(255,293,"V2");
	   outtextxy(420,293,"V3");
	   outtextxy(370,350,"V4");
	   outtextxy(320,115,"V5");

       getch( );
       closegraph( );
       return 0;
    }

 /************************************************************************/
 //-------------------------  draw_3d_polygon( )  -----------------------//
 /************************************************************************/

 void draw_3d_polygon(int vertices[5][3],int edges[8][2],int surfaces[5][5])
    {
       for(int i=0;i<5;i++)
	  {
	     for(int j=1;j<=surfaces[i][0];j++)
		{
		   int x_1=vertices[edges[surfaces[i][j]][0]][0];
		   int y_1=vertices[edges[surfaces[i][j]][0]][1];
		   int x_2=vertices[edges[surfaces[i][j]][1]][0];
		   int y_2=vertices[edges[surfaces[i][j]][1]][1];

		   Line(x_1,y_1,x_2,y_2);
		}
	  }
    }

 /************************************************************************/
 //---------------------  get_projected_point( )  -----------------------//
 /************************************************************************/

 void get_projected_point(int& x,int& y,int& z)
    {
       float projection_matrix[4][4]={
				      { -Zc,0,0,0 },
				      { 0,-Zc,0,0 },
				      { Xc,Yc,0,1 },
				      { 0,0,0,-Zc }
				   };

       float matrix3d[4]={x,y,z,1};
       float matrix2d[4]={0,0,0,0};

       for(int count_1=0;count_1<4;count_1++)
	  {
	     for(int count_2=0;count_2<4;count_2++)
		matrix2d[count_1]+=
			   (matrix3d[count_2]*projection_matrix[count_2][count_1]);
	  }

       x=(int)(matrix2d[0]+0.5);
       y=(int)(matrix2d[1]+0.5);
       z=(int)(matrix2d[2]+0.5);
    }

 /*************************************************************************/
 //--------------------------  Line( )  ------------------------//
 /*************************************************************************/

 void Line(const int x_1,const int y_1,const int x_2,const int y_2)
    {
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
	  {
	     x1=x_2;
	     y1=y_2;

	     x2=x_1;
	     y2=y_1;
	  }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
	  {
	     int two_dy=(2*dy);
	     int two_dy_dx=(2*(dy-dx));
	     int p=((2*dy)-dx);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(x<x2)
		{
		   x++;

		   if(p<0)
		      p+=two_dy;

		   else
		      {
			 y+=inc_dec;
			 p+=two_dy_dx;
		      }

		   putpixel(x,y,color);
		}
	  }

       else
	  {
	     int two_dx=(2*dx);
	     int two_dx_dy=(2*(dx-dy));
	     int p=((2*dx)-dy);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(y!=y2)
		{
		   y+=inc_dec;

		   if(p<0)
		      p+=two_dx;

		   else
		      {
			 x++;
			 p+=two_dx_dy;
		      }

		   putpixel(x,y,color);
		}
	  }
    }


 void show_screen( )
    {
 
    }

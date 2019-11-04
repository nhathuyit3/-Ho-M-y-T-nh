#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <graphics.h>
using namespace std;
// Khai bao bien toan cuc
int phepchieu; // = 1 : phoi canh; = 0 : song song
float r = 50, phi = 10,teta = 20,D = 20, tlx = 100, tly = 100;
int xo = 300, yo = 200; // (xo, yo) vi tri cai dat goc toa do tren man hinh
// Xay dung bo cong cu 3D
void chuyenHQS(float x, float y, float z, float &x1, float &y1, float &z1)
{
x1 = - x * sin(teta) + y * cos(teta);
y1 = - x * cos(teta) * sin(phi) - y * sin(teta) * sin(phi) + z * cos(phi);
z1 = - x * sin(teta) * cos(phi) - y * cos(teta) * sin(phi) - z * sin(phi) + r;
}
void chieu3D_2D(float x, float y, float z, float &xp, float &yp)
{
if (phepchieu == 1)
{
xp = D * x / z;
yp = D * y / z;
}
else
{
xp = x;
yp = y;
}
}
void chuyenMH(float x, float y, int &xm, int &ym)
{
xm = (int) (tlx * x + xo);
ym = (int) (tly * y + yo);
}
void chuyenDen(float x, float y, float z)
{
float x1, y1, z1, xp, yp;
int xm, ym;
chuyenHQS(x, y, z, x1, y1, z1);
chieu3D_2D(x1, y1, z1, xp, yp);
chuyenMH(xp, yp, xm, ym);
moveto(xm, ym);

}
void veDen(float x, float y, float z)
{
float x1, y1, z1, xp, yp;
int xm, ym;
chuyenHQS(x, y, z, x1, y1, z1);
chieu3D_2D(x1, y1, z1, xp, yp);
chuyenMH(xp, yp, xm, ym);
lineto(xm, ym);

}

// Ve lap phuong
void veLapPhuong(float x, float y, float z, float d)
{
chuyenDen(x, y, z); // > A
veDen(x + d, y, z); // > B
veDen(x + d, y + d, z); // > C
veDen(x, y + d, z); // > D
veDen(x, y, z); // > A
veDen(x, y, z + d); // > E
veDen(x + d, y, z + d); // > F
veDen(x + d, y + d, z + d); // > G
veDen(x, y + d, z + d); // > H
veDen(x, y, z + d); // > E
chuyenDen(x + d, y, z); // > B
veDen(x + d, y, z + d); // > F
chuyenDen(x + d, y + d, z); // > C
veDen(x + d, y + d, z + d); // > G
chuyenDen(x, y + d, z); // > D
veDen(x, y + d, z + d); // > F
}

void doixungLapPhuong(float x, float y, float z, float d)
{
chuyenDen(x, -y, z); // > A
veDen(x + d, -y, z); // > B
veDen(x + d, -(y + d),z); // > C
veDen(x, -(y + d), z); // > D
veDen(x, -y, z); // > A
veDen(x, -y, (z + d)); // > E
veDen(x + d, -y, (z + d)); // > F
veDen(x + d, -(y + d), (z + d)); // > G
veDen(x,-(y + d), (z + d)); // > H
veDen(x, -y, (z + d)); // > E
chuyenDen(x + d, -y, z); // > B
veDen(x + d, -y, (z + d)); // > F
chuyenDen(x + d, -(y + d), z); // > C
veDen(x + d, -(y + d), (z + d)); // > G
chuyenDen(x, -(y + d), z); // > D
veDen(x, -(y + d), (z + d)); // > F
}
int main()
{
int driver = DETECT, mode = 0;
initgraph(&driver, &mode,"C:\\Dev-Cpp\\include");



// Ve lap phuong
setcolor(WHITE);
veLapPhuong(0.5, 0.5, 0, 1);
doixungLapPhuong(0.5,0.5,0,1);
getch();
return 0;
}


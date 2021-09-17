#include<stdio.h>
#include<math.h>
#define f1(x,y,z,t)  (-2-y+z-t)/4
#define f2(x,y,z,t)  (-1-x+z+t)/4
#define f3(x,y,z,t)  (x+y-t)/5
#define f4(x,y,z,t)  (1-x+y-z)/3

void main()
{
//    Our equation:
//    4x+y-z+t=-2
//    x+4y-z-t=-1
//    -x-y+5z+t=0
//    x-y+z+3t=1
    float x0=0, y0=0, z0=0,t0=0, x1, y1, z1,t1, e1, e2, e3,e4, e;
    int counter=1;
    printf("Enter tolerable error (for example : 0.001) :\n");
    scanf("%f", &e);
    printf("\nIter\tx\ty\tz\tt\n");
    do
    {
        x1 = f1(x0,y0,z0,t0);
        y1 = f2(x1,y0,z0,t0);
        z1 = f3(x1,y1,z0,t0);
        t1 = f4(x1,y1,z1,t0);
        printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n",counter, x1,y1,z1,t1);

        e1 = fabs(x0-x1);
        e2 = fabs(y0-y1);
        e3 = fabs(z0-z1);
        e4 = fabs(t0-t1);

        counter++;
        x0 = x1;
        y0 = y1;
        z0 = z1;
        t0 = t1;

    }
    while(e1>e && e2>e && e3>e&& e4>e);

    printf("\nSolution: \nx =\t%0.3f\ny =\t%0.3f\nz =\t%0.3f\nt =\t%0.3f\n",x1,y1,z1,t1);
}

// g班 graphMain.c
#include <stdio.h>

#include "complex.h"

/* このプログラムはブランチを分けてから個々に作成してください */

// このファイルは 3316 関口丞 が記述
#include <math.h>
#define N 100

int main() {
    //printf("問2\n");
    //printf("時間t\t電圧vt\t電流it\n");
    complex v,z,i,Z_R1,Z_R2,Z_L,Z_C,Z_lef,Z_rig;
    double t,vt,it,r1,r2,l,c,f,period,omega;
    v = makeCompRT(50,M_PI/4);
    r1 = 5;
    r2 = 5;
    l = 5;
    c = 5;
    f = 500/M_PI;
    period = 1/f;
    omega = 2*M_PI*f;
    Z_R1 = makeComp(r1,0);
    Z_R2 = makeComp(r2,0);
    Z_L = makeComp(0,omega*l);
    Z_C = makeComp(0,-1/(omega*c));
    Z_lef = addComp(Z_R1,Z_L);
    Z_rig = addComp(Z_R2,Z_C);
    z = addComp(invComp(Z_lef),invComp(Z_rig));
    i = divComp(z,v);
    for(t=0;t<period;t+=period/N){
        vt = sqrt(2)*getR(v)*sin(omega*t+getTheta(v));
        it = sqrt(2)*getR(i)*sin(omega*t+getTheta(i));
        printf("%f\t%f\t%f\n",t,vt,it);
    }
    return 0;
}

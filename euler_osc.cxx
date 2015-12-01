#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;

void eulerbackward(double*, const int , const double);
void eulerforward(double*, const int , const double);

int main() {

 const int n = 100;
 const double pi= M_PI;
 const double dt= pi/n;
 const int N= 20*n;
 double x[2*N];
 double y[2*N];
 x[0]=1;
 x[N]=0;
 y[0]=1;
 y[N]=0;
 
 eulerbackward(x,N,dt);
 eulerforward(y,N,dt);

 ofstream out ( " euler_backward.txt ");
 for (int i=0; i<N ; i++) {
   out<< i*dt<< "\t"<< x[i] << \t" << x[N+i] << endl;
  }
 out.close();

 ofstream san( " euler_forward.txt ");
  for (int i=0; i<N ;i++){
    san<< i*dt << "\t" << y[i] << "/t" << y[N+i] << endl;
  }
  san.close();


 return 0;

}


void eulerbackward(double* p,  const int N, const double dt) {
 for (int i=0; i<N ; i++) {
   p[i+1]= ( p[i] + p[N+i]*dt )/ ( 1+ dt* dt);
   p[N+i+1]=( p[N+i]- p[i]*dt )/ (1+ dt*dt);
  }
}

void eulerfforward(double* p,  const int N, const double dt) {
 for (int i=0; i<N ; i++) {
   p[i+1]= p[i] + dt*p[N+i];
   p[N+i+1]=p[N+i] - dt*p[i];
  }
}



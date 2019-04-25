#include<cmath>
#include <iostream>
#include <fstream>
#include<vector>
using namespace std;
float dzdt(float delta_x, float omega){
    return -cos(delta_x*omega*omega);

};
void imprimir(string filename,vector<float> y,vector<float> dy,vector<float> x){
    ofstream file;
    file.open (filename);
    for(int i=0;i<y.size();i++){
        file<<y[i]<<" ";
    }
    file<<endl;
    for(int i=0;i<dy.size();i++){
        file<<dy[i]<<" ";
    }
    file<<endl;
    for(int i=0;i<x.size();i++){
        file<<x[i]<<" ";
    }
    file<<endl;
    file.close();

}
void solve_equation_euler(int t_init, int t_end, float delta_t, float omega, string filename){
    float yna1=0.0,ynb1=1.0,yna,ynb;
    float delta_x=delta_t;
    vector<float> y;
    vector<float> dy;
    vector<float> x;
    int lim=t_end/delta_t;
    while((lim--)>1){
        yna=yna1+delta_t*dzdt(delta_x,omega);
        ynb=ynb1+yna*delta_t;
        dy.push_back(yna);
        y.push_back(ynb);
        x.push_back(delta_x);
        ynb1=ynb;
        yna1=yna;
        delta_x+=delta_t;
    }
    imprimir(filename,y,dy,x);
}
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
    float yna1=0.0,ynb1=1.0,yna,ynb,k1,k2,k3,k4;
    float delta_x=delta_t;
    vector<float> y;
    vector<float> dy;
    vector<float> x;
    int lim=t_end/delta_t;
    while((lim--)>1){
        k1=dzdt(delta_x,omega);
        k2=dzdt(delta_x+delta_t/2.0,omega);
        k4=dzdt(delta_x+delta_t,omega);
        yna=yna1+(delta_t*(k1+4*k2+k4)/(6.0));
        k1=yna1;
        k2=(yna1+yna)/2.0;
        k4=yna1;
        ynb=ynb1+(delta_t*(k1+4*k2+k4)/(6.0));
        dy.push_back(yna);
        y.push_back(ynb);
        x.push_back(delta_x);
        ynb1=ynb;
        yna1=yna;
        delta_x+=delta_t;
    }
    imprimir(filename,y,dy,x);
}
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){
    float yna1=1.0,ynb1=0.0,yna,ynb,k1,k2,k3,k4;
    float delta_x=delta_t;
    vector<float> y;
    vector<float> dy;
    vector<float> x;
    int lim=t_end/delta_t;
    while((lim--)>1){
        ynb=ynb1+delta_t*(dzdt(delta_x,omega)+dzdt(delta_x+delta_t,omega))/2.0;
        yna=yna1+ynb*delta_t+delta_t*delta_t*dzdt(delta_x,omega)/2.0;

        dy.push_back(ynb);
        y.push_back(yna);
        x.push_back(delta_x);
        ynb1=ynb;
        yna1=yna;
        delta_x+=delta_t;
    }
    imprimir(filename,y,dy,x);
};
int main(){
  float omega=1.0;
  solve_equation_rk4(0, 15, 0.05, omega, "rk4.dat");
  solve_equation_leapfrog(0, 15, 0.01, omega, "leapfrog.dat");
  solve_equation_euler(0, 15, 0.2, omega, "euler.dat");
  return 0;
}

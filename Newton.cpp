#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;


//Definimos la funciÃ³n
inline double f(double x) { return (0.08205*273.15/x)+(-1.16583607818894/pow(x,2))+(0.0542253936905836/pow(x,3))+(-0.000125100322759761/pow(x,4))-200; }

//Derivada de la funciÃ³n
inline double df(double x) { return (-22.4119575/pow(x,2))+(2.33168/pow(x,3))-(0.16269/pow(x,4))+(0.00052/pow(x,5)); }

/*
p0: AproximaciÃ³n inicial
TOL: tolerancia
Nmax: nÃºmero mÃ¡ximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){

	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el mÃ©todo segÃºn los datos del problema
	newton((0.08205*273.15/200), pow(10, -9), 40);
	return 0;
}

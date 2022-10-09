#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class NepreklapajuciKrug{
double x,y,r;
 NepreklapajuciKrug* prethodni;
static int  *pokNaposljednuInstancu;

public:

NepreklapajuciKrug(double r = 0) {
	NepreklapajuciKrug::r = r;
}

NepreklapajuciKrug(double x, double y, double r = 0) {
    if(r < 0) throw logic_error("Negativan");
	NepreklapajuciKrug::r = r;
	NepreklapajuciKrug::x = x;
	NepreklapajuciKrug::y = y;
	prethodni = this;

}

void PostaviPoziciju(double x, double y) {
	NepreklapajuciKrug::x = x;
	NepreklapajuciKrug::y = y;
}

void PostaviPoluprecnik(double r) {
     if(r < 0) throw logic_error("Negativan");
		NepreklapajuciKrug::r = r;
}

double DajX() const {
	return x;
}

double DajY() const {
	return y;
}

double DajPoluprecnik() const {
	return r;
}

double DajObim() const {
	return 2*r*3.14;
}

double DajPovrsinu() const {
    return r * r * 3.14;
}

void Ispisi() const {
	cout << "{(" << x << "," << y << ")," << r << "}" << endl;
}

void Transliraj(double delta_x, double delta_y) {
	x += delta_x;
	y += delta_y;
}

void Rotiraj(double alpha){
	x = x * cos(alpha)- y * sin(alpha);
	y = y * sin(alpha) + y * cos(alpha);
}

void Rotiraj(double alpha, double x_c, double y_c){
	x = x_c + (x-x_c) * cos(alpha)- (y-y_c) * sin(alpha);
	y = y_c + (x-x_c) * sin(alpha) + (y-y_c) * cos(alpha);
}
};


int main()
{
    NepreklapajuciKrug k1(9);
	NepreklapajuciKrug k2(30, 15, 5);
	NepreklapajuciKrug k3(10,10,7);
    return 0;
}

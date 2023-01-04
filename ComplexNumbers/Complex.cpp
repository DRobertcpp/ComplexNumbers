#include "Complex.h"

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}
Complex::Complex(const Complex& z) {
	re = z.re;
	im = z.im;
}
Complex::Complex(const char* str) {
	char* pos_plus = (char*)strrchr(str, '+');
	char* pos_minus = (char*)strrchr(str, '-');
	if (pos_plus == NULL) {
		re = strtod(str, &pos_minus);
		im = strtod(pos_minus, NULL);
	}
	else if (pos_minus == NULL) {
		re = strtod(str, &pos_plus);
		im = strtod(pos_plus, NULL);
	}
	else {
		re = strtod(str, (pos_plus > pos_minus ? &pos_plus : &pos_minus));
		im = strtod(pos_plus > pos_minus ? pos_plus : pos_minus, NULL);
	}
}
double Complex::modul() {
	return sqrt(re * re + im * im);
}
double Complex::argument() {
	return atan2(im, re);
}
double distanta(const Complex& z1, const Complex& z2) {
	return sqrt((z1.re - z2.re) * (z1.re - z2.re) + (z1.im - z2.im) * (z1.im - z2.im));
}
double Complex::getRe() {
	return re;
}
void Complex::setRe(double re) {
	this->re = re;
}
double Complex::getIm() {
	return im;
}
void Complex::setIm(double im) {
	this->im = im;
}
Complex Complex::operator+(const Complex& c) {
	return Complex(re + c.re, im + c.im);
};
Complex Complex::operator-(const Complex& c) {
	return Complex(re - c.re, im - c.im);
};
Complex Complex::operator*(const Complex& z) {
	return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
};
Complex Complex::operator/(const Complex& z) {
	double t = z.re * z.re + z.im * z.im;
	return Complex((re * z.re + im * z.im) / t,
		(im * z.re - re * z.im) / t);
};
int Complex::operator==(const Complex& z) {
	return re == z.re && im == z.im;
};
int Complex::operator!=(const Complex& z) {
	return re != z.re || im != z.im;
};
Complex Complex::operator-() {
	return Complex(-re, -im);
};
Complex Complex::operator~() {
	return Complex(re, -im);
};
Complex& Complex::operator++() {
	re++;
	return *this;
};
Complex Complex::operator++(int) {
	Complex t(*this);
	re++;
	return t;
};
Complex& Complex::operator+=(const Complex& z) {
	if (this != &z) {
		re += z.re;
		im += z.im;
	};
	return *this;
};
Complex& Complex::operator-=(const Complex& z) {
	if (this != &z) {
		re -= z.re;
		im -= z.im;
	};
	return *this;
};
Complex& Complex::operator*=(const Complex& z) {
	if (this != &z) {
		double t = re;
		re = re * z.re - im * z.im;
		im = t * z.im + im * z.re;
	};
	return *this;
};
Complex& Complex::operator/=(const Complex& z) {
	if (this != &z) {
		double t1 = re, t2 = z.re * z.re + z.im * z.im;
		re = (re * z.re + im * z.im) / t2;
		im = (im * z.re - t1 * z.im) / t2;
	};
	return *this;
};
Complex::operator double() const {
	return re;
};
ostream& operator<<(ostream& out, const Complex& z) {
	if (z.re == 0)out << z.im << (z.im ? "i" : "");
	else if (z.im == 0)out << z.re;
	else out << z.re << (z.im > 0 ? "+" : "") << z.im << "i";
	return out;
};
istream& operator>>(istream& in, Complex& z) {
	in >> z.re >> z.im;
	return in;
};

void main() {
	double r = 5;//
	Complex c(r, 9);//constructor
	cout << c << endl;
	Complex z = c;//constructor copiere echivalent cu z(c)
	cout << z << endl;
	c = 5;//implicit
	Complex w = z + c;
	cout << w << endl;
	w = -w;
	cout << w << endl;
	w = ~w;
	cout << w << endl;
	cout << c << endl << (Complex)5 << endl << (Complex)5 / z++ << endl;
	z = c + (Complex)5 / z++;
	cout << c << endl;
	cout << z << endl;
	c = (Complex)"12+5i";
	cout << c << endl;
	cout << "Modul " << c.modul() << " Argument " << c.argument() << endl;
	r = (double)c;//operator conversie
	cout << r << endl;
	cin >> c;
	cout << c << endl;
}


#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;


class Rational {
public:
  Rational(){
    num = 0;
    den = 1;
  }

  Rational(int numerator, int denominator){
    if(denominator<0){
        if(numerator<0){
            denominator = abs(denominator);
            numerator = abs(numerator);
        }
        else {
            denominator = abs(denominator);
            numerator = -numerator;
        }
    }
    if(numerator == 0){
        denominator = 1;
    }
    int Nod = nod(abs(numerator), abs(denominator));
    num = numerator / Nod;
    denominator = denominator / Nod;
  }
  int Numerator() const{
    return num;
  }

  int Denominator() const{
    return den;
  }

private:
    int num, den;
    int nod (int a, int b) {
	return b ? nod (b, a % b) : a;
    }
    bool operator == (Rational a, Rational b){
        if(( a.Numerator() == b.Numerator() ) && (a.Denominator() == b.Denominator())){
            return true;
        }
        return false;
    }
    Rational operator + (Rational a, Rational b){
        return Rational(a.Numerator()*b.Denominator()+b.Numerator()*a.Denominator(), a.Denominator()*b.Denominator());
    }
    Rational operator - (Rational a, Rational b){
        return Rational(a.Numerator()*b.Denominator() - b.Numerator()*a.Denominator(), a.Denominator()*b.Denominator());
    }
    Rational operator * (Rational a, Rational b){
        return Rational (a.Numerator()*b.Numerator(), a.Denominator()*b.Denominator());
    }
    Rational operator / (Rational a, Rational b){
        return Rational (a.Numerator()*b.Denominator(), a.Denominator()*b.Numerator());
    }
    istream& operator >> (istream& stream, Rational& r) {
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = { p, q };
    }
    return stream;
}
    ostream& operator << (ostream& stream, const Rational& r) {
        stream << r.Numerator() << "/" << r.Denominator();
        return stream;
    }
    bool operator > (Rational a, Rational b) {
        return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
    }
    bool operator < (Rational a, Rational b) {
        return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
    }
};







int main(){
    return 0;
}

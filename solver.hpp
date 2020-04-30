
#include <iostream>
#include <complex>
using namespace std;

namespace solver{
	class RealVariable{
		public:
		RealVariable& operator/( int a){return *this;}
		RealVariable& operator+( int a){return *this;}
		RealVariable& operator*( int a){return *this;}
		RealVariable& operator^( int a){return *this;}
		RealVariable& operator-(  int a){return *this;}
		RealVariable& operator==(  int a){return *this;}
		RealVariable& operator+(  RealVariable& rv2){return *this;}
		RealVariable& operator-(  RealVariable& rv2){return *this;}
		RealVariable& operator==(  RealVariable& rv2){return *this;}

	};
	class ComplexVariable{
		public:
		ComplexVariable& operator/( int a){return *this;}
		ComplexVariable& operator+( complex<double> a){return *this;}
		ComplexVariable& operator*( int a){return *this;}
		ComplexVariable& operator^( int a){return *this;}
		ComplexVariable& operator-( int a){return *this;}
		ComplexVariable& operator==(  int a){return *this;}
		ComplexVariable& operator+( ComplexVariable& cv2){return *this;}
		ComplexVariable& operator-( ComplexVariable& cv2){return *this;}
		ComplexVariable& operator==( ComplexVariable& cv2){return *this;}
	};
	inline  double solve(RealVariable& rv){return 0;}
	inline  complex<double> solve(ComplexVariable& cv){return complex<double> (0.0,0.0);}
	
	inline RealVariable& operator*(int a,RealVariable& rv){return rv;}
	inline RealVariable& operator+(int a,RealVariable& rv){return rv;}
	inline ComplexVariable& operator*(int a, ComplexVariable& cv){return cv;}
	inline ComplexVariable& operator+(int a, ComplexVariable& cv){return cv;}

}




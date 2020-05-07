
#include <iostream>
#include <complex>
#include <math.h> 
#include <stdexcept>
using namespace std;

namespace solver{
	class RealVariable{
		public:
		double _coe=1;
		bool _isLinear=true;
		double _number=0;
		double _PIC=0; //if this is squared then we need to remember the other coe of the other x	
	
		RealVariable& operator/( int a){
		_coe/=a;
		return *this;}

		RealVariable& operator+( int a){
		_number-=a;
		return *this;}

		RealVariable& operator*( int a){
		_coe/=a;
		return *this;}

		RealVariable& operator^( int a){
		if(a==2){
		_isLinear=false;}
		return *this;}

		RealVariable& operator-(  int a){
		_number-=a;
		return *this;}

		RealVariable& operator==(  int a){
		_number-=a;
		return *this;}

		void minus(){
			_coe*=-1;
			_number*=-1;
			_PIC*=-1;
		}
		RealVariable& operator+(  RealVariable& rv){
			if(_isLinear&&rv._isLinear){
				_coe+=rv._coe;
				_number+=rv._number;
				return *this;}
			else if(!_isLinear&&rv._isLinear){
				_PIC+=rv._coe;
				_number+=rv._number;
				return *this;
			}
			else {return (rv+*this);}}
		RealVariable& operator-(  RealVariable& rv){
			rv.minus();
			return (*this+rv);}

		RealVariable& operator==(  RealVariable& rv){
			return (*this-rv);}

		

	};
	class ComplexVariable{
		public:
		double _coe=1;
		bool _isLinear=true;
		double _number=0;
		double _PIC=0; //if this is squared then we need to remember the other coe of the other x	
		double _complex=0;
	
		ComplexVariable& operator+( complex<double> a){
			_complex+=imag(a);
			return *this;
		}
		
		ComplexVariable& operator/( int a){
		_coe/=a;
		return *this;}

		ComplexVariable& operator+( int a){
		_number-=a;
		return *this;}

		ComplexVariable& operator*( int a){
		_coe/=a;
		return *this;}

		ComplexVariable& operator^( int a){
		if(a==2){
		_isLinear=false;}
		return *this;}

		ComplexVariable& operator-(  int a){
		_number-=a;
		return *this;}

		ComplexVariable& operator==(  int a){
		_number-=a;
		return *this;}

		void minus(){
			_coe*=-1;
			_number*=-1;
			_PIC*=-1;
			_complex*=-1;
		}

		ComplexVariable& operator+(  ComplexVariable& cv){
			if(_isLinear&&cv._isLinear){
				_coe+=cv._coe;
				_number+=cv._number;
				return *this;}
			else if(!_isLinear&&cv._isLinear){
				_PIC+=cv._coe;
				_number+=cv._number;
				_complex+=cv._complex;
				return *this;
			}
			else return (cv+*this);}
		ComplexVariable& operator-(  ComplexVariable& cv){
			cv.minus();
			return (*this+cv);}

		ComplexVariable& operator==(  ComplexVariable& cv){
			return (*this-cv);}

		
	};

	inline  double solve(RealVariable& rv){
		if(rv._PIC==0){
			double ans=-1*rv._number;
			if(rv._coe==0)throw "There is no real solution";
			ans/=rv._coe;
			if(!rv._isLinear){
				if(ans<0)throw "There is no real solution";}
			ans=sqrt(ans);
			return ans;
		}
		double ans=rv._PIC*rv._PIC;
		ans-=(-4*rv._coe*rv._number);
		if(ans<0)throw "There is no real solution";
		ans=sqrt(ans);
		ans+=-1*rv._PIC;
		if(rv._coe==0)throw "There is no real solution";
		ans/=rv._coe;
		return ans;
	}
	
	inline  complex<double> solve(ComplexVariable& cv){
		double real;
		double imag=cv._complex;
		if(imag==0){
			if(cv._PIC==0){
				real=-1*cv._number;
				if(cv._coe==0)throw "There is no real solution";
				real/=cv._coe;
				if(!cv._isLinear){
					if(real<0){
						imag=sqrt((real*-1));
						real=0;}
					else real=sqrt(real);}
				complex<double> ans(real,imag);
				return ans;
			}
			real=cv._PIC*cv._PIC;
			real-=(-4*cv._coe*cv._number);
			if(real<0){
				imag=sqrt((real*-1));
				real=0;}
			real+=-1*cv._PIC;
			if(cv._coe==0)throw "There is no real solution";
			real/=cv._coe;
			imag/=cv._coe;
			complex<double> ans(real,imag);
			return ans;
		}
		complex<double> ans(real,imag);
		return ans;
	}
	
	inline RealVariable& operator*(int a,RealVariable& rv){
		rv._coe*=a;
		return rv;}

	inline RealVariable& operator+(int a,RealVariable& rv){
		rv._number+=a;
		return rv;}

	inline RealVariable& operator/(int a,RealVariable& rv){
		rv._coe/=a;
		return rv;}

	inline RealVariable& operator-(int a,RealVariable& rv){
		rv._number-=a;
		return rv;}

	inline ComplexVariable& operator*(int a,ComplexVariable& cv){
		cv._coe*=a;
		return cv;}

	inline ComplexVariable& operator+(int a,ComplexVariable& cv){
		cv._number+=a;
		return cv;}

	inline ComplexVariable& operator/(int a,ComplexVariable& cv){
		cv._coe/=a;
		return cv;}

	inline ComplexVariable& operator-(int a,ComplexVariable& cv){
		cv._number-=a;
		return cv;}
}




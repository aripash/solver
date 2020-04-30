#include "solver.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;


TEST_CASE("correct input"){
RealVariable x;
ComplexVariable y;
CHECK(solve(x==0)==0);
CHECK(solve(y==0)==0+0i);
CHECK_THROWS(solve(x=0));
CHECK_THROWS(solve(0==0));
CHECK_THROWS(solve(y=0));
CHECK_THROWS(solve(x==y));
CHECK_THROWS(solve(x+y==0));
CHECK_THROWS(solve(x^3==0));
CHECK_THROWS(solve(x^-1==0));
CHECK_THROWS(solve(y^0==0));
CHECK_THROWS(solve(x^+2==0));
CHECK_THROWS(solve(2^x==0));
CHECK(solve(0==x)==0);
CHECK(solve(0==x*3)==0);
CHECK(solve(0==x^2)==0);
CHECK(solve(0==x^2*3)==0);
CHECK(solve(0==3*x^2)==0);
CHECK(solve(x==0)==0);
CHECK(solve(x*3==0)==0);
CHECK(solve(x^2==0)==0);
CHECK(solve(x^2*3==0)==0);
CHECK(solve(3*x^2==0)==0);
CHECK(solve(0==y)==0+0i);
CHECK(solve(0==y*3)==0+0i);
CHECK(solve(0==y^2)==0+0i);
CHECK(solve(0==y^2*3)==0+0i);
CHECK(solve(0==3*y^2)==0+0i);
CHECK(solve(y==0)==0+0i);
CHECK(solve(y*3==0)==0+0i);
CHECK(solve(y^2==0)==0+0i);
CHECK(solve(y^2*3==0)==0+0i);
CHECK(solve(3*y^2==0)==0+0i);
}

TEST_CASE("testing tests"){
	RealVariable x;
	for(int i=0;i<100;i++){
	CHECK(solve(x==i)==i);		
	}
}
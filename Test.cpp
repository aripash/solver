#include "solver.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;



TEST_CASE("testing tests"){
	RealVariable x;
	for(int i=0;i<100;i++){
	CHECK(solve(x==i)==i);		
	}
}

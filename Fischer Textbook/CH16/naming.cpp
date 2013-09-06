// --------------------------------------------------------- file: naming.cpp
#include "donut.hpp"
int main( void )
{
	C cc;							// Object has one base class.
	D dd; 							// Object has three base classes.
	cout <<" &cc.a=    " <<&cc.a <<"  value= " <<cc.a <<endl;	
	//cout <<" cc.A::x= " <<&cc.A::x <<"  cc.x=" <<cc.x <<endl;

	cout <<" &dd.x=    " <<&dd.x    <<"  value= " <<dd.x <<endl;
	cout <<" &dd.A::x= " <<&dd.A::x <<"  value= " <<dd.A::x <<endl;  		
	cout <<" &dd.B::a= " <<&dd.B::a <<"  value= " <<dd.B::a <<endl;
	cout <<" &dd.C::a= " <<&dd.C::a <<"  value= " <<dd.C::a <<endl;
	//cout <<" &dd.a= "  <<&dd.a    <<"  value= " <<dd.a <<endl;
}

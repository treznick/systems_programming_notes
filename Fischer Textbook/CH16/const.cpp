#include <iostream.h>
int main( void )
{	
	int w = 99;
	const int* cip = &w;

  	cout <<"  &w is " <<&w <<" referent of cip is " <<cip <<endl;
	cout <<"  w= " <<w  <<"  *cip= " <<*cip <<endl;
	 	
	* const_cast<int*>(cip) = 33;	
	//*cip = 33;				       	
	cout <<"  w= " <<w  <<"  *cip= " <<*cip <<endl;
}

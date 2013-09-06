#include <iostream.h>
using namespace std;
// ------------------------------------------------------------ File:  "assign.cpp"
int main( void )
{
	int    my_int = 987654321;
	int*   p_int = & my_int;
	float* p_float  = (float*) p_int;
	float  answer = *p_float + 1.0;
	cerr <<answer <<"\n";	
}

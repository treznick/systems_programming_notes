#include "tools.hpp" 
class Mixed {  
	int len; 
	char* name; 
    public:
	Mixed( char* nm ){ 	//------------------- Constructor 
		len = strlen(nm); 
		name = new char [len+1]; 
		strcpy( name, nm ); 
	}
	~Mixed() { delete[] name; }	
	void print(){ cout << name << " " << len <<'\t'; }
	void change( char x ) { name[0] = x; }		
};

int main( void )  
{	
	Mixed A( "Joe" );
	Mixed B( "Mary" );
	cout << "Initial values A, B:\t";  A.print();  B.print();
	B = A;
	cout << "\nAfter copying B = A:\t";  A.print();  B.print();
	B.change( 'T' );
	cout << "\nAfter setting B.name[0] = 'T':\t";  A.print();  B.print(); 
	cout <<endl;
}

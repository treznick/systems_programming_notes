//------------------------------------------------------------------
void 
print_parts( ostream& fout, Part* inventory, int n ){
	Part* p = inventory;
	Part* pend = inventory+n;

	for ( ; p<pend; ++p) {
        fout.setf(ios::left, ios::adjustfield); // Left-adjust the first two outputs.
        fout <<setw(25) <<setfill('.') <<p->part_name;   
        fout <<setw(3)  <<setfill(' ') <<p->store_code;  
        
        fout.setf(ios::fixed, ios::floatfield);   // Use fixed-point for float and double.
        fout.precision(2); 						  // 2 places after the decimal point. 
		fout.setf(ios::right, ios::adjustfield);  // Right-adjust the last two.
        fout <<setw(5) <<p->quantity;
        fout <<setw(8) <<p->price <<endl; 
	}
}
//------------------------------------------------------------------

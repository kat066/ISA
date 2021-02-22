// CSE141L
// possible lookup table for PC target
// leverage a few-bit pointer to a wider number
// Lookup table acts like a function: here Target = f(Addr);
//  in general, Output = f(Input); 
module LUT(
  input       [ 7:0] Addr,
  output logic[ 7:0] Target
  );

always_comb 
  case(Addr)		   //tap pattern;
	8'h00:   Target = 8'h60; 
	8'h01:	 Target = 8'h48;
	8'h02:	 Target = 8'h78;
	8'h03:   Target = 8'h72;
	8'h04:	 Target = 8'h6A;
	8'h05:	 Target = 8'h69;
	8'h06:   Target = 8'h5C;
	8'h07:	 Target = 8'h7E;
	8'h08:	 Target = 8'h7B;
	default: Target = 8'h48;
  endcase

endmodule
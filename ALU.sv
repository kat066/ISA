// Create Date:    2018.10.15
// Module Name:    ALU 
// Project Name:   CSE141L
//
// Revision 2018.01.27
// Additional Comments: 
//   combinational (unclocked) ALU
import definitions::*;			         // includes package "definitions"
//import LUT::*;
module ALU(
  input        [7:0] InputA,             // data inputs
                     InputB,
  input			[4:0] Imm,
  input        [4:0] OP,		         // ALU opcode, part of microcode
  output logic [7:0] Out,		         // or:  output reg [7:0] OUT,
  output logic       Zero                // output = zero flag
    );			

	 
  logic			[7:0] LookUp; 
  op_mne op_mnemonic;			         // type enum: used for convenient waveform viewing
  LUT LUT1 (
		.Addr		(InputB),
		.Target (LookUp)
  );
  always_comb begin
    Out = 0;                             // No Op = default
    case(OP)
		oLSR : Out = InputB << Imm;  	      
		oRSR : Out = InputB >> Imm;
		oMOVER : Out = InputA;
		oMOVEA : Out = InputB;
		oXOR : Out = InputA ^ InputB;
		oRXOR : Out = {7'b0, ^InputA};
		oAND : Out = InputA & InputB;      // and
		oANDI : Out = InputA & {3'b0,Imm};
		oLOAD : Out = InputB;
		oSTORE : Out = InputA;
		oHALT: Out = InputA;
		oBEQ : Out = !(InputA == InputB);
		oBLT : Out = !( InputB < InputA);
		oJUMP : Out = {3'b0,Imm};
		oADD : Out = InputA + InputB;      // add 
		oADDI : Out = InputA + {3'b0,Imm};
		oSUB : Out = InputA - {3'b0,Imm};
		oLUT : Out = LookUp;
    endcase
  end

  always_comb							  // assign Zero = !Out;
    case(Out)
      'b0     : Zero = 1'b1;
	  default : Zero = 1'b0;
    endcase

  always_comb
   op_mnemonic = op_mne'(OP);			 // displays operation name in waveform viewer

endmodule
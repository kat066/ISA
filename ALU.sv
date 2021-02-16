// Create Date:    2018.10.15
// Module Name:    ALU 
// Project Name:   CSE141L
//
// Revision 2018.01.27
// Additional Comments: 
//   combinational (unclocked) ALU
import definitions::*;			         // includes package "definitions"
module ALU(
  input        [7:0] InputA,             // data inputs
                     InputB,
  input			[4:0] Imm,
  input        [2:0] OP,		         // ALU opcode, part of microcode
  output logic [7:0] Out,		         // or:  output reg [7:0] OUT,
  output logic       Zero                // output = zero flag
    );								    
	 
  //op_mne op_mnemonic;			         // type enum: used for convenient waveform viewing
	
  always_comb begin
    Out = 0;                             // No Op = default
    case(OP)
		oLSR : Out = InputA << Imm;  	      
		oRSR : Out = InputA >> Imm;
		oMOVER : Out = InputA;
		oMOVEA : Out = InputB;
		oXOR : Out = InputA ^ InputB;
		oRXOR : Out = {7'b0, ^InputA};
		oAND : Out = InputA & InputB;      // and
		oANDI : Out = InputA & {4'b0,Imm};
		oLOAD : Out = InputB;
		oSTORE : Out = InputA;
		oBEQ : Out = (InputA == InputB);
		oBNE : Out = (InputA != InputB);
		oBLE : Out = (InputA <= InputB);
		oBLT : Out =  (InputA < InputB);
		oJUMP : Out = {4'b0,Imm};
		oADD : Out = InputA + InputB;      // add 
		oADDI : Out = InputA + {4'b0,Imm};
		oSUB : Out = InputA - {4'b0,Imm};
		oLUT : Out = InputA;
    endcase
  end

  always_comb							  // assign Zero = !Out;
    case(Out)
      'b0     : Zero = 1'b1;
	  default : Zero = 1'b0;
    endcase

  //always_comb
//    op_mnemonic = op_mne'(OP);			 // displays operation name in waveform viewer

endmodule
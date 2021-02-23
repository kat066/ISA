// CSE141L
import definitions::*;
// control decoder (combinational, not clocked)
// inputs from instrROM, ALU flags
// outputs to program_counter (fetch unit)
module Ctrl (
  input[ 8:0] Instruction,	   // machine code
  output logic Jump,
               BranchEn,
					WriteR,
					ImmMux,
  output logic[ 4:0] OP
   
  );
// jump on right shift that generates a zero
always_comb begin
  if(Instruction[8:7] ==  typeIII && Instruction[6:5] == iiiJUMP) begin
	 Jump = 1;
  end else
    Jump = 0;
	 
  if(Instruction[8:7] ==  typeII)  
		BranchEn = 1;
  else
    BranchEn = 0;
	
	WriteR = 0;
	ImmMux = 0;
	OP = 5'b0;
   case(Instruction[8:7])
		typeI: begin
			case(Instruction[6:3])
				iADD:OP = oADD;
				iMOVER: begin
					OP = oMOVER;
					WriteR = 1;
				end
				iMOVEA: OP = oMOVEA;
				iRXOR: OP = oRXOR;
				iLUT: OP = oLUT;
				iXOR: OP = oXOR;
				iAND: OP = oAND;
				iLOAD: OP = oLOAD;
				iSTORE: OP = oSTORE;
				iHALT: OP = oHALT;
			endcase
		end
		typeII: begin
			case(Instruction[6])
				iiBEQ: OP = oBEQ;
				iiBLT: OP = oBLT;
			endcase
		end
		typeIII:begin
			ImmMux=1;
			case(Instruction[6:5])
				iiiANDI: OP = oANDI;
				iiiADDI: OP = oADDI;
				iiiSUB: OP = oSUB;
				iiiJUMP: OP = oJUMP;
			endcase
		end
		typeIV: begin
			WriteR = 1;
			case(Instruction[6])
				ivLSR: OP = oLSR;
				ivRSR: OP = oRSR;
			endcase
		end

	endcase
	 
	 
end
// branch every time ALU result LSB = 0 (even)

endmodule


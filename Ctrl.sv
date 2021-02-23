// CSE141L
import definitions::*;
// control decoder (combinational, not clocked)
// inputs from instrROM, ALU flags
// outputs to program_counter (fetch unit)
module Ctrl (
  input[ 8:0] Instruction,	   // machine code
  output logic Jump,
               BranchEn,
					
  output logic[2:0] RegReadAddr,
						RegWriteAddr,
  output logic[ 4:0] Imm,
							OP
   
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
	
	RegWriteAddr=3'b001;
	RegReadAddr = 3'b001;
	Imm = 5'b0;
	OP = 5'b0;
   case(Instruction[8:7])
		typeI: begin
			RegReadAddr = Instruction[2:0];
			case(Instruction[6:3])
				iADD:OP = oADD;
				iMOVER: begin
					OP = oMOVER;
					RegWriteAddr = Instruction[2:0];
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
			Imm = {3'b000,Instruction[5:3]};
			RegReadAddr = Instruction[2:0];
			case(Instruction[6])
				iiBEQ: OP = oBEQ;
				iiBLT: OP = oBLT;
			endcase
		end
		typeIII:begin
			Imm = Instruction[4:0];
			case(Instruction[6:5])
				iiiANDI: OP = oANDI;
				iiiADDI: OP = oADDI;
				iiiSUB: OP = oSUB;
				iiiJUMP: OP = oJUMP;
			endcase
		end
		typeIV: begin
			RegReadAddr = Instruction[2:0];
			Imm = {2'b00,Instruction[5:3]};
			RegWriteAddr = Instruction[2:0];
			case(Instruction[6])
				ivLSR: OP = oLSR;
				ivRSR: OP = oRSR;
			endcase
		end

	endcase
	 
	 
end
// branch every time ALU result LSB = 0 (even)

endmodule
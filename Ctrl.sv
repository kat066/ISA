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
  if(Instruction[1:0] ==  typeIII && Instruction[3:2] == iiiJUMP) begin
	 Jump = 1;
  end else
    Jump = 0;
	 
  if(Instruction[1:0] ==  typeII)  
		BranchEn = 1;
  else
    BranchEn = 0;
	
	RegWriteAddr=3'b001;
	RegReadAddr = 3'b001;
	Imm = 5'b0;
	OP = 5'b0;
   case(Instruction[1:0])
		typeI: begin
			RegReadAddr = Instruction[8:6];
			case(Instruction[5:2])
				iADD:OP = oADD;
				iMOVER: begin
					OP = oMOVER;
					RegWriteAddr = Instruction[8:6];
				end
				iMOVEA: OP = oMOVEA;
				iRXOR: OP = oRXOR;
				iLUT: OP = oLUT;
				iXOR: OP = oXOR;
				iAND: OP = oAND;
				iLOAD: OP = oLOAD;
				iSTORE: OP = oSTORE;
			endcase
		end
		typeII: begin
			RegReadAddr = Instruction[6:4];
			Imm = {2'b00,Instruction[8:6]};
			case(Instruction[3:2])
				iiBEQ: OP = oBEQ;
				iiBNE: OP = oBNE;
				iiBLE: OP = oBLE;
				iiBLT: OP = oBLT;
			endcase
		end
		typeIII:begin
			Imm = Instruction[8:4];
			case(Instruction[3:2])
				iiiANDI: OP = oANDI;
				iiiADDI: OP = oADDI;
				iiiSUB: OP = oSUB;
				iiiJUMP: OP = oJUMP;
			endcase
		end
		typeIV: begin
			RegReadAddr = Instruction[5:3];
			Imm = {2'b00,Instruction[8:6]};
			RegWriteAddr = Instruction[5:3];
			case(Instruction[2])
				ivLSR: OP = oLSR;
				ivRSR: OP = oRSR;
			endcase
		end

	endcase
	 
	 
end
// branch every time ALU result LSB = 0 (even)

endmodule


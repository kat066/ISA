//This file defines the parameters used in the alu
// CSE141L
package definitions;
    
// Instruction map
	const logic [1:0]typeI  = 2'b00;
	const logic [1:0]typeII  = 2'b01;
	const logic [1:0]typeIII  = 2'b10;
	const logic [1:0]typeIV  = 2'b11;
   const logic [3:0]iADD  = 4'b0000;
   const logic [3:0]iMOVER  = 4'b0001;
   const logic [3:0]iMOVEA  = 4'b0010;
   const logic [3:0]iRXOR  = 4'b0011;
	const logic [3:0]iLUT = 4'b0100;
	const logic [3:0]iXOR  = 4'b0101;
	const logic [3:0]iAND  = 4'b0110;
	const logic [3:0]iLOAD  = 4'b0111;
	const logic [3:0]iSTORE  = 4'b1000;
	const logic [3:0]iHALT  = 4'b1001;
	const logic [1:0]iiBEQ  = 2'b00;
	const logic [1:0]iiBLT  = 2'b01;
	const logic [1:0]iiiANDI  = 2'b00;
	const logic [1:0]iiiADDI  = 2'b01;
	const logic [1:0]iiiSUB  = 2'b10;
	const logic [1:0]iiiJUMP  = 2'b11;
	const logic ivLSR = 1'b0;
	const logic ivRSR = 1'b1;
	
	const logic [4:0]oLSR = 5'b00000;
	const logic [4:0]oRSR = 5'b00001;
	const logic [4:0]oMOVER = 5'b00010;
	const logic [4:0]oMOVEA = 5'b00011;
	const logic [4:0]oXOR = 5'b00100;
	const logic [4:0]oRXOR = 5'b00101;
	const logic [4:0]oAND = 5'b00110;
	const logic [4:0]oANDI = 5'b00111;
	const logic [4:0]oLOAD = 5'b01000;
	const logic [4:0]oSTORE = 5'b01001;
	const logic [4:0]oHALT = 5'b01010;
	const logic [4:0]oBEQ = 5'b01011;
	const logic [4:0]oBLT = 5'b01100;
	const logic [4:0]oJUMP = 5'b01101;
	const logic [4:0]oADD = 5'b01110;
	const logic [4:0]oADDI = 5'b01111;
	const logic [4:0]oSUB = 5'b10000;
	const logic [4:0]oLUT = 5'b10001;
											
	
// enum names will appear in timing diagram
    typedef enum logic[4:0] {
        LSR, RSR, MOVER, MOVEA, XOR,RXOR, AND, ANDI,LOAD,
		 STORE,HALT, BEQ,BLT,JUMP,ADD,ADDI,SUB,LUT } op_mne;
// note: kADD is of type logic[2:0] (3-bit binary)
//   ADD is of type enum -- equiv., but watch casting
//   see ALU.sv for how to handle this   
endpackage // definitions

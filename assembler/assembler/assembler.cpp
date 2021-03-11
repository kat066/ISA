// assembler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void printVector(vector<string> vec);
void exportMachineCode(vector<string> vec);
int main() {
	string text;
	string line;
	// vector stores every string from file excluding white space
	vector<string> parts;

	// reads in file called 'assembly.txt' within the same directory of cpp file
	// and assigns it the ifstream variable named 'assemblyFile'
	ifstream assemblyFile("assembly.txt");

	while (assemblyFile >> text) {
		if (text.substr(0,2) == "//") {
			getline(assemblyFile, line);
			//cout << text << line << endl;
		}
		else {
			parts.push_back(text);
		}
		
	}

	assemblyFile.close();

	//printVector(parts);

	exportMachineCode(parts);

}

void printVector(vector<string> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}

void exportMachineCode(vector<string> vec) {
	ofstream machineCode("machine_code.txt");
	if (!machineCode.is_open()) {
		cout << "failed to open file";
	}
	vector<string> labels;
	int i;
	string reg;
	for (int j = 0; j < vec.size(); j++) {
		if (vec[j].substr((vec[j].length() - 1),1)==":") {
			labels.push_back(vec[j].substr(0, (vec[j].length() - 1)));
			cout << "label encountered: " << vec[j].substr(0, (vec[j].length() - 1)) << " before: " << vec[j - 1] << " after: " << vec[j + 1] << endl;
		}
	}
	for (int j = 0; j < labels.size(); j++) {
		cout << labels[j] << endl;
	}
	for (int j = 0; j < vec.size(); j++) {
		// Checking for TYPE 1 Instructions (00)
		// FORMAT: TYPE, OPCODE, REG
		if (vec[j] == "ADD") {
			machineCode << "00";
			machineCode << "0000";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {

				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}


		}
		else if (vec[j] == "MOVER") {
			machineCode << "00";
			machineCode << "0001";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}
			

		}
		else if (vec[j] == "MOVEA") {
			machineCode << "00";
			machineCode << "0010";
			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "RXOR") {
			// we are not using this instruction anymore i think (?)
			machineCode << "00";
			machineCode << "0011";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "LUT") {
			machineCode << "00";
			machineCode << "0100";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "XOR") {
			machineCode << "00";
			machineCode << "0101";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "AND") {
			machineCode << "00";
			machineCode << "0110";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "LOAD") {
			machineCode << "00";
			machineCode << "0111";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "STORE") {
			machineCode << "00";
			machineCode << "1000";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				machineCode << "000" << endl;
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				machineCode << "001" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				machineCode << "010" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				machineCode << "011" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				machineCode << "100" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				machineCode << "101" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				machineCode << "110" << endl;
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				machineCode << "111" << endl;
				++j;
			}

		}
		else if (vec[j] == "HALT") {
			machineCode << "00";
			machineCode << "1001";

			// does it take in register or should I just pad with zeroes
			machineCode << "000" << endl;

			// Now checking for TYPE 2 instructions (01)	 ################################
			// FORMAT: TYPE, OPCODE, LUT POINTER (3 bits), REGISTER (3 bits)
		}
		else if (vec[j] == "BEQ") {
			machineCode << "01";
			machineCode << "0";

			// need to check LUT POINTER
			// then check register

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				reg= "000";
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				reg =  "001";
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				reg =  "010";
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				reg =  "011";
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				reg =  "100";
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				reg =  "101";
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				reg = "110";
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				reg = "111";
				++j;
			}
			i = 0;
			while (i < labels.size() && (labels[i] != vec[j+1])) {
				i++;
			};
			switch (i) {
			case 0:
				machineCode << "000" << reg << endl;
				break;
			case 1:
				machineCode << "001" << reg << endl;
				break;
			case 2:
				machineCode << "010" << reg << endl;
				break;
			case 3:
				machineCode << "011" << reg << endl;
				break;
			case 4:
				machineCode << "100" << reg << endl;
				break;
			case 5:
				machineCode << "101" << reg << endl;
				break;
			case 6:
				machineCode << "110" << reg << endl;
				break;
			case 7:
				machineCode << "111" << reg << endl;
				break;
			default:
				machineCode << "000" << reg << endl;
				break;
			}
			++j;


		}
		else if (vec[j] == "BLT") {
			machineCode << "01";
			machineCode << "1";

			if (vec[j + 1] == "$ZERO" || vec[j + 1] == "$R0") {
				reg = "000";
				++j;
			}
			else if (vec[j + 1] == "$ACCU" || vec[j + 1] == "$R1") {
				reg = "001";
				++j;
			}
			else if (vec[j + 1] == "$R2") {
				reg = "010";
				++j;
			}
			else if (vec[j + 1] == "$R3") {
				reg = "011";
				++j;
			}
			else if (vec[j + 1] == "$R4") {
				reg = "100";
				++j;
			}
			else if (vec[j + 1] == "$R5") {
				reg = "101";
				++j;
			}
			else if (vec[j + 1] == "$R6") {
				reg = "110";
				++j;
			}
			else if (vec[j + 1] == "$R7") {
				reg = "111";
				++j;
			}
			i = 0;
			while (i < labels.size() && (labels[i] != vec[j+1])) {
				i++;
			};
			switch (i) {
			case 0:
				machineCode << "000" << reg << endl;
				break;
			case 1:
				machineCode << "001" << reg << endl;
				break;
			case 2:
				machineCode << "010" << reg << endl;
				break;
			case 3:
				machineCode << "011" << reg << endl;
				break;
			case 4:
				machineCode << "100" << reg << endl;
				break;
			case 5:
				machineCode << "101" << reg << endl;
				break;
			case 6:
				machineCode << "110" << reg << endl;
				break;
			case 7:
				machineCode << "111" << reg << endl;
				break;
			default:
				machineCode << "000" << reg << endl;
				break;
			}
			++j;

			// Now checking for TYPE 3 instructions (10)     ################################
			// FORMAT: TYPE, OPCODE, IMMEDIATE (5 BITS)
		}
		else if (vec[j] == "ANDI") {
			machineCode << "10";
			machineCode << "00";

			if (vec[j + 1] == "0") {
				machineCode << "00000" << endl;
				++j;
			}
			else if (vec[j + 1] == "1") {
				machineCode << "00001" << endl;
				++j;
			}
			else if (vec[j + 1] == "2") {
				machineCode << "00010" << endl;
				++j;
			}
			else if (vec[j + 1] == "3") {
				machineCode << "00011" << endl;
				++j;
			}
			else if (vec[j + 1] == "4") {
				machineCode << "00100" << endl;
				++j;
			}
			else if (vec[j + 1] == "5") {
				machineCode << "00101" << endl;
				++j;
			}
			else if (vec[j + 1] == "6") {
				machineCode << "00110" << endl;
				++j;
			}
			else if (vec[j + 1] == "7") {
				machineCode << "00111" << endl;
				++j;
			}
			else if (vec[j + 1] == "8") {
				machineCode << "01000" << endl;
				++j;
			}
			else if (vec[j + 1] == "9") {
				machineCode << "01001" << endl;
				++j;
			}
			else if (vec[j + 1] == "10") {
				machineCode << "01010" << endl;
				++j;
			}
			else if (vec[j + 1] == "11") {
				machineCode << "01011" << endl;
				++j;
			}
			else if (vec[j + 1] == "12") {
				machineCode << "01100" << endl;
				++j;
			}
			else if (vec[j + 1] == "13") {
				machineCode << "01101" << endl;
				++j;
			}
			else if (vec[j + 1] == "14") {
				machineCode << "01110" << endl;
				++j;
			}
			else if (vec[j + 1] == "15") {
				machineCode << "01111" << endl;
				++j;
			}
			else if (vec[j + 1] == "16") {
				machineCode << "10000" << endl;
				++j;
			}
			else if (vec[j + 1] == "17") {
				machineCode << "10001" << endl;
				++j;
			}
			else if (vec[j + 1] == "18") {
				machineCode << "10010" << endl;
				++j;
			}
			else if (vec[j + 1] == "19") {
				machineCode << "10011" << endl;
				++j;
			}
			else if (vec[j + 1] == "20") {
				machineCode << "10100" << endl;
				++j;
			}
			else if (vec[j + 1] == "21") {
				machineCode << "10101" << endl;
				++j;
			}
			else if (vec[j + 1] == "22") {
				machineCode << "10110" << endl;
				++j;
			}
			else if (vec[j + 1] == "23") {
				machineCode << "10111" << endl;
				++j;
			}
			else if (vec[j + 1] == "24") {
				machineCode << "11000" << endl;
				++j;
			}
			else if (vec[j + 1] == "25") {
				machineCode << "11001" << endl;
				++j;
			}
			else if (vec[j + 1] == "26") {
				machineCode << "11010" << endl;
				++j;
			}
			else if (vec[j + 1] == "27") {
				machineCode << "11011" << endl;
				++j;
			}
			else if (vec[j + 1] == "28") {
				machineCode << "11100" << endl;
				++j;
			}
			else if (vec[j + 1] == "29") {
				machineCode << "11101" << endl;
				++j;
			}
			else if (vec[j + 1] == "30") {
				machineCode << "11110" << endl;
				++j;
			}
			else if (vec[j + 1] == "31") {
				machineCode << "11111" << endl;
				++j;
			}

		}
		else if (vec[j] == "ADDI") {
			machineCode << "10";
			machineCode << "01";

			if (vec[j + 1] == "0") {
				machineCode << "00000" << endl;
				++j;
			}
			else if (vec[j + 1] == "1") {
				machineCode << "00001" << endl;
				++j;
			}
			else if (vec[j + 1] == "2") {
				machineCode << "00010" << endl;
				++j;
			}
			else if (vec[j + 1] == "3") {
				machineCode << "00011" << endl;
				++j;
			}
			else if (vec[j + 1] == "4") {
				machineCode << "00100" << endl;
				++j;
			}
			else if (vec[j + 1] == "5") {
				machineCode << "00101" << endl;
				++j;
			}
			else if (vec[j + 1] == "6") {
				machineCode << "00110" << endl;
				++j;
			}
			else if (vec[j + 1] == "7") {
				machineCode << "00111" << endl;
				++j;
			}
			else if (vec[j + 1] == "8") {
				machineCode << "01000" << endl;
				++j;
			}
			else if (vec[j + 1] == "9") {
				machineCode << "01001" << endl;
				++j;
			}
			else if (vec[j + 1] == "10") {
				machineCode << "01010" << endl;
				++j;
			}
			else if (vec[j + 1] == "11") {
				machineCode << "01011" << endl;
				++j;
			}
			else if (vec[j + 1] == "12") {
				machineCode << "01100" << endl;
				++j;
			}
			else if (vec[j + 1] == "13") {
				machineCode << "01101" << endl;
				++j;
			}
			else if (vec[j + 1] == "14") {
				machineCode << "01110" << endl;
				++j;
			}
			else if (vec[j + 1] == "15") {
				machineCode << "01111" << endl;
				++j;
			}
			else if (vec[j + 1] == "16") {
				machineCode << "10000" << endl;
				++j;
			}
			else if (vec[j + 1] == "17") {
				machineCode << "10001" << endl;
				++j;
			}
			else if (vec[j + 1] == "18") {
				machineCode << "10010" << endl;
				++j;
			}
			else if (vec[j + 1] == "19") {
				machineCode << "10011" << endl;
				++j;
			}
			else if (vec[j + 1] == "20") {
				machineCode << "10100" << endl;
				++j;
			}
			else if (vec[j + 1] == "21") {
				machineCode << "10101" << endl;
				++j;
			}
			else if (vec[j + 1] == "22") {
				machineCode << "10110" << endl;
				++j;
			}
			else if (vec[j + 1] == "23") {
				machineCode << "10111" << endl;
				++j;
			}
			else if (vec[j + 1] == "24") {
				machineCode << "11000" << endl;
				++j;
			}
			else if (vec[j + 1] == "25") {
				machineCode << "11001" << endl;
				++j;
			}
			else if (vec[j + 1] == "26") {
				machineCode << "11010" << endl;
				++j;
			}
			else if (vec[j + 1] == "27") {
				machineCode << "11011" << endl;
				++j;
			}
			else if (vec[j + 1] == "28") {
				machineCode << "11100" << endl;
				++j;
			}
			else if (vec[j + 1] == "29") {
				machineCode << "11101" << endl;
				++j;
			}
			else if (vec[j + 1] == "30") {
				machineCode << "11110" << endl;
				++j;
			}
			else if (vec[j + 1] == "31") {
				machineCode << "11111" << endl;
				++j;
			}


		}
		else if (vec[j] == "SUB") {
			machineCode << "10";
			machineCode << "10";

			if (vec[j + 1] == "0") {
				machineCode << "00000" << endl;
				++j;
			}
			else if (vec[j + 1] == "1") {
				machineCode << "00001" << endl;
				++j;
			}
			else if (vec[j + 1] == "2") {
				machineCode << "00010" << endl;
				++j;
			}
			else if (vec[j + 1] == "3") {
				machineCode << "00011" << endl;
				++j;
			}
			else if (vec[j + 1] == "4") {
				machineCode << "00100" << endl;
				++j;
			}
			else if (vec[j + 1] == "5") {
				machineCode << "00101" << endl;
				++j;
			}
			else if (vec[j + 1] == "6") {
				machineCode << "00110" << endl;
				++j;
			}
			else if (vec[j + 1] == "7") {
				machineCode << "00111" << endl;
				++j;
			}
			else if (vec[j + 1] == "8") {
				machineCode << "01000" << endl;
				++j;
			}
			else if (vec[j + 1] == "9") {
				machineCode << "01001" << endl;
				++j;
			}
			else if (vec[j + 1] == "10") {
				machineCode << "01010" << endl;
				++j;
			}
			else if (vec[j + 1] == "11") {
				machineCode << "01011" << endl;
				++j;
			}
			else if (vec[j + 1] == "12") {
				machineCode << "01100" << endl;
				++j;
			}
			else if (vec[j + 1] == "13") {
				machineCode << "01101" << endl;
				++j;
			}
			else if (vec[j + 1] == "14") {
				machineCode << "01110" << endl;
				++j;
			}
			else if (vec[j + 1] == "15") {
				machineCode << "01111" << endl;
				++j;
			}
			else if (vec[j + 1] == "16") {
				machineCode << "10000" << endl;
				++j;
			}
			else if (vec[j + 1] == "17") {
				machineCode << "10001" << endl;
				++j;
			}
			else if (vec[j + 1] == "18") {
				machineCode << "10010" << endl;
				++j;
			}
			else if (vec[j + 1] == "19") {
				machineCode << "10011" << endl;
				++j;
			}
			else if (vec[j + 1] == "20") {
				machineCode << "10100" << endl;
				++j;
			}
			else if (vec[j + 1] == "21") {
				machineCode << "10101" << endl;
				++j;
			}
			else if (vec[j + 1] == "22") {
				machineCode << "10110" << endl;
				++j;
			}
			else if (vec[j + 1] == "23") {
				machineCode << "10111" << endl;
				++j;
			}
			else if (vec[j + 1] == "24") {
				machineCode << "11000" << endl;
				++j;
			}
			else if (vec[j + 1] == "25") {
				machineCode << "11001" << endl;
				++j;
			}
			else if (vec[j + 1] == "26") {
				machineCode << "11010" << endl;
				++j;
			}
			else if (vec[j + 1] == "27") {
				machineCode << "11011" << endl;
				++j;
			}
			else if (vec[j + 1] == "28") {
				machineCode << "11100" << endl;
				++j;
			}
			else if (vec[j + 1] == "29") {
				machineCode << "11101" << endl;
				++j;
			}
			else if (vec[j + 1] == "30") {
				machineCode << "11110" << endl;
				++j;
			}
			else if (vec[j + 1] == "31") {
				machineCode << "11111" << endl;
				++j;
			}

		}
		else if (vec[j] == "JUMP") {
			machineCode << "10";
			machineCode << "11";
			i=0;
			while (i < labels.size() && (labels[i] != vec[j+1])) {
				i++;
			};
			switch (i) {
			case 0:
				machineCode << "00000" << endl;
				break;
			case 1:
				machineCode << "00001" << endl;
				break;
			case 2:
				machineCode << "00010" << endl;
				break;
			case 3:
				machineCode << "00011" << endl;
				break;
			case 4:
				machineCode << "00100" << endl;
				break;
			case 5:
				machineCode << "00101" << endl;
				break;
			case 6:
				machineCode << "00110" << endl;
				break;
			case 7:
				machineCode << "00111" << endl;
				break;
			default:
				machineCode << "00000" << endl;
				break;
			}
			++j;

			// Now checking for TYPE 4 instructions (11)     ################################
			// FORMAT: TYPE (2 bits), OPCODE (1 bit), IMMED (3 bits, highest immed = 7), REG (3 bits)
		}
		else if (vec[j] == "LSR") {
			machineCode << "11";
			machineCode << "0";

			// check for immediate
			// then check for reg
			if (vec[j + 1] == "0") {
				machineCode << "000";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "1") {
				machineCode << "001";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2]=="$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "2") {
				machineCode << "010";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] =="$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "3") {
				machineCode << "011";

				if (vec[j + 2] == "$ZERO" || vec[j + 2]== "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2]=="$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "4") {
				machineCode << "100";

				if (vec[j + 2] == "$ZERO" || vec[j + 2]=="$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "5") {
				machineCode << "101";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "6") {
				machineCode << "110";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "7") {
				machineCode << "111";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}

		}
		else if (vec[j] == "RSR") {
			machineCode << "11";
			machineCode << "1";

			// check for immediate
			// then check for reg
			if (vec[j + 1] == "0") {
				machineCode << "000";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;

			}
			else if (vec[j + 1] == "1") {
				machineCode << "001";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;

			}
			else if (vec[j + 1] == "2") {
				machineCode << "010";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;

			}
			else if (vec[j + 1] == "3") {
				machineCode << "011";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;

			}
			else if (vec[j + 1] == "4") {
				machineCode << "100";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "5") {
				machineCode << "101";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "6") {
				machineCode << "110";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
			else if (vec[j + 1] == "7") {
				machineCode << "111";

				if (vec[j + 2] == "$ZERO" || vec[j + 2] == "$R0") {
					machineCode << "000" << endl;
				}
				else if (vec[j + 2] == "$ACCU" || vec[j + 2] == "$R1") {
					machineCode << "001" << endl;
				}
				else if (vec[j + 2] == "$R2") {
					machineCode << "010" << endl;
				}
				else if (vec[j + 2] == "$R3") {
					machineCode << "011" << endl;
				}
				else if (vec[j + 2] == "$R4") {
					machineCode << "100" << endl;
				}
				else if (vec[j + 2] == "$R5") {
					machineCode << "101" << endl;
				}
				else if (vec[j + 2] == "$R6") {
					machineCode << "110" << endl;
				}
				else if (vec[j + 2] == "$R7") {
					machineCode << "111" << endl;
				}

				j = j + 2;
			}
		}
		else{
			// code below used for debugging purposes

			//cout << "label encountered: " << vec[j].substr(0, (vec[j].length() - 1)) << " before: " << vec[j - 1] << " after: " << vec[j + 1] << endl;
		}


	}


	


	machineCode.close();
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

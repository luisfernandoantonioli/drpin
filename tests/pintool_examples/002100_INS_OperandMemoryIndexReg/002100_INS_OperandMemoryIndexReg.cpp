#include "pin.H"
#include <iostream>
#include <fstream>

ADDRINT first_ins_addr;

int seen = 0;
VOID Instruction(INS ins, VOID *v)
{
  if(seen < 30){
      seen ++;
      std::cout << "Dissassemble: " << INS_Disassemble(ins) << std::endl << std::flush;
      UINT32 number_of_operands = INS_OperandCount(ins);
      std::cout << "Number of operands: " << number_of_operands << std::endl;
      for (UINT32 i = 0; i < number_of_operands; i++){
          /* std::cout << "Operand_" << i << " = " << (INS_OperandIsReg(ins, i) ? "REG: " : "Not REG: ") << INS_OperandReg(ins, i)  << " (" << REG_StringShort(INS_OperandReg(ins, i)) << (INS_OperandIsMemory(ins, i) ? " [ MEMORY ] " : "") << ")" << (INS_OperandRead(ins, i) ? (" (READ) | ") : " (WRITE) | "); */
          std::cout << "Operand_" << i << " = " << REG_StringShort(INS_OperandMemoryIndexReg(ins, i)) << " | " ;
      }
      std::cout << std::endl << std::endl << std::flush;
  }
}

int main(int argc, char *argv[])
{
    if( PIN_Init(argc,argv) )
    {
        std::cout << "initialization invalid" << std::endl;
    }

    INS_AddInstrumentFunction(Instruction, 0);



    PIN_StartProgram();

    return 0;
}


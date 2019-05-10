%{
  /*_____Definition section_____literal c++ code between single "%"_____*/

  /*Necesary imports*/
    #include <stdio.h>
    #include <iostream>
    #include <string.h>
    #include <bitset>
    #include <vector>
    #include <map>
    #include <stdlib.h>
    #include <algorithm>
    #include <cstdlib>
    #include <fstream>
    #include <list>

    

    //C++ definitions
    std::fstream fs; //stream instruction file
    std::string final_message="Compiler success";
    int memCount=0; // memory instruction count initialized
    std::string line;

    int yylex();  //call to invoke lexer, returns token
    extern int yylineno; //line number counter

    /*Define different ARM instructions structures*/
    void encondig_instruccion(std::string op,std::string rs,std::string rs2,std::string rd); // op rs,rs2,rd
    void encondig_instruccion1(std::string op,std::string rs,std::string rd,std::string immen); //op rs,rd,immen
    void encondig_instruccion2(std::string op,std::string rs,std::string rd); // op rs,rd
    void encondig_instruccion3(std::string op,std::string rs,std::string imme); //op rs,immen
    void encondig_instruccion4(std::string op,std::string rd,std::string rs,std::string rs2,int type); //op rd,rs,rs2,type
    void encondig_instruccion5(std::string op,std::string immen); //op rs,immen
    
    /*Other definitions*/
    std::string regtobin(std::string r); // parse register to binary data
    std::string immtobin(std::string in,int type,std::string rs); // parse immediate to binary
    int text_memory=0x00000000; //memory reference start for text
    bool repeat_flag=false; //flag to know if repeat instruction
    std::list <std::string> instlist; //list of instructions to repeat
    void yyerror(std::string S); // define error function

%}

%union{
  char* id;
  int num;
} // structure to make the id and number relationship

/*lex tokens*/
%token <id> addition subtra multiple comp load store mv xorop circularleft circularright linealleft linealright brepeat erepeat//instructions
%token <id> reg // register
%token <id> immediate //immediate
%token <id> commentary //commentary
%token <num> number //number

/*yacc tokens*/
%type <id> operation

%%
line   : line instruccion '\n'
       | line commentary '\n'
       | /* NULL */
      ;

instruccion : operation reg ',' reg {encondig_instruccion2($1,$2,$4);}
            | operation reg ',' immediate {encondig_instruccion3($1,$2,$4);}
            | operation reg ',' reg ',' immediate {encondig_instruccion1($1,$4,$2,$6);}
            | operation reg ',' '[' reg ']' {encondig_instruccion4($1,$2,$5,"",1);}
            | operation reg ',' '[' reg ',' immediate ']' {encondig_instruccion4($1,$2,$5,$7,3);}
            | operation reg ',' reg ',' reg {encondig_instruccion($1,$2,$4,$6);}
            | operation immediate {encondig_instruccion5($1,$2);}
            | instruccion commentary {;}
            | error {yyerror("instruccion not supported");}
            ;


operation : addition     {;}
          | subtra       {;}
          | multiple     {;}
          | comp         {;}
          | store        {;}
          | load         {;}
          | mv           {;}
          | xorop        {;}
          | circularleft {;}
          | circularright {;}
          | linealleft   {;}
          | linealright  {;}
          | brepeat      {;}
          | erepeat      {;}
          ;
 
%%

extern int yyparse();
extern FILE *yyin; //file used as input
std::string ruta=""; //where the file to read is located

//Instruccion op rd,rs,rm
void encondig_instruccion(std::string op,std::string rs,std::string rs2,std::string rd){
  std::string binIns="0000"; //Condition always
  text_memory+=0x4; // incrementa contador de instrucciones en 4 debido a la alineacion
  if(op.compare("Add")==0 || op.compare("ADD")==0 || op.compare("add")==0){
    binIns+="0001"; // Op code for add
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    binIns+="0010"; // Op code for sub
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("Mul")==0 || op.compare("MUL")==0 || op.compare("mul")==0){
    binIns+="0011"; // Op code for mul
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Xor")==0 || op.compare("XOR")==0 || op.compare("xor")==0){
    binIns+="0000"; // Op code for xor
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: Format mnemonic R,R,R only support Add,Sub,Mult,Xor"<<'\n';
  }
}

//intruccion  op rd,rs,#imme
void encondig_instruccion1(std::string op,std::string rs,std::string rd,std::string immen){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("Add")==0 || op.compare("ADD")==0 || op.compare("add")==0){

    binIns+="0001"; // Op code for add
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    binIns+="0010"; // Op code for add
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("Mul")==0 || op.compare("MUL")==0 || op.compare("mul")==0){
    binIns+="0011"; // Op code for mul
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Xor")==0 || op.compare("XOR")==0 || op.compare("xor")==0){
    binIns+="0000"; // Op code for xor
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R,Imm only support cmp,mov,up"<<'\n';
  }
}

//Instruccion op rd,rs
void encondig_instruccion2(std::string op,std::string rs,std::string rd){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="0100"; // Op code for cmp
    binIns+="0000000000000000"; // empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="0101"; // Op code for cmp
    binIns+="0000000000000000"; // empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R only support cmp,mov"<<'\n';
  }
}

//Instruccion op rd,#imme
void encondig_instruccion3(std::string op,std::string rs,std::string imme){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="0100";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="0101";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("csl")==0 || op.compare("CSL")==0 || op.compare("Csl")==0){
    binIns+="0110";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("csr")==0 || op.compare("CSR")==0 || op.compare("Csr")==0){
    binIns+="0111";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }
  else if(op.compare("lsl")==0 || op.compare("LSL")==0 || op.compare("Lsl")==0){
    binIns+="1000";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }
  else if(op.compare("lsr")==0 || op.compare("LSR")==0 || op.compare("Lsr")==0){
    binIns+="1001";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,Imm only support cmp,mov and shifts"<<'\n';
  }
}

//intruccion op rd,[rs,rm]
//op rd,[rs,#imme] (post index and offset)
void encondig_instruccion4(std::string op,std::string rd,std::string rs,std::string rs2,int type){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("ldr")==0 || op.compare("Ldr")==0 || op.compare("LDR")==0){
    if(type==1){ //op rd,[r]
      binIns+="1010";
      binIns+="0100000000000000"; // empty bits if necessary
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      if(!repeat_flag){
        fs<<binIns<<'\n';
      }
      else{
        instlist.push_back(binIns);
      }
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){ //neg imm
        binIns+="1010";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }else{ //pos imm
        rs2.erase(1,1);
        binIns+="1010";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }
    }
  }else if(op.compare("str")==0 || op.compare("Str")==0 || op.compare("STR")==0){
    if(type==1){ //op rd,[r]
      binIns+="1011";
      binIns+="0100000000000000"; // empty bits if necessary
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      if(!repeat_flag){
        fs<<binIns<<'\n';
      }
      else{
        instlist.push_back(binIns);
      }
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){
        binIns+="1011";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }else{
        rs2.erase(1,1);
        binIns+="1011";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }
    }
  }
  else{
    std::cout<< "Error at store/read instruccion: not supported instruction"<<'\n';
  }
}

//Instruccion op #imme
void encondig_instruccion5(std::string op,std::string imme){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("brt")==0 || op.compare("BRT")==0 || op.compare("Brt")==0){
    repeat_flag = true;
  }
  else if(op.compare("ert")==0 || op.compare("ERT")==0 || op.compare("Ert")==0){
    repeat_flag = false;
    std::string str1= imme.substr(1);
    int imm = std::stoi(str1);
    for(int i = 0 ; i < imm ; i++){
      std::list <std::string> templist = instlist; 
      int size = templist.size();
      for(int j = 0 ; j < size; j++){
        text_memory+=0x4;
        std::string temp1 = templist.front();
        templist.pop_front();
        fs<<temp1<<'\n';
      }
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic Imm only support repeat operation"<<'\n';
  }
}

//Conversion del numero de registro a binario
std::string regtobin(std::string r){
  r.erase(0,1); //erase 'r'
  std::string bin=std::bitset<4>(atoi(r.c_str())).to_string(); //set 4 bits for number of 'r'
  return bin;
}

//Se guarda el inmediato en binario
//Type= De que tamaño sera el inmediato
std::string immtobin(std::string in,int type,std::string rs){
  in.erase(0,1);
  int x=0;
  if(in.find("0x")==std::string::npos){
    x=strtol(in.c_str(),NULL,10);
  }else{
    x=strtol(in.c_str(),NULL,16);
  }
  if(type==1){
    if(x<4096){
      std::string bin=std::bitset<8>(x).to_string();
      return bin;
    }
  }
}

void yyerror(std::string S){
  final_message="Compiler failed";
  std::cout << S <<" at line: "<<yylineno<<'\n';
  yyclearin;
  exit(0);
}

int main(void) {

  std::cout<<"Ruta del archivo a compilar"<<'\n';
  fs.open ("text_out.txt", std::ios::out | std::ios::trunc); //Intrucciones
  std::cin>>ruta;
  FILE *myfile = fopen(ruta.c_str(), "r");

	//se verifica si es valido
	if (!myfile) {
		std::cout << "No es posible abrir el archivo" << std::endl;
		return -1;
	}

	yyin = myfile;
	do {
		yyparse(); // start yacc
	} while (!feof(yyin)); //condition of finish
  

  fs.close();
  std::cout<<final_message<<'\n';
  for(int i=0;i<100;++i);
}

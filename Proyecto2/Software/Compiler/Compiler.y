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

    

    //C++ definitions
    std::map<std::string,int> labels; //labels and values
    std::map<std::string,int> futureLabels; //if found a label before declaration
    std::fstream fs; //stream instruction file
    std::fstream fs2; // stream data file
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
    void encondig_instruccion4(std::string op,std::string rs,std::string tag); //op rs,tag
    void encondig_instruccion6(std::string op,std::string rd,std::string rs,std::string rs2,int type); //op rd,rs,rs2,type
    void encondig_instruccion7(std::string op,std::string rd,std::string rs,std::string rs2); //op rd,rs,rs2
    
    /*Other definitions*/
    std::string regtobin(std::string r); // parse register to binary data
    int indexOf(std::string tag); //get the index of tag
    std::string immtobin(std::string in,int type,std::string rs); // parse immediate to binary
    void procces_label(std::string tag,std::string g,int type);
    void variablestobin(int val); // parse variables to binary
    std::string current_type="DCD"; //define by default word aligment
    int data_memory=0x10000000; //memory reference start for data
    int text_memory=0x00000000; //memory reference start for text
    void yyerror(std::string S); // define error function
    void printt(std::string s); //Define print function

%}

%union{
  char* id;
  int num;
} // structure to make the id and number relationship

/*lex tokens*/
%token <id> addition subtra multiple comp load store mv xorop //instructions
%token <id> dcb dcw dcd // data types
%token <id> reg // register
%token <id> immediate //immediate
%token <id> label //label
%token <id> commentary //commentary
%token <num> number //number

/*yacc tokens*/
%type <id> operation val_type

%%
line   : line variable '\n'
       | line instruccion '\n'
       | line label '\n'  {procces_label($2,"",1);}
       | line label instruccion '\n'  {procces_label($2,"",1);}
       | line commentary '\n'
       | line label commentary '\n'  {procces_label($2,"",1);}
       | line variable commentary '\n'
       | /* NULL */
      ;

instruccion : operation reg ',' reg {encondig_instruccion2($1,$4,$2);}
            | operation reg ',' immediate {encondig_instruccion3($1,$2,$4);}
            | operation reg ',' '=' label  {encondig_instruccion4($1,$2,$5);}
            | operation reg ',' reg ',' immediate {encondig_instruccion1($1,$4,$2,$6);}
            | operation reg ',' '[' reg ']' {encondig_instruccion6($1,$2,$5,"",1);}
            | operation reg ',' '[' reg ',' reg ']' {encondig_instruccion6($1,$2,$5,$7,2);}
            | operation reg ',' '[' reg ',' immediate ']' {encondig_instruccion6($1,$2,$5,$7,3);}
            | operation reg ',' '[' reg ']' ',' immediate {encondig_instruccion7($1,$2,$5,$8);}
            | operation reg ',' '[' reg ',' immediate ']' '!' {encondig_instruccion6($1,$2,$5,$7,4);}
            | operation reg ',' reg ',' reg {encondig_instruccion($1,$2,$4,$6);}
            | instruccion commentary {;}
            | error {yyerror("instruccion not supported");}
            ;

variable  : label val_type array {procces_label($1,$2,2);}
          ;
array     : number  {variablestobin($1);}
          | array ',' number {variablestobin($3);}

val_type  : dcb     {$$=$1;}
          | dcw   {$$=$1;}
          | dcd   {$$=$1;}
          ;

operation : addition     {;}
          | subtra       {;}
          | multiple     {;}
          | comp         {;}
          | store        {;}
          | load         {;}
          | mv           {;}
          | xorop        {;}
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
    /*binIns+="00001000"; // 00 , ImmediateOperand = 0, OP code add, COndition code = 0
    binIns+=regtobin(rs); // agrega binario de registro operando 1
    binIns+=regtobin(rd); // agrega binario de registro destino
    binIns+="00000000"; // bits no utilizados
    binIns+=regtobin(rs2); // agrega binario de registro operando 2*/
    fs<<binIns<<'\n'; // guarda en archivo de instrucciones
  }else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    /*binIns+="00000100"; // 00 , ImmediateOperand = 0, OP code sub, COndition code = 0
    binIns+=regtobin(rs);
    binIns+=regtobin(rd);
    binIns+="00000000";
    binIns+=regtobin(rs2);
    fs<<binIns<<'\n';*/
  }else if(op.compare("Mul")==0 || op.compare("MUL")==0 || op.compare("mul")==0){
    /*binIns+="00011100"; // 000000, A = 0, Conditional Code = 0
    binIns+=regtobin(rs); // agrega binario de registro operando 1
    binIns+=regtobin(rd); // agrega binario de registro destino
    binIns+="00000000"; // bits no utilizados
    binIns+=regtobin(rs2); // agrega binario de registro operando 2
    fs<<binIns<<'\n';*/
  }
  else if(op.compare("Xor")==0 || op.compare("XOR")==0 || op.compare("xor")==0){
    binIns+="0000"; // Op code for xor
    binIns+="000000000000"; // empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    fs<<binIns<<'\n';
  }
  else{
    std::cout<< "Error at read instruccion: Format mnemonic R,R,R only support Add,Sub,Mult"<<'\n';
  }
}

//Instruccion op rd,rs
void encondig_instruccion2(std::string op,std::string rs,std::string rd){
  std::string binIns="1110";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="00010101"; //Alter conditional codes
    binIns+=regtobin(rd);
    binIns+="000000000000";
    binIns+=regtobin(rs);
    fs<<binIns<<'\n';
  }else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="000110100000";
    binIns+=regtobin(rd);
    binIns+="00000000";
    binIns+=regtobin(rs);
    fs<<binIns<<'\n';
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R only support cmp,mov"<<'\n';
  }
}

//Instruccion op rd,#imme
void encondig_instruccion3(std::string op,std::string rs,std::string imme){
  std::string binIns="1110";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="00110101";
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+="0000";
    binIns+=immtobin(imme,1,r);
    fs<<binIns<<'\n';
  }
  else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="001110100000";
    std::string r=regtobin(rs);
    binIns+=r;
    std::string inm=immtobin(imme,4,r);
    binIns+=inm;
    if(inm.compare("nop")!=0){ // identifies nop for coding over  pipeline without risks
       fs<<binIns<<'\n'; 
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,Imm only support cmp,mov"<<'\n';
  }
}

//No implementadas correctamente, no realizan lo que deberian
void encondig_instruccion4(std::string op,std::string rs,std::string tag){
  std::string binIns="1110";
  text_memory+=0x4;
  if(op.compare("ldr")==0 || op.compare("Ldr")==0 || op.compare("LDR")==0){
    binIns+="010100010000";
    binIns+=regtobin(rs);
    int result=labels.find(tag)->second;
    binIns+=std::bitset<12>(result).to_string();
    fs<<binIns<<'\n';
  }else if(op.compare("str")==0 || op.compare("Str")==0 || op.compare("STR")==0){
    binIns+="010100000000";
    binIns+=regtobin(rs);
    int result=labels.find(tag)->second;
    binIns+=std::bitset<12>(result).to_string();
    fs<<binIns<<'\n';
  }else{
    std::cout<< "Error at read instruccion: No implementado"<<'\n';
  }
}

//intruccion op rd,[rs,rm]
//op rd,[rs,#imme] (post index and offset)
void encondig_instruccion6(std::string op,std::string rd,std::string rs,std::string rs2,int type){
  std::string binIns="111001";
  text_memory+=0x4;
  if(op.compare("ldr")==0 || op.compare("Ldr")==0 || op.compare("LDR")==0){
    if(type==1){ //op rd,[r]
      binIns+="111001";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+="000000000000";
      fs<<binIns<<'\n';
      /*fs<<"11100001101000000000000000000000"<<'\n'; //atasca pipe
      fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';*/
      //text_memory+=0xC;
    }else if(type==2){ //op rd,[r, r]
      binIns+="011001";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+="00000000";
      binIns+=regtobin(rs2);
      fs<<binIns<<'\n';
      /*fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      text_memory+=0xC;*/
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){ //neg imm
        binIns+="111001";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
        /*fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        text_memory+=0xC;*/
      }else{ //pos imm
        rs2.erase(1,1);
        binIns+="110001";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
        /*fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        text_memory+=0xC;*/
      }
    }else if(type==4){ //op rd,[r,imm]!
      if(rs2.find("-")==std::string::npos){ //neg imm
        binIns+="111011";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
        /*fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        text_memory+=0xC;*/
      }else{ // pos imm
        rs2.erase(1,1);
        binIns+="110011";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
        /*fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        fs<<"11100001101000000000000000000000"<<'\n';
        text_memory+=0xC;*/
      }
    }
  }else if(op.compare("str")==0 || op.compare("Str")==0 || op.compare("STR")==0){
    if(type==1){ //op rd,[r]
      binIns+="111000";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+="000000000000";
      fs<<binIns<<'\n';
    }else if(type==2){ //op rd,[r,r]
      binIns+="011000";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+="00000000";
      binIns+=regtobin(rs2);
      fs<<binIns<<'\n';
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){
        binIns+="111000";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
      }else{
        rs2.erase(1,1);
        binIns+="110000";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
      }
    }else if(type==4){ //op rd,[r,imm]!
      if(rs2.find("-")==std::string::npos){
        binIns+="111010";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
      }else{
        rs2.erase(1,1);
        binIns+="110010";
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,2,"");
        fs<<binIns<<'\n';
      }
    }
  }
  else{
    std::cout<< "Error at read instruccion: not supported instruction"<<'\n';
  }
}

//Instruccion op rd,[rs],#imme (post index)
void encondig_instruccion7(std::string op,std::string rd,std::string rs,std::string rs2){
  std::string binIns="111001";
  text_memory+=0x4;
  if(op.compare("ldr")==0 || op.compare("Ldr")==0 || op.compare("LDR")==0){
    if(rs2.find("-")==std::string::npos){ //neg imm
      binIns+="101001";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+=immtobin(rs2,2,"");
      fs<<binIns<<'\n';
      /*fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      text_memory+=0xC;*/
    }else{ //pos imm
      rs2.erase(1,1);
      binIns+="100001";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+=immtobin(rs2,2,"");
      fs<<binIns<<'\n';
      /*fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      fs<<"11100001101000000000000000000000"<<'\n';
      text_memory+=0xC;*/
    }
  }else if(op.compare("str")==0 || op.compare("Str")==0 || op.compare("STR")==0){
    if(rs2.find("-")==std::string::npos){
      binIns+="101000";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+=immtobin(rs2,2,"");
      fs<<binIns<<'\n';
    }else{
      rs2.erase(1,1);
      binIns+="100000";
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      binIns+=immtobin(rs2,2,"");
      fs<<binIns<<'\n';
    }
  }
  else{
    std::cout<< "Error at read instruccion: not supported instruction"<<'\n';
  }
}

//intruccion  op rd,rs,#imme
void encondig_instruccion1(std::string op,std::string rs,std::string rd,std::string immen){
  std::string binIns="1110";
  text_memory+=0x4;
  if(op.compare("Add")==0 || op.compare("ADD")==0 || op.compare("add")==0){
    binIns+="00101000";
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=regtobin(rd);
    binIns+=immtobin(immen,1,r);
    fs<<binIns<<'\n';
  }
  else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    binIns+="00100100";
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=regtobin(rd);
    binIns+=immtobin(immen,1,r);
    fs<<binIns<<'\n';
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R,Imm only support cmp,mov,up"<<'\n';
  }
}

//Conversion del numero de registro a binario
std::string regtobin(std::string r){
  r.erase(0,1); //erase 'r'
  std::string bin=std::bitset<4>(atoi(r.c_str())).to_string(); //set 4 bits for number of 'r'
  return bin;
}

void variablestobin(int val){
  if(current_type.compare("DCB")==0){ 
    std::string bin=std::bitset<8>(val).to_string(); // assign 8 bits to val
    if(memCount>2){
      memCount=0; // set mem reference iterator to 0
      fs2<<bin<<'\n'; // write to data file
    }else{
      memCount++; // increment count  
      fs2<<bin; // write to data file
    }
  }else if(current_type.compare("DCW")==0){
    std::string bin=std::bitset<16>(val).to_string(); // assign 16 bits to val
    if(memCount>1){
      memCount=0;
      fs2<<bin<<'\n';
    }else{
      memCount++;
      fs2<<bin;
    }
  }else if(current_type.compare("DCD")==0){
    std::string bin=std::bitset<32>(val).to_string(); // assign 32 bits to val 
    fs2<<bin<<'\n';
  }
}

void procces_label(std::string tag,std::string g,int type){
  int tmp=futureLabels.find(tag)->second; // is there any label that havent been declared
  if(tmp > 0){ 
    int tposition=fs.tellp();
    int result=0x8+(0x4*tmp/33); // form of calc label dir.
    result=(text_memory-result)/4;
    fs.seekp(tmp+8);
    fs<<std::bitset<24>(result).to_string();
    fs.seekp(tposition);
  }

  if(type==1){ //get val
    labels[tag]=text_memory; //label val
  }else if(type==2){ // set val
    current_type=g; // set data type for correct alignment
    labels[tag]=data_memory;
  }
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
      std::string bin=std::bitset<12>(x).to_string();
      return bin;
    }else{
      while(x>4096){
        x=x-4095;
        std::string ins="111000101000";
        ins+=rs;
        ins+=rs;
        ins+="111111111111";
        fs<<ins<<'\n';
        text_memory+=0x4;
      }
      std::string bin=std::bitset<12>(x).to_string();
      return bin;
    }
  }else if(type==2){
    std::string bin=std::bitset<12>(x).to_string();
    return bin;
  }else if(type==3){
    std::string bin=std::bitset<24>(x).to_string();
    return bin;
  }else if(type==4){
    if(x<4096){
      std::string bin=std::bitset<12>(x).to_string();
      return bin;
    }else{
      x=x-4095;
      std::string ins="1110001110100000";
      ins+=rs;
      ins+="111111111111";
      fs<<ins<<'\n';
      while(x>4096){
        x=x-4095;
        ins="111000101000";
        ins+=rs;
        ins+=rs;
        ins+="111111111111";
        fs<<ins<<'\n';
        text_memory+=0x4;
      }
      ins="111000101000";
      ins+=rs;
      ins+=rs;
      ins+=std::bitset<12>(x).to_string();
      fs<<ins<<'\n';
      std::string bin="nop";
      return "nop";
    }
  }
}

void printt(std::string s){
  std::cout << s << std::endl;
}

void yyerror(std::string S){
  final_message="Compiler failed";
  std::cout << S <<" at line: "<<yylineno<<'\n';
  yyclearin;
  exit(0);
}

int bin2decimal(int data) {
  int output = 0;
  int m = 1;
  for (int i = 0; data > 0; i++) {
    if (data % 10 == 1) {
      output += m;
    }
    data /= 10;
    m <<= 1;
  }
  return output;
}

std::string binary2hex(int data) {
  int binnum = bin2decimal(data);
  long int rem, quot;
  int i = 1, j, temp;
  char hexdecnum[100];
  std::string result = "";
  quot = binnum;
  while (quot != 0) {
    temp = quot % 16;
    if (temp < 10) {
      temp = temp + 48;
    } else {
      temp = temp + 55;
    }
    hexdecnum[i++] = temp;
    quot = quot / 16;
  }
  for (j = i - 1; j > 0; j--) {
    std::cout << hexdecnum[j];
    result = result + hexdecnum[j];
  }
  return result;

}

int main(void) {

  std::cout<<"Ruta del archivo a compilar"<<'\n';
  fs.open ("text_out.txt", std::ios::out | std::ios::trunc); //Intrucciones
  fs2.open ("data_out.txt", std::ios::out | std::ios::trunc); //Datos
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
  fs2.close();
  std::cout<<final_message<<'\n';
  for(int i=0;i<100;++i);
}

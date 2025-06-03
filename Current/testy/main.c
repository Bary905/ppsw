/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"

void TestOf_CopyString(void){
    
  char cString1[] = "Test poprawnosci kopiowania";
  char cString2[25] = "";

  printf("CopyString\n\n ");
  
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie kopiuje
  CopyString(cString1, cString2);
  if (eCompareString(cString2, cString1) == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
  
}

void TestOf_eCompareString(void){
    
}

void TestOf_AppendString(void){
    
}

void TestOf_ReplaceCharactersInString(void){
    
}

void TestOf_UIntToHexStr(void){
    
}

void TestOf_eHexStringToUInt(void){
    
}

void TestOf_AppendUIntToString(void){
    
}

void TestOf_ucFindTokensInString(void){
    
}

void TestOf_eStringToKeyword(void){
    
}

void TestOf_DecodeTokens(void){
    
}

void TestOf_DecodeMsg(void){
    
}
int main(void){
    
    printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n");
    
    TestOf_CopyString();
    TestOf_eCompareString();
    TestOf_AppendString();
    TestOf_ReplaceCharactersInString();
    TestOf_UIntToHexStr();
    TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();
    
    printf("TESTY FUNKCJI DO DEKODOWANIA KOMUNIKATÓW \n\n\n");
    
    TestOf_ucFindTokensInString();
    TestOf_eStringToKeyword();
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();
    
}

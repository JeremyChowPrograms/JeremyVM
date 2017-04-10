//
//  JeremyVM.hpp
//  JeremyVM
//
//  Created by Jeremy Chow on 10/25/16.
//  Copyright © 2016 Jeremy Chow. All rights reserved.
//

#ifndef JeremyVM_hpp
#define JeremyVM_hpp

#include <iostream>
#include <stdio.h>
#include <stack>

typedef int32_t  X32;

const X32 HALT = 0;
const X32 POP = 1;
const X32 PUSH = 2;
const X32 IADD = 3;
const X32 ISUB = 4;
const X32 IMUL = 5;
const X32 IDIV = 6;
const X32 PRINT = 7;
const X32 STORE = 8;
const X32 LOAD = 9;
const X32 CALL = 10;
const X32 RET = 11;
const X32 CMP = 12;
const X32 JNE = 13;
const X32 JE = 14;
const X32 MSTORE = 15;
const X32 JMP = 16;


class JeremyVM{
    int ip=0;
    int reta=-1;
    std::stack<X32> Memory;
    std::stack<X32> Stack;
    X32 *code;
    bool tof = false;
    int codesize;
public:
    JeremyVM(X32*program, int main, int codesize);
    ~JeremyVM();
    void run();
    
    
};
#endif /* JeremyVM_hpp */

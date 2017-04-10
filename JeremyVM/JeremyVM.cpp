//
//  JeremyVM.cpp
//  JeremyVM
//
//  Created by Jeremy Chow on 10/25/16.
//  Copyright © 2016 Jeremy Chow. All rights reserved.
//

#include "JeremyVM.hpp"


JeremyVM::JeremyVM(X32 *program, int main, int codesize):code(program),ip(main),codesize(codesize){
}
void JeremyVM::run(){
    while (ip<codesize) {
        X32 opcode = code[ip];
        //std::cout<<ip<<" "<<opcode<<std::endl;
        ip ++;
        X32 a, b, c, z;
    switch (opcode) {
        case HALT:
            return;
        case PUSH:
            Memory.push(code[ip]);
            ip++;
            break;
        case POP:
            Memory.pop();
            break;
        case PRINT:
            std::cout<<"stdout:"<<Memory.top()<<std::endl;
            break;
        case STORE:
            Stack.push(code[ip]);
            ip++;
            break;
        case LOAD:
            Memory.push(Stack.top());
            Stack.pop();
            break;
        case CALL:
            reta = ip+1;
            ip = code[ip];
            break;
        case IADD:
            a = Memory.top();
            Memory.pop();
            b = Memory.top();
            c = a +b;
            Memory.push(a);
            Memory.push(c);
            break;
        case ISUB:
            a = Memory.top();
            Memory.pop();
            b = Memory.top();
            c = a -b;
            Memory.push(a);
            Memory.push(c);
            break;
        case IMUL:
            a = Memory.top();
            Memory.pop();
            b = Memory.top();
            c = a *b;
            Memory.push(a);
            Memory.push(c);
            break;
        case IDIV:
            a = Memory.top();
            Memory.pop();
            b = Memory.top();
            c = a /b;
            Memory.push(a);
            Memory.push(c);
            break;
        case MSTORE:
            z=Memory.top();
            Memory.pop();
            Stack.push(z);
            break;
        case JE:
            if(tof){
                reta = ip +1;
                ip = code[ip];
            }else{
                ip++;
            }
            break;
        case JNE:
            if(!tof){
                reta = ip +1;
                ip = code[ip];
            }else{
                ip++;
            }
            break;
        case CMP:
            X32 t1, t2;
            t1 = Memory.top();
            Memory.pop();
            t2 = Memory.top();
            if (t1==t2) {
                tof = true;
            }else{
                tof = false;
            }
            Memory.push(t1);
            break;
        case RET:
            ip = reta;
            reta = -1;
            break;
        case JMP:
            
            reta = ip +1;
            ip = code[ip];
            break;
        default:
            break;
        }
    }
}
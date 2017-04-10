//
//  main.cpp
//  JeremyVM
//
//  Created by Jeremy Chow on 10/25/16.
//  Copyright © 2016 Jeremy Chow. All rights reserved.
//

#include "JeremyVM.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    if (argc!=2) {
        std::cout<<"JeremyVM\nBy Jeremy Chow"<<std::endl;
        return 0;
    }
    std::vector<X32> prog;
    
    FILE* fp = fopen(argv[1], "rb");
    if (fp==NULL) {
        std::cout<<"File not exist"<<std::endl;
        return 0;
    }
    X32 segc;
    X32 stp;
    fread(&stp, sizeof(X32), 1, fp);
    while (!feof(fp)) {
        fread(&segc, sizeof(X32), 1, fp);
        prog.push_back(segc);
    }
    X32 *prgrm = &prog[0];
    JeremyVM *jvm = new JeremyVM(prgrm, stp, prog.size());
    jvm->run();
    return 0;
}
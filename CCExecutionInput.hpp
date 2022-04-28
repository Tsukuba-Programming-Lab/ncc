//
//  CCExecutionInput.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CCExecutionInput_hpp
#define CCExecutionInput_hpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <array>
#include <fstream>
#include <unordered_map>

using namespace std;

struct CCExecutionInput {
    vector<string> args;
    string commandline;
    unordered_map<string, string> file_contents;
    
    CCExecutionInput(vector<string> _args);
private:
    void build_commandline(vector<string> args);
    void build_file_contents(vector<string> args);
    auto extract_cfiles(vector<string> args) -> vector<string>;
};

#endif /* CCExecutionInput_hpp */

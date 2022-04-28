//
//  CCExecutionInput.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCExecutionInput.hpp"
#include <iterator>

CCExecutionInput::CCExecutionInput(vector<string> _args) {
    this->args = _args;
    this->build_commandline(_args);
    this->build_file_contents(_args);
}

void CCExecutionInput::build_commandline(vector<string> args) {
    auto os = ostringstream();
    copy(args.begin(), args.end(), ostream_iterator<string>(os, " "));
    this->commandline = os.str();
}

void CCExecutionInput::build_file_contents(vector<string> args) {
    auto cfiles = extract_cfiles(args);
    for (auto cfile: cfiles) {
        auto ifs = ifstream(cfile);
        auto content = string(istreambuf_iterator(ifs), istreambuf_iterator<char>());
        this->file_contents[cfile] = content;
    }
}

auto CCExecutionInput::extract_cfiles(vector<string> args) -> vector<string> {
    vector<string> res;
    for (auto &e: args) {
        if (e.size() > 2 && e.substr(e.size()-2, 2) == ".c") res.push_back(e);
    }
    return res;
}

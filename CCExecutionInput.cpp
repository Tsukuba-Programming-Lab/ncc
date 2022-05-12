//
//  CCExecutionInput.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCExecutionInput.hpp"
#include <iterator>

CCExecutionInput::CCExecutionInput(vector<string> _args) {
    cout << __func__ << endl;
    this->args = _args;
    this->build_commandline(_args);
    this->build_file_contents(_args);
    cout << __func__ << endl;
}

void CCExecutionInput::build_commandline(vector<string> args) {
    cout << __func__ << endl;
    auto os = ostringstream();
    copy(args.begin(), args.end(), ostream_iterator<string>(os, " "));
    this->commandline = os.str();
    cout << __func__ << endl;
}

void CCExecutionInput::build_file_contents(vector<string> args) {
    cout << __func__ << endl;
    auto cfiles = extract_cfiles(args);
    for (auto cfile: cfiles) {
        auto ifs = ifstream(cfile);
        stringstream buffer;
        buffer << ifs.rdbuf();
        auto content = buffer.str();
        this->file_contents[cfile] = content;
    }
    cout << __func__ << endl;
}

auto CCExecutionInput::extract_cfiles(vector<string> args) -> vector<string> {
    cout << __func__ << endl;
    vector<string> res;
    for (auto &e: args) {
        if (e.size() > 2 && e.substr(e.size()-2, 2) == ".c") res.push_back(e);
    }
    cout << __func__ << endl;
    return res;
}

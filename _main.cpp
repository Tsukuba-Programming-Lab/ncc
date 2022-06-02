//
//  main.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

#include <unistd.h>
#include <string.h>

#include "CCCommand.hpp"
#include "CurlLogWriter.hpp"

using namespace std;

string get_username() {
    auto username = getenv("LOGNAME");
    if (username == NULL) {
        throw "User名が取得できませんでした。"s;
    } else {
        return string(username);
    }
}

int main(int argc, const char * argv[]) {
#if DEBUG
    vector<string> args = { "gcc", "/Users/yuki/Developer/Git/ncc/sample.c"s };
    auto writer = make_shared<CurlLogWriter>("https://cgi.u.tsukuba.ac.jp/~s1911399/main.py", get_username());
#else
    vector<string> args(argv, argv+argc);
    auto writer = make_shared<CurlLogWriter>("https://cgi.u.tsukuba.ac.jp/~yuki/sample/main.py", get_username());
#endif
    auto logger = make_shared<CCLogger>(writer);
    auto ncc = CCCommand(logger, CommandExecutor::shared());

    ncc.run(args);
}

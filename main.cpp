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

#include "CCCommand.hpp"
#include "CCConfigFactory.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
#if DEBUG
    vector<string> args = { "gcc", "/Users/yuki/Developer/Git/ncc/sample.c"s };
    auto logpath = "/Users/yuki/Desktop/ncc.log"s;
    auto config = CCConfigFactory::make_debug(logpath);
#else
    vector<string> args(argv, argv+argc);
    auto basepath = "/www/nakai.hisashi.gt/Lecture/Programming/log"s;
    cout << "error" << endl;
    auto config = CCConfigFactory::make_user(basepath);
    cout << "error" << endl;
#endif
    auto logger = make_shared<CCLogger>(config);
    auto ncc = CCCommand(config, logger, CommandExecutor::shared());
    
    ncc.run(args);
}

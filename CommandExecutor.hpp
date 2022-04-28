//
//  CommandExecutor.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CommandExecutor_hpp
#define CommandExecutor_hpp

#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <array>

#include "CommandResult.hpp"
#include "CommandError.hpp"

using namespace std;

class CommandExecutor {
public:
    static auto shared() -> shared_ptr<CommandExecutor>;
    auto execute(const string command, const vector<string> arguments) const -> shared_ptr<CommandResult>;
private:
    CommandExecutor();
    auto build_commandline(const string command, const vector<string> arguments) const -> string;
    auto read_pipe(const shared_ptr<FILE> pipe) const -> string;
};


#endif /* CommandExecutor_hpp */


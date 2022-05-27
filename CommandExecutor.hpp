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
    bool disable_stdout;
    static auto shared() -> shared_ptr<CommandExecutor>;
    static auto silent() -> shared_ptr<CommandExecutor>;
    
    CommandExecutor(bool _disable_stdout) : disable_stdout(_disable_stdout) {
        if (!system(nullptr)) throw CommandError::notAvailable();
    };
    
    auto execute(const string command, const vector<string> arguments) const -> shared_ptr<CommandResult>;
private:
    auto build_commandline(const string command, const vector<string> arguments) const -> string;
    auto read_pipe(const shared_ptr<FILE> pipe) const -> string;
};


#endif /* CommandExecutor_hpp */


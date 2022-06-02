//
//  CommandExecutor.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CommandExecutor.hpp"
#include <iterator>
#include <iostream>
#include <chrono>
#include <thread>

auto CommandExecutor::shared() -> shared_ptr<CommandExecutor> {
    static auto shared_instance = make_shared<CommandExecutor>(false);
    return shared_instance;
}

auto CommandExecutor::silent() -> shared_ptr<CommandExecutor> {
    static auto shared_instance = make_shared<CommandExecutor>(true);
    return shared_instance;
}

auto CommandExecutor::execute(const string command, const vector<string> arguments) const -> shared_ptr<CommandResult> {
    const auto commandline = this->build_commandline(command, arguments);
    auto exit_code = -1;
            
    auto pipe = shared_ptr<FILE>(popen(commandline.data(), "r"), [&exit_code](auto _) {
        exit_code = pclose(_);
    });
    
    if (!pipe) throw CommandError::childNotCreated();
    
    auto std_output = this->read_pipe(pipe);
        
    pipe.reset();
    if (exit_code > 0) {
        return CommandResult::failure(std_output, exit_code);
    } else {
        return CommandResult::success(std_output);
    }
}

auto CommandExecutor::read_pipe(const shared_ptr<FILE> pipe) const -> string {
    auto output = ""s;
    array<char, 256> buf;
    while (!feof(pipe.get())) if (fgets(buf.data(), buf.size(), pipe.get())) {
        if (!disable_stdout) cout << buf.data();
        output += buf.data();
    }
    return output;
}

auto CommandExecutor::build_commandline(const string command, const vector<string> arguments) const -> string {
    auto args = vector<string>();
    args.push_back(command);
    args.insert(args.end(), arguments.begin(), arguments.end());
    
    auto os = ostringstream();
    copy(args.begin(), args.end(), ostream_iterator<string>(os, " "));
    
    string command_line;
    for (auto s: args) {
        command_line += "\"";
        command_line += s;
        command_line += "\" ";
    }
    command_line += " 2>&1";
    return command_line;
}

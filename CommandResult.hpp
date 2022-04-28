//
//  CommandResult.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CommandResult_h
#define CommandResult_h

#include <memory>
#include <string>

struct CommandResult {
    enum class Kind {
        Success, Failure
    };
    Kind kind;
    int exit_code;
    std::string output;
    
    CommandResult(Kind _kind, int _exit_code, std::string _output) : kind(_kind), exit_code(_exit_code), output(_output) {}
    
    static auto success(std::string output) -> std::shared_ptr<CommandResult> {
        return std::make_shared<CommandResult>(Kind::Success, 0, output);
    }
    static auto failure(std::string output, int exit_code) -> std::shared_ptr<CommandResult> {
        return std::make_shared<CommandResult>(Kind::Failure, exit_code, output);
    }
};

#endif /* CommandResult_h */

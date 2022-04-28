//
//  CommandError.hpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#ifndef CommandError_hpp
#define CommandError_hpp

#include <string>
#include <iostream>

struct CommandError {
    enum class Kind  {
        NotAvailable,
        ChildNotCreated,
        UnkownTermination
    };
    Kind kind;
    std::string message;
    
    static auto notAvailable() -> CommandError {
        return CommandError{ Kind::NotAvailable, "A shell is not available on the system." };
    }
    static auto childNotCreated() -> CommandError {
        return CommandError{ Kind::ChildNotCreated, "A child process could not be created." };
    }
    static auto unkownTermination() -> CommandError {
        return CommandError{ Kind::UnkownTermination, "A child process terminated by unkown reason." };
    }
};


#endif /* CommandError_hpp */

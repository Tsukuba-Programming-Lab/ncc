//
//  NCCCommand.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCCommand.hpp"

CCCommand::CCCommand(shared_ptr<CCLogger> _logger, shared_ptr<CommandExecutor> _executor) {
    this->logger = _logger;
    this->executor = _executor;
}

void CCCommand::run(vector<string> const args) const {
    auto input = make_shared<CCExecutionInput>(args);
    this->logger->loginput(input);
    
    auto oargs = args; oargs.erase(oargs.begin());
    auto result = this->executor->execute("cc", oargs);
    this->logger->logresult(result);
    this->logger->close();
}

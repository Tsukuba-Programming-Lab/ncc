//
//  CCLogger.cpp
//  ncc
//
//  Created by yuki on 2022/04/21.
//

#include "CCLogger.hpp"

CCLogger::CCLogger(CCConfig config) {
    this->logfile = ofstream(config.log_path, ios::app);
    this->uuid = Uuid::newUuid().toString();
    
    log_separator("Bigin");
}

CCLogger::~CCLogger() {
    log_separator("End");
}

void CCLogger::loginput(shared_ptr<CCExecutionInput> input) {
    log_separator("Command");
    logfile << input->commandline << endl;
    for (auto file: input->file_contents) {
        log_separator(file.first);
        logfile << file.second << endl;
    }
}

void CCLogger::logresult(shared_ptr<CommandResult> result) {
    log_separator("Status");
    if (result->kind == CommandResult::Kind::Success) {
        logfile << "Success" << endl;
    } else {
        logfile << "Failure" << "(" << result->exit_code << ")" << endl;
    }
    log_separator("Output");
    logfile << result->output;
}

void CCLogger::log_separator(string name) {
    logfile << "-----ncc" << uuid << "-----" << endl;
    logfile << ":" << name << ":" << endl;
}

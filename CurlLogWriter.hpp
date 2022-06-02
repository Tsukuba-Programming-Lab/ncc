//
//  CurlLogWriter.hpp
//  ncc
//
//  Created by yuki on 2022/05/27.
//

#ifndef CurlLogWriter_hpp
#define CurlLogWriter_hpp

#include "StringWriter.hpp"
#include "CommandExecutor.hpp"
#include "base64.hpp"

#include <sstream>
#include <curl/curl.h>

struct CurlPostClient {
    static auto post(string url, string username, string log) -> shared_ptr<CommandResult> {
        auto data = "{\\\"logdata\\\": \\\""s + log + "\\\", \\\"user\\\": \\\"" + username + "\\\" }";
                
        auto res = CommandExecutor::silent()->execute("curl", {
            url,
            "-s",
            "-H", "Content-Type: application/json",
            "-d", data,
        });

        cout << res->output << endl;
        
        return res;
    }
};

class CurlLogWriter: public StringWriter {
private:
    string url;
    string username;
    
    stringstream buffer;
public:
    CurlLogWriter(string _url, string _username) : url(_url), username(_username) {}
    
    void write(string data) override {
        buffer << data;
    }
    
    void close() override {
        auto logdata = buffer.str();
        auto source = vector<unsigned char>(logdata.begin(), logdata.end());
        
        string elogdata; algorithm::encode_base64(source, elogdata);
        auto res = CurlPostClient::post(url, username, elogdata);
        
        if (res->kind != CommandResult::Kind::Success) {
            cout << "[ncc] Log Post error" << std::endl;
        }
    }
};


#endif /* CurlLogWriter_hpp */

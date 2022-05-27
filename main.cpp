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
#include <unistd.h>
#include <fstream>

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

struct Buffer {
    char *data;
    int data_size;
};

size_t buffer_writer(char *ptr, size_t size, size_t nmemb, void *stream) {
    struct Buffer *buf = (struct Buffer *)stream;
    int block = size * nmemb;
    if (!buf) {
        return block;
    }

    if (!buf->data) {
        buf->data = (char *)malloc(block);
    }
    else {
        buf->data = (char *)realloc(buf->data, buf->data_size + block);
    }

    if (buf->data) {
        memcpy(buf->data + buf->data_size, ptr, block);
        buf->data_size += block;
    }

    return block;
}

void get_qiita() {

    CURL *curl;
    struct Buffer *buf;

    buf = (struct Buffer *)malloc(sizeof(struct Buffer));
    buf->data = NULL;
    buf->data_size = 0;

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://qiita.com/");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, buffer_writer);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);


    printf("%s\n", buf->data);

    free(buf->data);
    free(buf);
}

int main(int argc, const char * argv[]) {
    
    get_qiita();
    
#if DEBUG
    vector<string> args = { "gcc", "/Users/yuki/Developer/Git/ncc/sample.c"s };
    auto logpath = "/Users/yuki/Desktop/ncc.log"s;
    auto writer = make_shared<CurlLogWriter>(true, get_username());
#else
    vector<string> args(argv, argv+argc);
    auto basepath = "/www/nakai.hisashi.gt/Lecture/Programming/log"s;
    auto config = CCConfigFactory::make_user(basepath);
#endif
    auto logger = make_shared<CCLogger>(writer);
    auto ncc = CCCommand(logger, CommandExecutor::shared());

    ncc.run(args);
}

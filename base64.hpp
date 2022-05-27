//
//  base64.hpp
//  ncc
//
//  Created by yuki on 2022/05/27.
//

#ifndef BASE64_HPP
#define BASE64_HPP

#include <string>
#include <vector>

namespace algorithm {
    bool encode_base64(const std::vector<unsigned char>& src, std::string& dst);
    bool decode_base64(const std::string& src, std::vector<unsigned char>& dst);
}


#endif

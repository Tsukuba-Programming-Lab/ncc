//
//  Guid.cpp
//  ncc
//
//  Created by yuki on 2022/04/28.
//

#include "uuid.hpp"

bool Uuid::isInit = false;
std::mt19937 Uuid::mt;
std::uniform_int_distribution<uint64_t> Uuid::range;

Uuid Uuid::newUuid()
{
    if (!isInit) // エンジン初期化
    {
        isInit = true;
        std::random_device rnd;
        mt = std::mt19937(rnd());
        range = std::uniform_int_distribution<uint64_t>(0x1000000000000000, 0xFFFFFFFFFFFFFFFF);
    }

    _TempU64 upper = gen();
    _TempU64 lower = gen();
    
    Uuid ret;
    ret.a = upper.b[0];
    ret.b = upper.c[2];
    ret.c = upper.c[3];
    for (int i = 0; i < 8; i++) ret.d[i] = lower.d[i];

    // ver.4 sign
    ret.c = ((ret.c & 0x0FFF) + 0x4000);
    // RFC4122 sign
    ret.d[0] = ((ret.d[0] & 0x3F) + 0x80);

    return ret;
}

std::string Uuid::toString()
{
    return toHex(this->a).append("-").append(toHex(this->b))
        .append("-").append(toHex(this->c)).append("-").append(toHex(this->d, 8));
}

std::array<unsigned char, 16> Uuid::toByte()
{
    _TempU64 upper;
    upper.b[0] = this->a;
    upper.c[2] = this->b;
    upper.c[3] = this->c;

    auto array = std::array<unsigned char, 16>();
    for (int i = 0; i < 8; i++) array[i] = upper.d[i];
    for (int i = 8; i < 16; i++) array[i] = this->d[i - 8];

    return array;
}

bool Uuid::operator==(const Uuid& a)
{
    return
        this->a == a.a &&
        this->b == a.b && this->c == a.c &&
        this->d[0] == a.d[0] && this->d[1] == a.d[1] && this->d[2] == a.d[2] && this->d[3] == a.d[3] &&
        this->d[4] == a.d[4] && this->d[5] == a.d[5] && this->d[6] == a.d[6] && this->d[7] == a.d[7];
}

bool Uuid::operator!=(const Uuid& a)
{
    return
        this->a != a.a ||
        this->b != a.b || this->c != a.c ||
        this->d[0] != a.d[0] || this->d[1] != a.d[1] || this->d[2] != a.d[2] || this->d[3] != a.d[3] ||
        this->d[4] != a.d[4] || this->d[5] != a.d[5] || this->d[6] != a.d[6] || this->d[7] != a.d[7];
}

Uuid::_TempU64 Uuid::gen()
{
    _TempU64 value;
    value.a = range(mt);
    return value;
}

std::string Uuid::toHex(unsigned char value[], size_t vsize)
{
    std::string str;
    for (int i = 0; i < vsize; i++) {
        str.append(toHex(value[i]));
    }
    return str;
}

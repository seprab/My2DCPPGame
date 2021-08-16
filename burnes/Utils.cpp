#include "Utils.h"

std::set<std::string> Utils::GenerateHash()
{
    const size_t N = 5;
    std::set<std::string> myHashTags;

    srand(time(0));
    while (myHashTags.size() < N)
        myHashTags.insert(generateHashTag());

    return myHashTags;
}

std::string Utils::generateHashTag() {
    char str[5];
    for (int i = 0; i < 4; ++i)
        str[i] = irand('a', 'z');
    str[4] = '\0';
    return std::string(str);
}

int Utils::irand(int min, int max) {
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}
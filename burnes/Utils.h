#pragma once

#include <string>
#include <set>
#include <time.h>

static class Utils
{
public:
	static std::set<std::string> GenerateHash();
	static std::string generateHashTag();
	static int irand(int min, int max);

};


#pragma once

#include <string>
#include <set>
#include <time.h>
#include <sstream>

static class Utils
{
public:
	static std::set<std::string> GenerateHash();
	static std::string generateHashTag();
	static int irand(int min, int max);
	static std::string to_string_with_precision(float a_value, const int n = 2);
};

#pragma once

#include <string>

#ifdef _WIN32
const char PATH_SEP = '\\';
#else
const char PATH_SEP = '/';
#endif

std::string getRootDirectory();

std::string getResourceDirectory();
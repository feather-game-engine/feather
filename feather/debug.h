#ifndef DEBUG_H
#define DEBUG_H
#include "core.h"

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

int Log(const char *message);
int Log(double number);

int Crash(const char *message);

#endif

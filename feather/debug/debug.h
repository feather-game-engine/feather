#pragma once

#ifdef LOG_TO_FILE
#include <fstream>
using stream = std::ofstream;
#else
#include <iostream>
using stream = std::ostream&;
#endif

namespace fl {

extern stream log;

} // namespace fl

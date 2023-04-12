#include "Feather/Debug/Debug.h"


namespace fl {
#ifdef LOG_TO_FILE
stream log("Log.txt");
#else
stream log = std::clog;
#endif
}

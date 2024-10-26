// Crossplatform Utilities For Everyone

#pragma once

// Crossplatform Console Check 
#include "framework.h"

#include <consoleapi3.h>

namespace almond
{
    inline bool isConsoleApplication() {
#ifdef _WIN32
    return GetConsoleWindow() != nullptr;
#else
    return isatty(fileno(stdout))
#endif

    }
}
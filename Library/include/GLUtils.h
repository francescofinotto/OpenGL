#pragma once
#include <functional>

namespace MyGL::Utils
{
    void DoAndLogError(std::function<void(void)> glFunction, std::string message = "");
} // namespace MyGL::Utils
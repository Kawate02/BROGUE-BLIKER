#pragma once
#include <string>
#include <windows.h> 
#include <memory>
#include <type_traits>
#include <utility>
#include "const.h"
#include "Point2D.h"

namespace BROGUE_BLIKER
{
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))

    std::wstring StringToWString(const std::string& str);

    std::string WStringToString(const std::wstring& wstr);
    const char* WCharToChar(const wchar_t* wstr);

    template <typename T>
    std::shared_ptr<std::decay_t<T>> MakeSharedFromInstance(T&& obj)
    {
        return std::make_shared<std::decay_t<T>>(std::forward<T>(obj));
    }
}
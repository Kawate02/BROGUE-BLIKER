#pragma once
#include <string>
#include <windows.h> 
#include <memory>
#include <type_traits>
#include "const.h"
#include "Point2D.h"

namespace BROGUE_BLIKER
{
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))

    std::wstring StringToWString(const std::string& str);

    std::string WStringToString(const std::wstring& wstr);
    const char* WCharToChar(const wchar_t* wstr);

    template <typename T>
    std::shared_ptr<T> MakeSharedFromInstance(T&& obj);
}
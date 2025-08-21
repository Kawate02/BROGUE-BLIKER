#include "Macro.h"

namespace BROGUE_BLIKER
{
    std::wstring BROGUE_BLIKER::StringToWString(const std::string& str)
    {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), NULL, 0);

        std::wstring wstr(size_needed, 0);

        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.size()), &wstr[0], size_needed);
        return wstr;
    }
    std::string WStringToString(const std::wstring& wstr)
    {
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), NULL, 0, NULL, NULL);

        std::string str(size_needed, 0);

        WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.size()), &str[0], size_needed, NULL, NULL);
        return str;
    }
    const char* WCharToChar(const wchar_t* wstr)
    {
        char buffer[256];
        WideCharToMultiByte(CP_UTF8, 0, wstr, -1, buffer, sizeof(buffer), NULL, NULL);
        const char* multiByteStr = buffer;
        return multiByteStr;
	}
	template <typename T>
	std::shared_ptr<T> MakeSharedFromInstance(T&& obj) //Todo 
	{
		return std::make_shared<std::decay_t<T>>(std::forward<T>(obj));
	}
}

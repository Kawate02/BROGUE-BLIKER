#pragma once

#include "resource.h"
#include "framework.h"
#include "EntryPoint.h"

#include <future>

#include <windows.h>
#include <stdio.h>

#include "const.h"

#if defined(_DEBUG) || defined(DEBUG)
// Debug‚Ì‚Æ‚«
#define ASSERT(x) \
	if (!(x)) { \
		MyOutputDebugString("Assertion failed! in %s (%d)\n", \
			__FILE__, __LINE__); \
		DebugBreak(); \
	}
#define VERIFY(x)   ASSERT(x)
#else
// Release‚Ì‚Æ‚«
#define ASSERT(x)
#define VERIFY(x)   x
#endif
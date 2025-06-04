#pragma once

namespace BROGUE_BLIKER
{
#define WINDOW_WIDTH    700
#define WINDOW_HEIGHT	500
#define WIDTH_CENTER    WINDOW_WIDTH / 2
#define HEIGHT_CENTER   WINDOW_HEIGHT / 2
#define BIT_COLOR_SIZE  32

#define UNIT unsigned int

	enum BlendMode
	{
		DEFAULT = 0,
		ALPHA_BLEND
	};
	enum Error
	{
		NULL_REFARENCE = 0x00,
		EXCLUDED_VALUE
	};
}
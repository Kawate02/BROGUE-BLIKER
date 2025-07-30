#pragma once
#include "EffectBase.h"

namespace BROGUE_BLIKER
{
	class TempBoost : public EffectForBall
	{
	public:
		TempBoost();
		void OnAddEffect(Ball* ball) override;
		void OnUpdate(int crrentTime, Ball* ball) override;
	};
}
#pragma once
#include "EffectBase.h"

namespace BROGUE_BLIKER
{
	class HyperBound : public EffectForBar
	{
	public:
		HyperBound();
		void OnHitBallToBar(Ball* ball, Bar* bar) override;
		void OnUpdate(int crrentTime, Bar* object) override;
	};
}
#include "HyperBound.h"
#include "Ball.h"
#include "Bar.h"

namespace BROGUE_BLIKER
{
	HyperBound::HyperBound() : EffectForBar()
	{
	}
	void HyperBound::OnHitBallToBar(Ball* ball, Bar* bar)
	{
		effectAppliedFrame = -1;
		ball->AddEffect(&tempBoost);
	}
	void HyperBound::OnUpdate(int crrentTime, Bar* object)
	{
		if (effectAppliedFrame == -1)
		{
			effectAppliedFrame = crrentTime;
		}
	}
}

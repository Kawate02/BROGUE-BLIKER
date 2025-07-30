#include "TempBoost.h"
#include "Ball.h"

namespace BROGUE_BLIKER
{
	TempBoost::TempBoost() : EffectForBall()
	{
	}
	void TempBoost::OnAddEffect(Ball* ball)
	{
		effectAppliedFrame = -1;
		ball->SetSpeed(ball->base_speed * 2);
	}
	void TempBoost::OnUpdate(int crrentTime, Ball* ball)
	{
		if (effectAppliedFrame == -1)
		{
			effectAppliedFrame = crrentTime;
		}
		if (ball->GetSpeed() > ball->base_speed)
		{
			ball->SetSpeed(ball->GetSpeed() - 0.1f);
		}
	}
}
#pragma once

namespace BROGUE_BLIKER
{
	class Ball;
	class Bar;
	class Block;

	class EffectForBar
	{
	protected:
		int effectAppliedFrame = -1;
	public:
		EffectForBar() {}
		virtual void OnAddEffect(Bar* object) {}
		virtual void OnUpdate(int crrentTime, Bar* object) {}
		virtual void OnRemoveEffect(Bar* object) {}
		virtual void OnHitBallToBar(Ball* ball, Bar* bar) {}
		virtual void OnEraseBall(Ball* ball) {}
		virtual void OnMove(int crrentTime, Bar* bar) {}
	};

	class EffectForBall
	{
	protected:
		int effectAppliedFrame = -1;
	public:
		EffectForBall() {}
		virtual void OnAddEffect(Ball* object) {}
		virtual void OnUpdate(int crrentTime, Ball* object) {}
		virtual void OnRemoveEffect(Ball* object) {}
		virtual void OnHitBallToBlock(Ball* ball, Block* block) {}
		virtual void OnHitBallToBar(Ball* ball, Bar* bar) {}
		virtual void OnEraseBall(Ball* ball) {}
		virtual void OnMove(int crrentTime, Ball* ball) {}
	};

	class EffectForBlock
	{
	protected:
		int effectAppliedFrame = -1;
	public:
		EffectForBlock() {}
		virtual void OnAddEffect(Block* object) {}
		virtual void OnUpdate(int crrentTime, Block* object) {}
		virtual void OnRemoveEffect(Block* object) {}
		virtual void OnHitBallToBlock(Ball* ball, Block* block) {}
		virtual void OnEraseBall(Ball* ball) {}
		virtual void OnBreak(int crrentTime, Block* block) {}
	};
}
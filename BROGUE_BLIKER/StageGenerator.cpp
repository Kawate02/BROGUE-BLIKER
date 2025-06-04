#include "StageGenerator.h"

namespace BROGUE_BLIKER
{
	TestStage teststage;
	Stage* GenerateStage(Stage::StageId id)
	{
		switch (id)
		{
		case Stage::StageId::TEST:
			teststage.GenerateStage();
			return &teststage;
		default:
			teststage.GenerateStage();
			return &teststage;
		}
	}
}

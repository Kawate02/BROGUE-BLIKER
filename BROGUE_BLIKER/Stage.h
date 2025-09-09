#pragma once
#include "ViewModel.h"
#include "Block.h"
#include "Bar.h"
#include "Ball.h"

#include <string>
#include <vector>
 
namespace BROGUE_BLIKER
{
	struct StageStruct
	{
		std::string name;
		int id;
		int ballStock = 3;
		ViewModel background;
		std::vector<Block> block;
		std::vector<Bar> bar;
		std::vector<Ball> ball;
		StageStruct(std::string _name, int _id, ViewModel _background, std::vector<Block> _block, std::vector<Bar> _bar, std::vector<Ball> _ball, int _ballStock) : name(_name), id(_id), background(_background), block(_block), bar(_bar), ball(_ball), ballStock(_ballStock) {}
	};
	class Stage
	{
	protected:
		StageStruct stage;
		int crrentTime = 0;
		
		void BallBound();
	public:
		bool stageExitFlag = false;
		bool gameClearFlag = false;
		bool gameOverFlag = false;
		enum StageId
		{
			TEST = -1,
			TUTORIAL = 0
		};
		Stage() : stage("", -1, ViewModel(), std::vector<Block>(), std::vector<Bar>(), std::vector<Ball>(), 0) {}
		Stage(std::string _name, int _id, ViewModel _background, std::vector<Block> _block, std::vector<Bar> _bar, std::vector<Ball> _ball, int _ballStock) : stage(_name, _id, ViewModel(_background), std::vector<Block>(_block), std::vector<Bar>(_bar), std::vector<Ball>(_ball), _ballStock) {}
		virtual void GenerateStage();
		virtual void Update();
		virtual void DestroyStage();
		void LoadStage(StageStruct stage);
	};
}

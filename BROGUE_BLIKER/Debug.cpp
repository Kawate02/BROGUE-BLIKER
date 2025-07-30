#include "Debug.h"

std::vector<std::string> objects;

/// <summary>
/// デバッグ用テキストを登録
/// </summary>
/// <param name="object"></param>
void Log(std::string object)
{
	objects.push_back(object);
}
/// <summary>
/// デバッグ用テキスト群を描画
/// </summary>
void Write()
{
	for ( auto i = 0; i < objects.size(); i++ )
	{
		DrawFormatString(0, 15*i, GetColor(255, 255, 255), objects[i].c_str());
	}
	objects.clear();
}
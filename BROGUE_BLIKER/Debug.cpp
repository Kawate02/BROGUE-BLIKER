#include "Debug.h"

std::vector<std::string> objects;

void Log(std::string object)
{
	objects.push_back(object);
}
void Write()
{
	for ( auto i = 0; i < objects.size(); i++ )
	{
		DrawFormatString(0, 15*i, GetColor(255, 255, 255), objects[i].c_str());
	}
	objects.clear();
}
#pragma once

namespace BROGUE_BLIKER
{
	template<class T>
	class List
	{
	private:
		int size;
	public:
		T list[];
		List(int size);
		~List();
		void Add(T);
		void Remove(T);
		void RemoveAt(int index);
		void Clear();
	};
}
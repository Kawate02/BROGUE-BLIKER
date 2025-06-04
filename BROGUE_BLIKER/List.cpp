#include "List.h"

namespace BROGUE_BLIKER
{
	template<typename T>
	List<T>::List(int size)
	{
		this.size = size;
		list = new T[size];
	}

	template<typename T>
	List<T>::~List()
	{
		delete[] list;
	}
	template<typename T>
	void List<T>::Add(T t)
	{
		T tmp[size + 1] = list;
		tmp[size] = t;
		size++;
		list = new T[size];

		for (int i = 0; i < size; i++)
		{
			list[i] = tmp[i];
		}
	}
	template<typename T>
	void List<T>::Remove(T t)
	{
	}
	template<typename T>
	void List<T>::RemoveAt(int index)
	{
	}
	template<typename T>
	void List<T>::Clear()
	{
	}
}
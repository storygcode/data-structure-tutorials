#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#ifndef NULL
#define NULL 0
#endif

template <class T>
class ArrayList
{
  private:
	T *data;
	int size;  //size of list
	int count; //element count

	void resize()
	{
		T *tmp = new T[size * 2];

		memcpy(tmp, data, size * sizeof(T));
		delete[] data;

		data = tmp;
		size *= 2;
	}

	bool needToResize()
	{
		return size == count;
	}

  public:
	ArrayList()
	{
		count = 0;
		size = 5;
		data = new T[size]; // Unit 2
	}

	ArrayList(int size) : size(size)
	{
		count = 0;
		data = new T[size];
	}

	int indexOf(T item)
	{
		for (int i = 0; i <= count; i++)
		{
			if (item == data[i])
				return i;
		}

		return -1;
	}

	bool contains(T item)
	{
		return (indexOf(item) > -1);
	}

	T *get(int index)
	{
		if (index >= 0 && index <= count)
			return &data[index];
		return NULL;
	}

	int getSize()
	{
		return size;
	}

	int getCount()
	{
		return count;
	}

	void add(T item)
	{
		//리사이즈가 필요한가?
		if (needToResize())
			//필요하다면
			resize();

		//사이즈를 증가하면서 아이템을 추가해준다
		data[count++] = item;
	}

	void add(int index, T item)
	{
		if (needToResize())
			resize();

		for (int i = count++; i >= index; i--)
			data[i + 1] = data[i];

		data[index] = item;
	}
	void set(int index, T item)
	{
		if (index >= 0 && index <= count)
			data[index] = item;
	}

	void removeByPosition(int index)
	{
		for (int i = index; i < count; i++)
			data[i] = data[i + 1];
		count--;
	}

	void removeByItem(T item)
	{
		int index = indexOf(item);
		if (index > 0)
			removeByPosition(index);
	}
};
// #include "ArrayList.cpp"
#endif

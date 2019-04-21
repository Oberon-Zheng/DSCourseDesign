#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

static void Swap(int &opA, int &opB)
{
	int t = opA;
	opA = opB;
	opB = t;
}

Heap::Heap() :initSize(10), increSize(5), length(0)
{
	heap = new int[initSize];
	size = initSize;
}
Heap::~Heap()
{
	if (heap != 0)
	{
		delete[] heap;
		length = 0;
		size = 0;
	}
}
void Heap::Grow()
{
	int *newWrapper = new int[size + increSize];
	for (int i = 0; i < length; i++)
	{
		newWrapper[i] = heap[i];
	}
	delete[] heap;
	size += increSize;
	heap = newWrapper;
}
void Heap::Clear()
{
	length = 0;
}
void Heap::PushBack(int elem)
{
	if (length == size)
	{
		Grow();
	}
	heap[length++] = elem;
}
int Heap::GetParent(int index)
{
	if (index == 0)
	{
		return -1;
	}
	else
	{
		return (index - 1) / 2;
	}
}
int Heap::GetLSub(int index)
{
	int lch = index * 2 + 1;
	return (lch >= length) ? -1 : lch;
}
int Heap::GetRSub(int index)
{
	int rch = (index + 1) * 2;
	return (rch >= length) ? -1 : rch;
}
void Heap::MaxHeapify(int index,int vsize)
{
	int lind = GetLSub(index), rind = GetRSub(index);
	int maxind = index;
	if (lind != -1 && lind < vsize && heap[lind] > heap[maxind])
	{
		maxind = lind;
	}
	if (rind != -1 && rind < vsize && heap[rind] > heap[maxind])
	{
		maxind = rind;
	}
	if (maxind != index)
	{
		Swap(heap[index], heap[maxind]);
		MaxHeapify(maxind,vsize);
	}
}
void Heap::MinHeapify(int index,int vsize)
{
	int lind = GetLSub(index), rind = GetRSub(index);
	int minind = index;
	if (lind != -1 && lind < vsize && heap[lind] < heap[minind])
	{
		minind = lind;
	}
	if (rind != -1 && rind < vsize && heap[rind] < heap[minind])
	{
		minind = rind;
	}
	if (minind != index)
	{
		Swap(heap[index], heap[minind]);
		MinHeapify(minind,vsize);
	}
}
void Heap::Heapify(HeapType htype)
{
	void (Heap::*f)(int,int);
	switch (htype)
	{
	case MaxHeap:
		f = &Heap::MaxHeapify;
		break;
	case MinHeap:
		f = &Heap::MinHeapify;
		break;
	default:
		f = 0;
		break;
	}
	if (f == 0)
	{
		return;
	}
	else
	{
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			(this->*f)(i,length);
			Print();
		}
	}
}
void Heap::HeapSort(HeapType htype)
{
	void (Heap::*f)(int, int);
	int vsize = length;
	Heapify(htype);
	switch (htype)
	{
	case MaxHeap:
		f = &Heap::MaxHeapify;
		break;
	case MinHeap:
		f = &Heap::MinHeapify;
		break;
	default:
		f = 0;
		break;
	}
	if (f == 0)
	{
		return;
	}
	for (int i = length - 1; i >= 1; i--)
	{
		Swap(heap[0], heap[i]);
		vsize--;
		(this->*f)(0,vsize);
		Print();
	}
}
void Heap::Print()
{
	int hdpth = 0,tlen = length,pdpth = 0;
	int ind = 0;
	while (tlen != 0)
	{
		tlen = tlen >> 1;
		hdpth++;
	}
	int ucell = (1 << hdpth)-1;
	if (hdpth != 0)
	{
		for (pdpth = 1; pdpth <= hdpth; pdpth++)
		{
			for (int i = 0; i < ucell >> 1; i++)
			{
				cout << '\t';
			}
			cout << setfill(' ') << setw(8) << setiosflags(ios::right) << heap[ind++];
			for (int i = 0; i < (1<<(pdpth-1)) - 1; i++)
			{
				for (int j = 0; j < ucell; j++)
				{
					cout << '\t';
				}
				if (ind >= length)
				{
					cout << setfill(' ') << setw(8) << setiosflags(ios::right) << '*';
				}
				else
				{
					cout << setfill(' ') << setw(8) << setiosflags(ios::right) << heap[ind];
				}
				ind++;
			}
			ucell = ucell >> 1;
			cout << endl;
		}
	}
	cout << endl;
}

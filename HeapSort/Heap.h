#pragma once

enum HeapType
{
	MaxHeap,
	MinHeap
};

class Heap
{
private:
	const int initSize;
	const int increSize;
	void MaxHeapify(int,int);
	void MinHeapify(int,int);
public:
	int *heap;
	int length;
	int size;
	Heap();
	~Heap();
	void PushBack(int elem);
	void Grow();
	void Clear();
	int GetParent(int);
	int GetLSub(int);
	int GetRSub(int);
	void Heapify(HeapType);
	void HeapSort(HeapType);
	void Print();
};
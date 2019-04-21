#include <iostream>
#include "Heap.h"
#include <Windows.h>
#include <cassert>
#define EQULINE "==========================================="
using namespace std;

int main()
{
	Heap *hp = new Heap();
	HeapType htype = MaxHeap;
	cout << "欢迎使用堆排序" << endl;
	while (true)
	{
		int cnt;
		cout << "当前堆型为" << ((htype == MaxHeap) ? "最大堆" : "最小堆") << endl;;
		cout << "请输入堆大小（输入-1结束，输入-2切换堆类型）" << endl;
		cin >> cnt;
		if (cin.fail() || cin.bad())
		{
			cin.clear();
			cin.ignore();
			cout << "无效输入" << endl;
			//assert(!cin.bad());
			//assert(!cin.fail());
			//assert(cin.good());
			continue;
		}
		if (cnt == -1)
		{
			break;
		}
		else if (cnt == -2)
		{
			htype = (htype == MaxHeap) ? MinHeap : MaxHeap;
		}
		else if(cnt > 0)
		{
			cout << "请输入堆中元素" << endl;
			hp->Clear();
			for (int i = 0; i < cnt; i++)
			{
				int n;
				cin >> n;
				hp->PushBack(n);
			}
			cout << "所输入的树为" << endl;
			cout << EQULINE << endl;
			hp->Print();
			cout << EQULINE << endl;
			cout << "其堆化结果为：" << endl;
			cout << EQULINE << endl;
			hp->Heapify(htype);
			hp->Print();
			cout << EQULINE << endl;
			hp->HeapSort(htype);
			cout << "其排序结果为：" << endl;
			cout << EQULINE << endl;
			hp->Print();
			cout << EQULINE << endl;
			cout << "排序序列为：" << endl;
			for (int i = 0; i < hp->length; i++)
			{
				cout << hp->heap[i] << ' ';
			}
			cout << endl;
		}
		else if(cnt != 0)
		{
			cout << "无效的负数指令，请重新输入" << endl;
		}
		else
		{
			cout << "大小为0的是空堆，什么也不会发生" << endl;
		}
		
	}
	cout << "正在结束……" << endl;
	delete hp;
	Sleep(1000);
	return 0;
}
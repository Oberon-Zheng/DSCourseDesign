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
	cout << "��ӭʹ�ö�����" << endl;
	while (true)
	{
		int cnt;
		cout << "��ǰ����Ϊ" << ((htype == MaxHeap) ? "����" : "��С��") << endl;;
		cout << "������Ѵ�С������-1����������-2�л������ͣ�" << endl;
		cin >> cnt;
		if (cin.fail() || cin.bad())
		{
			cin.clear();
			cin.ignore();
			cout << "��Ч����" << endl;
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
			cout << "���������Ԫ��" << endl;
			hp->Clear();
			for (int i = 0; i < cnt; i++)
			{
				int n;
				cin >> n;
				hp->PushBack(n);
			}
			cout << "���������Ϊ" << endl;
			cout << EQULINE << endl;
			hp->Print();
			cout << EQULINE << endl;
			cout << "��ѻ����Ϊ��" << endl;
			cout << EQULINE << endl;
			hp->Heapify(htype);
			hp->Print();
			cout << EQULINE << endl;
			hp->HeapSort(htype);
			cout << "��������Ϊ��" << endl;
			cout << EQULINE << endl;
			hp->Print();
			cout << EQULINE << endl;
			cout << "��������Ϊ��" << endl;
			for (int i = 0; i < hp->length; i++)
			{
				cout << hp->heap[i] << ' ';
			}
			cout << endl;
		}
		else if(cnt != 0)
		{
			cout << "��Ч�ĸ���ָ�����������" << endl;
		}
		else
		{
			cout << "��СΪ0���ǿնѣ�ʲôҲ���ᷢ��" << endl;
		}
		
	}
	cout << "���ڽ�������" << endl;
	delete hp;
	Sleep(1000);
	return 0;
}
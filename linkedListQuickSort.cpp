#include "linkedListQuickSort.h"

int main()
{
    MyTestSpace::LinkedList<int>* pList = MyTestSpace::GenerateRandomLinkedList<int>(10);
    MyTestSpace::PrintLinkedList(pList);
    MyTestSpace::LinkedList<int>* pAfter = MyTestSpace::QuickSort(pList);    
    std::cout << std::endl;
    MyTestSpace::PrintLinkedList(pAfter);
    return 0; 
}

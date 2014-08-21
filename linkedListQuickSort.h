#include <ctime>
#include <cstdlib>
#include <iostream>

namespace MyTestSpace
{
    template<class T>
    class Node
    {
        public:
            Node(T value, Node<T>* next = NULL);
            T GetValue();
            void SetValue(T value);
            Node<T>* GetNext();
            void SetNext(Node<T>* next);
        private:
            T mValue;
            Node<T>* mpNext;
    };

    template<class T>
    Node<T>::Node(T value, Node<T>* next)
    {
        mValue = value;
        mpNext = next;
    }

    template<class T>
    T Node<T>::GetValue()
    {
        return mValue;
    }

    template<class T>
    void Node<T>::SetValue(T value)
    {
        mValue = value;
    }

    template<class T>
    Node<T>* Node<T>::GetNext()
    {
        return mpNext;
    }

    template<class T>
    void Node<T>::SetNext(Node<T>* next)
    {
        mpNext = next;
    }

    template<class T>
    class LinkedList
    {
        public:
            LinkedList(Node<T>* head = NULL);    
            ~LinkedList();
            Node<T>* GetHead();
        private:
            Node<T>* mpHead;
    };
    
    template<class T>
    LinkedList<T>::LinkedList(Node<T>* head)
    {
        mpHead = head;
    }

    template<class T>
    LinkedList<T>::~LinkedList()
    {
        Node<T>* pointer = mpHead;
        while(!pointer) 
        {
            Node<T>* pTemp = pointer->GetNext();
            delete pointer;
            pointer = pTemp;      
        }
    }
    
    template<class T>
    Node<T>* LinkedList<T>::GetHead()
    {
        return mpHead;
    }

    template<class T>
    LinkedList<T>* GenerateRandomLinkedList(int size)
    {
        exit(-1);
    }

    template<>
    LinkedList<int>* GenerateRandomLinkedList(int size)
    {
        LinkedList<int>* pLinkedList = NULL;
        Node<int>* pNode = NULL;
        if (size == 0)
        {
            pLinkedList = new LinkedList<int>(); 
            return pLinkedList;
        }
        else
        {
            srand(time(NULL));
            pNode = new Node<int>(rand()%100);
            pLinkedList = new LinkedList<int>(pNode);
        }
        while(--size)
        {
            Node<int>* pNext = new Node<int>(random()%100);
            pNode->SetNext(pNext);
            pNode = pNext; 
        }   
        return pLinkedList;
    }

    
   
    template<class T> 
    Node<T>* MyQuickSort(Node<T>* pStart, Node<T>* pEnd)
    {
        if (pStart == pEnd)
            return pStart;

        Node<T>* pHead = pStart;
        Node<T>* pTail = pStart;
        T value = pStart->GetValue();
        Node<T>* pIndex = pStart->GetNext();
        while(pIndex != pEnd)
        {
            T compare = pIndex->GetValue();
            if (compare < value)
            {
                Node<T>* pTemp = pIndex->GetNext();
                pTail->SetNext(pTemp);
                pIndex->SetNext(pHead);             
                pHead = pIndex; 
            } 
            else
            {
                pTail = pIndex;
            }
            pIndex = pTail->GetNext();
        } 
        pStart->SetNext(MyQuickSort(pStart->GetNext(), pEnd));
        return MyQuickSort(pHead, pStart);
    } 

    template<class T>
    LinkedList<T>* QuickSort(LinkedList<T>* pList)
    {
        Node<T>* end = NULL;
        return new LinkedList<T>(MyQuickSort(pList->GetHead(), end));
    }

    template<class T>
    void PrintLinkedList(LinkedList<T>* linkedList)
    {
        Node<T>* pIndex = linkedList->GetHead();
        while(pIndex)
        {
            std::cout << pIndex->GetValue() << "  ";
            pIndex = pIndex->GetNext(); 
        }
    }

}

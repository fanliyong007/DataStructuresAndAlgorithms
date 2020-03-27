#ifndef _LIST_H
#define _LIST_H
#include "ListNode.h"
template<typename T>
class List
{
private:
    int _size;ListNodePosi(T) header;ListNodePosi(T) trailer;
protected:
    void init();
    int clear();
    void copyNodes(ListNodePosi(T),int);
    void merge(ListNodePosi(T)&,int,List<T>&,ListNodePosi(T),int);
    void mergeSort(ListNodePosi(T)&,int);
    void selectionSort(ListNodePosi(T),int);
    void insertionSort(ListNodePosi(T),int);
public:
    List();
    List(List<T> const& L);
    List(List<T> const& L,Rank r,int n);
    List(ListNodePosi(T) p,int n);
    ~List();
    Rank size() const;
    bool empty() const;
    T& operator[](Rank r) const;
    ListNodePosi(T) first() const;
    ListNodePosi(T) last() const;
    bool valid(ListNodePosi(T) p);
    int disordered() const;
    ListNodePosi(T) find(T const& e) const;
    ListNodePosi(T) find(T const& e,int n,ListNodePosi(T) p) const;
    ListNodePosi(T) search(T const& e) const;
    ListNodePosi(T) search(T const& e,int n,ListNodePosi(T) p) const;
    ListNodePosi(T) selectMax(ListNodePosi(T) p,int n);
    ListNodePosi(T) selectMax();
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    ListNodePosi(T) insertA(ListNodePosi(T) p,T const& e);
    ListNodePosi(T) insertB(ListNodePosi(T) p,T const& e);
    T remove(ListNodePosi(T) p);
    void merge(List<T>& L);
    void sort(ListNodePosi(T) p,int n);
    void sort();
    int uniquify();
    void reverse();
    void traverse(void(*) (T&));
    template <typename VST>
    void traverse(VST&);
}
#endif
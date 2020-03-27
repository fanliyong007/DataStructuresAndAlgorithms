#include "List.h"
template<typename T>
void List<T>::init()//列表初始化，在创建列表对象时统一调用
{
    header=new ListNode<T>;//创建头哨兵节点
    trailer=new ListNode<T>;//创建尾哨兵节点
    header->succ=trailer;header->pred=NULL;
    trailer->pred=header;trailer->succ=NULL;
    _size=0;//纪录规模
}
template<typename T>
int List<T>::clear();
template<typename T>
void List<T>::copyNodes(ListNodePosi(T),int);
template<typename T>
void List<T>::merge(ListNodePosi(T)&,int,List<T>&,ListNodePosi(T),int);
template<typename T>
void List<T>::mergeSort(ListNodePosi(T)&,int);
template<typename T>
void List<T>::selectionSort(ListNodePosi(T),int);
template<typename T>
void List<T>::insertionSort(ListNodePosi(T),int);
//-------------------------------------------------public-------------------------------------------------
template<typename T>
List<T>::List(){init();}//默认构造
template<typename T>
List<T>::List(List<T> const& L);
template<typename T>
List<T>::List(List<T> const& L,Rank r,int n);
template<typename T>
List<T>::List(ListNodePosi(T) p,int n);
template<typename T>
List<T>::~List();
template<typename T>
Rank List<T>::size() const{return _size;}//规模
template<typename T>
bool List<T>::empty() const{return _size<=0;}//判空
template<typename T>
T& List<T>::operator[](Rank r) const;
template<typename T>
ListNodePosi(T) List<T>::first() const{return header->succ;}//首节点位置
template<typename T>
ListNodePosi(T) List<T>::last() const{return trailer->pred ;}//末节点位置
template<typename T>
bool List<T>::valid(ListNodePosi(T) p)//判位置P是否对外合法
{return p && (trailer != p)&&(header != p);}//将头、尾节点等同于NULL
template<typename T>
int List<T>::disordered() const;
template<typename T>
ListNodePosi(T) List<T>::find(T const& e)//无序列表查找
{return find(e,_size,trailer);}
template<typename T>
ListNodePosi(T) List<T>::find(T const& e,int n,ListNodePosi(T) p) const;
template<typename T>
ListNodePosi(T) List<T>::search(T const& e) const//有序列表查找
{return find(e,_size,trailer);}
template<typename T>
ListNodePosi(T) List<T>::search(T const& e,int n,ListNodePosi(T) p) const;
template<typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p,int n);
template<typename T>
ListNodePosi(T) List<T>::selectMax(){return selectMax(header->succ,_size);}//整体最大者
template<typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e);
template<typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e);
template<typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p,T const& e);
template<typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p,T const& e);
template<typename T>
T List<T>::remove(ListNodePosi(T) p);
template<typename T>
void List<T>::merge(List<T><T>& L){merge(first(),size,L,L.first(),L.size());}//全列表归并
template<typename T>
void List<T>::sort(ListNodePosi(T) p,int n);
template<typename T>
void List<T>::sort(){sort(first(),_size);}//列表整体排序
template<typename T>
int List<T>::uniquify();
template<typename T>
void List<T>::reverse();
template<typename T>
void List<T>::traverse(void(*) (T&));
template <typename VST>
void List<T>::traverse(VST&);
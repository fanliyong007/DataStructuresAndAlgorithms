#ifndef _LISTNODE_H
#define _LISTNODE_H
typedef int Rank;//秩

#define ListNodePosi(T) ListNode<T>* //列表节点位置

template <typename T>
struct ListNode
{
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;
    ListNode(){}
    ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T) s=NULL):data(e),pred(p),succ(s){}
    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

#endif
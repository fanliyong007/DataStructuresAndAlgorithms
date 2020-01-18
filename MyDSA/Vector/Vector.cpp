#include "Vector.h"
template <typename T>
void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi)//复制数组区间[lo,hi]
{
    _elem=new T[_capcatity=2*(hi-lo)];
    _size=0;
    while(lo<hi)
    {
        _elem[_size++]=A[lo++];//复制_elem[0,hi-lo]
    }
}
template <typename T>
void Vector<T>::expand()//扩容函数，用于空间不足时使用
{
    if(_size<_capcatity)return;//尚未满，不必扩容
    if(_capcatity<DEFAULT_CAPACITY)_capcatity=DEFAULT_CAPACITY;//不低于最小容量
    T *oldElem=_elem;//容量加倍
    _elem=new T[_capcatity<<=1];
    for(int i=0;i<_size;i++)
    {
        _elem[i]=oldElem[i];//复制原向量内容
    }
    delete [] oldElem;//释放原空间
}
template <typename T>
void Vector<T>::shrink()//装填因子过小时压缩空间
{
    if(_capacity<DEFAULT_CAPACITY<<1)
    {
        return;//不致收缩到DEFAULT_CAPACITY
    }
    if(_size<<2>_capacity)
    {
        return;//以25%为界
    }
    T *oldElem=_elem;
    _elem=new T[_capacity>>=1];//容量减半
    for(int i=0;i<_size;i++)
    {
        _elem[i]=oldElem[i];//复制原向量内容
    }
    delete [] oldElem;//释放空间
}
template <typename T>
void Vector<T>::swap(T &A,T &B)//交换操作
{
    T tmp=A;
    A=B;
    B=tmp;
}
template <typename T>
Vector<T>::Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0)//容量为c、规模为s、所有元素初始化为v
{
    _elem=new T[_capcatity=c];//申请空间
    for(_size=0;_size<s;_elem[_size++]=v);//对每个元素赋值v
}
template <typename T>
Vector<T>::Vector(T const* A,Rank n)//数组整体复制
{
    copyFrom(A,0,n);//数组整体复制
}
template <typename T>
Vector<T>::Vector(T const* A,Rank lo,Rank hi);//区间复制
{
    copyFrom(A,lo,hi);
}
template <typename T>
Vector<T>::Vector(Vector<T> const& V)//向量整体复制
{
    copyFrom(V._elem,0,V._size);
}
template <typename T>
Vector<T>::Vector(Vector<T> const& V,Rank lo,Rank hi)//区间
{
    copyFrom(V._elem,lo,hi);
}
Vector<T>::~Vector()//释放内部空间
{
    delete [] _elem;
}
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const//无序向量区间查找
{
    while((lo<hi--)&&(e!=_elem[hi]));//从后向前，顺寻查找
    return hi;//若hi<lo则查找失败，分批则hi即命中元素的秩
}
template <typename T>
Rank Vector<T>::find(T const& e) const//无序向量整体查找
{
    return find(e,0,_size);
}
template <typename T>
Rank Vector<T>::search(T const& e) const//有序向量整体查找
{
    return (0>=_size)?-1:search(e,0,_size);
}
template <typename T>
T& Vector<T>::operator[](Rank r)const//重载[]符号
{
    return _elem[r];//assert:0<=r<_size
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const&)//重载=符号
{
    if(_elem)
    {
        delete [] _elem;//释放原有内容
    }
    copyFrom(V._elem,0,V.size());//整体复制
    return *this;//返回当前对象的引用，方便链式赋值 
}
template <typename T>
T Vector<T>::remove(Rank r);//删除秩为r的元素
{
    T e=_elem[r];//备份删除元素
    remove(r,r+1);//调用区间删除算法等效于对区间删除
    return e;//返回被删除元素
}
template <typename T>
int Vector<T>::remove(Rank lo,Rank hi)//删除区间内元素
{
    if(lo==hi)
    {
        return 0;//出于效率考虑，单独处理退化情况，比如remove（0，0）
    }
    while(hi<_size)
    {
        _elem[lo++]=_elem[hi++];//[hi,_size)顺次前移hi-lo个单元
    }
    _size=lo;//更新规模，直接丢弃尾部[lo,_size=hi)区间
    shrink();//若有必要，则缩容
    return hi-lo;//返回被删除元素的数目
}
template <typename T>
Rank Vector<T>::insert(Rank r,T const& e)//插入元素
{
    expand();//若有需要，扩容
    for(int i=_size;i>r;i--)
    {
        _elem[i]=_elem[i-1];//自后向前，后继元素顺次后移一个单元
    }
    _elem[r]=e;
    _size++;//插入新元素并更新容量
    return r;//返回秩
}
template <typename T>
Rank Vector<T>::insert(T const& e)//在末尾插入元素
{
    return insert(_size,e);
}
template <typename T>
void Vector<T>::sort()//整体排序
{
    sort(0,_size);
}
template <typename T>
void Vector<T>::unsort(Rank lo,Rank hi)//区间乱序
{
    T* V=_elem+lo;//将子向量_elem[ko,hi)视作另一向量V[0,hi-lo)
    for(Rank i=hi-lo;i>0;i--)//自后向前
    {
        swap(V[i-1],V[rand()%i]);//将V[i-1]与V[0,i)中某一元素随机交换
    }
}
template <typename T>
void Vector<T>::unsort()//整体乱序
{
    unsort(0,_size);
}

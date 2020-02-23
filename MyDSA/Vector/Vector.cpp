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
template <typename T> //向量的起泡排序（基本版）
void Vector<T>::bubbleSort( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   while( lo < --hi ) //反复起泡扫描
      for( Rank i = lo; i < hi; i++ ) //逐个检查相邻元素
         if( _elem[i] > _elem[i + 1] ) //若逆序，则
            swap( _elem[i], _elem[i + 1] ); //经交换使局部有序
    //向量的起泡排序（提前终止版）
    // for( bool sorted = false; sorted = !sorted; )
    //   for( Rank i = lo; i < hi - 1; i++ )
    //      if( _elem[i] > _elem[i + 1] ) //若逆序，则
    //         swap( _elem[i], _elem[i + 1] ), sorted = false;
    //         //经交换使局部有序——当然，至此还不能确定已整体有序 
     //向量的起泡排序（跳跃版）       
    // for( Rank last = --hi; lo < hi; hi = last )
    //   for( Rank i = last = lo; i < hi; i++ )
    //      if( _elem[i] > _elem[i + 1] ) //若逆序，则
    //         swap( _elem[ last = i ], _elem[ i + 1 ] ); //经交换使局部有序
}
template <typename T>
void Vector<T>::swap(T &A,T &B)//交换操作
{
    T tmp=A;
    A=B;
    B=tmp;
}
template <typename T>
void Vector<T>::merge(Rank lo,Rank hi)//归并算法
{
    T* A=_elem+lo;//合并后的向量A[0,hi-lo)=_elem[lo,hi)
    Rank lb=mi-lo;//前子向量B[0,lb)=_elem[lo,mi]
    T* B=new T[lb];
    for(Rank i=0;i<lb;B[i]=A[i++]);//复制前子向量B
    Rank lc=hi-mi;//后子向量C[0,lc)=_elem[mi,hi)
    T* C=_elem+mi;
    for(Rank i=0,j=0,k=0;(j<lb)||(k<lc);)//B[j]和C[k]中小者转至A的末尾
    {
        if((j<lb)&&(lc<=k||(B[j]<=C[k])))
        {
            A[i++]=B[i++];//C[k]已无或不小
        }
        if((k<lc)&&(lb<=j||(C[k]<B[j])))
        {
            A[i++]=C[k++];//B[j]已无或更大
        }
    }
    delete [] B;//释放临时空间B
}
template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi)//归并排序算法
{
    if(hi-lo<2)
        return;//单元素区间自然有序
    Rank mi=(hi+lo)/2;
    mergeSort(lo,mi);//归并排序前一部分
    mergeSort(mi,hi);//归并排序后一部分
    merge(lo,mi,hi);//归并
}
template <typename T>
Rank Vector<T>::max(Rank lo,Rank hi){}//选取最大元素
template <typename T>
void Vector<T>::selectionSort(Rank lo,Rank hi){}//选择排序
template <typename T>
Rank Vector<T>::partition(Rank lo,Rank hi){}//轴点构造算法
template <typename T>
void Vector<T>::quickSort(Rank lo,Rank hi){}//快速排序算法
template <typename T>
void Vector<T>::heapSort(Rank lo,Rank hi){}//堆排序算法
//-------------------------------------------------public--------------------------------------------------------
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
Rank Vector<T>::fibSearch(T* A,T const& e,Rank lo,Rank hi)//Fibonacci查找算法
{
    Fib fib(hi-lo);
    while(lo<hi)
    {
        while(hi-lo<fib.get())fib.prev();
        Rank mi=lo+fib.get()-1;
        if(e<A[mi])hi=mi;
        else if(A[mi]<e)lo=mi+1;
        else return mi;
    }
    return -1;
}
template <typename T>
Rank Vector<T>::binSearch(T* A,T const& e,Rank lo,Rank hi)//二分查找
{
    //版本A
    // while(lo<hi)
    // {
    //     Rank mi=(lo+hi)>>1;
    //     if(e<A[mi])hi=mi;
    //     else if(A[mi]>e)lo=mi+1;
    //     else return mi;
    // }
    // return -1;
    //版本B
    // while(1<hi-lo)
    // {
    //     Rank mi=(lo+hi)>>1;
    //     (e<A[mi])?hi=mi:lo=mi;
    // }
    // return (e==A[lo])?lo:-1;
    //版本C
    while(1<hi-lo)
    {
        Rank mi=(lo+hi)>>1;
        (e<A[mi])?mi=lo:mi=hi;
    }
    return e==A[lo]?lo:-1;
}
template <typename T>
Rank Vector<T>::search(T const& e,Rank lo,Rank hi) const//有序向量区间查找
{
    return(std::rand()%2)?binSearch(_elem,e,lo,hi):fibSearch(_elem,e,lo,hi);
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
T Vector<T>::remove(Rank r);//删除秩为r的元素
{
    T e=_elem[r];//备份删除元素
    remove(r,r+1);//调用区间删除算法等效于对区间删除
    return e;//返回被删除元素
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
void Vector<T>::sort(Rank lo,Rank hi)//区间排序
{
    switch (rand()%3)
    {
    case 1:
        mergeSort(lo,hi);
        break;
    case 2:
        bubbleSort(lo,hi);
        break;
    //default:quickSort(lo,hi);break;
    }
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
        swap(V[i-1],V[std::rand()%i]);//将V[i-1]与V[0,i)中某一元素随机交换
    }
}
template <typename T>
void Vector<T>::unsort()//整体乱序
{
    unsort(0,_size);
}
template <typename T>
int Vector<T>::deduplicate()//无序去重
{
    int oldSize=_size;//纪录原始规模
    Rank i=1;//从_elem[1]开始
    while(i<_size)//自前向后逐一考察各元素_elem[i]
    {
        (find(_elem[i],0,i)<0)?//在其前缀中寻找与之雷同者（至少一个）
        i++:remove(i);//若无雷同则继续考查其后继，否则删除雷同者
    }
    return oldSize-_size;//向量规模变化量，即被删除元素总数
}
template <typename T>
void Vector<T>::traverse(void (*visit) (T&))//遍历（使用函数指针，只读或局部性修改）
{
    for(int i=0;i<_size;i++)
    {
        visit(_elem[i];)// 遍历向量
    }
}
template <typename VST>
void Vector<T>::traverse(VST& visit)//遍历（使用函数对象，可全局性修改）
{
    for(int i=0;i<_size;i++)
    {
        visit(_elem[i];)// 遍历向量
    }
}
template <typename T>
int Vector<T>::disorded() const//判断向量是否已排序
{
    int n=0;
    for(int i=1;i<_size;i++)
    {
        if(_elem[i-1]>_elem[i])
        {
            n++;
        }
    }
    return n;
}
/*template <typename T>
int Vector<T>::uniquify()//有序去重(低效版)
{
    int oldSize=_size;
    int i=1;
    while(i<_size)
    {
        _elem[i-1]==_elem[i]?remove(i):i++;
    }
    return oldSize-_size;
}*/
template <typename T>
int Vector<T>::uniquify()//有序去重(高效版)
{
    Rank i=0,j=0;//各对互异“相邻”元素的秩
    while(++j<_size)//逐一扫描，直至末元素
    {
        if(_elem[i]!=_elem[j])//跳过雷同者
        {
            _elem[++i]=_elem[j];//发现不同元素时，向前移至紧邻于前右侧
        }
    }
    _size=++i;
    shrink();//直接截除尾部多余元素
    return j-i;//向量规模变化量，即被删除元素总数
}
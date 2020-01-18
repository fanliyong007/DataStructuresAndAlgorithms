// #include <cstdio>
// #include <cstdlib>
#ifndef _VECTOR_H
#define _VECTOR_H
#define DEFAULT_CAPACITY 3
typedef int Rank;

template <typename T>
class Vector
{
protected:
    Rank _size;//规模
    int _capcatity;//容量
    T* _elem;//数据区
    void copyFrom(T const* A,Rank lo,Rank hi);//复制数组区间[lp,hi]
    void expand();//扩容函数，用于空间不足时使用
    void shrink();//装填因子过小时压缩空间
    void swap(T &A,T &B);//交换操作
    void bubble(Rank lo,Rank hi);//扫描交换
    bool bubbleSore(Rank lo,Rank hi);//起泡排序
    Rank max(Rank lo,Rank hi);//选取最大元素
    void selectionSort(Rank lo,Rank hi);//选择排序
    void merge(Rank lo,Rank hi);//归并算法
    void mergeSort(Rank lo,Rank hi);//归并排序算法
    Rank partition(Rank lo,Rank hi);//轴点构造算法
    void quickSort(Rank lo,Rank hi);//快速排序算法
    void heapSort(Rank lo,Rank hi);//堆排序算法
public:
    Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0);//容量为c、规模为s、所有元素初始化为v
    Vector(T const* A,Rank n);//数组整体复制
    Vector(T const* A,Rank lo,Rank hi);//区间复制
    Vector(Vector<T> const& V);//向量整体复制
    Vector(Vector<T> const& V,Rank lo,Rank hi);//区间
    ~Vector();//释放内部空间
    Rank size() const;//规模
    bool empty() const;//判空
    int disorded() const;//判断向量是否已排序
    Rank find(T const& e) const;//无序向量整体查找
    Rank find(T const& e,Rank lo,Rank hi) const;//无序向量区间查找
    Rank search(T const& e) const;//有序向量整体查找
    Rank search(T const& e,Rank lo,Rank hi);//有序向量区间查找
    T& operator[](Rank r)const;//重载[]符号
    Vector<T>& operator=(Vector<T> const&);//重载=符号
    T remove(Rank r);//删除秩为r的元素
    int remove(Rank lo,Rank hi);//删除区间内元素
    Rank insert(Rank r,T const& e);//插入元素
    Rank insert(T const& e);//在末尾插入元素
    void sort(Rank lo,Rank hi);//区间排序
    void sort();//整体排序
    void unsort(Rank lo,Rank hi);//区间乱序
    void unsort();//整体乱序
    int deduplicate();//无序去重
    int uniquify();//有序去重
    void traverse(void (*) (T&));//遍历（使用函数指针，只读或局部性修改）
    template <typename VST>void traverse(VST&);//遍历（使用函数对象，可全局性修改）
}
#endif
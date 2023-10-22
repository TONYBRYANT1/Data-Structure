#include<bits/stdc++.h>
using namespace std;
#define True 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1   // adj. 不可实行的
//#define OVERFLOW -2     // n./v. 溢出

#define MAXSIZE 10000

typedef struct 
{
    string no;    // 图书 ISBN(international standard book number)
    string name;  
    float price;
}Book;

typedef struct
{
    Book* data;
    int length;
}SqList;

// 初始化线性表     1
int InitList_Sq(SqList& L)
{
    L.data = new Book[MAXSIZE];

    if(L.data == NULL)  // 异常处理
    {
        exit(-2);
    }

    L.length = 0;
    return OK;
}

// 销毁线性表
void DestoryList(SqList& L)
{
    if(L.data != NULL)
    {
        delete[] L.data;
        L.data = NULL;
    }
    L.length = 0; // 因为销毁线性表之后 , 可以用 InitList_Sq() 进行重新初始化 , 所以 L.length 可以不用赋值为0
}

// 清空线性表       
void ClearList(SqList& L)
{
    L.length = 0;
}

// 求线性表的长度       1
int GetLength(const SqList& L)
{
    return (L.length);
}

// 判断线性表是否为空       1
int IsEmpty(const SqList& L)
{
    if(L.data == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 顺序表的取值 (根据位置 i 获取相应位置的数据元素的内容)           1
// 因为是顺序表 所以是随机存取 算法的时间复杂度为 O(1)
int GetElem(SqList& L , int i , Book& b)
{
    if(i<1 || i>L.length)
    {
        return ERROR;
    }
    else
    {
        b = L.data[i-1];
        return OK;
    }
}

// 在线性表 L 中查找名为 "数据结构(C语言版) 严蔚敏" 的书        1
int LocateElem(SqList& L , string name)
{
    // 用 for语句 实现
    for(int i=0 ; i<=L.length-1 ; i++)
    {
        if(L.data[i].name == name)
        {
            return i+1; // 返回位置
        }
    }
    
    //用 while语句 实现
    // int i=0;
    // while(i<=L.length-1 && L.data[i].name!=name)
    // {
    //     i++;
    // }

    // if(i<=L.length-1)
    // {
    //     return i+1;
    // }
    // else
    // {
    //     return 0;
    // }
    
    return 0;
}

// 顺序表的插入 i是位置         1
int ListInsert_Sq(SqList& L , int i , string no , string name , float price)
{
    if(i<1 || i>L.length+1)
    {
        return ERROR;
    }
    if(L.length == MAXSIZE)
    {
        return ERROR;
    }
    for(int j=L.length-1 ; j>=i-1 ; j--)
    {
        L.data[j+1] = L.data[j];
    }

    L.data[i-1].no = no;
    L.data[i-1].name = name;
    L.data[i-1].price = price;

    L.length++;

    return OK;
}

//顺序表的删除 i是位置          1
int ListDelete_Sq(SqList& L , int i)
{
    if(i<1 || i>L.length+1)
    {
        return ERROR;
    }
    for(int j=i ; j<=L.length-1 ; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return OK;
}
int main()
{
    SqList L;

    //初始化线性表
    InitList_Sq(L);

    //线性表的插入
    ListInsert_Sq(L , 1 , "0000" , "计算机科学" , 50);
    ListInsert_Sq(L , 2 , "0001" , "数据结构 (C语言版) 严蔚敏" , 60);
    ListInsert_Sq(L , 3 , "0002" , "Essential C++" ,35);
    ListInsert_Sq(L , 4 , "0002" , "Essential pro C++" ,35);

    //线性表的查找
    int ret = LocateElem(L , "数据结构 (C语言版) 严蔚敏");
    cout << ret << endl;
    cout << L.length << endl;

    //获取线性表的长度
    int length = GetLength(L);
    cout << length << endl;

    //线性表是否为空
    int Empty = IsEmpty(L);
    cout << Empty << endl;

    //线性表的删除
    Book b1 ;
    GetElem(L , 1 , b1);
    cout << b1.name << endl;
    ListDelete_Sq(L , 1);
    GetElem(L , 1 , b1);
    cout << b1.name << endl;

    //线性表的清除
    ClearList(L);
    cout << L.length << endl;

    //线性表的销毁
    DestoryList(L);
    cout << L.data << endl;

    return 0;
}
  
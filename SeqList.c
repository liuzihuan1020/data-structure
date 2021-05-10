#include <stdlib.h>

/**
 * 顺序表中元素的数据类型
 */
#define SeqList_DataType int

/**
 * 顺序表的结构体
 */
struct SeqList {
    int initsize;       // 顺序表的初始大小
    int length;         // 顺序表的长度
    int capacity;       // 顺序表的最大容量
    SeqList_DataType *data;     // 顺序表的数据指针
};

/**
 * 初始化顺序表
 * @param list 顺序表的结构体指针
 * @param initsize 顺序表的初始大小
 * @return 
 */
int SeqList_Init(struct SeqList *list, int initsize) {
    list->length = 0;
    list->initsize = initsize;
    list->capacity = initsize;
    list->data = (SeqList_DataType *) malloc(sizeof(SeqList_DataType) * list->capacity);
    return list->data != NULL ? 1 : 0;
}

/**
 * 顺序表内存重新分配
 * @param list 顺序表结的构体指针
 */
void SeqList_Realloc(struct SeqList *list) {
    list->capacity += list->initsize;
    list->data = realloc(list->data, sizeof(SeqList_DataType) * list->capacity);
}

/**
 * 顺序表向指定位置插入数据
 * @param list 顺序表的结构体指针
 * @param data 插入的数据
 * @param idx 插入的位置
 * @return 插入成功返回数据的索引，失败返回-1
 */
int SeqList_Insert(struct SeqList *list, SeqList_DataType data, int idx) {
    if (list == NULL || idx > list->length) {
        return -1;
    }
    if (list->length + 1 == list->capacity) {
        SeqList_Realloc(list);
    }
    if (list->data == NULL) {
        return -1;
    }
    for (int i = list->length - 1; i >= idx; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[idx] = data;
    list->length++;
    return idx;
}

/**
 * 在顺序表表尾追加数据
 * @param list 顺序表结构体指针
 * @param data 追加的数据
 * @return 追加成功返回数据的索引，失败返回-1
 */
int SeqList_Append(struct SeqList *list, SeqList_DataType data) {
    return SeqList_Insert(list, data, list->length);
}

/**
 * 顺序表删除指定位置的数据
 * @param list 顺序表结构体指针
 * @param idx 删除数据的索引
 * @return 删除成功返回删除数据的索引，失败返回-1
 */
int SeqList_Delete(struct SeqList *list, int idx) {
    if (idx > list->length - 1) {
        return -1;
    }
    for (int i = idx; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return idx;
}

/**
 * 顺序表中获取指定位置的数据
 * @param list 顺序表结构体
 * @param idx 数据的索引
 * @return 获取到的数据
 */
SeqList_DataType SeqList_Get(struct SeqList list, int idx) {
    return list.data[idx];
}

/**
 * 顺序表中查找元素
 * @param list 顺序表结构体
 * @param data 需要查找的目标数据
 * @return 查找成功返回数据索引，查找失败返回-1
 */
int SeqList_Locate(struct SeqList list, SeqList_DataType data) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == data) {
            return i;
        }
    }
    return -1;
}

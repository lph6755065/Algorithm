> 剑指offer
### No1、二维数组中的查找
[牛客原文链接](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 题目描述  

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
```cpp
[

 [1,2,8,9],
 [2,4,9,12],
 [4,7,10,13],
 [6,8,11,15]

]
```
给定 target = 7，返回 true。  

给定 target = 3，返回 false。  

示例1

输入

```cpp 
7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
```
返回值 true  
说明 存在7，返回true  

示例2

输入
```cpp
3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
```
返回值 false   
说明 不存在3，返回false  

**1、第一种方法** 

> 右上角逐渐逼近左下角

* 如果当前位置元素比target小，则row++
* 如果当前位置元素比target大，则col--
* 如果相等，返回true
* 如果越界了还没找到，说明不存在，返回false

```cpp
bool Find(int target, vector<vector<int> > array) {
        if(array.empty() || array[0].empty()) return false;
        int row = array.size(), col = array[0].size();
        int r = 0;
        int c = col - 1;
        while ( c >= 0 && r < row){
            if (array[r][c] > target) c--;
            else if(array[r][c] < target) r++;
            else return true;
        }
        return false;
    }

```  
**2、第二种方法**
> 每轮用二分法替换
```cpp
bool hasFound(vector<int>& array, int target) {

	int start = 0, end = array.size() - 1;
	while (start + 1 < end) {
		int mid = start + (end - start) /2;
		//cout << array[mid] << " "<<start<<" "<<mid<<" "<<end<<" ";
		if (array[mid] == target) return true;
		else if (array[mid] > target) end = mid;
		else
			start = mid;
	}
	if (array[start] == target || array[end] == target) return true;
	return false;

}



bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) return false;
	for (int i = 0; i < matrix.size(); ++i) {
		if (hasFound(matrix[i], target)) return true;
	}
	return false;

}

```
### No2、替换空格

[牛客网原题链接](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 题目描述

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
### 第一种方法：先转为string,然后处理完成后再转为`char *`。但不是以返回值的形式，还要利用好原来的空间，用strcpy实现之。
```cpp
void replaceSpace(char *str,int length) {
        string res,s = str;
        for(char x: s){
            if (x == ' ') res += "%20";
            else res +=x;
        }
        strcpy(str,res.c_str());
}
```
### 第二种方法：双指针
```cpp
 void replaceSpace(char* str, int length) {
        if(str == NULL || length <0)
            return;
        int num =0;    //空格数目
        for (int i = 0; i < length; i++){
            if (str[i] == ' ')
                num++;
        }
        char* p1 = &str[length -1];//原字符串指针
        char* p2 = &str[length -1 +num*2];//新字符串指针
        for (int i = length-1; i >= 0; i--) {
            if (str[i] == ' ') {
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
                p1--;
            }else{
                *p2-- = *p1--;
            }
        }
    }

```

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
### No3、从尾到头打印链表

[牛客网原题链接](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) 

**题目描述**    

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

**方法一：先让到容器里 再反转出来**  
```cpp
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == nullptr) return vector<int>();
        vector<int> result;
        while (head){
            result.push_back(head->val);
            head = head -> next;
        }
       reverse(result.begin(), result.end());
        return result;
    }
};
```  
**方法二：返回时，直接用快捷方式**  
```cpp
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head == nullptr) return vector<int>();
        vector<int> result;
        while (head){
            result.push_back(head->val);
            head = head -> next;
        }
       //reverse(result.begin(), result.end());
        return vector<int> (result.rbegin(),result.rend());
    }
};
```
**方法三：迭代法**  
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

```
**方法四：递归法**
```cpp
class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};

```
```cpp
// Recursive C++ program to reverse 
// a linked list 
#include <iostream> 
using namespace std; 

/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
    Node(int data) 
    { 
        this->data = data; 
        next = NULL; 
    } 
}; 

struct LinkedList { 
    Node* head; 
    LinkedList() 
    { 
        head = NULL; 
    } 

    Node* reverse(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 

        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverse(head->next); 
        head->next->next = head; 

        /* tricky step -- see the diagram */
        head->next = NULL; 

        /* fix the head pointer */
        return rest; 
    } 

    /* Function to print linked list */
    void print() 
    { 
        struct Node* temp = head; 
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 

    void push(int data) 
    { 
        Node* temp = new Node(data); 
        temp->next = head; 
        head = temp; 
    } 
}; 

/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    LinkedList ll; 
    ll.push(20); 
    ll.push(4); 
    ll.push(15); 
    ll.push(85); 

    cout << "Given linked list\n"; 
    ll.print(); 

    ll.head = ll.reverse(ll.head); 

    cout << "\nReversed Linked list \n"; 
    ll.print(); 
    return 0; 
} 
``` 
### No4、重建二叉树
> 首先, 了解find()函数的用法

find函数用于查找数组中的某一个指定元素的位置。

比如：有一个数组[0, 0, 5, 4, 4]；
问：元素5的在什么位置，find函数 返回值 为 2；

find （数组名 + 起始查找元素的位置， 数组名 + 结束查找的元素位置， 想要查找的元素）
```cpp
#include <iostream>
#include <vector>
#include <algorithm>//注意要包含该头文件
using namespace std;
int main()
{
    int nums[] = { 3, 1, 4, 1, 5, 9 };
    int num_to_find = 5;
    int start = 0;
    int end = 5;
    int* result = find( nums + start, nums + end, num_to_find );
    if( result == nums + end ) 
    {
        cout<< "Did not find any number matching " << num_to_find << endl;
    } 
    else
    {
         cout<< "Found a matching number: " << *result << endl;
    }
    return 0;
}


```
[重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&&tqId=11157&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 题目描述

好题 绝对的好题

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
       if(!stack2.empty()){
           int value = stack2.top();
           stack2.pop();
           return value;
       }else{
           while(!stack1.empty()){
               stack2.push(stack1.top());
               stack1.pop();
           }
           int res = stack2.top();
           stack2.pop();
           return res;
       }
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```
### 06旋转数组

[旋转数组](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

**方法一：二分法Log(N)时间复杂度**

```cpp
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        
        int low = 0;
        int high = rotateArray.size() - 1;
        int mid = 0;
        
        while (low < high){
            mid = low + (high - low)/2;
            if(rotateArray[low] < rotateArray[high]) return rotateArray[low];
            if (rotateArray[mid] > rotateArray[low]) low = mid;
            else if(rotateArray[mid] < rotateArray[high]) high = mid;
            else{
                low++;
            }
        }
        return rotateArray[low];
    }
};
```  
**常规法:是O(n)时间复杂度**
```cpp
 int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0) return 0;
    int minNum = rotateArray[0], len = rotateArray.size();
    for (int i = 1; i < len; ++i) {
        if (rotateArray[i] < minNum) return rotateArray[i];
    }
    return minNum;
    }
```
```cpp
    int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.size() == 0) return 0;
    int  len = rotateArray.size();
    for (int i = 0; i < len-1; ++i) {
        if (rotateArray[i] > rotateArray[i+1]) return rotateArray[i+1];
    }
    return rotateArray[0]; //走到这一步了，就说明整个数组都是递增或者都是非递减的
    }

```  
### No7、斐波那契数列  
[斐波那契数列](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

>题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。

**方法一：迭代
```cpp
public class Solution {
    public int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }
        int sum = 0;
        int two = 0;
        int one = 1;
        for(int i=2;i<=n;i++){
            sum = two + one;
            two = one;
            one = sum;
        }
        return sum;
    }
}
// 时间复杂度：O(n)
//空间复杂度：O(1)

``` 

**方法二：递归**  

```cpp
public class Solution {
    public int Fibonacci(int n) {
        if(n<=1){
            return n;
        }
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}
// 时间复杂度：O(n^2)
//空间复杂度：O(1)
```

```cpp
class Solution {
public:
    int Fibonacci(int n) {
        int ans[40];
        ans[0] = 0;
        ans[1] = 1;
        for ( int i = 2; i <= n; i++){
            ans[i] = ans[i - 1] + ans[i -2];
        }
        return ans[n];
    }
};
// 时间复杂度：O(n)
//空间复杂度：O(n)
```  
### No8、 跳台阶
[跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>题目描述
>一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

**递归**
```cpp
public class Solution {
    public int JumpFloor(int n) {
        if (n == 1) return 1; 
        if (n == 2) return 2;
        return JumpFloor(n - 1) + JumpFloor(n - 2);
    }
}
O(n^2)
```

**迭代**
```cpp
class Solution {
public:
    int jumpFloor(int number) {
     if(number <= 2) return number;
        int a = 1,b = 2;
        int c = 0;
        for(int i = 3; i <= number; i++){
         c = a + b;
         a = b;
         b = c;
       
        }
        return c;
    }
};
//时间复杂度为 O(n)。
```
**迭代优化版**

```cpp
class Solution {
public:
    int jumpFloor(int number) {
     if(number <= 1) return 1;
        int a = 1,b = 1, c= 0;
        for(int i = 2; i <= number; i++){
            a = a+b;//相当于C
            b=a-b; //相当于 b = a
       
        }
        return a;
    }
};
```  
### No9、变态跳台阶  
[变态跳台阶](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

**1、递推公式**

`因为n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级 跳1级，剩下n-1级，则剩下跳法是f(n-1) 跳2级，剩下n-2级，则剩下跳法是f(n-2) 所以f(n)=f(n-1)+f(n-2)+...+f(1) 因为f(n-1)=f(n-2)+f(n-3)+...+f(1) 所以f(n)=2*f(n-1)`  
```cpp

int jumpFloorII(int number) {

    if(number==1) return 1;
    return 2*jumpFloorII(number-1);
}
```
**2、第二种方法**
```cpp
    int jumpFloorII(int number) {

        if(number==1) return 1;
        int count=0,a=1;
        for(int i=2;i<=number;++i){
            count=a*2;
            a=count;
        }
        return count;
    }

```
### No10、矩阵覆盖  
[矩阵覆盖 ](https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

>题目描述： 
`我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
比如n=3时，2*3的矩形块有3种覆盖方法：` 

**实际上和跳台阶问题原理一样**
**1 递归法**
```cpp
int rectCover(int number) {

        if(number<=2) return number;       
        return rectCover(number-1)+rectCover(number-2);
    }
```  
**2 迭代法**  
```cpp
    int rectCover(int number) {
	if (number <= 2) {
		return number;
	}
	int first = 1, second = 2, third = 3;
	for (int i = 3; i <= number; ++i) {
		third = first + second;
		first = second;
		second = third;
	}
	return third;
    }

```  
### No11、二进制中1的个数   
[二进制中1的个数](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>题目描述
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。 

**方法一：bitset的运用** 
```cpp
int  NumberOf1(int n) {
	return bitset<32>(n).count();
	}
```
或者可以直接这样
```cpp
int  NumberOf1(int n) {

	bitset<32> bit(n);//将其初始化为 32 位，不足 32 位的前面补齐即可
	return bit.count();// 返回其中为 1 的个数
}

```   
**方法二：官方的做法**
```cpp

 int NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
         }
        return count;
    }

```
### No12、数值的整数次方  
[数值的整数次方](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
>题目描述：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0。不得使用库函数，同时不需要考虑大数问题，也不用考虑小数点后面0的位数。

>力扣大牛题解

```cpp
    double myPow(double x, int n) {
        if( n == 0) return 1;
        if( x == 0.0) return 0;
        long  exp = n;//
        if(n < 0) {
            exp = n* (-1.0);//，当n == INT_MIN时正数时大于INT_MAX的，所以要用一个大于 INT_MAX的类型来保存，同时在将他转正的时候， n*(-1)的结果依然是一个 int，此时的int是个隐藏类型，然后才将这个结果赋值给 exp，所以用来保存结果值的不应该是个int型，我们用double型的 -1 ,这样就可以将相乘的结果值保存为一个 double类型了，然后再进行赋值
        } 
        
        double res = 1.0;
        while(exp != 0){
            if( (exp &1) == 1 ){
                res *=x;
            }
            x *=x;
            exp >>= 1;
        }

        return n<0 ? 1/res: res;

    }

```

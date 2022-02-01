<p id="Algorithm basics"></p>


<h1 align="center">《Algorithm basics》</h1>

## 算法基本知识  
### 什么是稳定排序、原地排序、时间复杂度、空间复杂度：  

1、稳定排序：如果 a 原本在 b 的前面，且 a == b，排序之后 a 仍然在 b 的前面，则为稳定排序。

2、非稳定排序：如果 a 原本在 b 的前面，且 a == b，排序之后 a 可能不在 b 的前面，则为非稳定排序。

3、原地排序：原地排序就是指在排序过程中不申请多余的存储空间，只利用原来存储待排数据的存储空间进行比较和交换的数据排序。

4、非原地排序：需要利用额外的数组来辅助排序。

5、时间复杂度：一个算法执行所消耗的时间。

6、空间复杂度：运行完一个算法所需的内存大小

## 十大排序一图总览
![](https://github.com/lph6755065/Algorithm/blob/main/picture/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f67682f666f7274686573706164612f6d65646961496d6167653240342e332f3230323130352f515125453625383825414125453525394225424532303231303532333136313031302e706e67.png)

## 稳定排序

冒泡排序（bubble sort） — O(n2)
插入排序 （insertion sort）— O(n2)
归并排序 （merge sort）— O(n log n)
Timsort  O(n) / O (nlogn)

## 非稳定排序

> 面试考察中一般问快排，选择，希尔，堆这几种非稳定排序

选择排序 （selection sort）— O(n2)
希尔排序 （shell sort）— O(n log n)
堆排序 （heapsort）— O(n log n)
快速排序 （quicksort）— O(n log n)

<p id="冒泡排序"></p>

## 1、冒泡排序
> 冒泡排序就是把小的元素往前调或者把大的元素往后调，比较是相邻的两个元素，再进行交换。
* 冒泡排序是稳定的
    * 如果两个元素相等，不会把他们俩交换一下的；如果两个相等的元素没有相邻，那么即使通过前面的两两交换把两个相邻起来，这时候也不会交换，所以相同元素的前后顺序并没有改变，所以冒泡排序是一种稳定排序算法。  
> 以下是动态演示过程

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly91c2VyLWdvbGQtY2RuLnhpdHUuaW8vMjAxOS8yLzE1LzE2OGYxMGExYTlhMTVkNDc?x-oss-process=image/format,png)
> 算法过程
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

~~~cpp
void bubbleSort(vector<int>& a, int n) {
	for (auto i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
~~~

> 时间复杂度 o(n^2) ，空间 o 1， 原地算法，稳定

~~~cpp
void bubbleSort(vector<int>& nums) {

	int len = nums.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if (nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j + 1]);
		}
	}
}
~~~ 
**冒泡优化版本**

~~~cpp
#include <iostream>
#include <vector>

//using namespace std;

using std::cout;
using std::endl;
using std::vector;
using std::swap;

void print(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    bool flag = false;
    for (int i = 0; i < n - 1; ++i) {//i = 0 起，循环了n - 1趟，更符合规范理解
    //for (int i = 0; i < n; ++i) {//i = 0 起，循环了n 趟，不影响结果
        flag = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                //某一趟排序中，只要发生一次元素交换，flag就从false变为了true
                //也即表示这一趟排序还不能确定所剩待排序列是否已经有序，应继续下一趟循环
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        //但若某一趟中一次元素交换都没有，即依然为flag = false
        //那么表明所剩待排序列已经有序
        //不必再进行趟数比较，外层循环应该结束，即此时if (!flag) break; 跳出循环
        /* if (flag) { break; } */
        if (!flag) { break; }
    }
}

int main() {
    vector<int> nums = { 8,9,1,4,2,3,6,7,5,5 };
    bubbleSort(nums);
    print(nums);

    return 0;
}
~~~  

<p id="选择排序"></p>  

## 2、选择排序 
> 选择排序是给每个位置选择当前元素最小的，比如给第一个位置选择最小的，在剩余元素里面给>二个元素选择第二小的，依次类推，直到第n-1个元素，第n个 元素不用选择了，因为只剩下它一个最大的元素了。

* 选择排序是非稳定的 
	* 在一趟选择，如果当前元素比一个元素小，而该小的元素又出现在一个和当前元素相等的元素后面，那么 交换后稳定性就被破坏了。 
> 以下是动态演示过程

![](https://camo.githubusercontent.com/48dfb4ffc6191670d24da4c4336ecb175687d4bd353ff274a487bfdfddadd816/68747470733a2f2f696d67636f6e766572742e6373646e696d672e636e2f6148523063484d364c793931633256794c57647662475174593252754c6e687064485575615738764d6a41784f5338794c7a45354c7a45324f5441304d7a4e6b4f5446695a475931596a593f782d6f73732d70726f636573733d696d6167652f666f726d61742c706e67)
> 算法过程

1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
3. 以此类推，直到所有元素均排序完毕
4. 时间负复杂度：O(n^2)，空间O（1），非稳定排序，原地排序
> 动态演示过程

![](https://camo.githubusercontent.com/bfb324050cce10e7151411168440c2cb440f028083d3158f1fe967d288b6eaf9/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f67682f666f7274686573706164612f6d65646961496d6167653240342e332f3230323130352f2545392538302538392545362538422541392545362538452539322545352542412538462e676966) 
**代码**

~~~c++
void selectionSort(vector<int>& a, int n) {
	int minIndex;
	for (int i = 0; i < n; ++i) {
		minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[minIndex]) minIndex = j;
		}
		swap(a[i], a[minIndex]);	
	}
}

~~~



~~~cpp
void selectSort(vector<int>& nums) {
	int len = nums.size();
	int minIndex = 0;
	for (int i = 0; i < len; ++i) {
		minIndex = i;
		for (int j = i + 1; j < len; ++j) {
			if (nums[j] < nums[minIndex]) minIndex = j;
		}
		swap(nums[i], nums[minIndex]);
	}
}
~~~
<p id="插入排序"></p>


## 3、插入排序

> 插入排序是在一个已经有序的小序列的基础上，一次插入一个元素。当然，刚开始这个有序的小序列只有1个元素，就是第一个元素。比较是从有序序列的末尾开 始，也就是想要插入的元素和已经有序的最大者开始比起，如果比它大则直接插入在其后面，否则一直往前找直到找到它该插入的位置。

* 如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以**插入排序是稳定**的。 
![](https://camo.githubusercontent.com/e669617ee9fda89a018991c5662944b347d6cd13243641ad8f46f0696bcf6cd8/68747470733a2f2f696d67636f6e766572742e6373646e696d672e636e2f6148523063484d364c793931633256794c57647662475174593252754c6e687064485575615738764d6a41784f5338794c7a45314c7a45324f4759784d446b335a6a686a4d7a55784e54493f782d6f73732d70726f636573733d696d6167652f666f726d61742c706e67)
> 算法过程

1.从第一个元素开始，该元素可以认为已经被排序

2.取出下一个元素，在已经排序的元素序列中从后向前扫描

3.如果该元素（已排序）大于新元素，将该元素移到下一位置

4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置

5.将新元素插入到该位置后

6.重复步骤2~5
**代码**
时间复杂度 on^2 空间 o1，稳定排序，原地排序

比较简单易懂的方式
```cpp
void insert(int array[],int size) {
            int tmp;
            for(int i=1;i<size;i++){
                tmp = array[i];  //将当前位置的数给tmp
                int j = i;
                for(;j>0&&array[j-1]>tmp;j--){
                /*
                往右移，腾出左边的位置,
                array[j-1]>tmp:大于号是升序排列，小于号是降序排列
               */
                array[j] = array[j-1];
        }
        //将当前位置的数插入到合适的位置
        array[j] = tmp;
        }
    }
```


```cpp
void print(vector<int>& a, int n, int i) {
	cout << "step"<< i << ": ";
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}
void insertionSort(vector<int>& a, int n) {//{ 9,1,5,6,2,3 }
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {   //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入
			int j = i - 1;
			int x = a[i];     //复制为哨兵，即存储待排序元素
			//a[i] = a[i - 1];           //先后移一个元素，可以不要这一句，跟循环里面的功能重复了
			while (j >= 0 && x < a[j]) {   //查找在有序表的插入位置,还必须要保证j是>=0的 因为a[j]要合法
				a[j + 1] = a[j]; //元素后移
				j--;     // j坐标前移
			}
			a[j + 1] = x;     //插入到正确位置
		}

		print(a, n, i);      //打印每趟排序的结果
	}
}

```
```cpp
所用的数据： vector<int> nums = {8,9,1,4,2,3,6,7,5,5};
打印结果
step1: 8 9 1 4 2 3 6 7 5 5
step2: 1 8 9 4 2 3 6 7 5 5
step3: 1 4 8 9 2 3 6 7 5 5
step4: 1 2 4 8 9 3 6 7 5 5
step5: 1 2 3 4 8 9 6 7 5 5
step6: 1 2 3 4 6 8 9 7 5 5
step7: 1 2 3 4 6 7 8 9 5 5
step8: 1 2 3 4 5 6 7 8 9 5
step9: 1 2 3 4 5 5 6 7 8 9
```
## 4、快速排序 
> 思路

1、选取第一个数为基准

2、将比基准小的数交换到前面，比基准大的数交换到后面

3、对左右区间重复第二步，直到各区间只有一个数  

* 我们从数组中选择一个元素，我们把这个元素称之为中轴元素吧，然后把数组中所有小于中轴元素的元素放在其左边，所有大于或等于中轴元素的元素放在其右边，显然，此时中轴元素所处的位置的是有序的。也就是说，我们无需再移动中轴元素的位置。  
* 从中轴元素那里开始把大的数组切割成两个小的数组(两个数组都不包含中轴元素)，接着我们通过递归的方式，让中轴元素左边的数组和右边的数组也重复同样的操作，直到数组的大小为1，此时每个元素都处于有序的位置。  
> 动态演示过程

![](https://camo.githubusercontent.com/2885414f351ca5c30e08d7fd759e320581c003578d3406c55a33a209936ab535/68747470733a2f2f696d67636f6e766572742e6373646e696d672e636e2f6148523063484d364c793931633256794c57647662475174593252754c6e687064485575615738764d6a41784f5338794c7a45314c7a45324f4759775a5459354e7a45314f474530596a6b3f782d6f73732d70726f636573733d696d6167652f666f726d61742c706e67)


```cpp
#include<iostream>
using namespace std;
 
void print(int a[], int n)
{  
    for(int j= 0; j<n; j++)
	{  
           cout<<a[j] <<"  ";  
        }  
    cout<<endl;  
}  
 
void quickSort(int a[], int low ,int high)
{
	if(low<high)  //判断是否满足排序条件，递归的终止条件
	{
		int i = low, j = high;   //把待排序数组元素的第一个和最后一个下标分别赋值给i,j，使用i,j进行排序；
		int x = a[low];    //将待排序数组的第一个元素作为哨兵，将数组划分为大于哨兵以及小于哨兵的两部分                                   
		while(i<j)  
		{
		  while(i<j && a[j] >= x) j--;  //从最右侧元素开始，如果比哨兵大，那么它的位置就正确，然后判断前一个元素，直到不满足条件
		  if(i<j) a[i++] = a[j];   //把不满足位次条件的那个元素值赋值给第一个元素，（也即是哨兵元素，此时哨兵已经保存在x中，不会丢失）并把i的加1
		  while(i<j && a[i] <= x) i++; //换成左侧下标为i的元素开始与哨兵比较大小，比其小，那么它所处的位置就正确，然后判断后一个，直到不满足条件
		  if(i<j) a[j--] = a[i];  //把不满足位次条件的那个元素值赋值给下标为j的元素，（下标为j的元素已经保存到前面，不会丢失）并把j的加1
		} 
	        a[i] = x;   //完成一次排序，把哨兵赋值到下标为i的位置，即前面的都比它小，后面的都比它大
		quickSort(a, low ,i-1);  //递归进行哨兵前后两部分元素排序 ， low,high的值不发生变化，i处于中间
		quickSort(a, i+1 ,high);
	}
}
 
int main()
{  
    int a[10] = {8,1,9,7,2,4,5,6,10,3};  
    cout<<"初始序列：";  
    print(a,10);  
    quickSort(a,0,9);  
    cout<<"排序结果：";  
    print(a,10);  
    system("pause"); 
} 
 
 
```

~~~C++
void quickSort(vector<int>& a, int low, int high) {
	if (low >= high)		// 结束标志
		return;
	int first = low;		// 低位下标
	int last = high;		// 高位下标
	int key = a[first];		// 设第一个为基准

	while (first < last)
	{
		// 从后往前走，将比第一个小的移到前面
		while (first < last && a[last] > key)
			last--;
		if (first < last)
			a[first++] = a[last];

		//从前往后走， 将比第一个大的移到后面
		while (first < last && a[first] <= key)
			first++;
		if (first < last)
			a[last--] = a[first];
	}

	a[first] = key;
	// 前半递归
	quickSort(a, low, first - 1);
	// 后半递归
	quickSort(a, first + 1, high);
	
}


quickSort(A, 0,A.size()-1);
	for (auto a : A) {
		cout << a << endl;
	}
~~~

**三数取中**
```cpp
class Solution {
public:
	
    int midValue(vector<int>&nums , int left, int right)
    {
        
    if (left >= right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[left] < arr[right]) {
        if (arr[left] > arr[mid]) return left;
        else if (arr[right] < arr[mid]) return right;
        else return mid;
    }
    else {
        if (arr[left] < arr[mid]) return left;
        else if (arr[right] > arr[mid] ) return right;
        else return mid;
    }
    }
    void quickSort(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return ;
        //取中位数
        int mid = midValue(nums, left, right);
        swap(nums[left], nums[mid]);
        int begin = left;
        int end = right;
        int key = left;
        while(left < right)
        {
            //从右往左找，找到一个比key小的值
            while(left < right && nums[right] >= nums[key])
            {
                --right;
            }
            //从左往右找，找到一个比key大的值
            while(left < right && nums[left] <= nums[key])
            {
                ++left;
            }
            //这里说明我们已经找到了两个需要交换的数字
            swap(nums[left], nums[right]);
        }
        //这里说明交换完毕，这里我们需要将key值与right值进行交换
        //为什么是right？ 因为每次right先开始找，所以我们能保证right一定是较小值
        swap(nums[key], nums[right]);
        //这里进入递归过程
        quickSort(nums, begin, right-1);
        quickSort(nums, right+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};


```

<p id="希尔排序"></p>

## 5、希尔排序

> 希尔排序可以说是插入排序的一种变种。无论是插入排序还是冒泡排序，如果数组的最大值刚好是在第一位，要将它挪到正确的位置就需要 n - 1 次移动。也就是说，原数组的一个元素如果距离它正确的位置很远的话，则需要与相邻元素交换很多次才能到达正确的位置，这样是相对比较花时间了。

* 希尔排序就是为了加快速度简单地改进了插入排序，交换不相邻的元素以对数组的局部进行排序。

* 希尔排序的思想是采用插入排序的方法，先让数组中任意间隔为 h 的元素有序，刚开始 h 的大小可以是 h = n / 2,接着让 h = n / 4，让 h 一直缩小，当 h = 1 时，也就是此时数组中任意间隔为1的元素有序，此时的数组就是有序的了。

![](https://camo.githubusercontent.com/31d8a24e2c69ce0f9e90c0889a919e90b2707552def7d3b767723640dea347d3/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f67682f666f7274686573706164612f6d65646961496d6167653240342e332f3230323130352f3131313131312e676966)  

>优质的文章讲解：https://mp.weixin.qq.com/s/4kJdzLB7qO1sES2FEW0Low


**C++代码实现**
```cpp
void shellSortCore(vector<int>& nums, int gap, int i) {
	int inserted = nums[i];
	int j;
    //  插入的时候按组进行插入
	for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {
		nums[j + gap] = nums[j];
	}
	nums[j + gap] = inserted;
}

void shellSort(vector<int>& nums) {
	int len = nums.size();
    //进行分组，最开始的时候，gap为数组长度一半
	for (int gap = len / 2; gap > 0; gap /= 2) {
        //对各个分组进行插入分组
		for (int i = gap; i < len; ++i) {
            //将nums[i]插入到所在分组正确的位置上
			shellSortCore(nums,gap,i);
		}
	}

	for (auto a : nums) {
		cout << a << "";
	}

}
``` 
**合并一起的**  
```cpp
void shellSort(vector<int> & nums) {
    int len = nums.size();
    for (int gap = len /2 ; gap > 0; gap /= 2){ //gap >0 这里千万不能等于0 不然显示不了
        for (int i = gap; i < len; i++){
            int insert = nums[i];
            int j;
            for (j = i - gap; j >= 0 && insert < nums[j]; j -= gap){
                nums[j + gap] = nums[j];
            }
            nums[j + gap] = insert;
        }
    }
}
```
## 6、归并排序
> 将一个大的无序数组有序，我们可以把大的数组分成两个，然后对这两个数组分别进行排序，之后在把这两个数组合并成一个有序的数组。由于两个小的数组都是有序的，所以在合并的时候是很快的。
通过递归的方式将大的数组一直分割，直到数组的大小为 1，此时只有一个元素，那么该数组就是有序的了，之后再把两个数组大小为1的合并成一个大小为2的，再把两个大小为2的合并成4的 … 直到全部小的数组合并起来。

> 算法思想

1、把长度为n的输入序列分成两个长度为n/2的子序列；

2、对这两个子序列分别采用归并排序；

3、 将两个排序好的子序列合并成一个最终的排序序列。

> 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。


![](https://github.com/lph6755065/Algorithm/blob/main/picture/1632741128(1).jpg)
![](https://camo.githubusercontent.com/e887aad24f8311912b0802180ee78b0a81e829c5c70cd0edb7f77aaf02223af6/68747470733a2f2f696d67636f6e766572742e6373646e696d672e636e2f6148523063484d364c793931633256794c57647662475174593252754c6e687064485575615738764d6a41784f5338794c7a45314c7a45324f4759784d4467344f5441334f57466d4d546b3f782d6f73732d70726f636573733d696d6167652f666f726d61742c706e67)

**1、// 归并排序（C++-迭代版）** 
```cpp
template<typename T>
void merge_sort(T arr[], int len) {
	T* a = arr;
	T* b = new T[len];
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			cout << low << " " << mid << " " << high << endl;
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}

		swap(a, b); //交换a b 地址
        //T* temp = a;
        //  a = b;
        //  b = temp;

	}

	//if (a != arr) {
	//	for (int i = 0; i < len; i++)
	//		b[i] = a[i];
	//	b = a;
	//}
       
    /*
    十分严谨的一种安排
    每次排序都要交换 a、b 值（数组首地址）
1、if(a != arr)：如果排序结束后，a 值为原来数组 b 首地址，此时 arr 与 b 相同，arr 数组内容不是最终的结果，
2、循环内容：把 a数组内容复制到数组 b（数组arr）
3、b = a ：循环结束后，让 b 指向它原来的数组首地址，以便 delete[]
    
    */
	delete[] b;
}

```
**2、// 归并排序（C++-递归版）**
```cpp
template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

// merge_sort
template<typename T>
void merge_sort(T arr[], const int len) {
    T reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

```
**3、vector 类型的递归 ，就记这一种** 
```cpp
void mergeSortCore(vector<int>& data, vector<int>& dataTemp, int low, int high) {

	if (low >= high) return;
	int len = high - low, mid = low + len / 2;
	int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
	mergeSortCore(data, dataTemp, start1, end1);
	mergeSortCore(data, dataTemp, start2, end2);
	int index = low;
	while (start1 <= end1 && start2 <= end2) {
		dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
	}

	while (start1 <= end1) {
		dataTemp[index++] = data[start1++];
	}


	while (start2 <= end2) {
		dataTemp[index++] = data[start2++];
	}

	for (index = low; index <= high; ++index) {
		data[index] = dataTemp[index];
	}
}


void mergeSort(vector<int>& data) {
	int len = data.size();
	vector<int> dataTemp(len, 0);
	mergeSortCore(data, dataTemp, 0, len - 1);
}

```  
**节约时间的一种递归归并排序**
```cpp
void mergeSortCore(vector<int>& nums, vector<int>& copy, int begin, int end) {
	if (begin >= end) return;
	int mid = begin + (end - begin) / 2;
	int low1 = begin, high1 = mid, low2 = mid + 1, high2 = end;
	mergeSortCore(copy, nums, low1, high1);//这里减少了copy向nums的赋值部分，千万注意不要把copy 和 nums赋值反了
	mergeSortCore(copy, nums, low2, high2);

	int copyIndex = low1;
	while (low1 <= high1 && low2 <= high2) {
		copy[copyIndex++] = nums[low1] < nums[low2] ? nums[low1++] : nums[low2++];
	}
	while (low1 <= high1) {
		copy[copyIndex++] = nums[low1++];
	}
	while (low2 <= high2) {
		copy[copyIndex++] = nums[low2++];
	}

	cout << begin << " " << end << endl;
	for (auto a : copy) {
		cout << a << " ";
	}
	cout << endl;

}

void mergeSort(vector<int> nums) {

	for (auto a : nums) {
		cout << a << " ";
	}
	cout << endl;
	
	
	vector<int> copyNums(nums);//这里要借助一个一模一样的数组的
	mergeSortCore(nums, copyNums, 0, nums.size() - 1);
	nums.assign(copyNums.begin(), copyNums.end());//到最后copy数组是排序好的，记得要赋值一下
		
	for (auto a : nums) {
		cout << a << " ";
	}
}

``` 
**稍微完整版** 
```cpp
void print(vector<int>& nums) {
	for (auto a : nums)
		cout << a << " ";
	cout << endl;

}

void mergeSort(vector<int>& data, vector<int>&temp,int begin,int end) {
	if (begin >= end) return;      //注意大于等于
	int low1 = begin, high2 = end, mid = begin + (end - begin) / 2;
	int high1 = mid, low2 = mid + 1;
	print(data);
	mergeSort(temp, data, low1, high1);           //注意数组位置
	mergeSort(temp, data, low2, high2);
	int index = low1;
	while (low1 <= high1 && low2 <= high2) {
		temp[index++] = data[low1] < data[low2] ? data[low1++] : data[low2++];  //注意下标次序
	}
	while (low1 <= high1) {                    //注意小于等于
		temp[index++] = data[low1++];     //注意次序
	}

	while (low2 <= high2) {
		temp[index++] = data[low2++];    //注意次序
	}

}

void main(){
    
    
    vector<int> nums = { 5,3,5,6,1,4,9,10,6,2};
	vector<int> temp(nums);
	mergeSort(nums,temp , 0, nums.size() - 1);
    nums.assign(temp.begin(),temp.end());
}

```
## 7 堆排序
> 首先堆heap是一种数据结构，是一棵完全二叉树且满足性质：所有非叶子结点的值均不大于或均不小于其左、右孩子结点的值.

**堆排序思想**
* 堆排序的基本思想是利用heap这种数据结构(可看成一个完全二叉树)，使在排序中比较的次数明显减少。

* 堆排序的时间复杂度为O(n*log(n))， 非稳定排序，原地排序(空间复杂度O(1))。

* 堆排序的关键在于建堆和调整堆，下面简单介绍一下建堆的过程：

第1趟将索引0至n-1处的全部数据建大顶(或小顶)堆，就可以选出这组数据的最大值(或最小值)。将该堆的根节点与这组数据的最后一个节点交换，就使的这组数据中最大(最小)值排在了最后。

第2趟将索引0至n-2处的全部数据建大顶(或小顶)堆，就可以选出这组数据的最大值(或最小值)。将该堆的根节点与这组数据的倒数第二个节点交换，就使的这组数据中最大(最小)值排在了倒数第2位。

…

第k趟将索引0至n-k处的全部数据建大顶(或小顶)堆，就可以选出这组数据的最大值(或最小值)。将该堆的根节点与这组数据的倒数第k个节点交换，就使的这组数据中最大(最小)值排在了倒数第k位。

* 其实整个堆排序过程中, 我们只需重复做两件事：

建堆(初始化+调整堆, 时间复杂度为O(n));

拿堆的根节点和最后一个节点交换(siftdown, 时间复杂度为O(n*log n) ).

* 因而堆排序整体的时间复杂度为O(n*log n).

**注意代码**
```cpp
void heapify(vector<int>& nums, int n, int i)//对有一定顺序的堆，
//当前第i个结点取根左右的最大值（这个操作称heapfiy）
{
	int l = i * 2 + 1, r = i * 2 + 2;
	int max = i;
	if (l<n && nums[l]>nums[max])
		max = l;
	if (r<n && nums[r]>nums[max])
		max = r;
	if (max != i)
	{
		swap(nums[max], nums[i]);
		heapify(nums, n, max);
	}
}
void heapify_build(vector<int>& nums, int n)//建立大根堆，从树的倒数第二层第一个结点开始，
//对每个结点进行heapify操作，然后向上走
{
	int temp = (n - 2) / 2;
	for (int i = temp; i >= 0; i--)
		heapify(nums, n, i);

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}
void heapify_sort(vector<int>& nums, int n)//建立大根堆之后，每次交换最后一个结点和根节点（最大值），
//对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
{
	heapify_build(nums, n);
	for (int i = 0; i < n; i++)
	{
		swap(nums.front(), nums[n - i - 1]);
		heapify(nums, n - i - 1, 0);
	}
}

```
**C++完整实现版本** 
```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void adjust(int arr[], int len, int index)
{
    int left = 2*index + 1;
    int right = 2*index + 2;
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx]) maxIdx = right;  // maxIdx是3个数中最大数的下标
    //如果是降序排列的话，可以直接在这里改下每次所比较的大小就好
    //if(left<len && arr[left] < arr[maxIdx]) maxIdx = left;
    //if(right<len && arr[right] < arr[maxIdx]) maxIdx = right;  // maxIdx是3个数中最大数的下标
    if(maxIdx != index)                 // 如果maxIdx的值有更新
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);       // 递归调整其他不满足堆性质的部分
    }

}
void heapSort(int arr[], int size)
{
    for(int i=size/2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
    {
        adjust(arr, size, i);
    }
    for(int i = size - 1; i >= 1; i--) //这里也可以i >= 0;不过剩最后一个元素没必要再排序了，多此一举。
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}

int main()
{
    int array[8] = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(array, 8);
    for(auto it: array)
    {
        cout<<it<<endl;
    }
    return 0;
}
```
**C语言版**
```cpp
#include <stdio.h>

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int array[], int x, int y) {
    int key  = array[x];
    array[x] = array[y];
    array[y] = key;
}

// 从大到小排序
// void Down(int array[], int i, int n) {
//     int child = 2 * i + 1;
//     int key   = array[i];
//     while (child < n) {
//         if (child + 1 < n && array[child] > array[child + 1]) {
//             child++;
//         }
//         if (key > array[child]) {
//             swap(array, i, child);
//             i = child;
//         } else {
//             break;
//         }
//         child = child * 2 + 1;
//     }
// }

// 从小到大排序
void Down(int array[], int i, int n) { // 最后结果就是大顶堆
    int parent = i;                    // 父节点下标
    int child  = 2 * i + 1;            // 子节点下标
    while (child < n) {
        if (child + 1 < n && array[child] < array[child + 1]) { // 判断子节点那个大，大的与父节点比较
            child++;
        }
        if (array[parent] < array[child]) { // 判断父节点是否小于子节点
            swap(array, parent, child);     // 交换父节点和子节点
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child = child * 2 + 1; // 换行，比较下面的父节点和子节点
    }
}

void BuildHeap(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(array, i, size);                 // 否则有的不符合大顶堆定义
    }
}

void HeapSort(int array[], int size) {
    printf("初始化数组：");
    BuildHeap(array, size); // 初始化堆
    display(array, size);   // 查看初始化结果
    for (int i = size - 1; i > 0; i--) {
        swap(array, 0, i); // 交换顶点和第 i 个数据
                           // 因为只有array[0]改变，其它都符合大顶堆的定义，所以可以从上往下重新建立
        Down(array, 0, i); // 重新建立大顶堆

        printf("排序的数组：");
        display(array, size);
    }
}

int main() {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 10};
    int size    = sizeof(array) / sizeof(int);

    // 打印数据
    printf("%d \n", size);
    printf("排序前数组：");
    display(array, size);
    HeapSort(array, size);

    return 0;
}

```
**可重载比较函数的写法**: 参考来源：https://enjoy233.blog.csdn.net/article/details/52853194?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.no_search_link
```cpp
#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
void swap(void* x, void* y, size_t sz) {
    void* t = malloc(sz);
    memcpy(t, x, sz);
    memcpy(x, y, sz);
    memcpy(y, t, sz);
    free(t);
}
void makeHeap(void* x, int i, int n, size_t sz, int(*cmp)(const void*, const void*)) {
    char* y = (char*)x;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m;
    if (l<n && (*cmp)(y + l*sz, y + i*sz)>0) m = l;
    else m = i;
    if (r<n && (*cmp)(y + r*sz, y + m*sz)>0) m = r;
    if (m != i){
        swap(y + i*sz, y + m*sz, sz);
        makeHeap(x, m, n, sz, cmp);
    }
}
void buildHeap(void* x, int n, size_t sz, int(*cmp)(const void*, const void*)) {
    for (int i = n / 2 - 1; i >= 0; i--) makeHeap(x, i, n, sz, cmp);
}
void heapSort(void* x, int n, size_t sz, int(*cmp)(const void*, const void*)) {
    buildHeap(x, n, sz, cmp);
    char* y = (char*)x;
    for (int i = n - 1; i >= 1; i--){
        swap(y, y + i*sz, sz);
        makeHeap(x, 0, --n, sz, cmp);
    }
}

void p(int* x,int n){
    for (int k = 0; k < n; k++){
        printf("%d ", x[k]);
    }
    printf("\n");
}

int less(const void* a, const void* b){
    return *((int*)a) < *((int*)b);
}
int greater(const void* a, const void* b){
    return *((int*)a) > *((int*)b);
}
int main(){
    int x[] = { 2, 3, 4, 6, 8, 2, 9, 0 };
    // 降序全排列
    heapSort(x, 8, sizeof(int), less);
    p(x, 8);
    // 升序全排列
    heapSort(x, 8, sizeof(int), greater);
    p(x, 8);
    // 最大的4个元素，在数组末尾
    heapSort(x, 4, sizeof(int), less);
    p(x, 8);
}
``` 
> 参考来源： https://github.com/forthespada/InterviewGuide/blob/main/Doc/Knowledge/%E7%AE%97%E6%B3%95/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%8D%81%E5%A4%A7%E6%8E%92%E5%BA%8F.md
## 三维矩阵化一维的运算
```cpp
#include <stdio.h> 
#include <stdlib.h>
    int main(void) {
        int arr1[3][3][3] = {{{1,2,3},{4,5,6}, {7,8,9}},
            {{10,11,12},{13,14,15}, {16,17,18}},
           {{19,20,21},{22,23,24}, {25,26,27}}};
        int arr2[27] = {0}; int row, column,p, i;

        printf("原三维：\n"); for(row = 0; row < 3; row++) {
            for(column = 0; column < 3; column++) 
            for(p = 0; p < 3; p++)
            { printf("%4d", arr1[row][column][p]);
            }
            printf("\n");
        }

        printf("\n 以 行 为 主 ："); for(row = 0; row < 3; row++) {
            for(column = 0; column < 3; column++)
             for(p = 0; p < 3; p++)
             { i =   row * 3*3 +  column*3 + p;
                arr2[i] = arr1[row][column][p];
            }
        }
        for(i = 0; i < 27; i++) printf("%d ", arr2[i]);

        printf("\n 以 列 为 主 ："); for(row = 0; row < 3; row++) {
            for(column = 0; column <3; column++)
            for(p = 0; p < 3; p++){ i = row + column * 3+p*3*3;
                arr2[i] = arr1[row][column][p];
            }
        }
        for(i = 0; i < 27; i++) printf("%d ", arr2[i]);


        printf("\n");

        return 0;
    }
```  
## 动态规划
* 0 1 背包问题
![](https://github.com/lph6755065/Algorithm/blob/main/picture/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20220129041944.png)
```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5][9] = {0};
int w[5] = {0,2,3,4,5};
int v[5] = {0,3,4,5,8};


int main()
{
    int i, j;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (w[i] > j) 
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }

    return 0;
}
```  
## 并查集 
* 是一种数据结构，主要处理不相交集合的合并问题，一些常见问题有联通子图，求最小生成树的Kruskal算法和求最近公共祖先LCA问题。  
```cpp
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXN 20001
int fa[MAXN];
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}
int find(int x) {
    if (x == fa[x])
        return x;
    else {
        fa[x] = find(fa[x]);//父节点设置为根结点
        return fa[x];       //返回父节点
    }
}

void unionn(int i, int j) {
    int i_fa = find(i);     //找到i的祖先
    int j_fa = find(j);     //找到j的祖先
    fa[i_fa] = j_fa;        //谁指向谁都可以
}

int main()
{
    int n,m,x,y,q;
    scanf("%d",&n);
    init(n);
    scanf("%d",&m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d",&x, &y);
        unionn(x, y);
    }
    scanf("%d",&q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d",&x, &y);
        if (find(x) == find(y)) {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
//输入的数据
/*
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
7 10
8 9
*/
//打印结果
/*
10 7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3
3 4
YES
7 10
NO
8 9
YES
*/
```  
## 字符串比较大小 
```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

bool compare(char s1[], char s2[]) {
    int u = strlen(s1), v = strlen(s2);
    if (u != v) return u > v;
    for (int i = 0; i < u; ++i) {
        if (s1[i] != s2[i]) return s1[i] > s2[i];
    }
    return true;
}
int main()
{
   char s1[] = {"3222"};
   char s2[] = {"2333"};
  if(compare(s1, s2)){
        cout <<"true  s1 > s2";   
  }
  else{
      cout <<"false  s1 < s2";
  }
    return 0;
}
```  
## 迪杰斯特拉(Dijkstra)最短路径算法
> 算法介绍
* 迪杰斯特拉算法是由荷兰计算机科学家在1956年发现的算法，此算法使用类似广度优先搜索的方法解决了带权图的单源最短路径问题。它是一个贪心算法。  
> 算法思想
* 1. 选定一个点，这个点满足两个条件：1.未被选过，2.距离最短
* 2. 对于这个点的所有邻近点去尝试松弛
> 算法步骤  

![](https://github.com/lph6755065/Algorithm/blob/main/picture/20201128093946374.gif)
首先，可以设置两个集合分别是A和B，A用来存放已经求出最短路径的点，B用来存放还未计算出最短路径的点   
假设我们将源点source选择在” 0 "这个点。一开始所有点到达源点0的距离我们假设为∞，代表不可达。源点0到自己本身的距离为0，初始化如下：此时A集合为：{0}，B集合为：{1，2，3，4，5，6}   
1. 第一步：从0点开始，更新和0邻接的所有点的距离，此时，因为与0邻接的有1和2，并且到这两个点的距离，小于原来的∞距离，所以要将这两个点到0的距离都进行更新  
2. 第二步：从B集合里面选择一个点加入A集合，这个点要满足距离0点的距离最短，因此我们选择2这个点添加到集合A，此时集合A变为：{0,2}，集合B变为：{1，3，4，5，6}  
3. 第三步：选择刚刚加入的这个2点，更新所有与2点邻接的点，因为与2邻接的点有3和5，并且这两个点到0点的距离小于原来它们到0点的距离∞
4. 第四步：从B集合里面选择1这点加入到集合A中，因为1这个点在B集合中距离0最近，如下图，此时A集合变成：{0,1,2}，B集合变成：{3,4,5,6}
5. 第五步：选择刚刚加入的1这个点，更新1所有的邻接点，它的邻接点有3和4，因为此刻从0到3的距离为6，小于原来0到3的距离8，因此这个时候到6的距离更新为6(5+1)，此时0到4的距离被更新为11
6. 第六步：从B集合中选择一个距离0点最小距离的点，加入集合A，此时可以选择3这个点，因为3这个点在B集合里面距离0点最近，此时集合A变为：{0,1,2,3}，集合B变为：{4,5,6}
7. 第七步：从刚刚选择的这个3点出发，更新3所有的邻接点，3的邻接点有4和5，原来4到0的距离为11，3加进来之后，4到0的距离为7，小于原来的11，所以要更新，原来5到0的距离为10，3加进来之后，5到0的距离为8，所以也要更新
8. 第八步：从B集合中选择一个距离0点最小距离的点，因此我们选择4点，因为此时4这个点距离0点最近，为7，于是集合A变成：{0,1,2,3,4}，集合B变成：{5,6}
9. 第九步：从刚刚选择的点4出发，更新它的所有邻接点，4的邻接点有6，原来6到0的距离为∞，此时4加进来之后6到0的距离变为14，它小于∞，因此要更新6到0的距离，更新为11
10. 第十步：从集合B中选择一个距离0点最短距离的点，加入集合，此时我们可以选择5这个点，因为这个时候它在B集合中是距离0点最近的点，于是集合A变为：{0,1,2,3,4,5}，集合B变为{6}
11. 第11步：从刚刚选择的这个点出发，也就是从点5出发，更新它所有的邻接点，此时5的邻接点为6，原来0到6的距离为14，此时点5加进来之后，0到6的距离变为了11，因此需要更新0到6的距离
12. 第12步：因为B集合只剩下一个点，为点6，直接将其加入A集合即可，此时A集合变为:{0,1,2,3,4,5,6}，B集合变为:{ }，至此，从0点到其它所有点的最短路径已经算出来了  
> 注意事项
1.不能处理带有负权边的图(可能得不到最优解，认为是无法处理负权图)，只能处理非负权图。
2.只能解决单源最短路径问题
> 核心代码 
![]()

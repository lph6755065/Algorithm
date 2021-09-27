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

<p id="希尔排序"></p>

## 5、希尔排序

> 希尔排序可以说是插入排序的一种变种。无论是插入排序还是冒泡排序，如果数组的最大值刚好是在第一位，要将它挪到正确的位置就需要 n - 1 次移动。也就是说，原数组的一个元素如果距离它正确的位置很远的话，则需要与相邻元素交换很多次才能到达正确的位置，这样是相对比较花时间了。

* 希尔排序就是为了加快速度简单地改进了插入排序，交换不相邻的元素以对数组的局部进行排序。

* 希尔排序的思想是采用插入排序的方法，先让数组中任意间隔为 h 的元素有序，刚开始 h 的大小可以是 h = n / 2,接着让 h = n / 4，让 h 一直缩小，当 h = 1 时，也就是此时数组中任意间隔为1的元素有序，此时的数组就是有序的了。


优质的文章讲解：https://mp.weixin.qq.com/s/4kJdzLB7qO1sES2FEW0Low
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
## 6、归并排序
> 将一个大的无序数组有序，我们可以把大的数组分成两个，然后对这两个数组分别进行排序，之后在把这两个数组合并成一个有序的数组。由于两个小的数组都是有序的，所以在合并的时候是很快的。
通过递归的方式将大的数组一直分割，直到数组的大小为 1，此时只有一个元素，那么该数组就是有序的了，之后再把两个数组大小为1的合并成一个大小为2的，再把两个大小为2的合并成4的 … 直到全部小的数组合并起来。
> 算法思想

1、把长度为n的输入序列分成两个长度为n/2的子序列；

2、对这两个子序列分别采用归并排序；

3、 将两个排序好的子序列合并成一个最终的排序序列。

> 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。
![](https://camo.githubusercontent.com/31d8a24e2c69ce0f9e90c0889a919e90b2707552def7d3b767723640dea347d3/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f67682f666f7274686573706164612f6d65646961496d6167653240342e332f3230323130352f3131313131312e676966)
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
	if (begin >= end) return;
	int low1 = begin, high2 = end, mid = begin + (end - begin) / 2;
	int high1 = mid, low2 = mid + 1;
	print(data);
	mergeSort(temp, data, low1, high1);
	mergeSort(temp, data, low2, high2);
	int index = low1;
	while (low1 <= high1 && low2 <= high2) {
		temp[index++] = data[low1] < data[low2] ? data[low1++] : data[low2++];
	}
	while (low1 <= high1) {
		temp[index++] = data[low1++];
	}

	while (low2 <= high2) {
		temp[index++] = data[low2++];
	}

}

void main(){
    
    
    vector<int> nums = { 5,3,5,6,1,4,9,10,6,2};
	vector<int> temp(nums);
	mergeSort(nums,temp , 0, nums.size() - 1);
    nums.assign(temp.begin(),temp.end());
}

```

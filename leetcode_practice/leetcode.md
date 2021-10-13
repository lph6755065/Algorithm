
## 力扣一些算法题 

**马拉车**
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() < 2) {
            return s;
        }
        //对原始字符串做处理，将abc变成#a#b#c#
        string tmp = "#";
        for(char c : s) {
            tmp += c;
            tmp += "#";
        }
        tmp += "#";
        int n = tmp.size();
        //right表示目前计算出的最右端范围，right和左边都是已探测过的
        int right = 0;
        //center最右端位置的中心对称点
        int center = 0;
        int start = 0;
        int maxLen = 0;
        //p数组记录所有已探测过的回文半径，后面我们再计算i时，根据p[i_mirror]计算i
        vector<int> p(n, 0);
        //从左到右遍历处理过的字符串，求每个字符的回文半径
        for(int i = 0; i < n; ++i) {
            //根据i和right的位置分为两种情况：
            //1、i<=right利用已知的信息来计算i
            //2、i>right，说明i的位置时未探测过的，只能用中心探测法
            if(right >= i) {
                //这句是关键，不用再像中心探测那样，一点点的往左/右扩散，根据已知信息
                //减少不必要的探测，必须选择两者中的较小者作为左右探测起点
                int minArmLen = min(right - i, p[2 * center - i]);
                p[i] = expand(tmp, i - minArmLen, i + minArmLen);
            }
            else {
                //i落在right右边，是没被探测过的，只能用中心探测法
                p[i] = expand(tmp, i, i);
            }
            //大于right，说明可以更新最右端范围了，同时更新center
            if(i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
            //找到了一个更长的回文半径，更新原始字符串的start位置
            if(p[i] > maxLen) {
                maxLen = p[i];
                start = (i - p[i]) / 2;
            }
        }
        //根据start和maxLen，从原始字符串中截取一段返回
        return s.substr(start, maxLen);
    }

private:
    //以left和right为起点，计算回文半径，由于while循环退出后left和right各多走了一步
    //所以在返回的总长度时要减去2
    int expand(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }
};

作者：wang_ni_ma
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/tu-jie-ma-la-che-suan-fa-by-wang_ni_ma-if33/
来源：力扣（LeetCode）
```
## 69求平方数
>三种方法总结，类似的也可以求立方数

给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

**方法一：袖珍计算器算法**
[](https://github.com/lph6755065/Algorithm/blob/main/leetcode_practice/picture/1634111729(1).jpg) 
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};
//时间复杂度：O(1)
//空间复杂度：O(1)
```  
**方法二：二分查找**  

`由于 x 平方根的整数部分 ans 是满足 k^2 <= x的最大 k 值，因此我们可以对 k 进行二分查找，从而得到答案。
二分查找的下界为 0，上界可以粗略地设定为 x。在二分查找的每一步中，我们只需要比较中间元素 mid 的平方与 x 的大小关系，并通过比较的结果调整上下界的范围。由于我们所有的运算都是整数运算，不会存在误差，因此在得到最终的答案 ans 后，也就不需要再去尝试  ans+1 了。` 
```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
//时间复杂度：O(logx)
//空间复杂度：O(1)
```
**方法三：牛顿迭代**
> 牛顿迭代法是一种可以用来快速求解函数零点的方法。
为了叙述方便，我们用 C 表示待求出平方根的那个整数。显然，C 的平方根就是函数y = f(x)=x^2 - C的零点.  

* 牛顿迭代法的本质是借助泰勒级数，从初始值开始快速向零点逼近。我们任取一个 x_0作为初始值，在每一步的迭代中，我们找到函数图像上的点 (x_i, f(x_i))，过该点作一条斜率为该点导数 f'(x_i)的直线，与横轴的交点记为 x_{i+1}， x_{i+1}x 相较于 x_i而言距离零点更近。在经过多次迭代后，我们就可以得到一个距离零点非常接近的交点。
[](https://github.com/lph6755065/Algorithm/blob/main/leetcode_practice/picture/1634113249(1).jpg)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};
//时间复杂度：O(logx)
//空间复杂度：O(1)
```  
> 这种题目一定要注意边界和特殊点检验。








#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution1
{
    //arr = {0 24 34 41 58 62 64 67 69 78}
    //在已经有序的序列中，查找某个数
    //二分查找
public:
    bool binarySearch(vector<int> &arr,int l,int r,int value)
    {
        if(l>r) //l为子序列中 最左边元素的下标 r为子序列中 最右边元素的下标  当l>r时 说明没找到
        {
            return false;
        }
        int mid = (l+r)/2;  //求中间位置
        if(arr[mid]==value) //找到了 返回true
        {
            return true;
        }
        else if(arr[mid]<value) //value比中间值大 在mid右边找
        {
            return binarySearch(arr,mid+1,r,value);
        }
        else    //value比中间值下  在mid左边找
        {
            return binarySearch(arr,l,mid-1,value);
        }
        
    }
    void test()
    {
        vector<int> arr;
        for(int i=0;i<10;i++)
        {
            arr.push_back(rand()%100);  //生成100以内的随机数
        }
        sort(arr.begin(),arr.end());    //排序
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
        cout << binarySearch(arr,0,arr.size()-1,67) << endl;
    }

};

class Solution2
{
    //快速排序
    //1.选基准数
    //2.把小于基准数的调到左边
    //3.把大于基准数的调到右边
    //对基准数左边的子序列重复1，2，3
    //对基准数右边的子序列重复1，2，3
    //直到子序列长度为0 或 为1，默认有序
    //时间复杂度：
    //最好：O(nlogn)
    //最坏：O(n^2)  当原始序列有序时
public:
    int partition(vector<int> &arr,int i,int j)
    {
        int v = arr[i]; //默认取第一个数为基准数
        while (i<j)
        {
            while (i<j && arr[j]>=v)    //从右边开始 i<j arr[j]>v时 没有移动 j--
            {
                j--;
            }
            if(i<j) //如果i<j 说明存在arr[j]<v 移到左边  并将i++
            {
                arr[i++] = arr[j];
            }
            while (i<j && arr[i]<v) //从左边开始 i<j arr[i]<v 没有移动 i++;
            {
                i++;
            }
            if(i<j) //如果i<j 说明存在arr[j]>v  移到右边 并将j--
            {
                arr[j--] = arr[i];
            }
        }
        //退出循环 说明i==j
        arr[i] = v; //将基准数放入
        return i;   //返回新基准数的位置
    }

    void quickSort(vector<int> &arr,int l,int r)
    {
        if(l>=r)
        {
            return;
        }
        int pos = partition(arr,l,r);
        quickSort(arr,l,pos-1);
        quickSort(arr,pos+1,r);
    }
    void test()
    {
        vector<int> arr;
        for(int i=0;i<10;i++)
        {
            arr.push_back(rand()%100);
        }
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
        quickSort(arr,0,arr.size()-1);
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};


class Solution3
{
    //找top K问题
    //找第k小  或 前k小
    //找第k大  或 前k大
    //只是找 没有说对前k个排序
    //利用快速排序的划分函数
public:
    int partition(vector<int> &arr,int i,int j)
    {
        int v = arr[i]; //划分函数
        while (i<j)
        {
            while (i<j && arr[j]>=v)
            {
                j--;
            }
            if(i<j)
            {
                arr[i++] = arr[j];
            }
            while (i<j && arr[i]<v)
            {
                i++;
            }
            if(i<j)
            {
                arr[j--] = arr[i];
            }
        }
        arr[i] = v;
        return i;
    }
    void topK(vector<int> &arr,int l,int r,int k)
    {
        if(l>r) //如果l>r，说明k值非法
        {
            cout << "no found" << endl;
            return;
        }
        int pos = partition(arr,l,r);   //基准数新的位置
        if((pos+1)==k)  //如果等于k 说明pos-1为第k小的数
        {
            cout << k << "th little:" << arr[pos] << endl;  //打印
        }
        else if((pos+1)<k)  //如果<k，在右边找
        {
            topK(arr,pos+1,r,k);
        }
        else    //如果>k，在左边找
        {
            topK(arr,l,pos-1,k);
        }      
    }
    void test()
    {
        vector<int> arr;
        for(int i=0;i<10;i++)
        {
            arr.push_back(rand()%100);
        }
        topK(arr,0,arr.size()-1,5);

        sort(arr.begin(),arr.end());
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

class Solution4
{
    //归并排序
    //将原始序列对半划分
    //直到划分为子序列的长度为1，认为自然有序
    //然后向上合并，即有序的两个子序列合并
    //直到得到问题最后的解
public:
    void merge(vector<int> &arr,int l,int mid,int r)
    {
        vector<int> tmp;    //临时开辟的变量 存储两个子序列排好序的结果
        tmp.reserve(r-l+1);
        int i = l;  //初始化两个序列的初始下标
        int j = mid+1;
        while (i<=mid && j<=r)  //当i<mid 且 j<r  比较两个元素
        {
            if(arr[i]<arr[j])   //如果arr[i]小 先加arr[i] i++
            {
                tmp.push_back(arr[i++]);
            }
            else    //如果arr[j]小 加arr[j] j++
            {
                tmp.push_back(arr[j++]);
            }
        }
        while (i<=mid)  //第一个长  把第一个剩下的全加进去
        {
            tmp.push_back(arr[i++]);
        }
        while (j<=r)    //第二个长  把第一个剩下的全加进去
        {
            tmp.push_back(arr[j++]);
        }
        for(i=l;i<=r;i++)   //把排好序的结果 放到原数组中
        {
            arr[i] = tmp[i-l];
        }

    }
    void mergeSort(vector<int> &arr,int i,int j)
    {
        if(i>=j)    //如果只剩一个了 默认有序 回溯
        {
            return;
        }
        int mid = (i+j)/2;  //找中间位置
        mergeSort(arr,i,mid);   //继续划分左半边
        mergeSort(arr,mid+1,j); //划分右半边
        merge(arr,i,mid,j); //对已经排好序的两个子序列 合并，进一步排序

    }
    void test()
    {
        vector<int> arr;
        for(int i=0;i<10;i++)
        {
            arr.push_back(rand()%100);
        }
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
        mergeSort(arr,0,arr.size()-1);
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

class Solution5
{
    //合并k个有序链表
public:

    struct ListNode //链表节点定义
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr) {}
    };
    
    ListNode* initNode(initializer_list<int> list)  //初始化一个链表 返回第一个节点  不包含头节点
    {
        //initializer_list是一个迭代器对象
        ListNode* Head = nullptr;
        ListNode* p = nullptr;
        for(auto it = list.begin();it!=list.end();it++)
        {
            if(Head==nullptr)
            {
                Head = new ListNode(*it);
                p = Head;
            }
            else
            {
                p->next = new ListNode(*it);
                p = p->next;
            }
            
        }
        return Head;
    }

    ListNode* merge(ListNode* p1,ListNode* p2)  //合并2个有序链表
    {
        ListNode* Head = nullptr;
        ListNode* p = nullptr;
        if(p1==nullptr) //如果p1为空 返回p2
        {
            return p2;
        }
        if(p2==nullptr) //如果p2为空 返回p1
        {
            return p1;
        }
        if(p1->val<p2->val) //处理第一个节点 看是p1的还是p2的
        {
            Head = p1;
            p = Head;
            p1 = p1->next;
        }
        else
        {
            Head = p2;
            p = Head;
            p2 = p2->next;
        }
        while (p1!=nullptr && p2!=nullptr)  //当2个链表都不为空时
        {
            if(p1->val<p2->val) //p1小 加p1
            {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            }
            else    //p2小 加p2
            {
                p->next = p2;
                p = p2;
                p2 = p2->next;  //p2向后移一位
            }
        }
        if(p1!=nullptr) //p1没空 加p1
        {
            p->next = p1;
        }
        if(p2!=nullptr) //p2没空 加p2
        {
            p->next = p2;
        }
        return Head;    //返回合并后的新头节点
    }

    ListNode* mergeK(vector<ListNode*> vec,int l,int r) //合并k个有序链表
    {
        if(l>=r)    //此时只剩一个链表，直接返回
        {
            return vec[l];
        }
        int mid = (l+r)/2;  //求中间值
        ListNode* left = mergeK(vec,l,mid); //合并mid往左的所有链表
        ListNode* right = mergeK(vec,mid+1,r);  //合并mid及向右的所有链表

        return merge(left,right);   //合并划分后的两个链表
    }
    void test()
    {
        ListNode *p1 = initNode({2,4,6,8});
        ListNode *p2 = initNode({1,3,5});
        ListNode *p3 = initNode({12,14});
        ListNode *p4 = initNode({13});
        vector<ListNode*> vec;
        vec.push_back(p1);
        vec.push_back(p2);
        vec.push_back(p3);
        vec.push_back(p4);
        ListNode* res = mergeK(vec,0,vec.size()-1);
        while (res!=nullptr)
        {
            cout << res->val << " ";
            res = res->next;
        }
        cout << endl;
    }
};

class Solution6
{
    //求两个有序的序列中找中位数
    //要求在O(logn)时间下
    //在单个序列中，使用二分搜索
public:

    double getMidNumber(vector<int> &arr1,int length1,vector<int> &arr2,int length2)
    {
        if(length2<length1) //默认二分搜索比较短的
        {
            return getMidNumber(arr2,length2,arr1,length1);
        }
        int i,j;
        int k = (length1 + length2 + 1)/2;  //数学意义的第k个
        int begin = 0;  //左边界为0
        int end = length1;  //右边界为length1
        while (begin<=end)  //二分搜索arr1
        {
            i = (begin+end)/2;
            j = k - i;
            if(i>0 && j<length2 && arr1[i-1]>arr2[j])
            {
                end = i-1;
            }
            else if(j>0 && i<length1 && arr2[j-1]>arr1[i])
            {
                begin = i+1;
            }
            else
            {
                break;
            }
        }

        int left = 0;
        int right = 0; 
        //要找arr1[i-1]<arr2[j]的，i就一直往左找，直到i=0，还是没找到比arr2[j]小的,
        //说明，arr1特别短 且 arr1元素的值都特别大，此时中位数肯定在arr2里面
        if(i==0)   
        {
            left = arr2[j-1];   //中位数肯定在arr2中
        }
        //要找arr2[j-1]<arr1[i]的，j就一直往左找，直到j=0，还是没找到比arr1[i]小的，
        //说明，arr2特别短  且  arr2的元素的值都特别大，此时中位数肯定在arr1里面
        else if(j==0)
        {
            left = arr1[i-1];
        }
        //否则，arr1 arr2各占一部分
        else
        {
            left = max(arr1[i-1],arr2[j-1]);
        }
        //要找arr1[i]>arr2[j-1]的，i就一直向右找，直到i=length1，还是没找到比arr2[j-1]大的，
        //说明，arr1特别短 且 arr1的元素都特别小，此时中位数肯定在arr2里面
        if(i==length1)
        {
            right = arr2[j-1];
        }
        //要找arr2[j]>arr1[i-1]的，j就一直向右找，直到j=length2，还是没有找到比arr1[i-1]大的，
        //说明，arr2特别短 且 arr2的元素都特别小，此时中位数肯定在arr1里面
        else if(j==length2)
        {
            right = arr1[i-1];
        }
        //否则，arr1 arr2各占一部分
        else
        {
            right = min(arr1[i],arr2[j]);
        }
        if((length1+length2)%2==0)  //如果是偶数个
        {
            return (left+right)*1.0/2;  
        }
        else    //奇数个
        {
            return left;
        }  
    }

    void test()
    {
        vector<int> arr1 = {1,3,5,7,8};
        vector<int> arr2 = {2,4,6};
        vector<int> arr = arr1;
        for(int v:arr2)
        {
            arr.push_back(v);
        }
        sort(arr.begin(),arr.end());
        for(int v:arr)
        {
            cout << v << " ";
        }
        cout << endl;
        double midNumber = getMidNumber(arr1,arr1.size(),arr2,arr2.size());
        cout << "mid number:" << midNumber << endl;
    }
};

int main()
{
    Solution1 s1;
    s1.test();
    cout << "-----------" << endl;

    Solution2 s2;
    s2.test();
    cout << "-----------" << endl;

    Solution3 s3;
    s3.test();
    cout << "-----------" << endl;

    Solution4 s4;
    s4.test();
    cout << "-----------" << endl;

    Solution5 s5;
    s5.test();
    cout << "-----------" << endl;

    Solution6 s6;
    s6.test();
    cout << "-----------" << endl;

    system("pause");
    return 0;
}
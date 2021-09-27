#include<iostream>
#include<vector>

using namespace std;

// 八大排序算法
// 从小到大

//冒泡排序
//平均时间复杂度：O(n^2)
//最好情况：O(n)
//最坏情况：O(n^2)
//空间复杂度：O(1)
//稳定性：稳定
//思想：如果符合交换条件，每次都交换；
void bubbleSort(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++) //控制排序的次数，总共为size次
    {
        bool flg = false;   //标志位，可提前结束
        for(int j=0;j<arr.size()-i-1;j++)   //控制每趟排序时，比较的次数，总共为size-i-1次
        {
            if(arr[j]>arr[j+1]) //如果前面的原始 大于 后面的原素，大的元素向下沉
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flg = true; //如果有交换，flg为true
            }
        }
        if(flg==false)  //如果某一趟排序中，没有元素交换（flg为false），可提前结束排序
        {
            break;
        }
    }
}

//选择排序
//平均时间复杂度：O(n^2)
//最好情况：O(n^2)
//最坏情况：O(n^2)
//空间复杂度：O(1)
//稳定性：不稳定
//思想：如果符合交换条件，先更新最小值索引，最后再交换最小值和当前i位置的值；
void selectSort(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)   //控制排序的趟数，总共size次
    {
        int minIndex = i;   //默认i为值最小的索引
        for(int j=i+1;j<arr.size();j++) //从i以后的位置，找值小于arr[minIndex]的数，更新minIndex索引
        {
            if(arr[j]<arr[minIndex])    //如果后面的数有小于arr[minIndex]的，更新minIndex
            {
                minIndex = j;
            }
        }
        if(minIndex != i)   //如果minIndex不为i，交换数据，将arr[minIndex]放到arr[i]的位置，0-i为已经拍好序的数组
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

//插入排序
//平均时间复杂度：O(n^2)
//最好情况：O(n)
//最坏情况：O(n^2)
//空间复杂度：O(1)
//稳定性：稳定
//思想：前面序列为排好序的，从未排好序的序列中，每次取一个，放到排好序的序列中的合适位置；
void insertSort(vector<int> &arr)
{
    for(int i=1;i<arr.size();i++)   //从第2位开始
    {
        int key = arr[i];   //记录i位置的值
        int j = i-1;    //j从i前一个元素开始
        while (j>=0 && arr[j]>key)  //如果j>=0 && arr[j]>key
        {
            arr[j+1] = arr[j];  //arr[j]的值向后移动
            j--;    //j超前遍历
        }
        //结束循环的条件 j=-1，此前说明key为最小的，直接放在j=0的位置；arr[j]<=key，说明j+1的位置为key所在的位置；
        arr[j+1] = key;
    }
}

//希尔排序
//平均时间复杂度：O(nlogn)
//最好情况：O(n(logn)^2)
//最坏情况：O(n(logn)^2)
//空间复杂度：O(1)
//稳定性：不稳定
//思想：先根据步长分组进行插入排序；每次将步长更新为原来的一半；直到最终步长为1；
void shellSort(vector<int> &arr)
{
    int d = arr.size()/2;   //初始化步长为size的一半
    while (d>=1)
    {
        for(int i=d;i<arr.size();i++)   //i从d开始，对每一组同时处理
        {
            int key = arr[i];   //保存当前值
            int j = i-d;    //j为对应组排好序的序列中的最后一个元素的索引
            while (j>=0 && arr[j]>key)  //j>=0 && arr[j]>key
            {
                arr[j+d] = arr[j];  //后移
                j = j-d;    //找同一组前面元素
            }
            arr[j+d] = key; //将key放到合适的位置
        }
        d = d/2;    //之后每次步长为前面步长的一步（直到最终步长为1）
    }
}

//快速排序-划分函数
int partition(vector<int> &arr,int l,int r)
{
    int piviot = arr[l];    //选取左边界元素为主元
    while (l<r) //当l<r时，执行；l=r时，退出循环
    {
        while (l<r && arr[r]>=piviot)    //l<r && arr[r]大于主元，r--，直到找到arr[r]<主元
        {
            r--;
        }
        if(l<r) //如果l<r
        {
            arr[l++] = arr[r];  //将r处的值给l处，l++
        }
        while (l<r && arr[l]<=piviot)    //l<r && arr[l]小于主元，l++，直到找到arr[l]>主元
        {
            l++;
        }
        if(l<r)
        {
            arr[r--] = arr[l];  //将l处的值给r处，r--
        }      
    }
    //l==r时，退出循环  将主元放到l的位置，并返回l划分点
    arr[l] = piviot;  
    return l;
}
//快速排序
//平均时间复杂度：O(nlogn)
//最好情况：O(nlogn)
//最坏情况：O(n^2)
//空间复杂度：O(1)
//稳定性：不稳定
//思想：选取主元，将序列中小于主元的放到主元左边，将序列中大于主元的放到主元右边；递归排序主元左边序列和右边序列
void fastSort(vector<int> &arr,int l,int r)
{
    if(l>=r)    //如果左边界>=右边界，说明剩1个元素/没有元素，默认有序，回溯
    {
        return;
    }
    int pos = partition(arr,l,r);   //找到划分点，划分点左边的都比划分点处的值小，划分点右边的都比划分点处的值大
    fastSort(arr,l,pos-1);  //递归排序划分点左边的序列
    fastSort(arr,pos+1,r);  //递归排序划分点右边的序列
}

//归并排序-合并函数
void merge(vector<int> &arr,int l,int mid,int r)
{
    vector<int> tmp(r-l+1,0);   //申请临时数组，用于存储合并后的结果
    int i = l;  //第一个数组开始下标
    int j = mid+1;  //第二个数组开始下标
    int k = 0;
    while (i<=mid && j<=r)  //在各自的数组下标内
    {
        if(arr[i]<arr[j])   //arr[i]小，tmp[k]存arr[i]
        {
            tmp[k++] = arr[i++];    //k++,i++
        }
        else   //arr[j]小，tmp[k]存arr[j]
        {
            tmp[k++] = arr[j++];    //k++,j++
        }
    }
    while (i<=mid)  //第一个数组未完，剩余元素复制
    {
        tmp[k++] = arr[i++];
    }
    while (j<=r)    //第二个数组未完，剩余元素复制
    {
        tmp[k++] = arr[j++];
    }
    for(int s=l;s<=r;s++)   //将排好序的结果复制到原数组
    {
        arr[s] = tmp[s-l];
    }
}
//归并排序
//平均时间复杂度：O(nlogn)
//最好情况：O(nlogn)
//最坏情况：O(nlogn)
//空间复杂度：O(n)
//稳定性：稳定
//思想：将序列从中间划分为2个序列，直到划分为序列中只要一个元素/没有元素，默认该序列有序；对两个有序序列进行合并操作
void mergeSort(vector<int> &arr,int l,int r)
{
    while (l>=r)    //只剩一个元素/没有元素，默认有序
    {
        return;
    }
    int mid = (l+r)/2;  //找中间索引
    mergeSort(arr,l,mid);   //排序l-mid的序列
    mergeSort(arr,mid+1,r); //排序(mid+1)-r的序列
    merge(arr,l,mid,r); //2个有序数组合并
}

//计数排序
//平均时间复杂度：O(n+k)
//最好情况：O(n+k)
//最坏情况：O(n+k)
//空间复杂度：O(k)
//稳定性：不稳定
//思想：以数组的元素，作为新数组下标，统计每个元素出现的次数，最后按索引从小到大输出，并更新原数组；
void countSort(vector<int> &arr)
{
    int minV = arr[0];  //找出序列中最大值
    int maxV = arr[0];  //找出序列中最小值
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<minV)
        {
            minV = arr[i];
        }
        if(arr[i]>maxV)
        {
            maxV = arr[i];
        }
    }
    vector<int> num(maxV-minV+1,0); //以值为索引，建立计算数组，其中对于关系为 value = i+minV 
    for(int i=0;i<arr.size();i++)   //统计每个值出现的次数
    {
        num[arr[i]-minV] += 1;
    }
    int k = 0;
    for(int i=0;i<maxV-minV+1;i++)  //对统计数组遍历
    {
        while (num[i]--)
        {
            arr[k++] = i+minV;  //将值 复制到 原数组中，i+minV为原数组中的值，num[i]为i+minV出现的次数
        }
    }
}

//堆排序-堆调整（下沉）（大根堆）
void heapAdjust(vector<int> &arr,int s,int m)
{
    //s为初始调整节点，m为最后一个叶子节点
    for(int i=2*s+1;i<=m;i=2*i+1)   //i为s的左孩子
    {
        int key = arr[s];   //保存s的值
        if(i+1<=m && arr[i+1]>arr[i]) i=i+1;    //左 右孩子，哪个值大，i指向哪个孩子
        if(key>=arr[i]) break;  //如果父节点比两个孩子的值都>=，满足大根堆性质，退出循环，不用再调整；（s孩子的子树肯定满足性质）
        arr[s] = arr[i];    //如果孩子比s大，将孩子值和父节点值交换；孩子值给父节点
        arr[i] = key;   //父节点值给孩子
        s = i;  //s指向新的调整节点（作为新的父节点）
    }
}

//堆排序
//平均时间复杂度：O(nlogn)
//最好情况：O(nlogn)
//最坏情况：O(nlogn)
//空间复杂度：O(1)
//稳定性：不稳定
//思想：构建大根堆，每次将未排序序列的最后一个和arr[0]（未排序序列的最大值）交换，然后调整[0]节点，使其在未排序序列中满足堆属性；
void heapSort(vector<int> &arr)
{
    //初始化堆，从最后一个非叶子节点开始，左边的都为非叶子节点，右边的都为叶子节点
    for(int i=arr.size()/2-1;i>=0;i--)  //只需调整非叶子节点即可
    {
        heapAdjust(arr,i,arr.size()-1); //调整 以非叶子节点为根节点 的树，使其满足堆属性
    }
    for(int i=arr.size()-1;i>0;i--) //i从最后一个节点开始，i>0
    {
        int tmp = arr[0];   //arr[0]处的值为堆中最大值，将其放到最后；把最后的值放到最前面
        arr[0] = arr[i];
        arr[i] = tmp;
        heapAdjust(arr,0,i-1);  //对最前面[0]的值进行调整（叶子节点边界为i-1，i-(size-1)都是排好序的序列），使其满足堆属性
    }
}

int main()
{
    vector<int> arr1 = {5,2,10,9,1,6,4,3,5};
    cout << "before sort:";
    for(int v:arr1)
    {
        cout << v << " ";
    }
    cout << endl;

    cout << "after bubble sort:";
    bubbleSort(arr1);
    for(int v:arr1)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr2 = {5,2,10,9,1,6,4,3,5};
    cout << "after select sort:";
    selectSort(arr2);
    for(int v:arr2)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr3 = {5,2,10,9,1,6,4,3,5};
    cout << "after insert sort:";
    insertSort(arr3);
    for(int v:arr3)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr4 = {5,2,10,9,1,6,4,3,5};
    cout << "after shell sort:";
    insertSort(arr4);
    for(int v:arr4)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr5 = {5,2,10,9,1,6,4,3,5};
    cout << "after fast sort:";
    fastSort(arr5,0,arr5.size()-1);
    for(int v:arr5)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr6 = {5,2,10,9,1,6,4,3,5};
    cout << "after merge sort:";
    mergeSort(arr6,0,arr6.size()-1);
    for(int v:arr6)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr7 = {5,2,10,9,1,6,4,3,5};
    cout << "after count sort:";
    countSort(arr7);
    for(int v:arr7)
    {
        cout << v << " ";
    }
    cout << endl;

    vector<int> arr8 = {5,2,10,9,1,6,4,3,5};
    cout << "after heap sort:";
    countSort(arr8);
    for(int v:arr8)
    {
        cout << v << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
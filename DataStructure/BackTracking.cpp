#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution1
{
    //整数选择问题
    //给定一组整数，从里面选择一组整数，让选择的整数和与剩下的整数和 差值最小
    //即：找原始序列中的一个子集，和剩下的数的和  做差最小
public: 
    int sum = 0;    //当前已选择总和
    int r = 0;      //当前未选择总和
    vector<int> vec;    //存储选择的数
    vector<int> bestV;  //保留最优解
    unsigned int minV = 0xFFFFFFFF; //记录是不是最小值
    int cnt = 0;
    
    void func(int i,int length,int *arr)
    {
        if(i==length)   //如果到叶子节点 结束递归
        {
            if(abs(sum-r)<minV) //如果差值小于 最小的  更新最小差值，且保存最优解
            {
                minV = abs(sum-r);
                bestV = vec;
            }
            cnt++;
        }
        else
        {   
            //当sum已选的 已经大于 r未选的，就算剩下的都不选 差值仍然>=最小差值  就没必要进入这个节点的孩子节点
            //剪枝  条件是：sum>=r
            //当sum<r时，仍然要访问孩子节点
            if(abs(sum-r)<minV || sum<r)    
            {
                //处理父节点的左孩子
                sum += arr[i];  //之前选择的节点和 + 当前节点
                r -= arr[i];    //未选择的节点和 - 当前节点
                vec.push_back(arr[i]);  //保存选择的
                func(i+1,length,arr);
                vec.pop_back(); //处理完成后，后退到父节点状态
                r += arr[i];    //还原没选择arr[i]之前的状态
                sum -= arr[i];  //还原没选择arr[i]之前的状态

                //处理父节点的右孩子
                func(i+1,length,arr);
            }
        }  
    }

    void test()
    {
        int arr[] = {12,6,7,11,16,3,8};
        const int length = sizeof(arr)/sizeof(arr[0]);
        for(int v:arr)
        {
            r += v;
        }
        func(0,length,arr);

        cout << "best:" << minV << endl;
        for(int v:bestV)
        {
            cout << v << " ";
        }
        cout << endl;
        cout << "cnt:" << cnt << endl;
    }

};

class Solution2
{
    //整数选择问题2
    //给定2n个整数，从其中选择n个 让选择的数之和 与 未选择的数之和 最小
public:
    //从根节点到叶子节点的一条路径，才是一个子集；否则，从中间断开，不是子集
    vector<int> x;  //记录已选择的节点
    vector<int> bestx;  //记录最优结果
    unsigned int minV = 0xFFFFFFFF;
    int sum = 0;    //已选择数字和
    int r = 0;  //未选择数字和
    int rnum = 0;   //未处理节点个数

    int cnt = 0;

    void func(int i,int length,int *arr)
    {
        if(i==length)
        {
            cnt ++;
            int res = abs(sum-r);   //差值
            if(res<minV)    //更新最优解
            {
                minV = res;
                bestx = x;
            }
        }
        else
        {
            rnum--; //未处理节点-1
            
            //处理左孩子
            if(x.size()<length/2)   //如果已选择的已经==n个 不再选
            {
                sum += arr[i];
                r -= arr[i];
                x.push_back(arr[i]);
                func(i+1,length,arr);
                x.pop_back();
                r += arr[i];
                sum -= arr[i];
            }

            //处理右孩子
            if(x.size()+rnum >= length/2)   //如果已选的 + 未处理的能选的 < n，不再选
            {
                func(i+1,length,arr);
            }
            rnum++; //回溯到父节点 未处理节点+1

        }
        
    }

    void test()
    {
        int arr[] = {12,6,7,11,16,3,8,4};
        for(int v:arr)
        {
            r += v;
        }
        const int length = sizeof(arr)/sizeof(arr[0]);
        rnum = length;
        func(0,length,arr);
        cout << "best:" << minV << endl;
        for(int v:bestx)
        {
            cout << v << " ";
        }
        cout << endl;
        cout << "cnt:" << cnt << endl; 
    }
};

class Solution3
{
    //挑选数字问题
    //有一组整数 挑选一组数字 让他们的和 等于 指定的值 存在打印 不存在不打印
public:
    int number = 18;    //目标数字
    vector<int> x;  //已选择的数字
    int sum = 0;    //已选择数字的和
    int r = 0;  //未处理数字的和

    int cnt = 0;

    void func(int i,int length,int *arr)
    {   
        if(i==length)
        {
            cnt ++;
            if(sum==number) //如果numbel==sum 才打印
            {
                for(int v:x)
                {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
        else
        {
            r -= arr[i];    //当处理父节点孩子时，将孩子节点从未处理总和减去
            if(sum+arr[i]<=number)  //剪左枝  如果sum + 当前要加入的节点值  都打于 number了，就不加了
            {
                sum += arr[i];
                x.push_back(arr[i]);
                func(i+1,length,arr);
                x.pop_back();
                sum -= arr[i];
            }
            if(sum+r>=number)   //剪右枝  如果sum + 剩下未处理的节点值 还小于number，就不加了
            {
                func(i+1,length,arr);
            }
            r += arr[i];    //回溯到父节点 把孩子节点加到未访问的集合中
        }
        
    }

    void test()
    {
        int arr[] = {4,8,12,16,7,9,3};
        const int length = sizeof(arr)/sizeof(arr[0]);
        for(int v:arr)
        {
            r += v;
        }
        func(0,length,arr);
        cout << "cnt:" << cnt << endl;
    }

};

class Solution4
{
    //挑选数字问题
    //有一组整数 挑选一组数字 让他们的和 等于 指定的值 存在打印 不存在不打印
    //更高效的解法
public:
    int number = 18;    //目标值
    vector<int> x;  //选择的数结合

    int cnt = 0;

    void func(int i,int length,int *arr)
    {
        if(i==length)
        {
            cnt++;
            if(number==0)   //找到了  打印
            {
                for(int v:x)
                {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
        else
        {
            for(int k=i;k<length;k++)   //访问当前节点后的所有节点
            {
                if(number-arr[k]>=0)    //要加第k个元素 number得>=arr[k],不然都超过了
                {
                    number -= arr[k];   //选择arr[k]
                    x.push_back(arr[k]);    //加入
                    func(k+1,length,arr);   //访问第k个节点的孩子节点
                    x.pop_back();   //不选择arr[k]
                    number += arr[k];   //恢复状态
                }
            }
        }
        
    }

    void test()
    {
        int arr[] = {4,8,12,16,7,9,3};
        const int length = sizeof(arr)/sizeof(arr[0]);
        func(0,length,arr);
        cout << "cnt:" << cnt << endl;
    }

};

class Solution5
{
    //0-1背包问题
public:

    int c = 20; //背包容量
    vector<int> x;  //已选择重量集合
    vector<int> bestx;  //最优解
    int cw = 0; //已选择重量和
    int cv = 0; //已选择总价值
    int bestV = -1; //最好价值

    int cnt = 0;

    int rv = 0; //未处理节点价值

    void func(int i,int length,int *w,int *v)
    {
        if(i==length)
        {
            cnt++;
            if(cv>bestV)    //更新最好的
            {
                bestV = cv;
                bestx = x;
            }
        }
        else
        {
            rv -= v[i]; //处理孩子节点时 未处理节点和-v[i]
            if(cw+w[i]<=c)  //当已选择重量和+要选的 <= 背包容量 才能装的上 才选他
            {
                cw += w[i];
                cv += v[i];
                x.push_back(w[i]);
                func(i+1,length,w,v);   //访问 孩子节点
                x.pop_back();
                cv -= v[i];
                cw -= w[i];
            }
            if(cv+rv>=bestV)    //已选的+未处理总价值 >= bestV 时  才选他  如果<,选他就没有意义
            {
                func(i+1,length,w,v);
            }
            rv += v[i]; //回溯父节点  将当前节点划分为  未处理节点

        }
        
    }

    void test()
    {
        int w[] = {12,5,8,9,6};
        int v[] = {9,11,4,7,8};
        for(int vv:v)
        {
            rv += vv;
        }
        const int length = sizeof(w)/sizeof(w[0]);
        func(0,length,w,v);
        cout << "bestV:" << bestV << endl;
        for(int vv:bestx)
        {
            cout << vv << " ";
        }
        cout << endl;
        cout << "cnt:" << cnt << endl;
    }

};


class Solution6
{
    //8皇后问题 -- N皇后问题
public:

    int cnt = 0;    //统计问题解的个数

    void swap(int i,int j,int *arr) //根据索引，交换数组元素
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    bool judge(int i,int *arr)  //判断将皇后放到第i行 第arr[i]列  是否可行？ 即判断与前面行的皇后是否冲突
    {
        for(int k=0;k<i;k++)    //判断第i行前面所有的皇后
        {   
            //k==i 表示两个皇后在同一行
            //arr[k]==arr[i] 表示两个皇后在同一列
            //abs(i-k)==abs(arr[i]-arr[k]) 表示两个皇后在同一条斜线上（45度斜线或135度斜线）
            //如果有这三种情况的任何一种，表示皇后会冲突，返回false，代表该行 该列处不能放皇后
            if(k==i || arr[k]==arr[i] || abs(i-k)==abs(arr[i]-arr[k]))
            {
                return false;
            }
        }
        return true;    //否则 可以放皇后
    }

    void func(int i,int length,int *arr)
    {
        if(i==length)   //如果跑到这 说明皇后放置合理
        {
            cnt++;
            for(int j=0;j<length;j++)   //打印皇后放置顺序
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
        else
        {
            for(int k=i;k<length;k++)   //固定 0 ~ i-1位置处的皇后，将i ~ length-1位置处的皇后 依次与i位置互换
            {
                swap(i,k,arr);  //交换i k位置的元素  将皇后放置 第i行第k列的位置
                if(judge(i,arr))    //判断将皇后放置第i行 第arr[i]列 与前面行放置的皇后是否冲突，不冲突时，才放置下一行；否则，当前位置不能放皇后
                {
                    func(i+1,length,arr);   //放置下一行的皇后
                }       
                swap(i,k,arr);  //回退到 放当前行皇后之前的状态
            }
        }
        
    }
    void test()
    {
        int arr[] = {1,2,3,4,5,6,7,8}; //数组的索引代表行  对应索引的值 代表列
        const int length = sizeof(arr)/sizeof(arr[0]);
        func(0,length,arr);
        cout << "cnt:" << cnt << endl;
    }

};

class Solution7
{
    //求{1，2，3}的一个全排列
    //并要求 除固定数外，其他的数 都是以小的元素先排列，大的元素后排列
    //1，2，3
    //1，3，2
    //2，1，3
    //2，3，1
    //3，1，2
    //3，2，1
public:
    vector<int> x;  //已选择的排列顺序
    
    void func(int i,int length,int *arr,bool *state)
    {
        if(i==length)   //一组排列顺序，打印
        {
            for(int v:x)
            {
                cout << v << " ";
            }
            cout << endl;
        }
        else
        {
            for(int k=0;k<length;k++)   //对每一层 都遍历所有的值
            {
                if(!state[k])   //当第k个元素 没有排列过时，加入排列
                {
                    state[k] = true;    //将状态置为已排列过
                    x.push_back(arr[k]);    //将第k个元素加入排列
                    func(i+1,length,arr,state); //访问下一层    i只是用于控制层数，判断是否达到递归结束的条件
                    x.pop_back();   //回溯 弹出排列
                    state[k] = false;   //状态更新
                }
            }
        }
        
    }

    void test()
    {
        int arr[] = {1,2,3};
        const int length = sizeof(arr)/sizeof(arr[0]);
        bool state[length] = {false};
        func(0,length,arr,state);
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

    Solution7 s7;
    s7.test();
    cout << "-----------" << endl;

    system("pause");
    return 0;
}
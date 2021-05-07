#include<iostream>
#include<queue>

using namespace std;
//分支限界算法
class Solution1
{
    //装载问题
    //有一批，共有n个集装箱要装上2艘 载重量分别为c1，c2的轮船，其中集装箱i的重量为wi
    //且 要求确定是否有一个合理的装载方案可以将这几个集装箱装上这2艘轮船
    //
    //思路：先往c1中尽可能装满，剩下的给c2，c2能装上就装上，装不上就不行
    //构建子集树
public:
    struct Node //定义节点类型，用于存储相关信息
    {
        Node(int w,int l,Node *p,bool left)
        {
            cw = w;
            level = l;
            parent = p;
            isLeft = left;
        }
        int cw; //当前节点的总重量值
        int level;  //第几个节点
        Node *parent;   //父节点
        bool isLeft;    //是否为左子树，如果是，代表当前节点被选了
    };

    queue<Node*> que;   //广度优先的辅助队列（层序遍历）
    int bestw = 0;  //最大的重量
    Node *bestNode = nullptr;   //产生最大重量的叶子节点

    void addLiveNode(int cw,int l,int n,Node* p,bool left)  //活节点入队列
    {
        Node *node = new Node(cw,l,p,left); //新建活节点
        que.push(node); //入队列

        if(l==n && cw==bestw)   //如果是叶子节点 且  当前节点最大重量 为 最大重量  说明该叶子节点是最优解的叶子节点
        {
            bestNode = node;    //保存后，方便后续打印选择路径
        }
    }

    int upBound(int level,int n,int *w) //右节点子树的上界
    {
        int cw = 0;
        for(int i=level;i<n;i++)    //对非访问的节点 重量加起来，
        {
            cw += w[i];
        }
        return cw;
    }

    int func()
    {
        int w[] = {12,8,15};
        const int n = sizeof(w)/sizeof(w[0]);
        int c = 27;

        int cw = 0; //用于保存之前节点的累计重量
        int i = 0;  //用于控制层数
        
        Node *node = nullptr;   //父节点，初始为空
        
        while (i<n) //n次
        {
            int wt = cw + w[i]; //如果选当前节点（左孩子）
            if(wt<=c)   //如果选上后，容量支持
            {
                if(wt>bestw)    //是否大于最大的
                {
                    bestw = wt; //如果是 更新
                }
                addLiveNode(cw+w[i],i+1,n,node,true);   //将当前节点 加入 队列
            }
            int upV = upBound(i+1,n,w); //计算右节点的重量上界
            if(cw+upV >= wt)    //如果当前右节点累计重量+重量上界 还比 最大的累计重量小 ，剪枝，右孩子不入队列
            {
                addLiveNode(cw,i+1,n,node,false);   //否则 入队列
            }

            node = que.front(); //队头元素出队列
            que.pop();
            cw = node->cw;  //恢复累计重量
            i = node->level; //恢复层级
        }

        int x[n];
        for(int j=n-1;j>=0;j--) //向父节点循环 找 选择路径
        {
            x[j] = bestNode->isLeft?1:0;
            bestNode = bestNode->parent;
        }

        for(int v:x)    //打印路径
        {
            cout << v << " ";
        }
        cout << endl;

        return bestw;
        
    }

    void test()
    {
        cout << func() << endl;
    }
    
};

class Solution2
{
    //0-1背包问题
    //FIFO
public:
    struct Node
    {
        Node(int w,int v,int l,Node *p,bool left)
        {
            weight = w;
            value = v;

            level = l;
            parent = p;
            isLeft = left;
        }
        int weight; //记录累计重量
        int value;  //记录累计价值
        int level;  //记录在第几个节点（第几层/第几个元素）
        Node *parent; //记录父节点
        bool isLeft;  //判断是否为左孩子
    };

    Node* bestNode = nullptr;   //记录最优解的叶子节点
    queue<Node*> que;   //广度优先辅助队列
    int bestV = 0;  //最好的价值

    void addLiveNode(int w,int v,int i,int n,Node *p,bool left) //将活节点加入到队列
    {
        Node *node = new Node(w,v,i,p,left);
        que.push(node);

        if(i==n && bestV==v)    //叶子节点 求 累计价值==bestV，说明为最优叶子节点
        {
            bestNode = node;    //更新最优叶子节点
        }
    }

    int upBound(int level,int n,int *v) //获取右孩子未访问节点的上界
    {
        int cv = 0;
        for(int i=level;i<n;i++)    //累加
        {
            cv += v[i];
        }
        return cv;
    }

    int func()
    {
        int w[] = {16,15,15};   //重量数组
        int v[] = {45,25,25};   //对应的价值数组
        int c = 30; //背包容量
        const int n = sizeof(w)/sizeof(w[0]);   //物品个数
        int i = 0;  //控制第几个物品
        int cw = 0; //之前节点累加重量
        int cv = 0; //之前节点累加价值
        Node *node = nullptr;   //当前节点父节点

        while (i<n)
        {
            int wt = cw + w[i]; //如果把当前节点加上的重量
            if(wt<=c)   //<=背包容量时 才加入
            {
                int vt = cv + v[i]; //当前节点加上后的 累计价值
                if(vt>bestV)    //因为在确定最优叶子节点时，用到了bestV，因此需要先更新bestV，再将该活节点添加到队列中
                {
                    bestV = vt; //更新最优的
                }
                addLiveNode(cw+w[i],cv + v[i],i+1,n,node,true); //将活节点添加到队列 并判断是否为最优叶子节点
            }
            int r = upBound(i+1,n,v);   //右子树 未访问节点的价值上界
            if(cv+r >= bestV)   //之前累计价值+价值上界 >= bestV，说明跑这个分支才有意义，否则，剪枝
            {
                addLiveNode(cw,cv,i+1,n,node,false);
            }

            node = que.front(); //扩展节点
            que.pop();

            i = node->level;    //更新层数
            cw = node->weight;  //跟新扩展节点的累计重量
            cv = node->value;   //累计价值
        }

        int x[n] = {0};
        for(int j=n-1;j>=0;j--) //根据parent 找出 选择路径
        {
            x[j] = bestNode->isLeft?1:0;
            bestNode = bestNode->parent;
        }

        for(int v:x)    //打印
        {
            cout << v << " ";
        }
        cout << endl;
        return bestV;
    }

    void test()
    {
        cout << func() << endl;
    }

};

class Solution3
{
    //0-1背包问题
    //优先级队列
    //与FIFO最大的区别：
    //FIFO每次从队头出
    //优先级队列每次出优先级最高的
public:
    struct Node
    {
        Node(int w,int v,int up,int l,Node *p,bool left)
        {
            weight = w;
            value = v;
            upBound = up;   //当前节点的价值上界，依据此排序；价值上界越大的 越先出队列

            level = l;
            parent = p;
            isLeft = left;
        }
        bool operator<(const Node &n)
        {
            return upBound<n.upBound;
        }
        int weight;
        int value;
        int upBound;

        int level;
        Node *parent;
        bool isLeft;
    };

    int bestV = 0;
    priority_queue<Node*> que;
    
    int upBound(int level,int n,int cv,int *v)
    {
        
        for(int i=level;i<n;i++)
        {
            cv += v[i];
        }
        return cv;
    }

    void addLiveNode(int w,int v,int upv,int i,int n,Node *p,bool left)
    {
        Node *node = new Node(w,v,upv,i,p,left);
        que.push(node);
    }

    int func()
    {
        int w[] = {16,15,15};
        int v[] = {45,25,25};
        int c = 30;
        const int n = sizeof(w)/sizeof(w[0]);
        int i = 0;
        int cv = 0;
        int cw = 0;

        int upV = upBound(0,n,cv,v);    //初始为0节点的所有未处理的 即所有的
        Node *node = nullptr;
        while (i<n)
        {
            int wt = cw + w[i];
            if(wt<=c)
            {
                int vt = cv + v[i];
                if(vt>bestV)
                {
                    bestV = cv + v[i];
                }
                addLiveNode(cw+w[i],cv+v[i],upV,i+1,n,node,true);   //第一个是最大的 直接给
            }
            int upV = upBound(i+1,n,cv,v);  //算新的upV
            if(upV>=bestV)
            {
                addLiveNode(cw,cv,upV,i+1,n,node,false);
            }

            node = que.top();
            que.pop();

            cw = node->weight;
            cv = node->value;
            i = node->level;
            upV = node->upBound;    //更新upV，因为下一个也为左子树 两者upV相等 所有可以直接给
        }

        int x[n];
        for(int j=n-1;j>=0;j--)
        {
            x[j] = node->isLeft?1:0;
            node = node->parent;
        }
        for(int v:x)
        {
            cout << v << " ";
        }
        cout << endl;
        return bestV;
    }
    
    void test()
    {
        cout << func() << endl;
    }

};


int main()
{
    Solution1 s1;
    s1.test();

    Solution2 s2;
    s2.test();

    Solution3 s3;
    s3.test();

    system("pause");
    return 0;
}
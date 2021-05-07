#include<iostream>
#include<functional>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

template<typename T, typename Comp=less<T>>
class BSTree
{
public:
    BSTree(Comp comp = Comp()) 
        : root_(nullptr)
        ,comp_(comp) 
    {}
    //利用层序遍历 释放每个节点的资源
    ~BSTree() 
    {
        if(root_!=nullptr)
        {
            queue<Node*> pq;
            pq.push(root_);
            while (!pq.empty())
            {
                Node* node = pq.front();
                pq.pop();
                if(node->left_!=nullptr)
                {
                    pq.push(node->left_);
                }
                if(node->right_!=nullptr)
                {
                    pq.push(node->right_);
                }
                delete node;
            }
            
        }
    }
    //非递归插入元素
    void n_insert(const T &val)
    {
        if(root_ == nullptr){
            root_ = new Node(val);
            return;
        }
        Node *parent_ = nullptr;
        Node *cur = root_;
        while (cur != nullptr)
        {
            //!comp_(cur->data_, val) 表示>=都满足
            if(cur->data_ == val)   //不插入重复元素
            {
                return;
            }
            else if(comp_(cur->data_, val))
            {
                parent_ = cur;
                cur = cur->right_;
            }
            else
            {
                parent_ = cur;
                cur = cur->left_;
            }
        }
        if(comp_(val, parent_->data_))
        {
            parent_->left_ = new Node(val);
        }
        else
        {
            parent_->right_ = new Node(val);
        }   
    }
    //递归插入元素 封装
    void insert(const T &val)
    {
        root_ = insert(root_,val);
    }
    //非递归删除元素
    void n_remove(const T &val)
    {
        //树为空，直接返回
        while (!root_)
        {
            return;
        }
        Node *parent = nullptr;
        Node *cur = root_;
        //找待删除节点
        while (cur)
        {
            if(cur->data_ == val){
                break;
            }
            else if(comp_(cur->data_,val))
            {
                parent = cur;
                cur = cur->right_;
            }
            else
            {
                parent = cur;
                cur = cur->left_;
            }
        }
        //没找到 直接返回
        while (!cur)
        {
            return;
        }
        //先处理情况3 有左右孩子 找前驱节点
        if(cur->left_ && cur->right_)
        {
            Node *pre = cur->left_;
            parent = cur;
            //一直找右边
            while (pre->right_)
            {
                parent = pre;
                pre = pre->right_;
            }
            //找到后，将前驱节点的值 覆盖 待删除节点的值
            cur->data_ = pre->data_;
            //将cur指向前驱节点，将情况归结为1 / 2
            cur = pre;
        }
        //合并 1 / 2 情况 有一个孩子 / 没有孩子
        Node *child = cur->left_;
        if(!cur->left_)
        {
            child = cur->right_;
        }
        // 如果删除的是根节点，更换树的入口地址
        if(parent == nullptr)
        {
            root_ = child;
        }
        else
        {  
            //判断将孩子节点 放到 待删除节点 的 父节点的 左孩子 还是 右孩子
            if(parent->left_ == cur)
            {
                parent->left_ = child;
            }
            else
            {
                parent->right_ = child;
            }
        }
        // 删除待删除节点
        delete cur;
    }
    //递归删除元素 封装
    void remove(const T &val)
    {
        root_ = remove(root_,val);
    }
    //非递归查询元素
    bool n_query(const T &val)
    {
        Node *cur = root_;
        while (cur != nullptr)
        {
            if(cur->data_ == val)
            {
                return true;
            }
            else if(comp_(cur->data_,val))
            {
                cur = cur->right_;
            }
            else
            {
                cur = cur->left_;
            }
        }
        return false;
    }
    //递归查询元素 封装
    bool query(const T &val)
    {
        return nullptr != query(root_,val);
    }
    
    //封装递归前序遍历接口  VLR
    void preOrder()
    {
        cout << "[递归]前序遍历";
        preOrder(root_);
        cout << endl;
    }
    //非递归前序遍历
    void n_preOrder()
    {
        cout << "[非递归]前序遍历";
        stack<Node*> s; //先入栈的后访问，后入栈的先访问
        if(root_==nullptr)
        {
            return;
        }
        s.push(root_);
        while (!s.empty())
        {
            Node *node = s.top();
            s.pop();
            cout << node->data_ << " "; //V
            if(node->right_!=nullptr)
            {
                s.push(node->right_);   //R
            }
            if(node->left_!=nullptr)
            {
                s.push(node->left_);    //L
            }
        }
        cout << endl;
    }
    //封装递归中序遍历接口  LVR
    void inOrder()
    {
        cout << "[递归]中序遍历";
        inOrder(root_);
        cout << endl;
    }
    //非递归中序遍历接口  LVR
    void n_inOrder()
    {
        cout << "[递归]中序遍历";
        if(root_==nullptr)
        {
            return;
        }
        stack<Node*> s;
        s.push(root_);
        Node *cur = root_->left_;
        while(!s.empty() || cur!=nullptr)
        {
            if(cur!=nullptr)
            {
                s.push(cur);
                cur = cur->left_;   //L
            }
            else
            {
                Node *node = s.top();
                s.pop();
                cout << node->data_ << " ";
                cur = node->right_;
            }
        }
        
        cout << endl;
    }
    //封装递归后序遍历接口  LRV
    void postOrder()
    {
        cout << "[递归]后序遍历";
        postOrder(root_);
        cout << endl;
    }
    //非递归后序遍历  LRV
    void n_postOrder()
    {
        cout << "[非递归]后序遍历";
        if(root_==nullptr)
        {
            return;
        }
        stack<Node*> s,out;
        s.push(root_);
        while (!s.empty())
        {
            Node *node = s.top();
            s.pop();
            out.push(node); //V
            if(node->left_!=nullptr)
            {
                s.push(node->left_);    //L
            }
            if(node->right_!=nullptr)
            {
                s.push(node->right_);   //R
            }
        }
        while (!out.empty())
        {
            cout << out.top()->data_ << " ";
            out.pop();
        }
        
        cout << endl;
    }
    //封装递归层序遍历接口
    void levelOrder()
    {
        cout << "[递归]层序遍历";
        int h = high();
        for(int i=0;i<h;i++)
        {
            levelOrder(root_,i);
        }
        cout << endl;
    }
    //非递归层序遍历接口
    void n_levelOrder()
    {
        cout << "[非递归]层序遍历";
        if(root_==nullptr)
        {
            return;
        }
        queue<Node*> pq;
        pq.push(root_);
        while (!pq.empty())
        {
            Node* node = pq.front();
            pq.pop();
            cout << node->data_ << " ";
            if(node->left_!=nullptr)
            {
                pq.push(node->left_);
            }
            if(node->right_!=nullptr)
            {
                pq.push(node->right_);
            }
        }
        
        cout << endl;
    }
    //递归求二叉树层数
    int high()
    {
        return high(root_);
    }
    //递归求二叉树节点个数
    int number()
    {
        return number(root_);
    }
    //封装 求区间[i,j]之间的元素
    void findValues(vector<int> &vec,int i,int j)
    {
        findValues(root_,vec,i,j);
    }
    //封装 判断是否为BST树
    bool isBSTree()
    {
        Node *pre = nullptr;
        return isBSTree(root_,pre);
    }
    //判断是否为子树
    bool isChildTree(BSTree<T,Comp> &child)
    {
        if(child.root_ ==nullptr)
        {
            return true;
        }
        Node *cur = root_;
        while (cur!=nullptr)
        {
            if(cur->data_ == child.root_->data_)
            {
                break;
            }
            else if(comp_(cur->data_,child.root_->data_))
            {
                cur = cur->right_;
            }
            else
            {
                cur = cur->left_;
            }
            
        }
        if(cur==nullptr)
        {
            return false;
        }
        return isChildTree(cur,child.root_);
        
    }
    //找最近公共祖先节点
    int getLCA(T val1,T val2)
    {
        Node* node = getLCA(root_,val1,val2);
        if(node==nullptr)
        {
            throw "no lca";
        }
        else
        {
            return node->data_;
        }
        
    }
    //镜像翻转
    void mirror01()
    {
        mirror01(root_);
    }
    //镜像对称
    bool mirror02()
    {
        if(root_==nullptr)
        {
            return true;
        }
        return mirror02(root_->left_,root_->right_);
    }
    //根据前序 中序遍历 重建二叉树
    void rebuild(int pre[],int i,int j,int in[],int m,int n)
    {
        root_ = rebuild_(pre,i,j,in,m,n);
    }
    //判断是否为平衡树
    bool isBalance()
    {
        bool flag = true;
        isBalance(root_,0,flag);
        return flag;
    }
    //获取倒数第k个节点
    int getValue(int k)
    {
        Node *node = getValue(root_,k);
        if(node==nullptr)
        {
            throw "k invalid";
        }
        else
        {
            return node->data_;
        }
        
    }

private:
    //节点定义
    struct Node
    {
        Node(T data = T())
            :data_(data)
            ,left_(nullptr)
            ,right_(nullptr)
        {}
        T data_;
        Node *left_;
        Node *right_;
    };
    //递归插入元素实现
    Node* insert(Node* node, const T &val)
    {
        if(node == nullptr)
        {
            return new Node(val);
        }
        if(node->data_ == val)
        {
            return node;
        }
        else if(comp_(node->data_,val))
        {
            node->right_ = insert(node->right_,val);
        }
        else
        {
            node->left_ = insert(node->left_,val);
        }
        return node;
    }
    //递归查询元素 实现
    Node* query(Node* node,const T &val)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->data_ == val)
        {
            return node;
        }
        else if(comp_(node->data_,val))
        {
            return query(node->right_,val);
        }
        else
        {
            return query(node->left_,val);
        }
    }
    //递归删除元素 实现
    Node* remove(Node* node,const T &val)
    {
        //返回待删除节点的孩子节点
        //node为 以当前节点为根节点的子树中删除
        //当没找到元素 不删 直接返回nullptr
        while (node == nullptr)
        {
            return nullptr;
        }
        if(node->data_ == val)
        {
            //如果找到节点 有2个孩子
            if(node->left_ != nullptr && node->right_ != nullptr)
            {
                Node *pre = node->left_;
                //先找前驱节点
                while (pre->right_ != nullptr)
                {
                    pre = pre->right_;
                }
                //使用前驱节点的值替换
                node->data_ = pre->data_;
                //递归删除前驱节点
                node->left_ = remove(node->left_,pre->data_);
            }
            else if(node->left_ != nullptr)
            {
                //有一个节点，返回该孩子节点
                Node *left = node->left_;
                delete node;
                return left;
            }
            else if(node->right_ != nullptr)
            {
                Node* right = node->right_;
                delete node;
                return right;
            }
            else
            {
                //没有孩子  直接删除  返回nullptr
                delete node;
                return nullptr;
            }
        }
        //如果val大，在右子树中删除
        else if(comp_(node->data_,val))
        {
            node->right_ = remove(node->right_,val);
        }
        //如果val小，在左子树中删除
        else
        {
            node->left_ = remove(node->left_,val);
        }
        return node;    //把当前节点返回给父节点 用于更新父节点
    }
    //递归前序遍历  VLR
    void preOrder(Node *node)
    {
        if(node!=nullptr)
        {
            cout << node->data_ << " "; //操作V
            preOrder(node->left_);  // L
            preOrder(node->right_); // R
        }
    }
    //递归中序遍历  LVR
    void inOrder(Node *node)
    {
        if(node!=nullptr)
        {
            inOrder(node->left_);  // L
            cout << node->data_ << " "; //操作V
            inOrder(node->right_); // R
        }
    }
    //递归后序遍历  LRV
    void postOrder(Node *node)
    {
        if(node!=nullptr)
        {
            postOrder(node->left_);  // L
            postOrder(node->right_); // R
            cout << node->data_ << " "; //操作V
        }
    }
    //递归层序遍历
    void levelOrder(Node *node, int i)
    {
        if(node==nullptr)
        {
            return;
        }
        //深度递归会遍历每一层的节点，此时只需控制打印输出的层数即可
        if(i==0)
        {
            cout << node->data_ << " "; //每次打印完就退出，不用再递归到叶子节点
            return;
        }
        levelOrder(node->left_,i-1);
        levelOrder(node->right_,i-1);
    }
    //递归求二叉树层数（深度） 求以node为根节点的子树的高度 并返回高度
    int high(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        int left = high(node->left_);  //L
        int right = high(node->right_);    //R
        return left > right? left+1 : right+1;  //V
    }
    //递归求二叉树节点个数 求以node为根节点的节点个数，并返回
    //后序遍历，往后回溯时，遇上每个节点都+1
    int number(Node *node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int left = number(node->left_); //L
        int right = number(node->right_);   //R
        return left + right + 1;    //V
    }
    //利用中序遍历 求查找指定区间的数
    void findValues(Node* node,vector<int> &vec,int i,int j)
    {
        if(node!=nullptr)
        {
            if(node->data_ > i) //当前节点的值大于i，左子树中才可能有大于i的
            {
                findValues(node->left_,vec,i,j);
            }
            if(node->data_ >= i && node->data_ <= j)
            {
                vec.push_back(node->data_);
            }
            if(node->data_ < j) // 当前节点的值小于j，右子树才有可能有小于j的
            {
                findValues(node->right_,vec,i,j);
            }
        }
    }
    //利用中序遍历思想 判断是否为BST数
    bool isBSTree(Node *node,Node* &pre)
    {
        if(node==nullptr)   //节点为空，到达最低端了，返回true
        {
            return true;
        }
        if(!isBSTree(node->left_,pre))  // L    判断使递归结束的条件
        {
            return false;
        }
        if(pre!=nullptr)    //当前节点不是第一个，才有前一个节点
        {
            if(comp_(node->data_,pre->data_))   //V 判断使递归结束的条件
                {
                    return false;
                }
        }
        pre = node;
        return isBSTree(node->right_,pre);  //R
    }
    //判断是否为子树
    bool isChildTree(Node *father,Node *child)
    {
        if(father==nullptr && child==nullptr)   //如果父节点 孩子 都为空  是子树
        {
            return true;
        }
        if(father==nullptr) //如果孩子不为空 父节点为空，肯定不是子树
        {
            return false;
        }
        if(child==nullptr)  //如果孩子为空，父节点不为空，允许，返回false
        {
            return true;
        }
        if(father->data_ != child->data_)   //如果值不相同 提前结束
        {
            return false;
        }
        return isChildTree(father->left_,child->left_) && isChildTree(father->right_,child->right_);   //继续判断两者的左右子树
    }
    //找最近公共祖先节点 实现
    Node* getLCA(Node* node,T val1,T val2)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        if(comp_(node->data_,val1) && comp_(node->data_,val2))
        {
            return getLCA(node->right_,val1,val2);
        }
        else if(comp_(val1,node->data_) && comp_(val2,node->data_))
        {
            return getLCA(node->left_,val1,val2);
        }
        else
        {
            return node;
        }    
    }
    //镜像翻转 实现
    void mirror01(Node *node)
    {
        if(node==nullptr)
        {
            return;
        }
        //V
        Node* tmp = node->left_;
        node->left_ = node->right_;
        node->right_ = tmp;        

        mirror01(node->left_);  //L
        mirror01(node->right_); //R
    }
    //镜像对称
    bool mirror02(Node* node1, Node* node2)
    {
        if(node1==nullptr && node2==nullptr)
        {
            return true;
        }
        if(node1==nullptr || node2==nullptr)
        {
            return false;
        }
        if(node1->data_ != node2->data_)
        {
            return false;
        }
        return mirror02(node1->left_,node2->right_) && mirror02(node1->right_,node2->left_);
    }
    //根据前序 中序遍历 重建二叉树
    Node* rebuild_(int pre[],int i,int j,int in[],int m,int n)
    {
        if(i>j || m>n)
        {
            return nullptr;
        }
        //创建当前子树根节点
        Node *node = new Node(pre[i]);  //V
        for(int k=m;k<=n;k++)
        {
            if(pre[i] == in[k])
            {
                node->left_ = rebuild_(pre,i+1,i+(k-m),in,m,k-1);   //L
                node->right_ = rebuild_(pre,i+(k-m)+1,j,in,k+1,n);  //R
                return node;
            }
        }
        return node;
    }
    //判断是否为平衡树
    int isBalance(Node* node,int level,bool &flag)
    {
        if(node==nullptr)
        {
            return level;
        }
        int lval = isBalance(node->left_,level+1,flag);
        if(!flag)
        {
            return lval;
        }
        int rval = isBalance(node->right_,level+1,flag);
        if(!flag)
        {
            return rval;
        }
        if(abs(lval-rval)>1)
        {
            flag = false;
        }
        return max(lval,rval);
    }
    int i = 1;
    Node* getValue(Node* node,int k)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        Node* right = getValue(node->right_,k); //R
        if(right!=nullptr)
        {
            return right;
        }
        if(i++==k)    //V   在RVL顺序下，找正数第k个元素
        {
            return node;
        }
        return getValue(node->left_,k);    //L
    }

    Node *root_;
    Comp comp_;
    
};

void test02()   //测试是否为子树问题
{
    vector<int> arr = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    vector<int> arr2 = {67,62,69,68};
    BSTree<int> child;
    for(int a:arr2)
    {
        child.insert(a);
    }
    cout << root.isChildTree(child) << endl;
}

void test03()   //测试LCA问题
{
    vector<int> arr = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    cout << root.getLCA(5,41) << endl;
    cout << root.getLCA(64,41) << endl;
    cout << root.getLCA(64,62) << endl;
    cout << root.getLCA(100,62) << endl;    //没有检测该节点是否在树上

}

void test04()   //镜像反转测试
{
    vector<int> arr = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    root.inOrder();
    root.mirror01();
    root.inOrder();
}

void test05()   //镜像对称测试
{
    vector<int> arr = {58};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    cout << root.mirror02() << endl;
}
void test06() //测试子树重建
{
    BSTree<int> bst;
    int pre[] = {58,24,0,5,34,41,67,62,64,69,78};
    int in[] = {0,5,24,34,41,58,62,64,67,69,78};
    bst.rebuild(pre,0,10,in,0,10);
    bst.preOrder();
    bst.inOrder();
}

void test07()   //判断是否为平衡数
{
    vector<int> arr = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    root.insert(12);
    cout << root.isBalance() << endl;

}

int main()
{
    // test07 ();
    vector<int> arr = {58,24,67,0,34,62,69,5,41,64,78};
    BSTree<int> root;
    for(int a:arr)
    {
        root.insert(a);
    }
    cout << root.getValue(2) << endl;
    // root.preOrder();
    // root.n_preOrder();
    // root.inOrder();
    // vector<int> vec;
    // root.findValues(vec,10,60);
    // cout << root.isBSTree() << endl;
    // for(int v:vec)
    // {
    //     cout << v << " ";
    // }
    // cout << endl;
    // root.n_inOrder();
    // root.postOrder();
    // root.n_postOrder();
    // root.levelOrder();
    // root.n_levelOrder();
    // cout << root.high() << endl;
    // cout << root.number() << endl;
    // root.n_insert(12);
    // root.remove(12);
    // root.remove(67);
    // root.remove(58);
    // root.inOrder();
    // bool isQ = root.query(24);
    // cout << isQ << endl;
    system("pause");
    return 0;
}

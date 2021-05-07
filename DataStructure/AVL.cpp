#include<iostream>

using namespace std;

template<typename T>
class AVLTree   //二叉平衡搜索树 
{
    //四种节点失衡原因：
    //1.左孩子的左子树太高，右旋转
    //2.右孩子的右子树太高，左旋转
    //3.左孩子的右子树太高，左-右旋转（左平衡）
    //4.右孩子的左子树太高，右-左旋转（右平衡)
public:
    AVLTree(): root_(nullptr) {}

    //利用层序遍历 释放每个节点的资源
    ~AVLTree() 
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
    
    //AVL树插入
    void insert(const T &val)
    {
        root_ = insert(root_,val);
    }

    //AVL树删除
    void remove(const T &val)
    {
        root_ = remove(root_,val);
    }
    
private:
    //定义AVL树的节点类型
    struct Node
    {
        Node(T data = T()):
            data_(data),
            left_(nullptr),
            right_(nullptr),
            height_(1)
        {}
        T data_;
        Node* left_;
        Node* right_;
        int height_;
    };
    
    //返回节点的高度值
    int height(Node* node)
    {
        return node==nullptr?0:node->height_;
    }

    //右旋转操作 以参数node为轴进行右旋转操作，并把新的根节点返回
    Node* rightRotate(Node* node)
    {
        //节点旋转
        Node* child = node->left_;
        node->left_ = child->right_;
        child->right_ = node;
        //高度更新
        node->height_ = max(height(node->left_),height(node->right_)) + 1;
        child->height_ = max(height(child->left_),height(child->right_)) + 1;
        //返回旋转后的子树的新的根节点
        return child;
    }

    //左旋转操作 以参数node为轴进行左旋转操作，并把新的根节点返回
    Node* leftRotate(Node* node)
    {
        //节点旋转
        Node* child = node->right_;
        node->right_ = child->left_;
        child->left_ = node;
        //高度更新
        node->height_ = max(height(node->left_),height(node->right_)) + 1;
        child->height_ = max(height(child->left_),height(child->right_)) + 1;
        //返回旋转后的子树的新的根节点
        return child;
    }

    //左平衡操作 以参数node为轴做左-右旋转操做，并把新的根节点返回
    Node* leftBalance(Node* node)
    {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }

    //右平衡操作 以参数node为轴做右-左旋转操做，并把新的根节点返回
    Node* rightBalance(Node* node)
    {
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }

    //AVL树的插入操作实现
    Node* insert(Node* node,const T &val)
    {
        if(node==nullptr)   //递归结束，找到插入的位置了
        {
            return new Node(val);
        }
        if(node->data_ > val)
        {
            node->left_ = insert(node->left_,val);
            //添加1 在递归回溯时判断节点是否时候 node的左子树太高 node失衡了
            if(height(node->left_) - height(node->right_) >1)
            {
                if(height(node->left_->left_)>=height(node->left_->right_))
                {
                    //节点失衡 由于左孩子的左子树太高
                    node = rightRotate(node);
                }
                else
                {
                    //节点失衡 由于左孩子的右子树太高
                    node = leftBalance(node);
                }
            }
        }
        else if(node->data_ < val)
        {
            node->right_ = insert(node->right_,val);
            //添加2 在递归回溯时判断节点是否时候 node的右子树太高 node失衡了
            if(height(node->right_) - height(node->left_) >1)
            {
                if(height(node->right_->right_)>=height(node->right_->left_))
                {
                    //节点失衡 由于右孩子的右子树太高
                    node = leftRotate(node);
                }
                else
                {
                    //节点失衡 由于右孩子的左子树太高
                    node = rightBalance(node);
                }
            }
        }
        else
        {
            ;   //找到相同节点了 不用往下递归 直接向上回溯
        }
        //添加3 因为子树中增加了新的节点 在递归回溯时检测更新节点高度
        node->height_ = max(height(node->left_),height(node->right_))+1;
        return node;
        
    }
    
    //AVL树删除
    Node* remove(Node* node,const T &val)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        if(node->data_ > val)
        {
            node->left_ = remove(node->left_,val);
            //左子树删除节点 可能右子树太高
            if(height(node->right_)-height(node->left_)>1)
            {
                if(height(node->right_->right_)>=height(node->right_->left_))
                {
                    node = leftRotate(node);
                }
                else
                {
                    node = rightBalance(node);
                }
                
            }
        }
        else if(node->data_ < val)
        {
            node->right_ = remove(node->right_,val);
            //右子树删除节点 可能左子树太高
            if(height(node->left_)-height(node->right_)>1)
            {
                if(height(node->left_->left_)>=height(node->left_->right_)) //>=当左子树的左子树高度和左子树的右子树高度一致，当成左孩子的左子树太高，可以少旋转一次
                {
                    node = rightRotate(node);
                }
                else
                {
                    node = leftBalance(node);
                }
                
            }
        }
        else
        {
            //找到了  先处理有两个孩子的节点删除情况
            if(node->left_!=nullptr && node->right_!=nullptr)
            {
                //为了避免删除前驱或者后继节点造成节点失衡 谁高删除谁
                if(height(node->left_)>=height(node->right_))
                {
                    //删前驱
                    Node *pre = node->left_;
                    while (pre->right_)
                    {
                        pre = pre->right_;
                    }
                    node->data_ = pre->data_;
                    node->left_ = remove(node->left_,pre->data_);
                    
                }
                else
                {
                    //删后继
                    Node* post = node->right_;
                    while (post->left_)
                    {
                        post = post->left_;
                    }
                    node->data_ = post->data_;
                    node->right_ = remove(node->right_,val);
                    
                }
                
            }
            else    //删除节点，最多有一个孩子
            {
                 if(node->left_!=nullptr)
                 {
                     Node *left = node->left_;
                     delete node;
                     return left;
                 }
                 else if(node->right_!=nullptr)
                 {
                     Node *right = node->right_;
                     delete node;
                     return right;
                 }
                 else
                 {
                     delete node;
                     return nullptr;
                 }
                 

            }
            
        }
        node->height_ = max(height(node->left_),height(node->right_))+1;
        return node; //递归回溯过程中，把当前节点给父节点
        
    }

    Node* root_;
    
};

int main()
{
    AVLTree<int> avl;
    for(int i=1;i<=10;i++)
    {
        avl.insert(i);
    }
    avl.remove(9);
    avl.remove(10);
    return 0;
}
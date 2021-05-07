#include<iostream>

using namespace std;

template<typename T>
class RBTree
{
public:
    //根节点初始化为空
    RBTree(): root_(nullptr) {}
    //插入节点
    void insert(const T &val)
    {
        if(root_ == nullptr)    //如果树为空，直接插入黑色的节点，置为val
        {
            root_ = new Node(val);
            return;
        }

        Node *parent = nullptr;
        Node *cur = root_;
        while (cur)
        {
            if(cur->data_ > val)    //如果大于val，去左子树找位置
            {
                parent = cur;
                cur = cur->left_;
            }
            else if(cur->data_ < val)   //如果小于val，去右子树找位置
            {
                parent = cur;
                cur = cur->right_;
            }
            else    //如果等于val，直接退出，不插入相同的值
            {
                return;
            }
        }

        Node *node = new Node(val,parent,nullptr,nullptr,RED);  //新建节点，父节点为parent，颜色为RED，值为val
        if(parent->data_>val)   //如果parent的值大于val，val插入到parent的左边
        {
            parent->left_ = node;
        }
        else    //否则插入到parent的右边
        {
            parent->right_ = node;
        }
        
        if(color(parent)==RED)  //node为红色，如果node的父节点为红色，进行调整；如果node的父节点为黑色，不用调整
        {
            fixAfterInsert(node);
        }
    }
    //删除节点
    void remove(const T &val)
    {
        if(root_==nullptr)  //如果树为空 直接返回
        {
            return;
        }
        Node *cur = root_;  //从根节点开始找
        while (cur)
        {
            if(cur->data_>val)  //当前节点值 大于 val
            {
                cur = cur->left_;   //去左子树找
            }
            else if(cur->data_<val) //当前节点值 小于 val
            {
                cur = cur->right_;  //去右子树找
            }
            else    //找到了  退出循环
            {
                break;
            }
        }
        //退出循环有2种情况，一直找到了 一直没找到（此时cur为空）
        if(cur==nullptr)    //没找到 直接返回
        {
            return;
        }

        if(left(cur)!=nullptr && right(cur)!=nullptr)   //先处理情况三，有2个孩子，删前驱
        {
            Node *pre = cur->left_; //找前驱
            while (pre->right_) //如果有右孩子
            {
                pre = pre->right_;  //pre更新为pre的右孩子
            }
            //跳出循环后，pre的右孩子为空，此时pre为前驱节点
            cur->data_ = pre->data_;    //将前驱节点的值 给 cur
            cur = pre;  //cur指向前驱节点
        }
        //处理情况一 和 情况二（一个孩子或者没有孩子）
        Node *child = cur->left_;   //child指向非空的孩子
        if(child==nullptr)
        {
            child = cur->right_;    //指向非空的孩子
        }
        if(child!=nullptr)  //child！=nullptr，表示child不为叶子节点
        {
            child->parent_ = cur->parent_;  //更新child的父节点 为 cur的父节点
            if(child->parent_==nullptr) //如果更新后的父节点为空，说明 cur为根节点
            {
                root_ = child;  //更新根节点为child
            }
            else    //cur不为根节点
            {
                if(left(parent(cur))==cur)  //如果cur为其父节点的左孩子
                {
                    parent(cur)->left_ = child; //将父节点的左孩子更新为child
                }
                else    //如果cur为其父节点的右孩子
                {
                    parent(cur)->right_ = child;    //将父节点的右孩子更新为child
                }
            }
            Color c = color(cur);   //先保存删除节点cur的颜色
            delete cur; //删除cur
            if(c==BLACK)    //只要当删除的是黑色节点时，才进行调整（某一个之路会少黑色）；如果删除的是红色，不用管
            {
                fixAfterRemove(child);  //从孩子节点开始调整
            }
        }
        else    //child为叶子节点
        {
            if(parent(cur)==nullptr)    //cur父节点为空，说明该树只有一个cur根节点
            {
                root_ = nullptr;    //根节点置为空
                delete cur; //删除
                return; //结束
            }
            else    //cur不为根节点
            {
                if(color(cur)==BLACK)   //如果删除的节点是黑色，调整
                {
                    fixAfterRemove(cur);    //以当前节点调整，只能从兄弟借黑色
                }
                if(left(parent(cur))==cur)  //如果cur为其父节点的左孩子
                {
                    parent(cur)->left_ = nullptr;   //将其父节点的左孩子置为空
                }
                else    //如果cur为其父节点的右孩子
                {
                    parent(cur)->right_ = nullptr;  //将其父节点的右孩子置为空
                }
                
                delete cur; //删除cur
                
            }
            
        }
        
    }

private:

    //颜色为枚举类型，黑红两种可选
    enum Color
    {
        BLACK,
        RED
    };

    struct Node
    {
        Node(T data = T(),Node *parent = nullptr,
            Node *left = nullptr,Node *right = nullptr,
            Color color=BLACK)
            :data_(data)
            ,left_(left)
            ,right_(right)
            ,parent_(parent)
            ,color_(color)
        {}
        
        T data_;    //节点值
        Node *left_;    //左孩子
        Node *right_;   //右孩子
        Node *parent_;  //父亲节点
        Color color_;   //节点颜色
    };
    //给节点设置颜色
    void setColor(Node *node,Color color)
    {
        node->color_ = color;
    }
    //获取节点颜色，节点为空时为黑色
    Color color(Node *node)
    {
        return node == nullptr? BLACK:node->color_;
    }
    //获取父节点
    Node* parent(Node *node)
    {
        return node->parent_;
    }
    //获取左孩子
    Node* left(Node* node)
    {
        return node->left_;
    }
    //获取右孩子
    Node* right(Node *node)
    {
        return node->right_;
    }
    //左旋转
    void leftRotate(Node *node)
    {
        Node *child = right(node);  //保存右孩子
        child->parent_ = node->parent_; //更新孩子节点的父节点
        if(node->parent_ == nullptr)    //如果node的父节点为空，则node为根节点
        {
            root_ = child;  //更新根节点为child
        }
        else    //node不为根节点
        {
            if(left(parent(node))==node)    //node是它父亲的左孩子
            {
                parent(node)->left_ = child;    //更新node父亲的左孩子域
            }
            else
            {
                parent(node)->right_ = child;   //更新node父亲的右孩子域
            }
        }   
        node->right_ = child->left_;    //将child的左孩子给node的右孩子
        if(left(child)!=nullptr)    //如果child有左孩子
        {
            left(child)->parent_ = node;    //更新child左孩子的父节点
        }
        child->left_ = node;    //child的左孩子指向node
        node->parent_ = child;  //node的父节点指向child
    }
    //右旋转
    void rightRotate(Node *node)
    {
        Node *child = left(node);
        child->parent_ = node->parent_;
        if(node->parent_ == nullptr)
        {
            root_ = child;
        }
        else
        {
            if(left(parent(node))==node)
            {
                parent(node)->left_ = child;
            }
            else
            {
                parent(node)->right_ = child;
            }
        }
        node->left_ = child->right_;
        if(right(child)!=nullptr)
        {
            right(child)->parent_ = node;
        }
        child->right_ = node;
        node->parent_ = child;
    }
    //插入后节点调整
    void fixAfterInsert(Node *node)
    {   
        //当node的父节点颜色为红色时 调整（node颜色为红色，不能出现连续的红色）
        while (color(parent(node))==RED)
        {
            if(left(parent(parent(node)))==parent(node))    //node插到祖先节点的左子树中
            {
                Node *uncle = right(parent(parent(node)));  //看叔叔节点
                if(color(uncle)==RED)   //处理情况一，叔叔为红色
                {
                    setColor(parent(node),BLACK);   //父亲节点置为黑色，叔叔节点置为黑色，爷爷节点置为红色
                    setColor(uncle,BLACK);
                    setColor(parent(parent(node)),RED);
                    node = parent(parent(node));    //node指向爷爷，向上回溯更新（此时node依旧为红色）
                }
                else
                {
                    if(right(parent(node))==node)   //处理情况三，叔叔为黑色，且 node和父节点没在同一条直线
                    {
                        node = parent(node);    //旋转后，node仍然该指向最下面，因此node指向node的父节点（父节点旋转后，到最下面了）
                        leftRotate(parent(node));   //以node父节点为轴，左旋，使node和父节点在同一个直线
                    }
                    //统一处理情况二
                    setColor(parent(node),BLACK);       //node父亲 爷爷颜色互换 父亲为黑色
                    setColor(parent(parent(node)),RED); //爷爷为红色
                    rightRotate(parent(parent(node)));  //以node爷爷为轴右旋，
                    break;  //此时调整完成，直接退出；
                }
                
            }
            else    //node插到祖先节点的右子树中
            {
                Node *uncle = left(parent(parent(node)));
                if(color(uncle)==RED)
                {
                    setColor(parent(node),BLACK);
                    setColor(uncle,BLACK);
                    setColor(parent(parent(node)),RED);
                    node = parent(parent(node));
                }
                else
                {
                    if(left(parent(node))==node)
                    {
                        node = parent(node);
                        rightRotate(parent(node));
                    }

                    setColor(parent(node),BLACK);
                    setColor(parent(parent(node)),RED);
                    leftRotate(parent(parent(node)));
                    break;
                }
            }
            
        }

        setColor(root_,BLACK);  //根节点强制置为黑色，防止向上回溯时 root_被置为红色
        
    }
    //删除后节点调整
    void fixAfterRemove(Node* node)
    {
        while (node!=root_ && color(node)==BLACK)   //当node不为根节点 且 node为黑色，才进行调整；
        {
            if(left(parent(node))==node)    //删除节点在父节点的左子树
            {
                Node *brother = right(parent(node));    //兄弟节点在父节点的右子树
                if(color(brother)==RED) //先处理情况4，兄弟节点为红色
                {
                    setColor(parent(node),RED); //把父节点置为红色
                    setColor(brother,BLACK);    //把兄弟节点置为黑色
                    leftRotate(parent(node));   //以父节点为轴，左旋，给node找一个黑色节点
                    brother = right(parent(node));  //更新兄弟节点
                    //处理完成后 归结为情况一  二 三 
                }
                if(color(left(brother))==BLACK && color(right(brother))==BLACK) //处理情况三，兄弟节点的左孩子和右孩子都是黑色，只能为祖先借
                {
                    setColor(brother,RED);  //把兄弟节点置为红，使兄弟那一路也少一个黑色
                    node = parent(node);    //更新node指向其父节点，向父节点借
                }
                else    //处理情况 一 二
                {
                    if(color(right(brother))!=RED)  //情况二，兄弟节点的右孩子为黑色，左孩子为红色
                    {
                        setColor(brother,RED);  //将兄弟节点置为红
                        setColor(left(brother),BLACK);  //从左孩子借 将兄弟节点的左孩子置为黑色
                        rightRotate(brother);   //以兄弟节点为轴 右旋
                        brother = right(parent(node));  //更新兄弟节点
                    }
                    //统一处理情况一，兄弟节点为黑，兄弟节点的右孩子为红，用该右孩子 给补
                    setColor(brother,color(parent(node)));  //将兄弟节点的颜色置为父节点的颜色
                    setColor(parent(node),BLACK);   //将父节点的颜色置为黑
                    setColor(right(brother),BLACK); //将兄弟节点的右孩子置为黑
                    leftRotate(parent(node));   //以父节点为轴，左旋
                    break;  //结束调整
                }
                
            }
            else    //删除节点在父节点的左子树
            {
                Node *brother = left(parent(node));
                if(color(brother)==RED)
                {
                    setColor(parent(node),RED);
                    setColor(brother,BLACK);
                    rightRotate(parent(node));
                    brother = left(parent(node));
                }
                if(color(left(brother))==BLACK && color(right(brother))==BLACK)
                {
                    setColor(brother,RED);
                    node = parent(node);
                }
                else
                {
                    if(color(left(brother))!=RED)
                    {
                        setColor(brother,RED);
                        setColor(right(brother),BLACK);
                        leftRotate(brother);
                        brother = left(parent(node));
                    }

                    setColor(brother,color(parent(node)));
                    setColor(parent(node),BLACK);
                    setColor(left(brother),BLACK);
                    rightRotate(parent(node));
                    break;
                }
                
            }
        }

        setColor(node,BLACK);   //node为红色，直接置为黑色即可
    }

    Node *root_;


};


int main()
{
    RBTree<int> rb;
    for(int i=1;i<=10;i++)
    {
        rb.insert(i);
    }
    rb.remove(9);
    rb.remove(10);
    rb.remove(5);
    rb.remove(3);
    return 0;
}
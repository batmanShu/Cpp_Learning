/* 总结Morris的算法核心就是左顾右盼
左顾： 看左子树是否为空，若不为空，判断左子树的最右节点右指针是否指向自己
右盼： 左边都处理了，就可以右移了 */

//前序遍历
//左顾的时候发现其左子树为空或者其最右节点右指针没有指向自己，则收集该点的值
void morris(TreeNode* root){
    if(root==nullptr)
        return;
    TreeNode* cur=root;
    TreeNode* next=nullptr;
    while(cur!=nullptr)
    {
        next=cur->left;
        if(next)
        {
            while(next->right&&next->right!=cur)
                next=next->right;
            if(!next->right)
            {
                next->right=cur;
                cout<<cur->val<<endl;
                cur=cur->left;
                continue;
            }
            else
            {
                next->right=nullptr;
            }
        }
        else
            cout<<cur->val<<endl;
        cur=cur->right;
    }
}

//中序遍历
//左顾的时候发现其左子树为空或者其最右节点右指针有指向自己，则收集该点的值
void morris(TreeNode* root){
    if(root==nullptr)
        return;
    TreeNode* cur=root;
    TreeNode* next=nullptr;
    while(cur!=nullptr)
    {
        next=cur->left;
        if(next)
        {
            while(next->right&&next->right!=cur)
                next=next->right;
            if(!next->right)
            {
                next->right=cur;
                cur=cur->left;
                continue;
            }
            else
            {
                next->right=nullptr;
            }
        }
        cout << cur->val << endl;
        cur = cur->right;
    }
}
//后序遍历
//左顾的时候发现其左子树为空或者其最右节点右指针有指向自己，则逆序遍历其左子树的右边界节点
void morris(TreeNode* root){
    if(root==nullptr)
        return;
    TreeNode* cur=root;
    TreeNode* next=nullptr;
    while(cur!=nullptr)
    {
        next=cur->left;
        if(next)
        {
            while(next->right&&next->right!=cur)
                next=next->right;
            if(!next->right)
            {
                next->right=cur;
                cur=cur->left;
                continue;
            }
            else
            {
                next->right=nullptr;
                printEdge(cur->left);
            }
        }
        cur = cur->right;
    }
}

void printEdge(TreeNode *root)
{
    root = rightReverse(root); //逆
    printTree(root);
    root = rightReverse(root); //反逆
}

void printTree(TreeNode *root)
{
    TreeNode *head = root;
    while (head != NULL)
    {
        std::cout << head->val << " ";
        head = head->right;
    }
}
//左子树右边界的逆
TreeNode *rightReverse(TreeNode *root)
{
    TreeNode *cur = root->right;
    TreeNode *pre = root;
    pre->right = NULL;
    while (cur != NULL)
    {
        TreeNode *tmp = cur;
        cur = cur->right;
        tmp->right = pre;
        pre = tmp;
    }
    return pre;
}
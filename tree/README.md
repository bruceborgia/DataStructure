树


### void postorderNoRecursion(BTNode *bt) 后续非递归遍历二叉树

经过观察，逆后序遍历 是 先序遍历 过程中对左右子树遍历顺序交换所得到的结果；

因此需两个栈，一个栈用来辅助做逆后序遍历 并将遍历结果序列压入另一个栈stack2,将stack2全部出栈
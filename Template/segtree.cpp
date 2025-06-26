struct node
{
    int s,e,m;
    int val;
    node *left,*right;
    node(int ss,int ee,vector<int> &a)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        if(s==e)
        {
            val=a[e];
            return;
        }
        left=new node(s,m,a);
        right=new node(m+1,e,a);
        val=left->val+right->val;
    }
    void upd(int p,int v)
    {
        if(s==e)
        {
            val=v;
            return;
        }
        int m=(s+e)/2;
        if(p<=m)
        {
            left->upd(p,v);
        }
        else
        {
            right->upd(p,v);
        }
        val=left->val+right->val;
    }
    int qry(int l,int r)
    {
        if(l>e or r<s)
        {
            return 0;
        }
        if(l<=s and e<=r)
        {
            return val;
        }
        return left->qry(l,r)+right->qry(l,r);
    }
};
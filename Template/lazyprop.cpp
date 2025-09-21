/*
 !!! = careful when modifying
*/
struct node
{
    int s,e,m;
    int val,lazy;
    node *left=nullptr,*right=nullptr;
    node(int ss,int ee)
    {
        s=ss,e=ee;
        m=(s+e)/2;
        val=0;
        lazy=0;
    }
    
    void prop(){
        if(s!=e)
        {
            left->lazy+=lazy; // !!!
            right->lazy+=lazy; // !!!
        }
        val+=(e-s+1)*lazy; // !!!
        lazy=0; // !!!
    }
    
    void create()
    {
        if(s==e or left!=nullptr)
        {
            return;
        }
        left=new node(s,m);
        right=new node(m+1,e);
    }
    void upd(int l,int r,int v)
    {
        create();
        prop();
        if(l>e or r<s)
        {
            return;
        }
        if(l<=s and e<=r)
        {
            lazy+=v; // !!!
            return;
        }
        left->upd(l, r, v);
        right->upd(l, r, v);
        
        left->prop();
        right->prop();
        val=left->val+right->val; // !!!
    }
    int qry(int l,int r)
    {
        create();
        prop();
        if(l>e or r<s)
        {
            return 0; // !!!
        }
        if(l<=s and e<=r)
        {
            return val;
        }
        
        return left->qry(l,r)+right->qry(l,r); // !!!
    }

};
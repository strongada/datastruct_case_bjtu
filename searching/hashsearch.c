void InsertHash(HashTable *H,int key)
{
    int addr=Hash(key);
    while(H->elem[addr]!=NULL)
    {
        addr=(addr+1)%m;
    }
    H->elem[addr]=key;
}

Status SearchHash(HashTable H,int key,int *addr)
{
    *addr=Hash(key);
    while(H.elem[*addr]!=key)
    {
        *addr=(*addr+1)%m;
        if(H.elem[*addr]==NULL||*addr=Hash(key))
            return UNSUCCESS;
    }
    return SUCCESS;
}

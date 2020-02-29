struct Node
{
    int key;
    int value;
    Node *next,*pre;
    Node(int key, int value)
    {
        this->key=key;
        this->value=value;
        next=pre=NULL;
    }

};

class LRUCache
{
    private:

    static unordered_map<int,Node *> hsmap;
    static int capacity,count;
    static Node *head,*tail;

    public:

    LRUCache(int cap)
    {
        capacity = cap;
        count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->pre = head;
        //clear the hash map
        hsmap.clear();
    }
    static void addToFront(Node* node)
    {
        Node* next = head->next;
        head->next = node;
        node->next = next;
        next->pre = node;
        node->pre = head;
    }
    static void deleteFromList(Node* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    static int get(int key)
    {
        if(hsmap.find(key) == hsmap.end())
        {
            return -1;
        }
        else
        {
            Node* temp = hsmap[key];
            int val = temp->value;
            deleteFromList(temp);
            addToFront(temp);
            return val;
        }
    }

    static void set(int key, int value)
    {
        if(hsmap.find(key) == hsmap.end())
        {
            //the element is not present in the hash map
            if(count == capacity)
            {
                Node* temp = tail->pre;
                int k = temp->key;
                deleteFromList(temp);
                free(temp);
                hsmap.erase(k);
                count--;
            }
            //add the pair to list & map
            Node* newNode = new Node(key,value);
            hsmap[key] = newNode;
            addToFront(newNode);
            count++;
        }
        else
        {
            //update the value & add to front
            Node* temp = hsmap[key];
            temp->value = value;
            deleteFromList(temp);
            addToFront(temp);
        }
    }

};

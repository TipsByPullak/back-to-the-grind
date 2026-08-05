class Node {
public:
    int val = 0;
    Node *next = NULL;
};

class LinkedList {
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    LinkedList() {

    }

    int get(int index) {
        if (index >= size) return -1;

        // Traversal
        if (head == NULL) return -1;
        if ((index + 1) == size) return tail->val;
        if (index == 0) return head->val;

        Node *nd = NULL;
        nd = head;

        int i = 0;
        while (i < index)
        {
            nd = nd->next;
            ++i;
        }

        return nd->val;
    }

    void insertHead(int val) {
        Node *newNode = new Node;
        newNode->val = val;

        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        
        size++;
    }
    
    void insertTail(int val) {
        Node *newNode = new Node;
        newNode->val = val;

        if (size == 0)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        ++size;
    }

    bool remove(int index) {
        if (index >= size)
        {
            return false;
        }

        if (index == 0)
        {
            Node *nd = head;
            head = head->next;

            delete nd;
            --size;
            return true;
        }
        else 
        {
            Node *prev = head;
            Node *curr = head->next;
            Node *next = curr->next;

            int i = 1;
            
            while (i != index)
            {
                next = next->next;
                curr = curr->next;

                if (i > 1)
                    prev = prev->next;        

                ++i;
            }

            if (curr == tail)
            {
                tail = prev;
            }

            prev->next = next;

            delete(curr);
            --size;
            return true;
        }
    }

    vector<int> getValues() {
        vector<int> v(size);

        Node *tr = head;
        for (int i = 0; i < v.size(); ++i)
        {
            if (tr != NULL)
            {
                v[i] = tr->val;
                tr = tr->next;
            }
        }

        return v;
    }
};

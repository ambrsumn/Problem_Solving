class DLL {

    int val;
    int key;
    DLL next;
    DLL prev;

    DLL(int key, int val) {
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {

    DLL head;
    DLL tail;
    Map<Integer, DLL> cache;
    int cap;

    public LRUCache(int capacity) {
        this.cap = capacity;
        cache = new HashMap<>();
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head.next = tail;
        tail.prev = head;
        IO.println(head.next.val);
    }

    public void makeNodeFirst(DLL node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        node.prev = head;
    }

    public int get(int key) {

        if (cache.containsKey(key)) {
            DLL node = cache.get(key);
            if (head.next != node)
                makeNodeFirst(node);

            return node.val;
        }

        return -1;

    }

    public void put(int key, int value) {

        if (cache.containsKey(key)) {
            DLL node = cache.get(key);
            if (head.next != node)
                makeNodeFirst(node);

            node.val = value;

            return;
        }

        DLL newNode = new DLL(key, value);
        IO.println(head.next.val);
        newNode.next = head.next;
        head.next.prev = newNode;
        head.next = newNode;
        newNode.prev = head;

        cache.put(key, newNode);

        if (cache.size() > cap) {
            DLL lastNode = tail.prev;
            lastNode.prev.next = tail;
            tail.prev = lastNode.prev;
            cache.remove(lastNode.key);
        }

    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
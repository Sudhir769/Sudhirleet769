class MyHashSet {
    
private:
    vector<bool> hashSet;
public:
    MyHashSet() {
        hashSet = vector<bool>(1000001, false);
    }
    
    void add(int key) {
         if (key >= 0 && key <= 1000000) {
            hashSet[key] = true;
         }
    }
    
    
    void remove(int key) {
        if (key >= 0 && key <= 1000000) {
            hashSet[key] = false;
        }
    }
    
    bool contains(int key) {
        if (key >= 0 && key <= 1000000) {
            return hashSet[key];
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
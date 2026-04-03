class LFUCache {
public:
    int cap, minFreq;
    
    unordered_map<int, pair<int,int>> mp;
    unordered_map<int, list<int>> freqList; 
    unordered_map<int, list<int>::iterator> pos; 
    
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        
        int val = mp[key].first;
        int freq = mp[key].second;
        
   
        freqList[freq].erase(pos[key]);
        
     
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
       
        freq++;
        mp[key].second = freq;
        
        
        freqList[freq].push_front(key);
        pos[key] = freqList[freq].begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        
        if (mp.find(key) != mp.end()) {
            mp[key].first = value;
            get(key); 
            return;
        }
        
     
        if (mp.size() == cap) {
            int evict = freqList[minFreq].back();
            
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }
            
            mp.erase(evict);
            pos.erase(evict);
        }
        
       
        mp[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        
        minFreq = 1;
    }
};
class FrequencyTracker {
public:
    FrequencyTracker() {
        cnt.resize(100010);
        freq.resize(100010);
    }
    
    void add(int number) {
        int a = cnt[number];
        cnt[number] += 1;
        if (a) freq[a]--;
        freq[a+1]++;
    }
    
    void deleteOne(int number) {
        int a = cnt[number];
        if (a == 0) return;
        cnt[number]--;
        if (a == 1) freq[1]--;
        else freq[a]--, freq[a-1]++;
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency];
    }
    
private:
    vector<int> cnt, freq;
    
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
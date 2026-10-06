class ExamTracker {
public:
    vector<int> times;
    vector<long long> prefix;

    ExamTracker() {
        prefix.push_back(0);
    }

    void record(int time, int score) {
        times.push_back(time);
        prefix.push_back(prefix.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        int left = lower_bound(times.begin(), times.end(), startTime)
                   - times.begin();

        int right = upper_bound(times.begin(), times.end(), endTime)
                    - times.begin();

        return prefix[right] - prefix[left];
    }
};
/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
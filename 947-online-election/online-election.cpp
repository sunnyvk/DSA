class TopVotedCandidate {
public:
    // map: time -> leader at that time
    map<int, int> leaderAtTime;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> voteCount;  // person -> votes
        int currentLeader = -1;             // no leader initially
        int maxVotes = 0;

        // Process votes one by one
        for (int i = 0; i < persons.size(); i++) {

            int person = persons[i];
            int time = times[i];

            // Increase vote count for this person
            voteCount[person]++;

            // If this person has more or equal votes than current leader
            // he becomes the new leader
            if (voteCount[person] >= maxVotes) {
                currentLeader = person;
                maxVotes = voteCount[person];
            }

            // Store leader at this time
            leaderAtTime[time] = currentLeader;
        }
    }

    int q(int t) {
        // Find first time strictly greater than t
        auto it = leaderAtTime.upper_bound(t);

        // Move back to get time <= t
        it--;

        // Return leader at that time
        return it->second;
    }
};


/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
class SummaryRanges {
	  map < int, int > intervals;

	  public:
	    SummaryRanges() {}

	  void addNum(int value) {
	    int left = value, right = value;
	    auto min_entry = intervals.upper_bound(value);
	    if (min_entry != intervals.begin()) {
	      auto max_entry = min_entry;
	      --max_entry;
	      if (max_entry -> second >= value) {
	        return;
	      }
	      if (max_entry -> second == value - 1) {
	        left = max_entry -> first;
	      }
	    }
	    if (min_entry != intervals.end() && min_entry -> first == value + 1) {
	      right = min_entry -> second;
	      intervals.erase(min_entry);
	    }
	    intervals[left] = right;
	  }

	  vector < vector < int >> getIntervals() {
	    vector < vector < int >> answer;
	    for (const auto & p: intervals) {
	      answer.push_back({
	        p.first,
	        p.second
	      });
	    }
	    return answer;
	  }
	};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
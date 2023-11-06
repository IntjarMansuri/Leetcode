
// Time : O((m+n)*log(n)), Space : O(n) 

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    SeatManager(int n) {
        for(int i = 1; i<=n; i++) {
            pq.push(i);
        }
    }

    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }

    void unreserved(int seatNumber) {
        pq.push(seatNumber);
    }
};

// Time : O(m * log(n)), Space : O(n)

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int seat_marker;   // Smallest unreserd seat rakhega

    SeatManager(int n) {
        seat_marker = 1;
    }

    int reserve() {
        if(!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }

        int seat = seat_marker;
        seat_marker++;
        return seat;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
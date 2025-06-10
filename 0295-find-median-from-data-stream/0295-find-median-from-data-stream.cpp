class MedianFinder {
public:

    double median;
    priority_queue<double> left_heap;
    priority_queue<double,vector<double>,greater<double>> right_heap;

    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        
        if(num > median){
            if(left_heap.size() == right_heap.size()){
                right_heap.push(num);
                median = right_heap.top();
            }
            else if(right_heap.size() > left_heap.size()){
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(num);
                median = (left_heap.top()+right_heap.top())/2;
            }
            else{
                right_heap.push(num);
                median = (left_heap.top()+right_heap.top())/2;
            }
        }
        else{
            if(left_heap.size() == right_heap.size()){
                left_heap.push(num);
                median = left_heap.top();
            }
            else if(left_heap.size() > right_heap.size()){
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(num);
                median = (left_heap.top()+right_heap.top())/2;
            }
            else{
                left_heap.push(num);
                median = (left_heap.top()+right_heap.top())/2;
            }
        }

    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//  Name: Himanshu Singh
//  Date: 3/10/2022

class MyCircularQueue {
  private:
    vector < int > que;
  int front = 0, cnt = 0;
  public:
    MyCircularQueue(int k): que(k) {}

  bool enQueue(int value) {
    if (isFull()) return false;
    que[(front + cnt++) % que.size()] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    front = (front + 1) % que.size();
    --cnt;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return que[front];
  }

  int Rear() {
    if (isEmpty()) return -1;
    return que[(front + cnt - 1) % que.size()];
  }

  bool isEmpty() {
    return !cnt;
  }

  bool isFull() {
    return que.size() == cnt;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
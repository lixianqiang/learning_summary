#include <iostream>
/*****************************************************************************
 * STL的链表容器及其迭代器实现
 * STL迭代器本质是智能指针,它对指针进行了一层封装,简单理解就是指针套指针
 * 参考链接:
 *      https://blog.csdn.net/sinat_35512245/article/details/54600187
 *      https://www.cnblogs.com/wxquare/p/4699429.html
 *  
 * 关于STL的vector容器及其迭代器实现
 *      参考链接: https://juejin.im/post/6844904165265653773
 ******************************************************************************/
template<typename T>
struct Node {
    T val;
    Node<T>* nextPtr;
    Node(): nextPtr(nullptr) {
        //..............略
    }
    Node(T val, Node<T>* obj = nullptr): val(val), nextPtr(obj) {
        //..............略
    }
};

template<typename T>
class List {
    private:
        Node<T>* headPtr_;
        Node<T>* tailPtr_;
    public:
        List(): headPtr_(nullptr), tailPtr_(nullptr){
            //..................略
        }
        ~List(){
            delete headPtr_;
            delete tailPtr_;
        }
        //从链表尾部插入元素
        void push_back(T val) {
            if (headPtr_ == nullptr) {
                headPtr_ =  tailPtr_ = new Node<T>(val);
                headPtr_->nextPtr = nullptr;
                tailPtr_->nextPtr = nullptr;
            } 
            else {
                tailPtr_->nextPtr = new Node<T>(val);
                tailPtr_ = tailPtr_->nextPtr;
                tailPtr_->nextPtr = nullptr;
            }
        }        
        // void push_back(Node<T>* obj){
        //     if(headPtr_ == nullptr){
        //         headPtr_ = tailPtr_ = obj;
        //         headPtr_->nextPtr = nullptr;
        //         tailPtr_->nextPtr = nullptr;
        //     }
        //     else{
        //         tailPtr_->nextPtr = obj;
        //         tailPtr_ = tailPtr_->nextPtr;
        //         tailPtr_->nextPtr = nullptr;
        //     }
        // }
        //从链表中删除元素
        void pop(T val) {
            Node<T> *currPtr, *tmpPtr;
            currPtr = tmpPtr = headPtr_;
            if (currPtr == NULL) {
                return;
            }
            while (currPtr != NULL && currPtr->val != val) {
                tmpPtr = currPtr;
                currPtr = currPtr->nextPtr;
            }
            tmpPtr->nextPtr = currPtr->nextPtr;
        }
        // void pop(Node<T>* obj){
        //     Node<T> *currPtr, *tmpPtr;
        //     currPtr = tmpPtr = headPtr_;
        //     if (currPtr == NULL) {
        //         return;
        //     }
        //     while (currPtr != NULL && currPtr->val != obj->val) {
        //         tmpPtr = currPtr;
        //         currPtr = currPtr->nextPtr;
        //     }
        //     tmpPtr->nextPtr = currPtr->nextPtr;
        // }
        //前向迭代器类
        class Iterator
        {
            private:
                Node<T>* nodePtr_;
            public:
                Iterator(Node<T>* obj = nullptr) : nodePtr_(obj) {
                    //............略
                }
                //运算符重载 
                T& operator*() const {
                    return nodePtr_->val;
                }
                Node<T>* operator->() const {
                    return nodePtr_;
                }
                Iterator& operator++() {
                    nodePtr_ = nodePtr_->nextPtr;
                    return *this;
                }
                Iterator operator++(int) {
                    Node<T>* tmpPtr = nodePtr_;
                    nodePtr_ = nodePtr_->nextPtr;
                    return Iterator(tmpPtr);
                }
                bool operator==(const Iterator& iter) const {
                    return iter.nodePtr_ == this->nodePtr_;
                }
                bool operator!=(const Iterator& iter) const {
                    return iter.nodePtr_ != this->nodePtr_;
                }
        };
        //返回链表头部指针
        Iterator begin() const {
            return Iterator(headPtr_);
        }
        //返回链表尾部指针
        Iterator end() const {
            return Iterator(tailPtr_->nextPtr);
        }
        //打印链表元素
        void print(std::ostream &os = std::cout) const {
            for (Node<T> *ptr = headPtr_; ptr != tailPtr_->nextPtr ; ptr = ptr->nextPtr)
                std::cout << ptr->val << " ";
            os << std::endl;
        }
};

int main() {
    List<int> xl;
    xl.push_back(1);
    xl.push_back(2);
    xl.pop(2);
    for (List<int>::Iterator it = xl.begin(); it != xl.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
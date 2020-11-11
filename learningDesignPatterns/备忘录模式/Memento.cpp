#include <list>
#include<string>
#include <boost/any.hpp>
/**********************************************************************************************************
 * 备忘录模式适合(有选择性)保存一部分信息.相对地,当需要保存当前对象的所有信息时可以考虑使用原型模式
 * 备忘录模式又名快照模式,常见的如:虚拟机,git上的快照技术都使用备忘录模式来存放状态信息(发生变化的内容)
 * 备忘录模式包括三个对象:发起者,备忘录,管理者
 * 对备忘录而言:储存需要保存的状态, 提供读取状态的接口
 * 对发起者而言:创建备忘录,恢复备忘录
 * 对管理者而言:保存备忘录,读取备忘录
 * 关键是:如何设计可以同时动态承载不同类型的状态信息类.
 * 目前的基本思路是使用模板方法, boost::any, std::variant
 * 参考资料： https://www.cnblogs.com/qicosmos/p/3420095.html
 ***********************************************************************************************************/

typedef std::list<boost::any> anytype;

class Memento
{
    private:
        anytype state_; 
    public:
        Memento(anytype& st): state_(st){
            //................略
        }
        anytype ReadState(){
            return state_;
        }
};

class Originator
{
    private:
        int state1_;
        std::string state2_;
        bool state3_;
    public:
        Originator(): state1_(10), state2_("lxq"), state3_(true){
            //假设了一些初始状态数据
        }
        Memento* CreateMemento(){
            anytype stateA;
            stateA.push_back(state1_);
            stateA.push_back(state2_);
            return  new Memento(stateA);
        }
        void RestoreMemento(Memento* memo){
            anytype state = memo->ReadState();
            for (auto iter = state.begin(); iter!= state.end(); ++iter) {
                if ((*iter).type() == typeid(int)) {
                    printf("recover the state1_ %d\n", boost::any_cast<int>(*iter));
                } 
                else if ((*iter).type() == typeid(std::string)) {
                    printf("recover the state2_ %s\n", boost::any_cast<std::string>(*iter).c_str());
                }
            }
        }
};

class Caretaker
{
    private:
        std::list<Memento*> memoTable_;
    public:
        void SaveMemento(Memento* memo){
            memoTable_.push_back(memo);
        }
        Memento* ReadMemento(){
            Memento* snapShot = memoTable_.back();
            memoTable_.pop_back();
            return snapShot;
        }
};

int main(){
    Originator* org = new Originator();
    Caretaker* crt = new Caretaker();
    crt->SaveMemento(org->CreateMemento());
    org->RestoreMemento(crt->ReadMemento());
}
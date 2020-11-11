#include<string>
using std::string;
/**********************************************************************************************************************
 * 适配器模式有两种实现形式:类适配器, 对象适配器
 *      类适配器(当前例子)
 *              核心思路:采用多重继承,同时继承目标类和适配者类,然后在重载目标类接口时,在内部调用适配者类的接口
 *              缺点:增加类与类之间的耦合度,由于涉及多重继承,要求开发者本身清楚了解各个接口的构成
 *      对象适配器
 *              核心思路:只继承目标类,将适配者对象作为参数传入,然后在重载目标类接口时,在内部调用适配者对象的接口
 **********************************************************************************************************************/
//适配者类 电能发动机
class ElectricMotor
{
    public:
        void ElectricDrive(){  // 待适配接口 (该接口方法名与目标接口的不一致)
            printf("Use electric energy to drive cars\n"); 
        }
}; 

//适配者类 光能发动机
class OpticalMotor
{
    public:
        void OpticalDrive(){ // 待适配接口 (该接口方法名与目标接口的不一致)
            printf("Use light energy to drive cars\n"); 
        }
};

//目标类
class Motor
{
    public:
        virtual void drive()=0; //目标接口(客户端/用户通过调用目标接口去访问它所提供的服务)
};

//类适配器 电能适配器 
class ElectricAdapter :public Motor, public ElectricMotor
{
    public:
        void drive(){
            this->ElectricDrive(); //在重载目标类接口时,在内部调用适配者类的接口
        }
};

//类适配器 光能适配器 
class OpticalAdapter :public Motor, public OpticalMotor
{
    public:
        void drive(){
            this->OpticalDrive(); //在重载目标类接口时,在内部调用适配者类的接口
        }
};

int main()
{
    Motor* motor = new ElectricAdapter();
    motor->drive();
}
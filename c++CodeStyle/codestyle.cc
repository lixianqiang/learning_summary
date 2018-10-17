文件夹命名规范
全部小写 下划线相间


文件命名规范
全部小写


源文件以.cpp为后缀，如：mycodestyle.cpp
头文件以.h为后缀， 如：mycodestyle.h
编写时源文件与头文件均放在src文件夹
安装时对应分开存放


注释命名规范
段注释："//"或"/*"后空一格进行注释，段与段之间的注释对齐，美观为主，每段一句(最多不超过两句)
注释的两种方法
方法1
/*
 *注释内容.........
 *
 */

方法2
//
// 注释内容.........
//
//
行注释：行尾空一格进行注释,"//"后紧接注释内容，行与行之间的注释对齐，美观为主
void funA()
{
  ....
} //注释内容........
TODO注释 （短期方案，待优化代码）
邮箱，名字，bugID，注释内容
例子1：
funcA(const double& paramA); //空一格后进行单行注释
例子2：
// TODO(kl@gmail.com): Use a "*" here for concatenation operator.
// TODO(Zeke) change this to use relations.
// TODO(bug 12345): remove the "Last visitors" feature


#include 排序要求
1. 当前源文件对应的头文件
2. 本项目内其他头文件
3. C系统头文件
4. C++系统头文件
5. 其他库的头文件
#include头文件时优先所使用"",后使用<>
include与<>之间留有一个空格，如：#include <cmath>
每一项作为一个大类，空一行隔开，具体参考风格实例
例子：
#include "mycodestyle.h"
// 当前源文件对应的头文件
#include <Foo.h>
// 本项目内其他头文件空一格
#include <math.h>
// C系统头文件
#include <iostream>
// C++系统头文件
#include <Boost>
#include <ros/ros.h>
// 其他库的头文件

宏定义 全部大写
例子：
#define PI 3.1415926;
#ifndef MYCODESTYLE_H_
.....
#endif //MYCODESTYLE_H_
结尾附上定义注释


变量命名规范
普通变量 全部小写 下划线相间
常量 全部小写 下划线相间 前缀c_+变量名
全局变量 全部小写 下划线相间 _+变量名
指针变量 全部小写 下划线相间
静态变量 全部小写 下划线相间
  static 类型 对象名 
  static 类型 变量名（仅用于一次性的初始化）
  static const 类型 c_变量名 = 初始赋值（用作静态常量）
枚举型 大驼峰写法 前缀e_+变量名(复数)
  枚举型成员 全部小写 下划线相间 前缀(枚举变量名)_+数值名
结构体 大驼峰写法 全部小写 下划线相间
  结构体成员 全部小写 下划线相间
联合体 大驼峰写法 下划线相间
例子：
double font_color;
const double c_value_type;
double _goabalval;
static double objA;
static const double var_value = 0;
enum e_Colors
{
    Colors_red;
    Colors_blue;
    Colors_green;
}
struct TextFormat
{
    format;
    size;
    font;
}


函数命名规范
函数名 小驼峰写法 动词/形容词+名词+类型属性
函数参数 输入在前 输出在后
  输入参数 const 类型&+参数名
    特殊情况如：在输入参数为函数指针时可用 const 类型*+参数名
    特殊情况如：传入的值本身需要随函数调用而变化的，用值的指针作为输入形参，用 const 类型*+参数名
  输出参数 类型*+参数名
每行代码不超过80个字符，超过则进行分行，且形参对齐
return 不加"()"，除非含有复杂表达式，如：return(sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
例子：
void setFontStyle(const double& num,const double& text,const string& data_type,
                 string* outputA,double* outputB)
{
  .....
  .....
}



操作符 运算符 = + - * / < > <= >= == && ! ++ --
"="
赋值操作符要求前后均留空格
"+" "-" "*" "/" "<" ">" "<=" ">=" "==" "&&"
上述其它二元操作符也前后留有空格, 但对于复杂的表达式的子式不加空格(作为子式内部不留空格),对总式前后留有空格
圆括号内部没有紧邻空格
"!" "++" "--"
在参数和一元操作符之间不加空格
例子：
v = w * x;
v = w*x + y/z;
v = w * (x+z);
x = -5;
++x;
if (x && !y)
...


条件语句 if...else
不管代码数量，执行语句全部在"{}"进行


循环语句 for() / while()
不管代码数量，执行语句全部在"{}"进行


开关语句 switch...case...default
代码数量较少时，执行语句不需要放进"{}"
代码数量较多时，执行语句全部在"{}"进行，并且全部统一使用


类命名规范
类名 大驼峰写法 名词+类型属性
类函数
   公有 小驼峰写法 动词/形容词+名词+类型属性
   私有 小驼峰写法 动词/形容词+名词+类型属性
类数据
   公有 全部小写 名词+类型属性
   私有 全部小写 名词+类型属性+_
类对象
   公有 小驼峰写法 名词+类型属性
   私有 小驼峰写法 名词+类型属性+_

类函数内使用自身成员：
   公有函数成员 this->+函数名
   公有数据成员 this->+变量名
   公有对象成员 this->+对象名
   私有函数成员 this->+函数名
   私有数据成员 变量名+_
   私有对象成员 this->对象名+_

初始化列表:基类名(形参),对象成员名(形参),数据成员名(形参)
   基类名(形参)实质就是该基类的构造函数

例子1：名词+类型属性
class MyCodeStyleText {...} //名词+类型属性
class MyCodeStyle {...}
void MyCodeStyle::getFontColorsText(const double& num) {} //动词+名词+类型属性
void MyCodeStyle::getFontColors(const double& num) {}
例子2：
class MyCodeStyle:public Rectangle,public Controller
{
    public:
      MyCodeStyle():Rectangle(12),Controller("try"),ctrller("another")
      {
        ......
      }
      void getTextContent(const string& content) //公有函数成员
      {
        this->countNumString(10); //类内使用公有函数成员
        this->fontsize = num; //类内使用公有数据成员
        this->ctrllerA(1); //类内使用公有对象成员
        stringnum_val_ = num; //类内使用私有数据成员
        this->ctrllerB_(1); //类内使用私有对象成员
      }
      void countNumString(const double& num){...} //公有函数成员
      double fontsize; //公有数据成员
      Controller ctrllerA; //公有对象成员
    private:
      double stringnum_val_; //私有数据成员
      Controller ctrllerB_; //私有对象成员
}
class Rectangle
{
    public:
      Rectangle(double i)
      {
        ......
      }
    private:
}
class Controller
{
    public:
      Controller(string text)
      {
        ......
      }
      funA(const double& a){...}
    private:
}
组合与继承
另一个类是当前类的一个属性时，即：当关系满足"有一个"的时候，使用组合
另一个类是当前类的一种关系时，即：当关系满足"是一个"的时候，使用继承
    "教授是老师，教授有生日 前者是继承，后者是属性"


命名空间命名规范
命名空间  上级：项目名/团队名；下级：工程名
空间别名
    在对应命名空间的.h文件底部添加
结尾附上命名空间的注释
禁止使用 using namespace xxx;
可以使用 using 命名空间::标识符(标识符是指：类名，函数名，参数名，[次级命名空间不算])
例子：
namespace CppCodeStyle
{
......
} //namespace CppCodeStyle
namespace cppcodsty = CppCodeStyle;



风格实例
/*
 *  This is my c++ code style
 *  it will continually updated until finished
 *  <author> lixianqiang </author>
 *  <email> lxq243808918@gmail.com </email>
 */

#include "myCodeStyle.h"
#include "common.h"

#include <Format.h>
#include <Font.h>

#include <math.h>
#include <iostream>

#include <boost>
#include <ros/ros.h>

#define PI 3.1415926

/*
 * 变量命名规范
 * 包括普通变量，常量，枚举，结构体
 * 行注释：行尾空一格进行注释,行与行之间的注释对齐，美观为主
 */
double status_val; //普通变量，全部小写，下划线相间
const c_value_type; //常量，前缀c_+变量名
enum e_Colors   //枚举型，前缀e_+变量名
{
  Colors_red;   //枚举值，前缀(枚举变量名)+数值名
  Colors_blue;
  Colors_green;
}
struct TextFormat //结构体 大驼峰写法
{
  paragraph_format; //结构体成员，全部小写，下划线相间
  paragraph_size;
  paragraph_font;
}


//函数命名规范
//函数名 小驼峰写法 动词/形容词+名词+类型属性
//函数参数 输入在前 输出在后
//输入参数 const&+参数名
//每行代码不超过80个字符
void setFooText(const double& a,const double& b,double& out) //","后面不空格
{
  for(double i = 0;i < a;i++) //循环语句";"后面空一个空格
  {
    if(i < b) //条件语句就算只有一行代码也要{}
    {
      out = b;
    }
    else
    {
      out = b+i;
    }
  }
}

void setFontStyle(const double& num,const double&);

// TODO注释使用
// TODO(123456@abc.com)@这是假设该函数时临时方案
// TODO(mko_li)@需要继续完善，或提出更好的解决方法
// TODO@发现还有一点bug，但先留着以后在修改
void bugFun(double i)
{
  static double counter = 0;
  counter += i;
}

namespace Foo
{
namespace Bar
{
.....
}
}  //namespace Foo
namespace FB = Foo::Bar


// 类名 大驼峰写法 名词+类型属性
// 类函数 小驼峰写法 动词/形容词+名词+类型属性
// 类数据成员 变量名+_
class CodeStyle
{
  public:
    CodeStyle(double font, double rgb):size_(font),color_(rgb);
    void getTextContent(string& text)
    {
      string out_content = text;
      return out_content;
    }


  private:
    double size_;
    double color_;
};


}  //namespace Foo

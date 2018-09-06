源文件以.cpp为后缀，如：mycodestyle.cpp
头文件以.h为后缀， 如：mycodestyle.h
xxx.cc与xxx.h均放在src文件夹


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
段注释："//"或"/*"后空一格进行注释，段与段之间的注释对齐，美观为主，每段一句(最多不超过两句)
行注释：行尾空一格进行注释,行与行之间的注释对齐，美观为主
TODO注释 （短期方案，待优化代码）
邮箱，名字，bugID，注释内容
例子：
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
#include <Foo.h>
#include <math.h>
#include <iostream>
#include <Boost>
#include <ros/ros.h>


宏定义 全部大写
例子：
#ifndef MYCODESTYLE_H_
#define PI 3.1415926;


变量命名规范
普通变量 全部小写 下划线相间
常量 全部小写 下划线相间 前缀c_+变量名
枚举型 大驼峰写法 前缀e_+变量名(复数)
  枚举型成员 全部小写 下划线相间 前缀(枚举变量名)_+数值名
结构体 大驼峰写法 全部小写 下划线相间
  结构体成员 全部小写 下划线相间
例子：
int font_color;
const c_value_type;
enum e_Colors
    {
    Colors_red;
    Colors_blue;
    Colors_green;
}
struct TextFormat
    {
    paragraph_format;
    paragraph_size;
    paragraph_font;
}


函数命名规范
函数名 小驼峰写法 动词/形容词+名词+类型属性
函数参数 输入在前 输出在后
  输入参数 const&+参数名
  特殊情况如：在输入参数为函数指针时可用 const*+参数名
  特殊情况如：传入的值本身需要随函数调用而变化的，用值的指针作为输入形参，用 const*+参数名
每行代码不超过80个字符，超过则进行分行，且形参对齐
分行时，不要在 return 表达式里加上非必须的圆括号，除非含有复杂表达式

c++特性第6章
如果你向一个函数传入 const 变量, 函数原型声明中也必须对应 const 参数 (否则变量需要 const_cast 类型转换), 在调用库函数时显得尤其麻烦.



例子：
int setFontStyle(const int& num,const double& text,const string& data_type,
                  string paramA,int paramB)
{
  .....
  .....
  return unnknow_param;
}


条件语句 if...else
不管代码数量，执行语句全部在"{}"进行


循环语句 for() / while()
不管代码数量，执行语句全部在"{}"进行

开关语句 switch...case...default
代码数量较少时，执行语句不需要放进"{}"
代码数量较多时，执行语句全部在"{}"进行，并且全部统一使用



类命名规范
类名 大驼峰写法 名词+类型属性
类函数 小驼峰写法 动词/形容词+名词+类型属性
类数据成员 变量名+_
使用类成员时，用this->作区分
例子1：名词+类型属性
class MyCodeStyleText {...} //名词+类型属性
class MyCodeStyle {...}
void MyCodeStyle::getFontColorsText(const int& num) {} //动词+名词+类型属性
void MyCodeStyle::getFontColors(const int& num) {}
例子2：
class MyCodeStyle
{
    public
      string getTextContent(string& content)
      {
        return(this->text_ = content);
      }
    private
      string text_;
}


命名空间命名规范
命名空间  上级：项目名/团队名；下级：工程名
结尾附上命名空间的注释
namespace Foo
{

}// namespace Foo






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
int status_val; //普通变量，全部小写，下划线相间
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
void setFooText(const int& a,const int& b,int& out) //","后面不空格
{
  for(int i=0; i<a; i++) //循环语句";"后面空一个空格
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

void setFontStyle(const int& num,const double&);

// TODO注释使用
// TODO(123456@abc.com)@这是假设该函数时临时方案
// TODO(mko_li)@需要继续完善，或提出更好的解决方法
// TODO@发现还有一点bug，但先留着以后在修改
void bugFun(int i)
{
  static int counter = 0;
  counter += i;
}

  namespace Foo
  {


  }
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

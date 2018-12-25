文件夹命名规范：全部小写，下划线相间
  my_style


文件命名规范：全部小写
头文件命名格式：xxx.h
源文件命名格式：xxx.cpp 
  mycodestyle.h
  mycodestyle.cpp


注释命名规范：文件注释，段注释（类/函数注释），行注释（代码注释），TODO注释（短期方案，待优化代码）
文件注释：头/源文件首行位置，版权，作者信息，文件描述，版本信息(含重大修改)，
段注释：类声明（函数声明）、类实现（函数实现）
行注释：行尾空一格进行注释,"//"后紧接注释内容，行与行之间的注释对齐，美观为主
TODO注释：描述内容

/**************************************************************************

Copyright: MyCompany   //版权声明

License: GPL

Author: Lxq            //作者名字

Date: 2018-12-23       //创建日期

Description: This Is My Own C++ CodeStyle File   //文件描述

***************************************************************************/

// 段注释：类声明/函数声明
// This is a codestyle class used in generate interrelated code format           
// Funciton changeFrontSize(sring& name) using ......                            
// ......      																	 																	 
class MyCodeStyle																 
{																				 
	public:																			
		MyCodeStyle();															    
		void changeFontShape(string& name);             						    
		bool resetOptinon(bool exec);													
		private:																	
		int fontSize;															 
		String fontShape
}

// 段注释：类实现/函数实现
// This function can change font shape user will need 
// Parameter name is represent the shape of system provided
void MyCodeStyle::changeFontShape(string& name)
{
	bool result = font(name);
	
	if(result == true)
	{
		std::cout << "change successful" << std::endl;
	}
	else
	{	//行注释：代码块解释 
		resetOptinon(result); //if failed to change that will reset defualt option for font shape
	}
}

// TODO注释：短期方案，待优化代码
// this function still not finished yet
bool MyCodeStyle::resetOptinon(bool exec)
{
	if(exec == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


命名空间命名规范
命名空间 上级：项目名/团队名；下级：工程名
空间别名 在对应命名空间的.h文件底部添加
禁止使用 using namespace xxx;但可以使用 using 命名空间::标识符(标识符是指：类名，函数名，参数名，[次级命名空间不算])

#ifndef MYCODESTYLE_H_
#define MYCODESTYLE_H_

#include "mycodestyle.h" //当前源文件对应的头文件
#include <Foo.h> //本项目内其他头文件空一格

#include <math.h>   //C系统头文件

#include <iostream> //C++系统头文件
#include <vector>   //C++系统头文件

#include <Boost>     //第三方库的头文件
#include <ros/ros.h> //第三方库的头文件
#define PI 3.1415926; //宏定义 全部大写

namespace CppCodeStyle
{
	...
	...
	...
} //namespace CppCodeStyle  /****结尾附上命名空间的注释****/

#endif //MYCODESTYLE_H_  /*****结尾附上定义注释*****/
namespace ccs = CppCodeStyle; //空间别名

// using namespace cppcodsty; //禁止使用
using cppcodesty::标识符； //可以使用


变量命名规范 （前缀组合代表变量类型）
普通变量 小驼峰  			double fontColor;
常量     小驼峰 c_+变量名   const double c_valueType;
全局变量 小驼峰 g_+变量名   double g_goabalval;
指针变量 小驼峰 p_+变量名   vector<int> p_iter;
静态变量 小驼峰 s_+变量名   static s_inputSystem;
枚举型变量 小驼峰 e_+变量名 Color e_setRGBColor；
联合体变量 小驼峰 u_+变量名 EncoderData u_wheelCount；
结构体变量 小驼峰           TextFormat strctType 
（C++中结构体与类没本质区别，故结构体变量与类对象相同）

枚举型 大驼峰 
  枚举型成员 小驼峰
enum Color
{
    red;
    blue;
    green;
}

联合体 大驼峰 
  联合体成员 小驼峰
union EncoderData
{
	unsigned char trickValue;
	float odomValue;
}

结构体 大驼峰 
  结构体成员 小驼峰
struct TextFormat
{
    std::string format;
    int size;
    std::vector<string> font;
}

函数命名规范
函数名 小驼峰 动词/形容词+名词+类型属性
函数参数 输入在前(常数类型) 输出在后(指针类型/引用类型)
    输入参数为普通参数时，常引用类型
	输入参数为函数指针或需要递归变化时，常指针类型
    输出参数为普通参数时，指针类型/引用类型

// 每行代码不超过80个字符，超过则进行分行，且形参对齐
void setFontStyle(const double& num,const double& text,const string& data_type, 
				  string* outputA,double* outputB)
{
  if(num == 1)
  {
	return 0; //return 不加"()"，含复杂表达式除外
  }
  else
  {
	return((sqrt(pow(x1-x2,2)+pow(y1-y))));
  }
}

类命名规范
类名 大驼峰 名词+类型属性（可选）
  公有
	构造函数 形参为非引用类型(可以为引用，但不提倡)
	类函数成员 小驼峰 动词/形容词+名词+类型属性
	类数据成员 小驼峰 _+名词+类型属性
  私有
    类函数成员 小驼峰 动词/形容词+名词+类型属性
    类数据成员 小驼峰 名词+类型属性+_

类函数内使用自身成员：
   函数成员 this->函数名
   公有数据成员 _+变量名
   私有数据成员 变量名+_

class MyCodeStyleText //类名 大驼峰 名词+类型属性'Text'
{
  public:
	MyCodeStyle(double paramName){} //构造函数 形参为非引用类型
    void setFormat(const string& typeName);
    bool setGlobarOption(); 
    void MyCodeStyle::getFontColorsText(const double& colorVal,const double& fontSize) //公有类函数成员 小驼峰 动词+名词+类型属性'Text'

	unsigned char rgbColors; //公有数据成员 小驼峰 名词+类型属性
	double fontWidth;

  private:
    bool resetOption();      //私有函数成员 小驼峰 动词+名词+类型属性
	unsigned char fontSize_; //私有数据成员 小驼峰 名词+类型属性+_
}
void MyCodeStyle::setFormat(const string& typeName)
{
	if(typeName == "reset")
	{
		bool result = this->resetOptinon(); //类函数内使用私有函数成员
		return result;
	}
	else
	{
		return this->setGlobarOption(); //类函数内使用公有函数成员
		
	}
}
void MyCodeStyle::getFontColorsText(const double& colorVal,const double& fontSize) 
{
    _rgbColors = colorVal; //类函数内使用公有数据成员 this->变量名
	std::cout << " RGB Color is "<< _rgbColors << std::endl; 
	fontSize_ = fontSize; //类函数内使用私有数据成员 变量名+_
	std::cout << " Font Size is "<< fontSize_ << std::endl; 
}


书写规范

小驼峰式：(lower camel case)
	第一个单词以小写字母开始;第二个单词的首字母大写
大驼峰式：(upper camel case)
	每个单词的第一个字母都大写;

行与行之间的注释对齐，美观为主

#include 排序要求
1. 当前源文件对应的头文件
2. 本项目内其他头文件
3. C系统头文件
4. C++系统头文件
5. 第三方库的头文件
PS：include头文件时优先所使用"",后使用<>
    include与<>之间留有一个空格，如：#include <cmath>
    每一项作为一个大类，空一行隔开

每行代码不超过80个字符，超过则进行分行，且形参对齐

return 不加"()"，含复杂表达式除外，如：return(sqrt(pow(x1-x2,2)+pow(y1-y)))

符号运算 赋值运算符 关系运算符
1.要求前后均留空格
2.含复杂的表达式的子式除外，但总式前后要求留有空格
3.圆括号内部没有紧邻空格
4.一元操作符之间不加空格

v = w * x;
v = w*x + y/z;
v = (x+z) + a;
x = -5;
++x;
if (x && !y)
{
  return 0;
}

条件语句 if...else
不管代码数量，执行语句全部在"{}"进行


循环语句 for() / while()
不管代码数量，执行语句全部在"{}"进行


开关语句 switch...case...default
代码数量较少时，执行语句不需要放进"{}"
代码数量较多时，执行语句全部在"{}"进行，并且全部统一使用

class 类名：<继承方式>:<基类名>
{
 public:
   类名(); //构造函数，不带参数，类外定义
   类名(参数名) //构造函数，带参数，非引用类型，类外定义
   ~类名(){......}; //析构函数，类内定义
   函数a(int& b); //公有函数，类外定义
   函数b(int& c){...} //公有函数，类内定义
 private:
   其他类 对象a //对象成员
}

类名::类名():基类名(参数b),对象a(参数c)
{
  数据成员名(参数d)
  构造函数的其他初始化操作....
}

类名::类名(参数a):基类名(参数b),对象a(参数c)
{
  数据成员名(参数d)
  构造函数的其他初始化操作....
}

类名::函数a(int& b)
{
  ......
}
初始化列表在c++用处：执行基类的构造以及内嵌对象的初始化

组合与继承
另一个类是当前类的一个属性时，即：当关系满足"有一个"的时候，使用组合
另一个类是当前类的一种关系时，即：当关系满足"是一个"的时候，使用继承
    "教授是老师，教授有生日 前者是继承，后者是属性"
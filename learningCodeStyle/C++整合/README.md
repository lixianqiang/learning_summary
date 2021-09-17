```
***********************************************************************************
***********************************版本规范总结***********************************
语义化版本控制规范
	版本号的格式为 X.Y.Z(又称 Major.Minor.Patch)，递增的规则为：

	X 表示主版本号(Major Version)，当 API 的兼容性变化时，X 需递增。
	Y 表示次版本号(Minor Version)，当增加功能时(不影响 API 的兼容性)，Y 需递增。
	Z 表示修订号(Patch Version)，当进行 Bug 修复时(不影响 API 的兼容性)，Z 需递增。

	详细的规则如下：
			1，X, Y, Z 必须为非负整数，且不得包含前导零，必须按数值递增，如 1.9.0 -> 1.10.0 
					-> 1.11.0

			2，0.Y.Z 的版本号表明软件处于初始开发阶段，意味着 API 可能不稳定；
					1.0.0 表明版本已有稳定的 API。

			3，当 API 的兼容性变化时，X 必须递增，Y 和 Z 同时设置为 0；当新增功能(不影响 
					API 的兼容性)或者 API 被标记为 Deprecated 时，Y 必须递增，同时 Z 设置为 0；
					当进行 bug 修复 时，Z 必须递增。

			4，先行版本号(Pre-release)意味该版本不稳定，可能存在兼容性问题，
					其格式为：X.Y.Z-[a-c][正整数]，如 1.0.0-alpha，1.0.0-0.3.7，1.0.0.c1000。

			5，开发版本号常用于 CI-CD，其格式为 X.Y.Z.dev[正整数]，如 1.0.1.dev4。

			6，版本号的排序规则为依次比较主版本号、次版本号和修订号的数值，如 1.0.0 
					< 1.0.1 < 1.1.1 < 2.0.0；对于先行版本号和开发版本号，有：1.0.0.a100 
					< 1.0.0，2.1.0.dev3 < 2.1.0；当存在字母时，以 ASCII 的排序来比较，如 1.0.0.a1 
					< 1.0.0.b1。

			7，版本一经发布，不得修改其内容，任何修改必须在新版本发布！

				一些修饰的词
						alpha：内部版本
						beta：测试版
						demo：演示版
						enhance：增强版
						free：自由版
						full version：完整版，即正式版
						lts：长期维护版本
						release：发行版
						rc：即将作为正式版发布
						standard：标准版
						ultimate：旗舰版
						upgrade：升级版




***********************************************************************************
***********************************版权声明总结***********************************
声明格式1
		Copyright(c) Huawei Technology Co., Ltd. 1998-2011. All right reserved
声明格式2
		Copyright(c), 1998-2011, Huawei Technology. Co., Ltd. All rights reserved.
声明格式3
		Copyright © 1998-2011, Huawei Technology. Co., Ltd. All rights reserved.
声明格式4
		Copyright(c), 1998-2011, Huawei Technology. Co., Ltd.

1998-2011根据实际需要可以修改，1998是文件首次创建年份，2011是文件最新修改年份




***********************************************************************************
***********************************注释规范总结***********************************
1-1) 说明性文件（头文件 .h 文件， .inc 文件， .def 文件， .cfg 编译说明文件等）
说明性文件头部注释必须列出：
版权说明、许可证书、版本号、生成日期、作者、工号、内容、功能、与其他文件的关系、
修改日志。（另外，头文件注释中还应有对函数功能和用法的简要说明）
/***************************************************************************
Copyright(C), 1998-1999, Huawei Technology Co., Ltd.  All right reserved
License(可选):		// 许可证版本
FileName:		// 文件名
Author:            ID(可选):			Version:           Date:
Description:		// (详细/简要)描述该文件完成的主要功能，与其他模块
								// 或函数接口，输出值，取值范围，含义
								// 以及参数间的控制，顺序，独立与依赖关系
Others: 		// 与其他内容的说明
Function List(可选):		// 主要函数列表，每条记录应包括函数名及功能简要说明
	1， ...
Histiory:		// 修改历史记录表
						// 内容包括：修改日期，修改者以及修改内容简述
	1，	Date:
			Author:
			Modification:
	2，	...
***************************************************************************/


1-2) 源文件
源文件头部注释必须列出：
版权说明、许可证书、版本号、生成日期、作者、模块目的/功能、主要函数及其功能、
修改日志。
/**************************************************************************
Copyright(C) Huawei Technology Co., Ltd. 1998-2011. All right reserved
License(可选):		// 许可证版本
FileName:		// 文件名 
Author:             Date:           Version:
Description:		// (详细/简要)描述本文件的内容、功能、内部各部分之间的关系
            					// 以及本文件与其他文件的关系
Version:		// 版本信息，包括但不限于以下内容：
						// 1，版本号和发布日期（前面已有的情况下，可选）
						// 2，新功能和主要改进
						// 3，次要改进
						// 4，Bug修复
						// 5，杂项
Function List(可选):		// 主要函数及其功能
		1, .......
Histiory:		// 修改历史记录表，内容包括：修改日期，修改者
            			// 以及修改内容简述
   <author>				<date>				<version>				<desc>
   David       			2020/10/12     		1.0.0         			....
**************************************************************************/


1-3) 函数
函数头部注释必须列出：
函数目的/功能、输入参数、输出参数、返回值、调用关系（函数、表）等
/*************************************************************
Function:		// 函数名称
Description:		// 函数功能、性能、用法等描述
Calls(可选):		// 被本函数调用的函数清单
Called By(可选):		// 调用本函数的函数清单
Table Accessed(可选):		// 被访问的表
Table Updated(可选):		// 被修改的表
Input:		// 输入参数说明 包括每个参数的作用、取值关系以及参数间关系
OutPut:		// 对输出参数的说明
Return:		// 函数返回值说明
Others:		// 其他说明
*************************************************************/


全局变量
	要有较详细的注释，包括对其功能，取值范围以及存取时注意事项等的说明

	// 用于函数 GenerateTrajectory() 中距离判断
	// 可以在函数 ModefiyGlobalParam() 中进行修改
	// 取值范围：(0,100] 
	float dist_thresh = 1


注释方案（目前使用）
		仅代码前注释 // ...

备选方案1
		代码前注释 /* ... */
		代码行注释 // ...

备选方案2
		代码前注释 // ...
		代码行注释 // ...

		注意事项：
			采用行注释时，需在行尾空两格进行注释.
			注释符与注释内容之间要用一个空格进行分隔

			#define MAX_ACT_TASK_NUMBER 1000	// active statistic task number

注意事项：
		1，修改代码时，维护代码周边的所有注释，以保证注释与代码的一致性，不再有用的注释要删除

		2，注释函数重载时, 注释的重点应该是函数中被重载的部分, 而不是简单的重复被重载的函数的注释. 
			多数情况下, 函数重载不需要额外的文档, 因此也没有必要加上注释.

		3，注释构造/析构函数时, 应当注明的是注明构造函数对参数做了什么 (例如, 是否取得指针所有权) 
			以及析构函数清理了什么. 如果都是些无关紧要的内容, 直接省掉注释. 析构函数前没有注释是很正常的.

		4，注释应考虑程序员易读性以及外观排版的因素，使用的语言是中，英兼有。
			建议多使用中文，除非能用非常流利准确的英文表达。对于有外籍员工，有产品确定注释语言
			说明：注释语言不统一，影响程序易读性和外观排版，出于对维护人员的考虑，建议使用中文。

		5，注释应放在其代码上方相邻位置或右侧若放于上方需与其上面的代码用空行隔开，
			且与下方代码缩进相同

			/* temporary variable */
			int tmp = 10

			/* active statistic task number */
			const int MAX_ACT_TASK_NUMBER = 1000


文档注释（doxygen/javadoc格式）
	在开始的 /** 之后，第一行或几行是关于类、变量和方法的主要描述;
	在此之后，可以包含一个或多个各种各样的 @ 标签；
	每一个 @ 标签必须在一个新行的开始或者在一行的开始紧跟星号(*)；
	多个相同类型的标签应该放成一组。

头文件注释
	/**
	* @file		// 文件名
	* @brief 	// 文件功能的简述
	* @version 1.1		// 版本号
	* @author 	// 作者
	* @date 	// 文件创建日期
	*/

函数注释
	注释写在声明处，只对重要的、复杂的、以及对外提供使用的接口函数进行注释

	/**
	* @description		// 函数简要说明
	* @param arg1		// 参数1
	* @param arg2 		// 参数2
	* @return 		//成功，
	* 				//失败，
	*/

@author	标识一个类的作者	@author description
@param	说明一个方法的参数	@param parameter-name explanation
@deprecated	指名一个过期的类或成员	@deprecated description
@return	说明返回值类型	@return explanation
@version	指定类的版本	@version info
@value	显示常量的值，该常量必须是static属性。	Displays the value of a constant,
		which must be a static field.
@docRoot	指明当前文档根目录的路径	Directory Path
@exception	标志一个类抛出的异常	@exception exception-name explanation
@inheritDoc	从直接父类继承的注释	Inherits a comment from the immediate sur-
		perclass.

如下所示：
		/**
		* 这个类演示了文档注释
		* @author Ayan Amhed
		* @version 1.2
		*/
		public class SquareNum 
		{
		/**
		* This method returns the square of num.
		* This is a multiline description. You can use
		* as many lines as you like.
		* @param num The value to be squared.
		* @return num squared.
		*/
		public double square(double num) 
		{
			return num * num;
		}

		/**
		* This method inputs a number from the user.
		* @return The value input as a double.
		* @exception IOException On input error.
		* @see IOException
		*/
		public double getNumber() throws IOException 
		{
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader inData = new BufferedReader(isr);
			String str;
			str = inData.readLine();
			return (new Double(str)).doubleValue();
		}

		/**
		* This method demonstrates square().
		* @param args Unused.
		* @return Nothing.
		* @exception IOException On input error.
		* @see IOException
		*/
		public static void main(String args[]) throws IOException
		{
			SquareNum ob = new SquareNum();
			double val;
			System.out.println("Enter value to be squared: ");
			val = ob.getNumber();
			val = ob.square(val);
			System.out.println("Squared value is " + val);
		}
		}


TODO注释
	注释要使用全大写字符串 'TODO' 
	在 'TODO' 一词后, 在括号里留下名字，邮件地址，其他身份标识和与这一 'TODO' 相关的issue。
	写了TODO注释并不保证写的人会亲自解决问题. 当你写了一个TODO, 请注上你的名字.
	如果加 TODO 是为了在 “将来某一天做某事”, 可以附上一个明确的时间 ('Fix by November
	 2005') ,或者一个明确的事项 ("Remove this code when all clients can handle XML responses.").

	// TODO(kl@gmail.com): Use a "*" here for concatenation operator.
	// TODO(Zeke) change this to use relations.
	// TODO(bug 12345): remove the "Last visitors" feature


弃用注释
	注释要使用全大写字符串 'DEPRECATED'
	注释放在接口声明前,以标记某接口为弃用状态.
	在 'DEPRECATED' 一词后, 在括号中留下名字, 邮箱地址以及其他身份标识.


********************************************************************************
***********************************命名规范总结***********************************
文件
命名方案
	名字全部小写，单词之间使用 '_' 下划线连接
	建议：C++文件要以 .cc 为结尾，头文件以 .h 为结尾

	code_style.h
	code_style.cc


数据结构(自己编写实现)
命名方案
	必须与正在编写语言,它所使用官方命名保持一致,且自己实现功能需官方提供的保持一致
	根本目的是: 不能违背"里氏替换原则"


#define 保护
命名方案（目前使用）
	<PROJECT>_<PATH>_<FILE>_H_
备选方案
	<PROJECT>_<PATH>_<FILE>_H

项目 foo 中的头文件 foo/src/bar/baz.h 可按如下方式保护:
	#ifndef FOO_BAR_BAZ_H_
	#define FOO_BAR_BAZ_H_
	...
	#endif	// FOO_BAR_BAZ_H_


命名空间
命名方案
	名字全部小写，单词之间使用 '_' 下划线连接
	建议：顶级命名空间是项目名称或代码所属的团队的名字


函数命名
命名方案
	仅有一个单词时，整体小写，动词命名 
	
	void show()

	多个单词组成时，大驼峰写法，动词+名词进行命名
	
	void SetParam()


常用反义词组
		add/remove		begin/end		create/destory
		insert/delete	first/last		get/release
		incerement/decrement	put/get
		add/delete		lock/unlock		open/close
		min/max			old/new			start/stop
		next/previous	source/target	show/hide
		send/receive	source/destination
		cut/paste		up/down


变量 
命名方案
	仅有一个单词时，全部小写 
	
	int paramA = 0

	两个单词时，小驼峰写法
			
	bool isBool = true

	三个或三个单词以上时，下划线 '_' + 小驼峰写法

	copy_trajParam
		
	当变量有相似的属性时，属性 + 变量

	gradRep			gradAtt			gradSum

	当变量之间需要体现属性差异时，属性 + '_' + 变量

	paramA 			last_paramA		next_paramA

	argVal 			last_argVal		next_argVal

			
单词缩写可以通过去掉元音字母（a,e,i,o,u）的方式实现
常用变量缩写
		argument arg 	buffer buff 	clock clk
		command cmd 	compare cmp 	configuration cfg
		device dev 		error err 		flag flg
		hexadecimal hex increment inc 	initialize init 
		maximum max     message msg 	minimum min
		parameter para  previous prev 	register reg
		semaphore sem   statistic stat 	synchronize sync
		temp tmp
注意事项：
	当使用缩写时，尽量整体都缩写，只缩写一部分很丑，建议缩写时名字全部缩写；
	在 for 循环时，用于循环的内部变量可以采用缩写，代替 i，j，k；
	当单词数目超过10个时，应考虑缩写


常量 
命名方案
	名字全部大写，单词之间使用 '_' 下划线连接
	USE_SIM_TIME = True


宏 
命名方案
	名字全部大写，单词之间使用 '_' 下划线连接


全局变量 
命名方案（目前使用）
	名字全部大写，单词之间使用 '_' 下划线连接

	MIN_SPLIT_LEN = 1

备选方案
	前缀 'g_' + 变量名

    

静态变量（具有静态生存周期）
命名方案
	前缀 's_' + 变量名


类
命名方案（目前使用）
	大驼峰写法

	class TimeWindow

备选方案
	前缀 'C' + 大驼峰写法


类的数据成员
命名方案（目前使用）
	私有（保护）成员 
			变量名 + 后缀 '_'
	公有成员
			变量名

	Protect:
		int bodyLen_ = 10

	Publish:
		bool isTrue = False

备选方案1
		私有（保护）成员 
				前缀 'm_' + 变量名
		公有成员
				前缀 'm_' + 变量名

备选方案2
		私有（保护）成员 
				前缀 'm_' + 变量名 + 后缀 '_'
		公有成员
				前缀 'm_' + 变量名


枚举
命名方案1
		大驼峰写法
命名方案2
		前缀 'E' + 大驼峰写法

枚举型成员
命名方案1
		名字全部大写字母，单词之间使用 '_' 下划线连接
命名方案2
		名字首字母大写（仅适用一个单词的情况）


结构体
命名方案1
		大驼峰写法
命名方案2
		前缀 'S' + 大驼峰写法

结构体成员
命名方案1
		名字全部小写，单词之间使用 '_' 下划线连接




********************************************************************************
***********************************其他事项总结***********************************
函数形参尽量使用语言本身拥有的基本类型

函数的返回值与输入形参有关的话，则参数类型应保持一致

使用 Cpplint.py 进行风格检查

最高警告级别下干净地编译

变量定义定义在最小作用于，并在声明同时进行初始化

使用前置自增（++i）、前置自减（--i）

优先使用乘法 '*' 代替除法 '/'

用括号明确表达式的操作顺序，避免使用默认优先级

少用或不用全局变量

少用/不用静态周期变量
静态生存周期变量的对象，即全局变量，静态变量，静态类成员变量和函数静态变量

指针在创建后要及时初始化

指针被delete后，将指针设为NULL，防止野指针
释放指针数组前，先释放数组元素指针的内存

使用智能指针来进行内存的动态分配

禁止使用系统命令来执行相关命令
禁止使用与运行环境相关的系统函数
即：函数 system() 属于系统定义的命令解析器

禁止放回局部对象的指针

禁止使用无意义的数字（魔鬼数字）作为变量名
避免在名字中出现数字编号，除非是逻辑上的确需要

禁止编写复杂多用途的复合表达式

禁止使用难以理解，容易产生歧义的语句

使用异常来报告错误

检查所有可能返回的情况，不应该返回的情况要用ASSERT断言来确定

设计函数时，作为防御性编程风格，有必要对传入参数作安全检查
调用函数时，调用者有义务保证参数符合要求

禁止使用 using namespace nsA; 会污染其他头文件
可以使用 namespace nsA{ .... } 或 using nsA::funA; 


********************************************************************************
*********************************Git提交规范总结**********************************
Angular提交信息规范
提交格式如下：
		<type>(<scope>，可选): <subject>

		<body>

		<footer>

		每次提交可以包含页眉(header)、正文(body)和页脚(footer)
		每次提交页眉的必需的，正文与页脚是可选的
		每次提交的信息不超过100个字符


页眉 <type>(<scope>): <subject>
只有一行，包括三个字段：提交类型(type，必需)、作用域(scope，可选)、主题(subject，必需)

		提交类型(type)
			提交类型指定为下面其中一个： 
			1，feat：新功能
			2，fix：修补 bug
			3，docs：修改文档，比如 README, CHANGELOG, CONTRIBUTE 等等
			4，style： 不改变代码逻辑 (仅仅修改了空格、格式缩进、逗号等等)
			5，refactor：重构（既不修复错误也不添加功能）
			6，perf: 优化相关，比如提升性能、体验
			7，test：增加测试，包括单元测试、集成测试等
			8，build: 构建系统或外部依赖项的更改
			9，ci：与CI（持续集成服务）有关的改动，即：自动化流程配置或脚本修改
			10，chore: 非 src 和 test 的修改，例如构建过程或辅助工具的变动
			11，revert: 恢复先前的提交

		作用域(scope)
			范围可以是任何指定提交更改位置的内容，如果没有更合适的范围，则可以使用星号 (*)

		主题(subject)
			主题包括了对本次修改的简洁描述，有以下准则
			1，使用命令式，现在时态：“改变”不是“已改变”也不是“改变了”
			2，首字母小写
			3，不在末尾添加句号


正文 <body>
应包含本次提交的详细的主要内容。其中，需要注意的事项有：
		1，使用命令式、现在时态：“改变”不是“已改变”也不是“改变了”
		2，应该包含修改的动机以及和之前行为的对比


页脚 <footer>   
应包含关于重大变更(Breaking changes)的相关信息，以及Github issue的关闭提交应包含以下信息：
		1，不兼容修改/重大变更(Breaking changes)
		2，关闭 Github issue(Referencing issues)

		不兼容修改/重大变更(Breaking changes)
				1，所有的重大变更需要在页脚的 '重大变更区' 里提及到，以 'BREAKING CHANGE:' 开头，
					后跟一个空格或者两个换行符
				2，其余的信息就是对此次修改的描述，修改的理由和修改注释

				如下所示：
					BREAKING CHANGE: isolate scope bindings definition has changed and
					the inject option for the directive controller injection was removed.

					To migrate the code follow the example below:

					Before:

					......
					......

					After:

					......
					......

					The removed `inject` wasn't generaly useful for directives so there 
					should be no code using it.

		关闭 Github issue(Referencing issues)
				1，如果本次提交目的是关闭issue的话，需要关闭的issue应在页脚(footer)的单独一行中列出，
						并以" Closes" 关键字开头，如下所示：Closes #234
				2，如果修改了多个bug，以逗号隔开 Closes #123, #245, #992


特殊情况:
还原/回滚 <revert>
如果当前提交的目的是恢复为先前的提交（取消先前的提交），则应以开头 'revert:' ，后跟该还原的
提交的页眉。在正文中应该说：This reverts commit <hash>.，其中哈希<hash>是要还原的提交的SHA。

	提交格式如下：
		revert: <type>(<scope>，可选): <subject>

		This reverts commit 待还原提交的SHA

	如下所示：
		revert: feat(pencil): add 'graphiteWidth' option
		
		This reverts commit 667ecc1654a317a13331b17617d973392f415f02.




********************************************************************************
************************************参考文献*************************************
版本规范总结：
		1，http://wsfdl.com/devops/2016/09/27/%E7%89%88%E6%9C%AC%E5%8F%B7.html
		2，https://semver.org/lang/zh-CN/
版权声明总结：
		1，https://www.cnblogs.com/flyme/archive/2012/07/04/2575694.html
		2，http://www.lingsky.net/post/2018/12/07/copyright
注释规范总结：
		1，Google开源风格指南.pdf
		2，腾讯C++编码规范.pdf
		3，华为C语言编程规范.pdf
		4，华为C++语言编程规范.pdf
Git信息提交规范：
		1，https://zj-git-guide.readthedocs.io/zh_CN/latest/message/Angular%E6%8F%90%E4%BA%A4%E4%BF%A1%E6%81%AF%E8%A7%84%E8%8C%83/
```
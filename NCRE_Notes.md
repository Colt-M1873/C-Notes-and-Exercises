# 一、公共基础知识

程序流程图中，连接线表示控制流

需求分析阶段产生的是软件需求规格说明书

算法有穷性指运行时间有限

除了堆排序的比较次数为log，其他如快速、冒泡、直接插入排序的最大比较次数均为n*(n-1)/2

（E-R图是什么？）

E-R图到关系数据模型的过程属于逻辑设计阶段

# 二、C++

### const相关：常量、指向常量的指针以及常指针

const int a=0; 定义常量，定义常量时候必须初始化（初始化为NULL可否？）

const double *p; 在定义指向常量的指针时初始化与否均可，p是一个指向double型常量的指针，具体指向哪个常量不一定 p is a point to a const double

double *const p=m; 定义常指针时必须初始化，p是一个指向double的常指针 p is a const point to double 

常指针意味着该*const p指针中保存的地址不能再变，即该指针中存的地址值固定，该指针不能指向内存中的其他地址

简便方法：从右往左读，遇到p就替换为“p is a”，遇到*就替换为“point to”，其余不变。

C++中const int和int const意义相同

不能用常量直接给指针赋值，*p=5 这样写不对







## C++语法规则

if语句的条件部分不能嵌套条件语句

运算符重载不允许定义新的运算符，不能改变运算符的优先级、结核性和运算对象个数

内联函数由编译器实现，编译器直接用函数代码替换函数调用，调用时不发生控制转移，故运行速度较快，但比较占用内存，因此通常将短小且频繁调用的函数写成内联函数。

运算符重载：一般来说单目运算符最好重载为类的成员函数，双目运算符最好重载为类的友元函数，特例：双目运算符=  ()  [] -> 不能重载为类的友元函数



通过常对象只能调用其常成员函数，不能调用非const成员函数，常对象的成员函数不都是常成员函数，只需保证其数据成员为常数据成员即可

常成员函数不能修改对象数据成员的值，不能调用该类中没有用const修饰的成员函数，只能调用该类中的常数据成员
只能通过构造函数的参数初始化列表对常数据成员进行初始化



静态成员函数与静态成员数据一样，属于类而不属于对象，因此没有this指针，没有this指针,因此只能访问静态成员，不能访问非静态成员
友元函数与普通函数相同， 无this指针，不归属于某个类，不是类的成员，在类外可以直接调用

函数名前加~表示析构函数

类的数据成员不能在声明类时初始化



纯虚函数 virtual<类型><函数名>（<参数表>）=0; 纯虚函数没有函数体，要在派生类中定义，纯虚函数不能声明为内联函数
拥有纯虚函数的类叫做抽象类，抽象类不能用于定义对象，若改抽象类派生的派生类中没有对纯虚函数进行重定义，则派生类也是抽象类

声明对象数组时，数组长度即执行构造函数的次数
定义指针对象时不调用构造函数



派生类在创建对象时要说明基类对象如何初始化，需要在构造函数后面添加初始化列表。在初始化列表中，要指明调用基类构造函数的形式。具体写法如下：
派生构造函数名(形参表): 基类名(基类构造函数实参表) { }

定义派生类的对象时，先调用基类构造函数，再调用派生类构造函数，对象释放时，先执行派生类析构函数，再执行基类构造函数

2.25 选择题14分

释放指针数组用 delete []       注：单纯delete不能用于释放指针数组
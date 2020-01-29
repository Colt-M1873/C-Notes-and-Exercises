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


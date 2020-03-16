# Algorithm

常见算法分析，按照不同的思想进行分类，包含完整代码(C++)，更多解析见我的[个人博客](http://www.cgz.net.cn/)。

This repo displays common algorithms, which are classified according to different ideas, including complete code(C++). More analysis can refer to my [Personal Blog](http://www.cgz.net.cn/).


## (I) Divide and Conquer

### 1. Binary Search(二分搜索)

[code](https://github.com/spuronlee/Algorithm/blob/master/Divide%20and%20Conquer/DC_1_BinarySearch.cpp)，解析

### 2. Round Robin Schedule(循环赛日程表)

设有n=2^k个运动员要进行网球循环赛，现在设计一个满足以下要求的比赛日程表：  
(1)每个选手必须与其他n-1个选手各比赛一次;  
(2)每个选手一天只能参赛一次;  
(3)循环赛在n-1天内结束.  
请按照此要求将比赛日程表设计成有n行和n-1列的日程表，在表中第i行第j列填入第i个选手在第j天所遇到的对手，其中1<=i<=n,1<=j<= n-1.  

[code](https://github.com/spuronlee/Algorithm/blob/master/Divide%20and%20Conquer/DC_2_RoundRobinSchedule.cpp)，解析

## (II) Dynamic Programming

### 1. Matrix-chain Multiplication(矩阵连乘)

给定n个矩阵｛A1,A2,…,An｝，其中Ai与Ai+1是可乘的，i=1，2…，n-1。如何确定计算矩阵连乘积的计算次序，使得依此次序计算矩阵连乘积需要的数乘次数最少？例如，设有四个矩阵A, B, C, D，总共有五种完全加括号的方式:(A((BC)D))、(A(B(CD)))、((AB)(CD))、(((AB)C)D)、((A(BC)D)). 假如他们的维度矩阵是A=50×10, B=10×40, C=40×30, D=30×5.上述5种完全加括号方式的计算工作量为:16000,10500, 36000,87500, 34500,那么最优的加括号方式为(A(B(CD))).

`Example`: 给定6个矩阵,A1=50×10, A2=10×40, A3=40×30, A4=30×5, A5=5×20, A6=20×15

`Input`: 矩阵个数n, 矩阵的维数向量 int n = 6; int p[n+1] = {50, 10, 40, 30, 5, 20 ,15}; 

`Output`: 矩阵加括号方式 ((A1(A2(A3A4)))(A5A6))

`Function`: string MarticChain(int * p, int n);

[code](https://github.com/spuronlee/Algorithm/blob/master/Dynamic%20Programming/DP_1_MatrixMultiplication.cpp)，解析

## (III) Greedy

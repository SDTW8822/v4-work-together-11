//学生成绩管理系统v4.0--团队合作项目
/*学生成绩管理系统V4.0(指针和数组)

某班有最多不超过30人（具体人数有键盘输入）参加期末考试，考试科目最多不超过6门（具体门数有键盘输入），用二维数组作函数参数，编程实现如下学生成绩管理：

（1）  录入每个学生的学号、姓名和各科考试成绩；

（2）  计算每门课程的总分和平均分；

（3）  计算每个学生的总分和平均分；

（4）  按每个学生的总分由高到低排出名次表；

（5）  按每个学生的总分由低到高排出名次表；

（6）  按学号由小到大排出成绩表；

（7）  按姓名的字典顺序排出成绩表；

（8）  按学号查询学生排名及其各科考试成绩；

（9）  按姓名查询学生排名及其各科考试成绩；

（10）按优秀（90-100）、良好（80-89）、中等（70-79）、及格（60-69）、不及格（0-59）5个类别，统计每个类别的人数以及所占的百分比；

（11）输出每个学生的学号、姓名、各科考试成绩、总分、平均分，以及每门课程的总分和平均分。

 

实验目的：在学生成绩管理系统V3.0基础上，通过增加任务要求，熟悉二维数组作为函数参数、模块化程序设计以及增量测试方法。

 

要求程序运行后先显示如下菜单，并提示用户输入选项：

1.  Input record

2.  Calculate total and average score of every course

3.  Calculate total and average score of every student

4.  Sort in descending order by total score of every student

5.  Sort in asending order by total score of every student

6.  Sort in ascending order by number

7.  Sort in dictionary order by name

8.  Search by number

9.  Search by name

10.Statistic analysis

11.List record

0.  Exit

Please enter your choice:*/


#include <stdio.h>
#include <string.h>
#define MAX_len 10                                                          //最大姓名长度
#define N 30                                                                //最多学生人数
#define MAX_css  6                                                          //最多考试科目总数
void Readscore(int score[], long num[], char name[][MAX_len],char prac[][MAX_css], int n);		                    /*读入学生学号、姓名和成绩*/
void T_Ascore(int n, int score[]);					                            /*计算总成绩和平均成绩*/
void PrintScore(long num[], int score[], char name[][MAX_len], int n);                           /*打印学号和成绩*/
void SelectionScore(int num[], int score[], char name[][MAX_len], int n, int (*compare)(int a, int b)); /*函数指针*/
int Ascending(int a, int b);                                                           /*使函数按照升序排列*/
int Descending(int a, int b);                                                       /*使函数按照降序排列*/
void Swapchar(char a[], char[]);                                                       /*交换两个字符数组数据*/
void  Swapint(int* a, int* b);                                                /*交换两个整型数据*/
void ASsortbynum(long num[], int score[], char name[][MAX_len], int n, int (*nunn)(int a, int b));/*将学号按照从小到大排序*/
void Searchbynum(long num[], char name[][MAX_len], int score[], int n);                        /*按照学号查询数据*/
void StatisticAnalysis(int score[], int n);                                     /*统计各个类别的人数以及所占比例*/
void Searchbyname(long num[], int score[], char name[][MAX_len], int n);   /*按照学生姓名查找学生成绩信息*/
void ASsortbynameD(long num[], int score[], char name[][MAX_len], int n);/*按照学生字典进行排序*/

int main(void)
{
    int score[N], n, sum, average, c;			                     //变量解释：n是学生人数，sum是学生总成绩，average是学生平均成绩,c是用户功能选项
    int     p;
    long int num[N];
    int i;
    char prac[MAX_css][MAX_css];
    char name[N][MAX_len];                                         //定义一个输入学生姓名的字符数组
    char(*pr)[MAX_css];
    pr = prac;
    printf("Please input the total students number:");
    scanf("%d", &n);                                                /*从键盘读入学生人数*/
    printf("Please input the test number:");                        /*从键盘读入需要录入的科目数目*/
    scanf("%d", &p);
    printf("Please input all of the test name:\n");
    for (i = 0; i < p; i++,pr++)
    {
        scanf("%s", pr);                                            /*通过for循环把考试科目名称存放在二维数组中*/
    }

    printf("------------------------------------------------------------------------\n");
    printf("1.————Input record\n");                                                     //选项1：输入学生学号、姓名和学生成绩
    printf("2.————Caculate totel and average score of course\n");         //选项2：计算学生总成绩和平均成绩
    printf("3.————Sort in descending order by score\n");                      //选项3：按照成绩由高到低排出名次表
    printf("4.————Sort in ascending order by score\n");                        //选项4：按照成绩由低到高排出名次表
    printf("5.————Sort in ascending order by number\n");                   //选项5：按照学号由低到高排出名次表
    printf("6.————Search by number\n");                                             //选项6：查询学号信息
    printf("7.————Statistic analysis\n");                                               //选项7：统计类别人数以及所占人数比例
    printf("8.————List record\n");                                                       //选项8：输出每个学生的学号考试成绩以及课程总分和平均分
    printf("9.————Sarch by name \n");                                                  //选项9：按照学生姓名查找成绩信息
    printf("10.———-Sarch by name dictionary \n");                                    //选项10：按照学生姓名字典排序学生成绩
    printf("0.————Exit\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Please enter your choice:\n");
    printf("\n");
    for (;;)
    {
        scanf("%d", &c);
        switch (c)
        {
        case 1:Readscore(score, num, name,prac,n);
            printf("Please enter your choice:\n");
            break;
        case 2:T_Ascore(n, score);
            printf("Please enter your choice:\n");
            break;
        case 3:SelectionScore(num, score, name, n, Ascending);
            PrintScore(num, score, name, n);
            printf("Please enter your choice:\n");
            break;
        case 4:SelectionScore(num, score, name, n, Descending);
            PrintScore(num, score, name, n);
            printf("Please enter your choice:\n");
            break;
        case 5:ASsortbynum(num, score, name, n, Ascending);
            PrintScore(num, score, name, n);
            printf("Please enter your choice:\n");
            break;
        case 6:Searchbynum(num,name,score,n);
            printf("Please enter your choice:\n");
            break;
        case 7: StatisticAnalysis(score, n);
            break;
        case 8:PrintScore(num, score, name, n);
            T_Ascore(n, score);
            printf("Please enter your choice:\n");
            break;
        case 9:Searchbyname(num, score, name, n);
            PrintScore(num, score, name, n);
            printf("Please enter your choice:\n");
            break;


        case 10:ASsortbynameD(num, score, name, n);
            PrintScore(num, score, name, n);
            printf("Please enter your choice:\n");
            break;
        case 0:printf("End of program !\n");
            break;
        default:printf("Iput error ! \n");
        }
    }
    return 0;
}



/*函数功能：键盘输入学生的学号姓名和成绩*/
void Readscore(int score[], long num[], char name[][MAX_len],char prac[][MAX_css], int n)
{
    int i, j;
    char(*p)[MAX_len];
    p = name;

    for (i = 0; i < n; i++)
    {


        printf("Input student name:\t");
        scanf("%s", p);
        printf("Input student ID:\t");
        scanf("%ld", &num[i]);
        printf("Input student score:\t");
        scanf("%d", &score[i]);
        p++;

    }
}

/*函数功能：打印学生总成绩和平均成绩*/
void T_Ascore(int n, int score[])
{
    int sum = 0, totalscore, averagescore;
    int i;
    for (i = 0; i < n; i++)
        sum += score[i];
    averagescore = sum / n;
    printf("\tThe student totalscore is %d\n", sum);
    printf("\tThe student averagescore is %d\n", averagescore);
}


/*函数功能：打印每个同学的姓名、学号和成绩*/
void PrintScore(long num[], int score[], char name[][MAX_len], int n)
{
    int i;
    char(*p)[MAX_len];
    p = name;
    for (i = 0; i < n; i++)
    {
        printf("\t%s%10ld%4d\n", p[i], num[i], score[i]);
    }
}
/*函数功能：两个字符数组的交换*/
void Swapchar(char a[], char b[])
{
    char t[N];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);



}
/*函数功能：两个整数值的交换*/
void Swapint(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*函数功能：调用函数指针compare指向的函数实现对数组score的交换排序*/

void SelectionScore(int num[], int score[], char name[][MAX_len], int n, int (*compare)(int a, int b))
{
    int i, j, k;
    char(*p)[MAX_len];
    p = name;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j], score[k]))  k = j;
        }
        if (k != j)
        {
            Swapint(&score[k], &score[i]);
            Swapint(&num[k], &num[i]);
            Swapchar(p + k, p + i);


        }
    }
}

/*函数功能：使数据按照升序排列*/
int Ascending(int a, int b)
{
    return  a < b;
}


/*函数功能：使数据实现降序排列*/
int Descending(int a, int b)
{
    return a > b;
}

/*函数功能：学号按照从小到大排序*/
void ASsortbynum(long num[], int score[], char name[][MAX_len], int n, int (*nunn)(int a, int b))
{
    int i, j, k;
    char(*p)[MAX_len];
    p = name;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*nunn)(num[j], num[k]))  k = j;
        }
        if (k != j)
        {
            Swapint(&score[k], &score[i]);
            Swapint(&num[k], &num[i]);
            Swapchar(p + k, p + i);
        }
    }
}



/*函数功能：按照学号查找成绩信息*/
void Searchbynum(long num[], char name[][MAX_len], int score[], int n)

{
    int i, think, cishu = 0;
    long   nums;
    think = 0;

    SelectionScore(num, score, name, n, Descending);

    printf("******************Whitch ID do you want to know !Please input it :\n");
    scanf("%ld", &nums);
    for (i = 0; i <= n - 1; i++)
    {
        if (num[i] != nums)
        {
            cishu++;
        }
        if (num[i] == nums)
        {
            think = i;
        }

    }

    printf("This ID :%ld\t  name is :%s \t score is :%d \t  名次：%d\n", num[think], name[think], score[think], think + 1);

}





/*按照学生姓名查找学生成绩信息*/
void Searchbyname(long num[], int score[], char name[][MAX_len], int n)
{
    int i, think, cishu = 0;
    char names[1][MAX_len];

    think = 0;

    SelectionScore(num, score, name, n, Descending);

    printf("******************Whitch NAME   do you want to know !Please input it :\n");
    scanf("%s", names[0]);
    for (i = 0; i <= n - 1; i++)
    {
        if (strcmp(name[i], names[0]) != 0)
        {
            cishu++;
        }
        if (strcmp(name[i], names[0]) == 0)
        {
            think = i;
        }

    }

    printf("This ID :%ld\t  name is :%s \t score is :%d \t  名次：%d\n", num[think], name[think], score[think], think + 1);

}

/*函数功能：按照学生姓名字典顺序排名*/
void ASsortbynameD(long num[], int score[], char name[][MAX_len], int n)
{
    char(*p)[MAX_len];
    p = name;
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)

        {
            if (strcmp(name[i], name[j]) > 0)



            {
                Swapint(&score[j], &score[i]);
                Swapint(&num[j], &num[i]);
                Swapchar(p + j, p + i);
            }
        }
    }



}

/*函数功能：计算各个类别的学生成绩状况*/



void StatisticAnalysis(int score[], int n)
{
    printf("n=%d", n);
    int i, vgod, gods, jige, unjige;
    i = 0; vgod = 0; gods = 0; jige = 0; unjige = 0;
    for (i = 0; i < n; i++)
    {
        if (score[i] >= 90)
        {
            vgod++;
        }
        if (score[i] >= 80 && score[i] < 90)
        {
            gods++;
        }
        if (score[i] >= 60)

        {
            jige++;
        }
        if (score[i] < 60)
        {
            unjige++;
        }
    }

    printf("本次成绩情况如下：\n 优秀率：%1f %%\n 良好率：%1f %%\n 及格率： %1f %%  \n不及格率：%1f %% \n", (float)vgod * 100 / n, (float)gods * 100 / n, (float)jige * 100 / n, (float)unjige * 100 / n);
}

//每次修改完标注一下你们修改了哪些地方
//张泽含真帅
//ѧ���ɼ�����ϵͳv4.0--�ŶӺ�����Ŀ
/*ѧ���ɼ�����ϵͳV4.0(ָ�������)

ĳ������಻����30�ˣ����������м������룩�μ���ĩ���ԣ����Կ�Ŀ��಻����6�ţ����������м������룩���ö�ά�������������������ʵ������ѧ���ɼ�����

��1��  ¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���

��2��  ����ÿ�ſγ̵��ֺܷ�ƽ���֣�

��3��  ����ÿ��ѧ�����ֺܷ�ƽ���֣�

��4��  ��ÿ��ѧ�����ܷ��ɸߵ����ų����α�

��5��  ��ÿ��ѧ�����ܷ��ɵ͵����ų����α�

��6��  ��ѧ����С�����ų��ɼ���

��7��  ���������ֵ�˳���ų��ɼ���

��8��  ��ѧ�Ų�ѯѧ������������ƿ��Գɼ���

��9��  ��������ѯѧ������������ƿ��Գɼ���

��10�������㣨90-100�������ã�80-89�����еȣ�70-79��������60-69����������0-59��5�����ͳ��ÿ�����������Լ���ռ�İٷֱȣ�

��11�����ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ���֣��Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�

 

ʵ��Ŀ�ģ���ѧ���ɼ�����ϵͳV3.0�����ϣ�ͨ����������Ҫ����Ϥ��ά������Ϊ����������ģ�黯��������Լ��������Է�����

 

Ҫ��������к�����ʾ���²˵�������ʾ�û�����ѡ�

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
#define MAX_len 10                                                          //�����������
#define N 30                                                                //���ѧ������
#define MAX_css  6                                                          //��࿼�Կ�Ŀ����
void Readscore(int score[], long num[], char name[][MAX_len],char prac[][MAX_css], int n);		                    /*����ѧ��ѧ�š������ͳɼ�*/
void T_Ascore(int n, int score[]);					                            /*�����ܳɼ���ƽ���ɼ�*/
void PrintScore(long num[], int score[], char name[][MAX_len], int n);                           /*��ӡѧ�źͳɼ�*/
void SelectionScore(int num[], int score[], char name[][MAX_len], int n, int (*compare)(int a, int b)); /*����ָ��*/
int Ascending(int a, int b);                                                           /*ʹ����������������*/
int Descending(int a, int b);                                                       /*ʹ�������ս�������*/
void Swapchar(char a[], char[]);                                                       /*���������ַ���������*/
void  Swapint(int* a, int* b);                                                /*����������������*/
void ASsortbynum(long num[], int score[], char name[][MAX_len], int n, int (*nunn)(int a, int b));/*��ѧ�Ű��մ�С��������*/
void Searchbynum(long num[], char name[][MAX_len], int score[], int n);                        /*����ѧ�Ų�ѯ����*/
void StatisticAnalysis(int score[], int n);                                     /*ͳ�Ƹ������������Լ���ռ����*/
void Searchbyname(long num[], int score[], char name[][MAX_len], int n);   /*����ѧ����������ѧ���ɼ���Ϣ*/
void ASsortbynameD(long num[], int score[], char name[][MAX_len], int n);/*����ѧ���ֵ��������*/

int main(void)
{
    int score[N], n, sum, average, c;			                     //�������ͣ�n��ѧ��������sum��ѧ���ܳɼ���average��ѧ��ƽ���ɼ�,c���û�����ѡ��
    int     p;
    long int num[N];
    int i;
    char prac[MAX_css][MAX_css];
    char name[N][MAX_len];                                         //����һ������ѧ���������ַ�����
    char(*pr)[MAX_css];
    pr = prac;
    printf("Please input the total students number:");
    scanf("%d", &n);                                                /*�Ӽ��̶���ѧ������*/
    printf("Please input the test number:");                        /*�Ӽ��̶�����Ҫ¼��Ŀ�Ŀ��Ŀ*/
    scanf("%d", &p);
    printf("Please input all of the test name:\n");
    for (i = 0; i < p; i++,pr++)
    {
        scanf("%s", pr);                                            /*ͨ��forѭ���ѿ��Կ�Ŀ���ƴ���ڶ�ά������*/
    }

    printf("------------------------------------------------------------------------\n");
    printf("1.��������Input record\n");                                                     //ѡ��1������ѧ��ѧ�š�������ѧ���ɼ�
    printf("2.��������Caculate totel and average score of course\n");         //ѡ��2������ѧ���ܳɼ���ƽ���ɼ�
    printf("3.��������Sort in descending order by score\n");                      //ѡ��3�����ճɼ��ɸߵ����ų����α�
    printf("4.��������Sort in ascending order by score\n");                        //ѡ��4�����ճɼ��ɵ͵����ų����α�
    printf("5.��������Sort in ascending order by number\n");                   //ѡ��5������ѧ���ɵ͵����ų����α�
    printf("6.��������Search by number\n");                                             //ѡ��6����ѯѧ����Ϣ
    printf("7.��������Statistic analysis\n");                                               //ѡ��7��ͳ����������Լ���ռ��������
    printf("8.��������List record\n");                                                       //ѡ��8�����ÿ��ѧ����ѧ�ſ��Գɼ��Լ��γ��ֺܷ�ƽ����
    printf("9.��������Sarch by name \n");                                                  //ѡ��9������ѧ���������ҳɼ���Ϣ
    printf("10.������-Sarch by name dictionary \n");                                    //ѡ��10������ѧ�������ֵ�����ѧ���ɼ�
    printf("0.��������Exit\n");
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



/*�������ܣ���������ѧ����ѧ�������ͳɼ�*/
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

/*�������ܣ���ӡѧ���ܳɼ���ƽ���ɼ�*/
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


/*�������ܣ���ӡÿ��ͬѧ��������ѧ�źͳɼ�*/
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
/*�������ܣ������ַ�����Ľ���*/
void Swapchar(char a[], char b[])
{
    char t[N];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);



}
/*�������ܣ���������ֵ�Ľ���*/
void Swapint(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*�������ܣ����ú���ָ��compareָ��ĺ���ʵ�ֶ�����score�Ľ�������*/

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

/*�������ܣ�ʹ���ݰ�����������*/
int Ascending(int a, int b)
{
    return  a < b;
}


/*�������ܣ�ʹ����ʵ�ֽ�������*/
int Descending(int a, int b)
{
    return a > b;
}

/*�������ܣ�ѧ�Ű��մ�С��������*/
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



/*�������ܣ�����ѧ�Ų��ҳɼ���Ϣ*/
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

    printf("This ID :%ld\t  name is :%s \t score is :%d \t  ���Σ�%d\n", num[think], name[think], score[think], think + 1);

}





/*����ѧ����������ѧ���ɼ���Ϣ*/
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

    printf("This ID :%ld\t  name is :%s \t score is :%d \t  ���Σ�%d\n", num[think], name[think], score[think], think + 1);

}

/*�������ܣ�����ѧ�������ֵ�˳������*/
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

/*�������ܣ������������ѧ���ɼ�״��*/



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

    printf("���γɼ�������£�\n �����ʣ�%1f %%\n �����ʣ�%1f %%\n �����ʣ� %1f %%  \n�������ʣ�%1f %% \n", (float)vgod * 100 / n, (float)gods * 100 / n, (float)jige * 100 / n, (float)unjige * 100 / n);
}

//ÿ���޸����עһ�������޸�����Щ�ط�
//������˧
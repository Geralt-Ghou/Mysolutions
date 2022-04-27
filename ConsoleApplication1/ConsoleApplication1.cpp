// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int High = 3660, Width = 1200;
int high_left=3660, width_left=1200;
int width_last=Width;

void pip_box(int h, int w)
{

    if (high_left >= h && width_left >= w)
    {
        if (high_left==High)
        {
            high_left = High - h;
            width_last = Width;
            width_left = Width - w;

        }
        else
        {
            high_left = high_left - h;
            width_left = (width_last - w < width_left) ? (width_last - w) : width_left;
        }
        std::cout << h << "\t" << w << "\n";
    }
    else if (high_left < h && width_left >= w)
    {
        high_left = High - h;
        width_last = width_left;
        width_left = width_left - w;
        std::cout << h << "\t" << w << "\n";

    }
    else if (high_left >= h && width_left < w)
    {
        high_left = high_left - h;
        std::cout << h << "\t" << w << "\n";
    }
    else
        std::cout << "It's can't be pipped in" << "\n";
}
int main()
{

    int box[10][2] = {
        660,630,
        100,400,
        1600,140,
        290,390,
        370,180,
        660,630,
        150,400,
        100,140,
        290,390,
        170,180,

    };

    for (int i = 0;i < 10;i++)
        std::cin >> box[i][0]>>box[i][1];

    int S_MAX;
    int s=0;
    float rate;
    for (int i = 0;i < 10;i++)
    { 
        pip_box(box[i][0], box[i][1]);
        std::cout <<"left:"<< high_left << "\t" << width_left << "\n";
        s += box[i][0] * box[i][1];
    }
   
    S_MAX = (Width - width_left)*High;

    rate = (float)s / S_MAX;
    std::cout << "rate:"<<rate;









    //for (int i = 0;i < 5;i++)
    //{
    //    for (int j = 0;j < 2;j++)
    //        std::cout << box[i][j] << "\t";
    //    std::cout << "\n";
    //}
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

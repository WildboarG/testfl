#include <stdio.h>

#define N 10  // 数组长度
#define M 3   // 滑动窗口长度

void slidingAverageFilter(float *input, float *output) {
    float sum = 0;
    int i, j;

    // 计算初始窗口内的和
    for (i = 0; i < M; i++) {
        sum += input[i];
    }

    // 对于每个元素，计算滑动平均值
    for (i = 0; i <= N - M; i++) {
        output[i] = sum / M;
        // 移动窗口，更新和
        sum -= input[i];
        sum += input[i + M];
    }
}

int main() {
    float input[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100}; // 输入数组
    float output[N - M + 1]; // 输出数组

    slidingAverageFilter(input, output);

    // 输出滤波后的结果
    printf("滑动平均滤波后的结果为：\n");
    for (int i = 0; i < N - M + 1; i++) {
        printf("%.2f ", output[i]);
    }
    printf("\n");

    return 0;
}
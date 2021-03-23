

int x;

void BitCalc()
{
    x & -x; // 最后一位1保留，其他全为0
    x & (x-1); // 最后一位1变为0，其他不变


    int pos = ~(col | ld | rd) & ((1 << n) - 1);
}
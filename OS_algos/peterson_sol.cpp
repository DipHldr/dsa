#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int flag[2];
int turn;
const int MAX = 1e9;
int ans = 0;

void lock_init()
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int self)
{
    flag[self] = 1;
    turn = 1 - self;

    while (flag[1 - self] == 1 && turn == 1 - self);
}

void unlock(int self)
{
    flag[self] = 0;
}

void func(int self)
{
    int i = 0;
    cout << "Thread Entered: " << self << endl;

    lock(self);

    for (i = 0; i < MAX; i++)
        ans++;

    unlock(self);
}

int main()
{
    thread t1(func, 0);
    thread t2(func, 1);

    lock_init();

    t1.join();
    t2.join();

    cout << "Actual Count: " << ans << " | Expected Count: " << MAX * 2 << endl;

    return 0;
}
// Note :  To compile your code correctly, you need to link it with the pthread library.
//g++ -pthread peterson_spinlock.cpp -o peterson_spinlock

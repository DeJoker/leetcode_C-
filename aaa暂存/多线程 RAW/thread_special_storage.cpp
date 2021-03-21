
// namespace ThreadStorage {
// //无锁加锁，线程局部变量
// thread_local void* storage;

// void Set(void* ptr)
// {
//     storage = ptr;
// }

// void* Get()
// {
//     return storage;
// }

// void reset()
// {
//     storage = nullptr;
// }

// } // namespace ThreadStorage

static thread_local int storage;  //无锁加锁，线程局部变量

template<typename Type>
class ThreadStorage {
    static thread_local Type _storage;  //无锁加锁，线程局部变量
public:
    ThreadStorage() {}

    void Set(Type& ptr)
    {
        _storage = ptr;
    }

    Type Get()
    {
        return _storage;
    }
};

// class ThreadStorage {
//     static thread_local int _storage;  //无锁加锁，线程局部变量
// public:
//     ThreadStorage() {}

//     void Set(int ptr)
//     {
//         _storage = ptr;
//     }

//     int Get()
//     {
//         return _storage;
//     }
// };


#include "concurrency.h"


struct P {
    string a;
    int b;
    P* next;

    P() {}

    P(const string& r, int k, void* nn) :
        a(r), b(k), next((P*)nn)
    {}
};

template<typename Type>
static thread_local Type yyy;


void TestGetTSS()
{
    yyy<int> = 4;
    yyy<string> = "wokao";
    // ThreadStorage<int> aa;
    // int var = aa.Get();

    // ThreadStorage<P> aa;
    // P var = aa.Get();
    // cout << std::this_thread::get_id() << "    ---->   " << var.a <<" : "<< var.b <<" : "<< var.next << endl;
}


// void TestTSS(int num)
// {
//     // P* local(nullptr);
//     int h;
//     P local("nimade", 1e3+num, &h);
//     {
//         auto var = make_shared<P>("nimade", 1e3+num, &h);
//         cout << var.use_count() << endl;
//         P* heheh = var.get();
//         cout << var.use_count() << endl;
//     }
//     ThreadStorage<P> aa;
//     aa.Set(local);
//     TestGetTSS();
// }


int main()
{
    // thread a(TestTSS, 3), b(TestTSS, 2);
    // a.join();
    // b.join();
    return 0;
}



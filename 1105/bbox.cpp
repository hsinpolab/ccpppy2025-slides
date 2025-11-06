
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

std::mutex OnlyOneThreadCanRun;

// This is the "main" function for the B sound
void Bfunc() {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    while (true) {
        OnlyOneThreadCanRun.lock();
        cout << "B" << endl;
        OnlyOneThreadCanRun.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

// This is the "main" function for the TS sound
void TSfunc() {
    string indent = "          ";
    while(true) {
        OnlyOneThreadCanRun.lock();
        cout << indent << "TS" << endl;
        OnlyOneThreadCanRun.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// This is the "main" function for the K sound
void Kfunc() {
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    string indent = "                    ";
    while (true) {
        OnlyOneThreadCanRun.lock();
        cout << indent << "K" << endl;
        OnlyOneThreadCanRun.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

// This is the mainest main function, the main function of all
int main() {
    std::thread Bthread(Bfunc);
    std::thread TSthread(TSfunc);
    std::thread Kthread(Kfunc);

    Bthread.join();
    TSthread.join();
    Kthread.join();

    cout << "All threads join the main thread.  Music ends." << endl;
}


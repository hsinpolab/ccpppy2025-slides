#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
using namespace std;

class Animal {
public:
    // member variables
    int age;
    int health;
    int x, y;

    // constructor and destructor
    Animal() {};
    Animal(int h) : age(1), health(h) {
        x = rand() % 50;
        y = rand() % 50;
    }
    Animal(int h, int x, int y) : age(1), health(h), x(x), y(y) {}
    ~Animal() {}

    // other member functions
    void move() {
        age += 1;
        health -= 1;
        int a = rand() % 5;
        if (a == 0) x += 1;
        if (a == 1) x -= 1;
        if (a == 2) y += 1;
        if (a == 3) y -= 1;
        if (x < 0) x = 0;
        if (x >= 400) x = 399;
        if (y < 0) y = 0;
        if (y >= 200) y = 199;

        // x = (x + 400) % 400;
        // y = (y + 200) % 200;
    }
};

class Rabbit : public Animal {
public:
    // constructors and destructor
    Rabbit() : Animal(0) {}
    Rabbit(int h) : Animal(h) {}
    Rabbit(int h, int x, int y) : Animal(h, x, y) {}
    ~Rabbit() {}

    // other member functions
    bool IsReady() {
        return age % 10 == 0;
    }
    Rabbit Reproduce() {
        Rabbit R = Rabbit(100, x, y);
        return R;
    }
};

class Tiger : public Animal {
public:
    // constructors and destructor
    Tiger() : Animal(0){}
    Tiger(int h) : Animal(h) {}
    Tiger(int h, int x, int y) : Animal(h, x, y) {}
    ~Tiger() {}

    // other member functions
    bool IsReady() {
        return health > 100;
    }
    Tiger Reproduce() {
        Tiger T = Tiger(health/2, x, y);
        health /= 2;
        return T;
    }
    void eat(Rabbit& R) {
        health += 5;
        R.health = 0;
    }
};

Rabbit ListOfR[1000010];
Tiger ListOfT[1000010];
int nRabbit = 0;
int nTiger = 0;

void PushR(Rabbit R) {
    ListOfR[nRabbit] = R;
    nRabbit++;
}
void PushT(Tiger T) {
    ListOfT[nTiger] = T;
    nTiger++;
}

int CompareXY(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * 1000 + dy;
}

int CompareRabbitsXY(const void* a, const void* b) {
    Rabbit* R1 = (Rabbit*)a;
    Rabbit* R2 = (Rabbit*)b;
    return CompareXY(R1->x, R1->y, R2->x, R2->y);
}

void SortRabbit() {
    qsort(ListOfR, nRabbit, sizeof(Rabbit), CompareRabbitsXY);
}

int CompareTigersXY(const void* a, const void* b) {
    Tiger* T1 = (Tiger*)a;
    Tiger* T2 = (Tiger*)b;
    return CompareXY(T1->x, T1->y, T2->x, T2->y);
}

void SortTiger() {
    qsort(ListOfT, nTiger, sizeof(Tiger), CompareTigersXY);
}

void VisualizeField(int day) {
    // create field
    char Field[100][400];
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 400; x++) {
            Field[y][x] = ' ';
        }
    }
    // put rabbits on the field
    for (int i = 0; i < nRabbit; i++) {
        Rabbit& R = ListOfR[i];
        if (R.health > 0) Field[R.y/2][R.x] = '.';
        if (R.health == 0) Field[R.y/2][R.x] = ' ';
    }
    // put tigers on the field
    for (int j = 0; j < nTiger; j++) {
        Tiger& T = ListOfT[j];
        if (T.health > 0) Field[T.y/2][T.x] = '#';
        if (T.health == 0) Field[T.y/2][T.x] = ' ';
    }
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 400; x++) {
            cout << Field[y][x];
        }
        cout << endl;
    }
    cout << day << " days  " << nRabbit << " Rabbits  " << nTiger << " Tigers  " << endl;
    for (int i = 0; i < sqrt(nRabbit) && i < 400; i++) cout << ".";
    cout << endl;
    for (int j = 0; j < sqrt(nTiger) && j < 400; j++) cout << "#";
    cout << endl;
    
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main() {
    srand(time(NULL));

    // Add rabbits at random places
    for (int i = 0; i < 1000; i++) {
        PushR(Rabbit(100));
    }
    // Add tigers at random places
    for (int j = 0; j < 200; j++) {
        PushT(Tiger(50));
    }
    
    // Main loop
    for (int day = 0; day < 10000000; day++) {
        if (nTiger == 0) break;
        if (nRabbit == 0) break;

        // Rabbit moving
        for (int i = 0; i < nRabbit; i++) {
            ListOfR[i].move();
        }
        // Rabbit reproduce
        if (nRabbit < 500000) {
            for (int i = 0; i < nRabbit; i++) {
                Rabbit& R = ListOfR[i];
                if (R.IsReady()) PushR(R.Reproduce());
            }
        }
        // Tiger moving
        for (int j = 0; j < nTiger; j++) {
            ListOfT[j].move();
        }
        // Tiger reproduce
        if (nTiger < 500000) {
            for (int j = 0; j < nTiger; j++) {
                Tiger& T = ListOfT[j];
                if (T.IsReady()) PushT(T.Reproduce());
            }
        }
        // Check if tiger overlap with rabbit
        SortRabbit();
        SortTiger();
        for (int i = 0, j = 0; i < nRabbit && j < nTiger;) {
            Rabbit& R = ListOfR[i];
            Tiger& T = ListOfT[j];
            int C = CompareXY(R.x, R.y, T.x, T.y);
            if (C < 0) {
                i++; // next rabbit
                continue;
            }
            if (C > 0) {
                j++; // next tiger
                continue;
            }
            if (C == 0) {
                T.eat(R);
                i++; // next rabbit
                // tiger can eat multiple rabbits
                continue;
            }
        }
        // Rabbits overlapping ==> die
        for (int i = 0; i < nRabbit - 1; i ++) {
            int j = i + 10;
            if (ListOfR[i].x == ListOfR[j].x && ListOfR[i].y == ListOfR[j].y) {
                ListOfR[i].health = 0;
                ListOfR[j].health = 0;
            }
            else i++;
        }

        if (day % 10 == 0) VisualizeField(day);

        // Remove dead Rabbit
        for (int i = 0; i < nRabbit;) {
            if (ListOfR[i].health <= 0) {
                --nRabbit;
                ListOfR[i] = ListOfR[nRabbit];
            }
            else i++;
        }
        // Remove dead tiger
        for (int j = 0; j < nTiger;) {
            if (ListOfT[j].health <= 0) {
                --nTiger;
                ListOfT[j] = ListOfT[nTiger];
            }
            else j++;
        }
    }
}
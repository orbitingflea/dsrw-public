#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
  while (true) {
    system("python3 dmk.py in && ./btree < in > out && ./brute < in > ans");
    if (system("diff -b ans out")) {
      puts("wrong");
      exit(0);
    } else {
      puts("ok");
    }
  }
}

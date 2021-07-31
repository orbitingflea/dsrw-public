#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 3e7;

int n;
int nk, keys[maxn];

struct Oper {
  char type;
  int lv, rv;
} op[maxn];

int bit[maxn];

int Lowbit(int i) {
  return i & -i;
}

void Add(int i, int x) {
  for (; i < n; i += Lowbit(i + 1)) {
    bit[i] += x;
  }
}

int Sum(int i) {
  int sum = 0;
  for (--i; i >= 0; i -= Lowbit(i + 1)) {
    sum += bit[i];
  }
  return sum;
}

int main(void) {
  scanf("%d", &n);
  nk = 0;
  for (int i = 0; i < n; ++i) {
    char type[2];
    int lv, rv;
    scanf("%s%d%d", type, &lv, &rv);
    op[i] = {*type, lv, rv};
    if (*type == 'i') {
      keys[nk++] = lv;
    }
  }
  sort(keys, keys + nk);
  nk = unique(keys, keys + nk) - keys;
  for (int i = 0; i < n; ++i) {
    if (op[i].type == 'i') {
      int x = lower_bound(keys, keys + nk, op[i].lv) - keys;
      if (Sum(x) == Sum(x + 1)) {
        // if duplicate, ignore
        Add(x, 1);
      }
    } else {
      int l = lower_bound(keys, keys + nk, op[i].lv) - keys;
      int r = lower_bound(keys, keys + nk, op[i].rv) - keys;
      int ans = Sum(r) - Sum(l);
      printf("%d\n", ans);
    }
  }
  return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <random>
#include "fastio_f.hpp"
using namespace std;

const int maxn = 1e7;

unordered_set<string> S;
int n;
string arr[maxn];

#define rand _rand
random_device rand;

FastOutput fin;
FastOutput fans;

const char *alphabet =
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int alphabet_len = strlen(alphabet);
const int key_len = 16;

char GenerateChar(void) {
  return alphabet[rand() % alphabet_len];
}

string GenerateKey(void) {
  string s(key_len, '0');
  for (int i = 0; i < key_len; ++i) {
    s[i] = GenerateChar();
  }
  return s;
}

void MakeInsert(int time) {
  string s;
  while (true) {
    s = GenerateKey();
    if (S.count(s)) continue;
    S.insert(s);
    arr[n++] = s;
    break;
  }

  fin.PutString("insert ");
  fin.PutString(s.c_str());
  fin.Putch(' ');
  fin.PutInt(time);
  fin.Putch('\n');
}

void MakeQuery(int time, int ans = -1) {
  if (ans == -1) {
    ans = rand() & 1;
  }
  string s;
  if (ans == 0) {
    s = GenerateKey();
  } else {
    s = arr[rand() % n];
  }
  fin.PutString("query ");
  fin.PutString(s.c_str());
  fin.Putch(' ');
  fin.PutInt(time);
  fin.Putch('\n');
  bool res = S.count(s);
  fans.Putch('0' + res);
  fans.Putch('\n');
}

int main(void) {
  FILE *in = fopen("data.in", "w");
  FILE *ans = fopen("result.ans", "w");
  fin.Init(in);
  fans.Init(ans);

  // insert * N + negative_query * N
  fin.PutInt(maxn * 3);
  fin.Putch('\n');

  int time = 0;
  for (int i = 0; i < maxn; ++i) {
    MakeInsert(++time);
  }
  for (int i = 0; i < 2 * maxn; ++i) {
    MakeQuery(++time, 0);
  }
  return 0;
}

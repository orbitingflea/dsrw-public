#include <cstdio>
#include <cctype>
using namespace std;

const int buffer_size = 1e7;

class FastInput {
  FILE *f;
  char in[buffer_size], *in_l, *in_r;

public:

  void Init(FILE *f_0) {
    f = f_0;
    in_l = in_r = in;
  }

  inline char Getch(void) {
    if (in_l == in_r) {
      in_l = in;
      in_r = in + fread(in, 1, buffer_size, f);
    }
    return *in_l++;
  }

  int GetInt(void) {
    char c = Getch();
    while (!isdigit(c)) {
      c = Getch();
    }
    int x = 0;
    while (isdigit(c)) {
      x = 10 * x + (c - '0');
      c = Getch();
    }
    return x;
  }

  void GetString(char *s) {
    char c = Getch();
    while (!isdigit(c) && !isalpha(c)) {
      c = Getch();
    }
    while (isdigit(c) || isalpha(c)) {
      *s++ = c;
      c = Getch();
    }
    *s++ = '\0';
  }
};

class FastOutput {
  FILE *f;
  char out[buffer_size], *out_r;

public:

  void Init(FILE *f_0) {
    f = f_0;
    out_r = out;
  }

  ~FastOutput(void) {
    // flush
    fwrite(out, 1, out_r - out, f);
  }

  inline void Putch(char c) {
    if (out_r == out + buffer_size) {
      fwrite(out, 1, buffer_size, f);
      out_r = out;
    }
    *out_r++ = c;
  }

  void PutInt(int x) {
    static char buf[20];
    int len = 0;
    while (x) {
      buf[len++] = '0' + x % 10;
      x /= 10;
    }
    if (!len) {
      buf[len++] = '0';
    }
    while (len--) {
      Putch(buf[len]);
    }
  }

  void PutString(const char *s) {
    while (*s) {
      Putch(*s++);
    }
  }
};

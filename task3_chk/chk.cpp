#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
  FILE *out, *ans;
  if (argc == 1) {
    out = fopen("result.out", "r");
    ans = fopen("result.ans", "r");
  } else if (argc == 3) {
    out = fopen(argv[1], "r");
    ans = fopen(argv[2], "r");
  } else {
    fprintf(stderr, "0 or 2 args are needed.\n");
    return 1;
  }

  int cnt[2][2] = {}, x, y;
  while (fscanf(ans, "%d", &y) == 1) {
    fscanf(out, "%d", &x);
    ++cnt[y][x];
  }

  double FPR = 1.0 * cnt[0][1] / (cnt[0][0] + cnt[0][1]);
  double FNR = 1.0 * cnt[1][0] / (cnt[1][0] + cnt[1][1]);
  printf("FPR = %.6lf\n", FPR);
  printf("FNR = %.6lf\n", FNR);
  return 0;
}

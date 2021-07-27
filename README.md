# dsrw-public
Shared code for dsrw course

## task2_checker

这是 task2 的对拍器，用于检验你的程序的正确性。它将重复随机生成测试数据，运行对照程序与待测程序，并对比二者的答案。

为了使用该对拍器，你需要：

1. (可选) 打开 `task2_chk/dmk.py`，修改生成的数据范围。
2. 将你的可执行文件命名为 `./main`，放在 `task2_chk` 的兄弟位置（即在 `task2_chk` 文件夹外，仓库的根目录位置）。
3. 进入 `task2_chk` 文件夹，运行 `main`。

助教上传的 data maker 较慢，请耐心等待。每 check 一组测例，对拍器将会输出一行 ok。若答案错误，则会报错停止，此时 `task2_chk` 目录下的 `in` 文件是让你出错的输入，`out` 是你的输出，`ans` 是对照程序的输出。

若遇到问题或不会使用，请联系本人。

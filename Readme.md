### 编译
使用make命令编译
```commandline
make
```
或
```commandline
make main
```

### 运行
输入文件：在main.cpp中第78行修改输入文件路径重新编译。

threshold：根据图的特性可以在main.cpp中第83行修改threshold限制传染源点的度数必须超过threshold。
运行命令：
```commandline
./main alpha K everyK rr S everyS setRumorRound outputFileName
```
共8个参数：
alpha：每轮选点之间模拟的传播的次数。

K：第一轮选择节点的个数。

everyK：每轮新选择节点的个数。

rr：轮数。

S：最初的传染源个数。

everyS：每轮新增传染源个数（有可能会新增感染不成功）。

setRumorRound：前多少轮有新增感染源。

outputFileName：输出文件名。


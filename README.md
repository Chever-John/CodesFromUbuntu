# CodesFromUbuntu
> Description：This catalog contains content of "Cmake & make" ,thread examples and Shell scripts.

![文件目录](https://i.loli.net/2020/05/23/r1UB8WZe3fh4Axw.jpg)

## Cmake & make

### Files

CMakeFiles、cmake_install.cmake、CMakeCache.txt、CMakeList.txt、Makefile



### Some ideas

1、使用 cmake 增加学习成本（小项目）
2、makefile 这么简单都搞不清楚的脑子，还指望搞得清 cmake ?
3、cmake 是解决多个编译器的兼容问题，我又不支持 gcc 之外的编译器。
4、关键是解决什么问题？你要给白痴用，用 cmake 还要多敲键盘；你要理解构建过程，cmake 多加个间接层，不是更难搞明白？
5、你说，你要不出问题吧，cmake 还需要额外安装，还要多敲一行指令；你说要出了问题自己解决吧，cmake 并不解决构建问题，它只是生成其它构建工具的脚本，结果你最终在什么平台出的问题，一样要自己搞清楚 makefile gcc 这些东西怎么用，不然你还是解决不了问题。
6、你用 cmake 到底想解决啥问题？cmake 只会更加复杂。
7、cmake 解决的是你的项目要在不同平台不同编译器下都可以写一致构建脚本的问题，它要抽象各个不同环境为一致的环境。你必须学习这个抽象方法。
8、然后你工作在哪个平台，还是要学习那个平台具体的构建方法。等于你至少要学习两套：一套 cmake 一套你的目标平台。你不跨 3 个平台以上，根本值不回学习成本。
9、两个平台的话，你分别学两套就够了，用不着多学 cmake。只学 cmake 没任何用啊，必须加学目标环境的东西。cmake 又不帮你解决编译器怎么开关的问题。
10、只学了 cmake 等于什么都没学，构建遇到问题肯定一抹黑。
11、cmake 解决的问题和 make 解决的问题是两码事。比如你编译要加个警告开关，你要写在编译指令里，这个不是 cmake 要解决的问题。cmake 帮你解决的是，你在不同环境要做同一个事情，怎么写在同一个脚本分发，它本身不解决具体加什么编译开关的问题。比方说你的编译流程有一步要把一个文件复制到另一个位置，cmake 并不解决拷贝文件的问题，它解决的是让你在 windows 下用 copy ， unix 下用 cp ，怎么把两套指令写在同一套构建文件的问题。
12、这是两个层面不同的问题。cmake 解决的只是跨平台和开发环境时，怎么把不同的编译工具的调用方法写在同一套脚本里的问题；并没有解决怎么把项目从源代码构建成目标程序的问题。
13、cmake 可能提供了一些默认脚本把一些默认的构建行为写好了给你调用，但是当你要自定义构建行为时，学习成本是很高的。因为你要兼顾各种不同的平台。
14、如果你不要跨很多平台，cmake 解决的那个层次的问题对你本来就是不存在的。
15、ide 解决的是另一个层次的问题，和 cmake make 更不一样。
————————————————
版权声明：本文为CSDN博主「TTC」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/liutianshx2012/article/details/80811175



## Thread example

### Files

demos、example、homework



## Shell scripts

### Files

scripts

脚本运行命令分别是：source test.sh 182219605113 和  sh forc.sh


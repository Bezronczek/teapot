teapot
======

To install GCC v4.7 which contain more support for C++0x (i.e. std::string::pop_back method) just  do:
$ sudo add-apt-repository ppa:ubuntu-toolchain-r/test 
$ sudo apt-get update
$ sudo apt-get install gcc-4.7 g++-4.7
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.6 
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.7 40 --slave /usr/bin/g++ g++ /usr/bin/g++-4.7 
$ sudo update-alternatives --config gcc

To switch between compilers use:
$ sudo update-alternatives --config gcc

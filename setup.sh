echo -e "\033[0;34mMade by \033[1;36mKeonHeeLee] \033[1;34m(Thursday, 7 June 2018)"
echo -e "\033[0;34m- Github : \033[1;36mhttps://github.com/KeonHeeLee/study-compiler"
echo -e "\033[0;34m- E-mail : \033[1;36mbeta1360@naver.com\033[0m"
echo " "

if ! [ -d "$src"]; then
    echo -e "\033[0;31mSetup Error: Don't exist directory::src\033[0m"
    echo -e "\033[0;31mPlease check directory::src\033[0m"
    exit
fi

cd src

if ! [ -d "$icg"]; then
    echo -e "\033[0;31mSetup Error: Don't exist directory::icg\033[0m"
    echo -e "\033[0;31mPlease check directory::icg\033[0m"
    exit
fi

cd icg

if ! [ -e "$make"]; then
    echo -e "\033[0;31mSetup Error: Don't compile this source codes!!\033[0m"
    echo -e "\033[0;31mMakefile don't exists this directory.\033[0m"
    exit
fi

make
mv minic ../..
make clean
cd ..

if ! [ -d "$ucode"]; then
    echo -e "\033[0;31mSetup Error: Don't exist directory::ucode\033[0m"
    echo -e "\033[0;31mPlease check directory::ucode\033[0m"
    exit
fi

cd ucode
g++ -c ucodei.cpp -w
g++ -o ucodei ucodei.o
mv ucodei ../..
rm -rf ucodei.o
cd ../..

echo " "
echo -e "\e[32m== Installation is complete. =="
echo -e "== Usage is as follows. ======="
echo -e "\033[1;33m - Usage(make '.uco' file):: ./minic <miniC file>\e[39m"
echo -e "\033[1;33m - Usage(execute U-code interpreter):: ./ucodei <uco file>\e[39m"
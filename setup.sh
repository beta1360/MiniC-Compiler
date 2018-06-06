echo -e "\033[0;34mMade by \033[1;36mKeonHeeLee] \033[1;34m(Thursday, 7 June 2018)"
echo -e "\033[0;34m- Github : \033[1;36mhttps://github.com/KeonHeeLee/study-compiler"
echo -e "\033[0;34m- E-mail : \033[1;36mbeta1360@naver.com\e[39m"
echo " "

cd icg
make
mv minic ..
make clean
cd ..

echo " "
echo -e "\e[32m== Installation is complete. =="
echo -e "== Usage is as follows. ======="
echo -e "\033[1;33m - Usage:: ./minic <miniC file>\e[39m"
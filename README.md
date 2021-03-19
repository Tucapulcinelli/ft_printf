Introduction

The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable you to discover variadic functions in C. The key to a successful ft_printf is a well-structured and good extensible code.

Tests

Clone your repo, do not enter it, then do the following:

git clone https://github.com/cacharle/ft_printf_test.git

cd ft_printf_test
make run
make fclean
cd ..
rm -rf ft_printf_test

cd ft_printf
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini &&
git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
make && ./test
cd ..
make fclean
rm -rf .gitignore
rm -rf pft_2019

git clone https://github.com/Mazoise/42TESTERS-PRINTF
cd 42TESTERS-PRINTF
bashruntest.sh
cd ..
rm -rf 42TESTERS-PRINTF

git clone https://github.com/Tripouille/printfTester
cd printfTester
make m && make fclean
cd ..
rm -rf printfTester

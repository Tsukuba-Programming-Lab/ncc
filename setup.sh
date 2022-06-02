#!/bin/sh

# default setup
bold=$(tput bold)
normal=$(tput sgr0)
echo "${bold}:ncc setup:${normal}\n"

# get directory setup
echo "type CGI directory (~/wwws/cgi-bin/[input]/main.py)"
read -p "> " cgi_dir

echo "type bin directory (~/[input]/ncc)"
read -p "> " ncc_dir

if [ -z "$cgi_dir" ]; then
    echo "Empty CGI directory"; exit 1
fi

ncc_path="$HOME/$ncc_dir"
if [ ! -e $ncc_path ]; then
    mkdir -p $ncc_path; 
fi

# make dir (if not exists)
cgi_path="$HOME/wwws/cgi-bin/$cgi_dir"
if [ ! -e $cgi_path ]; then
    mkdir -p $cgi_path; 
fi

echo ''

cgi_url="https://cgi.u.tsukuba.ac.jp/~$LOGNAME/$cgi_dir/main.py" 

echo "CGI path: $cgi_path/main.py"
echo "CGI URL: $cgi_url"
echo "ncc path: $ncc_path"

echo ''

echo "Copy CGI files..."

cp ./main.py $cgi_path
chmod +x $cgi_path/main.py

echo "Running make..."

cat main.cpp | sed -e "s|::CGI_PLACEHOLDER::|$cgi_url|" > _main.cpp
make -s all

mv ./ncc $ncc_path

echo "Cleaning files...\r"

make -s clean

echo "Complete!"
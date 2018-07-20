#!/bin/bash
echo ""
echo "Cleaning old build"
echo ""
make clean
echo ""


echo ""
echo "=================	FTP install wizard ======================="
echo ""

echo "What do you want to install?"
echo "1.	Server"
echo "2.	Client"
echo ""

LOOP=true
while $LOOP; do
read -p "Please select [1/2]: " delconf
LOOP=false
if [ $delconf == 1 ]; then
	echo "Installing Server..."
	echo ""
	make myftpd
	echo ""
	echo "Executable in bin folder"
elif [ $delconf == 2 ]; then
	echo "Installing Client..."
	echo ""
	make myftp
	echo ""
	echo "Executable in bin folder"
else
	echo "Enter a valid response 1 or 2"
	LOOP=true
fi
done
	

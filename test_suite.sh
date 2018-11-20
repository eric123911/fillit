#!/bin/sh

#set -o errexit

NOM_FICHIER_EXECT="./fillit"
NOM_DOSSIER_TESTS="./examples"

excut=$(ls ${NOM_FICHIER_EXECT})
test_files=$(ls ${NOM_DOSSIER_TESTS}/*)

# Verify that execuable exists
if [[ ($excut != "./fillit") ]]; then
	echo $excut
	printf "Compiling fillit (please wait) "
	eval `make all` > /dev/null 2>&1
	sleep 1 ; printf ". "
	sleep 1 ; printf ". "
	sleep 1 ; printf ". \n"
	sleep 3
fi

excut=$(ls ${NOM_FICHIER_EXECT})
j=0
echo
for i in $test_files; do
	echo "\033[31m+-------------------------------+"
	if ((j < 10)); then
		echo "|\t \033[32mTEST\033[0m 0$j\t\t\033[31m|"
	else
		echo "|\t \033[32mTEST\033[0m $j\t\t\033[31m|"
	fi
	echo "+-------------------------------+\033[0m"
	echo $excut $i
	echo OUTPUT:
	eval time $excut $i
#	echo
#	echo $excut -u $i
#	echo OUTPUT:
#	eval $exect -u $i
	echo "--------------------"
	let j+=1
done

echo
echo
echo ============
echo DONE TESTING
exit 0

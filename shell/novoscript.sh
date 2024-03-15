lista=(1 2 3 4 45 12 92)
frutas[0]=banana
frutas[1]=melancia
echo $frutas
echo ${frutas[1]}
x=0
until [ $x -eq 7 ]; do
	echo ${lista[$x]}
	x=$((x+1))
done

frutas2=(banana, abacaxi, uva, abacate, melancia, maçã, kiwi)
for fruta in ${frutas2[@]};
do
    echo $fruta
done

x=1
if [ $x -eq 5 ]; then
    echo "x é igual a 5"
elif [ $x -eq 4 ]; then
    echo "x é igual a 4"
elif [ $x -eq 3 ]; then
    echo "x é igual a 3"
elif [ $x -eq 2 ]; then
    echo "x é igual a 2"
else
    echo "x é diferente de 5, 4, 3 e 2"
fi

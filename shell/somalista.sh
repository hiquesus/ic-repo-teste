#!/bin/bash

lista=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 90)
soma=0

for num in ${lista[@]};
do
	soma=$((soma+num))
done

echo $soma


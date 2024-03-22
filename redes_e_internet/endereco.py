#convertendo o IP 198.51.100.123 para binário
endereço = [198, 51, 100, 123]
endereço_binário = [bin(i)[2:].zfill(8) for i in endereço]
 # Calculando a máscara de subrede de sub-rede
máscara = [255, 255, 255, 0]
máscara_binária = [bin(i)[2:].zfill(8) for i in máscara]
# Aplicando a operação lógica AND 
resultado = [a & m for a,m in zip(endereço, máscara)]
# Note que o operador AND binário, &, quando aplicado a dois números em base 10, primeiro os converte para binário e depois aplica a operação AND bit a bit.
print(resultado)
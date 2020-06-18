# BomDiaCpp

Há algumas regras que, como estudante, irei seguir para melhorar a qualidade do meu código e criar bons hábitos desde cedo:

1 - Usar nomes de variáveis descritivas.
	O código deve se auto explicar no quesito de funcionalidade. Os comentários são apenas para informar o porquê da escolha daquela abordagem.
	Um princípio a ser seguido aqui é de que "O tamanho e especificidade do nome das variáveis é proporcional ao escopo em que ela atua".
	No caso, quanto menor for o escopo de atuação, mais vago é permitido nomear as variáveis. É o caso para variáveis de controle, swap, e afins.
	Porém em outros casos, é necessário nomes mais descritivos. É necessário bom senso para equilibrar entre praticidade e legibilidade.

2 - Minimalismo
	Este projeto não tem como finalidade ser uma aplicação de grande porte. Dessa forma, não usarei recursos que são além do que o bom senso permite.
	Por ser um projeto simples de tratamento de texto, não irei usar um banco de dados como SQL ou da mesma robustez. Os dados serão armazenados em formatos simples.
	Nada impede no futuro de aplicar criptografia, senha para acesso e permissões por usuário. Mas até lá irei abusar da simplicidade onde por possível.
	
3 - Comentários
	Comentários são para explicar o porquê de certas escolhas terem sido feitas, ou para explicar alguma fórmula ou linha de código que não fica imediatamente clara.
	Comentários não são para explicar o que cada comando faz, ou como eles se relacionam entre si. A funcionalidade do código deve ser auto explicativa.
	Então por exemplo, se estivermos programando um jogo, e encontrarmos a linha a seguir:
			carteira = carteira - 2*pocaoFraca.preco;
	Um mau comentário seria:
			"//Carteira recebe o valor dentro dela menos o dobro do valor do itemA"
	É um mau comentário porque isso já é evidente no código (que utiliza de variáveis bem nomeadas). Ali é só chover no molhado.
	
	Um bom comentário seria:
			"// O item em questão só pode ser comprado em 2 unidades ou múltiplos de 2 unidades (4,6,8,256, etc..)
	É um bom comentário pois explica o porque da linha de código ser do jeito que é, ao mesmo tempo que deixa os comandos explicarem o resto da função
	
	
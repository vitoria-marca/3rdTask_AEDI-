Vitória Marca Santa Lucia - 23200577 AED - M2 / 2024-2

O problema 1845 do LeetCode propõe a implementação de uma classe chamada "SeatManager". A lógica por trás seria implementar 4 funções, criar o objeto, reservar um assento, liberar um assento (seria dado o número do mesmo) e liberar o objeto.
Como estamos trabalhando em C, não é possível implementar classes pois a linguagem não abrange esse paradigma, mas é possível utilizar do conceito de MinHeap (fila de prioridade) para solucionar o problema.

Além dos casos testados dentro do próprio LeetCode, foram testados localmente:
1. Pedir para reservar um assento que não existe;
2. Pedir para liberar o assento mais de uma vez;

Entretanto, eu praticamente mudei todo o código que desenvolvi em aula por não ter implementado o Heap corretamente, mas sim uma espécie de lista encadeada com uma variável booleana "available". Não é errado, mas o runtime do LeetCode acusava um tempo muito grande para rodar determinados casos, então essa estratégia não foi válida.

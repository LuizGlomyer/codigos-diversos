#ifndef COMBSORT_HPP_INCLUDED
#define COMBSORT_HPP_INCLUDED

template<typename T>
void combsort(T* matriz, int tamanho)
{
	int i, j, intervalo, trocado = 1;
	T aux;
	intervalo = tamanho;
	while (intervalo > 1 || trocado == 1)
	{
		intervalo = intervalo * 10 / 13;
		if (intervalo == 9 || intervalo == 10) intervalo = 11;
		if (intervalo < 1) intervalo = 1;
		trocado = 0;
		for (i = 0, j = intervalo; j < tamanho; i++, j++)
		{
			if (matriz[i] > matriz[j])
			{
				aux = matriz[i];
				matriz[i] = matriz[j];
				matriz[j] = aux;
				trocado = 1;
			}
		}
	}
}

#endif // COMBSORT_HPP_INCLUDED

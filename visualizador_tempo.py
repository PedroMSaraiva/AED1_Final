import matplotlib.pyplot as plt

# Dados da tabela atualizados com ShellSort (valores hipotéticos para demonstração)
algorithms = ['QuickSort', 'QuickSort', 'QuickSort', 'QuickSort', 'QuickSort',
              'MergeSort', 'MergeSort', 'MergeSort', 'MergeSort', 'MergeSort',
              'ShellSort', 'ShellSort', 'ShellSort', 'ShellSort', 'ShellSort']  
records = [500, 1000, 2000, 3000, 5000,
           500, 1000, 2000, 3000, 5000,
           500, 1000, 2000, 3000, 5000] 
times = [0.0000059696, 0.0000070510, 0.0000064948, 0.0000066958, 0.0000068570,
         0.000044, 0.000096, 0.000199, 0.000313, 0.000756,
         0.000000, 0.000000, 0.000000, 0.000000, 0.000000]  # Guilherme, coloque os valores aqui

colors = {
    'QuickSort': 'green',
    'MergeSort': 'blue',
    'ShellSort': 'red'
}

# Marcadores para os algoritmos
markers = {
    'QuickSort': 'o',
    'MergeSort': 's',
    'ShellSort': 'd'
}

# Separar os tempos por algoritmo
records_qs = records[:5]
records_ms = records[5:10]
records_ss = records[10:]

times_qs = times[:5]
times_ms = times[5:10]
times_ss = times[10:]

# Criar gráfico com estilo mais elegante
plt.style.use('seaborn-v0_8-darkgrid')

# Criar figura e eixo
fig, ax = plt.subplots(figsize=(12, 7))

# Plot QuickSort
ax.plot(records_qs, times_qs, marker=markers['QuickSort'], color=colors['QuickSort'], label='QuickSort', linewidth=2)

# Plot MergeSort
ax.plot(records_ms, times_ms, marker=markers['MergeSort'], color=colors['MergeSort'], label='MergeSort', linewidth=2)

# Plot ShellSort
ax.plot(records_ss, times_ss, marker=markers['ShellSort'], color=colors['ShellSort'], label='ShellSort', linewidth=2)

# Títulos e rótulos
ax.set_title('Comparação do Tempo de Execução dos Algoritmos de Ordenação', fontsize=18, fontweight='bold')
ax.set_xlabel('Quantidade de Registros', fontsize=14)
ax.set_ylabel('Tempo (segundos)', fontsize=14)

# Melhorar a legenda
ax.legend(frameon=True, loc='upper left', fontsize=12)

# Adicionar grades para melhor leitura
plt.grid(True, which="both", linestyle="--", linewidth=0.5, color='gray')

# Adicionar anotações dos tempos nos pontos
for i, txt in enumerate(times):
    ax.annotate(f'{txt:.8f}', (records[i], times[i]), textcoords="offset points", xytext=(0,10), ha='center')

# Mostrar o gráfico
plt.show()
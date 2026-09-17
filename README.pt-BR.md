# 🧵 Transferência Colaborativa entre Contas

Este repositório contém uma atividade acadêmica desenvolvida durante a disciplina de **Sistemas Operacionais** no curso de Ciência da Computação.

A atividade implementa uma **transferência colaborativa entre duas contas utilizando múltiplas threads**, explorando os efeitos do acesso concorrente e o uso de mecanismos de sincronização.

📅 **Semestre Acadêmico:** 2026/02

---

## 🚀 Tecnologias & Ferramentas

* **Linguagem:** C
* **Biblioteca de Threads:** POSIX Threads (`pthread`)
* **Sistema Operacional:** Linux
* **Compilador:** GCC

---

## 📋 Instruções da Atividade

### Objetivo

Implementar um programa que utiliza **múltiplas threads** para transferir todo o saldo da **Conta A** para a **Conta B**.

### Estado Inicial

* **Conta A = 100.000.000**
* **Conta B = 0**
* **Auditoria = 0** (variável global utilizada para verificar se todos os valores foram realmente transferidos)

### Comportamento de Cada Thread

1. Cada thread mantém uma variável **local** (`local_sum`), inicializada com 0.
2. Enquanto houver saldo na Conta A:

   * Se **A < 100**, transfere todo o valor restante (`v = A`) para a Conta B.
   * Caso contrário, sorteia um número inteiro `v` entre **1 e 100**.
   * Transfere `v` da Conta A para a Conta B.
   * Adiciona `v` à variável local **`local_sum`**.
3. Ao terminar, a thread adiciona seu `local_sum` à variável global **Auditoria**.
4. A thread termina quando a **Conta A** for menor ou igual a 0.

### Regras Gerais

* Utilizar **variáveis compartilhadas** para representar a Conta A, a Conta B e a Auditoria.
* O valor transferido em cada passo **não pode ultrapassar 100**.
* Criar **N threads** (sugestão de 4 ou 8 threads).
* Após todas as threads terminarem, exibir os saldos finais das contas.

Exemplo:

```text
Conta A=0 Conta B=1000000 Auditoria=1000000
```

---

## 📂 Implementações

### Q1 - Sem Sincronização

A primeira implementação não utiliza **nenhuma primitiva de sincronização**, como mutex ou semáforos.

O objetivo é observar os efeitos do acesso concorrente às variáveis compartilhadas e a possibilidade de ocorrerem **condições de corrida**.

**Compilar:**

```bash
gcc -pthread -o q1 q1.c
```

**Executar:**

```bash
./q1
```

### Q3 - Com Mutex

A segunda implementação realiza a mesma tarefa utilizando `pthread_mutex_*` para controlar o acesso concorrente às variáveis compartilhadas.

O mutex garante que as transferências sejam consistentes e evita que condições de corrida causem resultados incorretos.

**Compilar:**

```bash
gcc -pthread -o q3 q3.c
```

**Executar:**

```bash
./q3
```

---

## 👩‍💻 Autora

Desenvolvido com 💙 por **Júlia Roos Costa**

// Brendo Yuki Katagi - RA 120.682
// Luan Olimpio Claro da Costa - RA 120.855
// Matheus Anido Pereira Coimbra - RA 104.112

// Atividade 2 - Programacao Concorrente e Distribuida
//Manna-Pnueli Critical Section

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

# define NUM_THREADS 12
# define N 11*1000
# define TRUE 1
# define FALSE 0
typedef struct Thread_data {
  int id;
} Thread_data;

int soma = 0;
int nSC = 0;
int request = 0; 
int respond = 0;
int hasThread = TRUE;

void * client(void* ptr) { 
  Thread_data * t_data = (Thread_data *) ptr;
  int i, local;
  while (i < N / (NUM_THREADS-1)) {
    //while(respond != t_data->id) request = t_data->id;
    //Critial Section
    if(i<5){
      printf("Thread %d entrou na SC\n", t_data->id);
    }
    local = soma;
    nSC++;
    // sleep(rand()%2);
    soma = local+1;
    respond = 0;
    if(i<5){
      printf("Thread %d saiu da SC\n", t_data->id);
    }
    i++;
  }
}

void * server(void* ptr) {
  while(hasThread){
    while(request == 0 && hasThread);
    respond = request;
    while(respond != 0 && hasThread);
    request = 0;
  }
}

int main() {
  int thread_num;
  pthread_t threads[NUM_THREADS];
  Thread_data t_data[NUM_THREADS];
  for(thread_num = 1; thread_num < NUM_THREADS; thread_num++){
    t_data[thread_num].id = thread_num;
  }

  pthread_create(&threads[thread_num], NULL, &server, NULL);
  for(thread_num = 1; thread_num < NUM_THREADS; thread_num++){
    pthread_create(&threads[thread_num], NULL, &client, &t_data[thread_num]);
  }

  for(thread_num = 1; thread_num < NUM_THREADS; thread_num++){
    pthread_join(threads[thread_num], NULL);
  }
  hasThread = FALSE;
  printf("Thread client joined\n");
  pthread_join(threads[0], NULL); 

  printf("%d\n", soma);
  return 0;
}

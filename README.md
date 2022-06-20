# Minitalk

Fonction getpid :
```c
pid_t getpid(void);
```
Cette fonction renvoie l'identifiant de processus (PID) appelant.

Fonction kill :
```c
int kill(pid_t pid, int sig);
```
kill permet d'envoyer n'importe quel signal a n'importe quel processus. 
- Si le PID est positif, le signal sig est envoye au processus dont l'identifiant est indique grace au PID.
- Si le PID vaut 0, le sig est envoyes a tous les processus du meme groupe que le processus appelant

## Usefull links

[Youtube, CodeVault, Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs)

# Minitalk

Le but de ce projet est de realiser un programme de communication sous la forme d'un client et d'un serveur. Le serveur devra etre lance en premier et doit afficher son PID, tandis que le client prendra en parametre le PID du serveur ainsi qu'une chaine de caracteres a transmettre. Le client doit communiquer au serveur la chaîne passée en paramètre et l’afficher rapidement.

Le serveur doit povoir recevoir des chaines de plusieurs clients a la suite sans devoir etre relance, la communication doit se faire uniquement avec des signaux UNIX, les seuls signaux utilisables etant SIGUSR1 et SUGUSR2.

Fonctions autorisees :

- write
- ft_printf et tout équivalent que VOUS avez codé
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit

## Les fonctions

Le man de la fonction signal precisant par lui-meme de preferer la fonction sigaction pour eviter les comportements variables selon la version d'Unix utilisee, on se tournera plutot sur sigaction pour ce projet.

### sigaction
```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```
Cette fonction permet de modifier l'action effectuee par un processus a la reception d'un signal specifique. sigaction retourne 0 en cas de succes, -1 en cas d'erreur.

- signum : La variable signal, tel que **SIGUSR1** ou **SIGUSR2**
- sigaction act : Prends la structure de sigaction

La structure de sigaction est la suivante :
```c
struct sigaction {
    void     (*sa_handler) (int);
    void     (*sa_sigaction) (int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer) (void);
};
```
Sigaction necessite une fonction handler, qui remplace et change le signal recu par sigaction. Le signum passe a sigaction ira dans cette fonction handler.
sa_handler permet de declarer quel gestionnaire est utilise si le signal est passe a la structure sa.

### getpid
```c
pid_t getpid(void);
```
Cette fonction renvoie l'identifiant de processus (PID) appelant.

### kill
```c
int kill(pid_t pid, int sig);
```
kill permet d'envoyer n'importe quel signal a n'importe quel processus. kill retourne 0 en cas de succes, et -1 en cas d'echec.

### pause
```c
int pause(void);
```
pause force le procesus a s'endormir jusqu'a ce qu'un signal soit recu, qui le termine ou lui fasse invoquer une fonction de gestionnaire de signal.

## Usefull links

[Youtube, CodeVault, Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs)
[Youtube, Codevault, Communicating between processes using signals](https://www.youtube.com/watch?v=PErrlOx3LYE)

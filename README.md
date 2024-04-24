# Guide d'utilisation de pipex

Ce guide explique comment utiliser le projet pipex pour exécuter des commandes shell à travers des pipes.

## Installation

1. Clonez le dépôt pipex depuis GitHub :

    ```shell
    git clone https://github.com/votre-utilisateur/pipex.git
    ```

2. Accédez au répertoire du projet :

    ```shell
    cd pipex
    ```

3. Compilez le projet en exécutant la commande make :

    ```shell
    make
    ```

## Utilisation

Pour utiliser pipex, suivez les étapes suivantes :

1. Exécutez la commande suivante pour exécuter une commande shell à travers un pipe :

    ```shell
    ./pipex fichier_in cmd1 cmd2 fichier_out
    ```

    - `fichier_in` : le fichier d'entrée contenant les données à envoyer à la première commande.
    - `cmd1` : la première commande à exécuter.
    - `cmd2` : la deuxième commande à exécuter.
    - `fichier_out` : le fichier de sortie où les résultats seront stockés.

2. Les résultats de la commande seront écrits dans le fichier de sortie spécifié.

## Exemples

Voici quelques exemples d'utilisation de pipex :

- Pour exécuter la commande `ls -l | grep .txt` et enregistrer les résultats dans le fichier `resultats.txt`, utilisez la commande suivante :

  ```shell
  ./pipex fichier.txt "ls -l" "grep .txt" resultats.txt
  ```

- Pour exécuter la commande `cat fichier.txt | sort | uniq` et afficher les résultats à l'écran, utilisez la commande suivante :

  ```shell
  ./pipex fichier.txt "cat" "sort" "uniq"
  ```
